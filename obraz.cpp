#include <stdlib.h>
#include "obraz.h"
#include <math.h>
#include <iostream>

Obraz::Obraz(int szer, int wys)
{
    this->szer = szer;
    this->wys = wys;
    dane = new unsigned char[szer*wys*4];
    for (int i = 0; i < szer*wys; ++i) {
        dane[4*i] = 0;
        dane[4*i+1] = 0;
        dane[4*i+2] = 0;
        dane[4*i+3] = 255;
    }
}

void Obraz::wstawPiksel(int x, int y, int r, int g, int b)
{
    if (x < 0 || y < 0 || x >= szer || y >= wys) return;
    int adr = 4*(y*szer + x);
    dane[adr] = b;
    dane[adr+1] = g;
    dane[adr+2] = r;
    dane[adr+3] = 255;
}

void Obraz::linia(int x1, int y1, int x2, int y2)
{
    /*int dx = x2 - x1;
    int dy = y2 - y1;
    int l = sqrt(dx*dx + dy*dy)*2;

    for (int i = 0; i <= l; ++i)
    {
        float a = (float)i/l;
        wstawPiksel(x1 + dx*a, y1 + dy*a, 255, 255, 255);
    }*/
    bool spr = (fabs(y2-y1) > fabs(x2-x1));
    if(spr)
    {
       std::swap(x1,y1);
       std::swap(x2,y2);
    }

    if(x1>x2)
    {
        std::swap(x1,x2);
        std::swap(y1,y2);
    }
    float dx = x2 - x1;
    float dy = fabs(y2-y1);

    float error = dx / 2.0f;
    int ystep = ( y1 < y2 ) ? 1 : -1;
    int y = (int)y1;

    int maxX = (int)x2;

    for(int x=(int)x1; x<maxX; x++)
    {
        if(spr)
        {
             wstawPiksel(x,y, 255, 255, 255);
        }
        else
        {
             wstawPiksel(y,x, 255, 255, 255);
        }

        error -= dy;
        if(error < 0)
        {
            y += ystep;
            error += dx;
        }
    }
}

void Obraz::fillRect(int x1, int y1, int x2, int y2, int r, int g, int b)
{

}
