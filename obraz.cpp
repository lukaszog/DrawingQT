#include <stdlib.h>
#include "obraz.h"
#include <math.h>
#include <QtDebug>
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
void Obraz::sym(int x, int y, int x0, int y0)
{
    wstawPiksel(x+x0,y+y0,255,255,255);
    wstawPiksel(y+x0,x+y0,255,255,255);
    wstawPiksel(y+x0,-x+y0,255,255,255);
    wstawPiksel(x+x0,-y+y0,255,255,255);
    wstawPiksel(-y+x0,-x+y0,255,255,255);
    wstawPiksel(-x+x0,-y+y0,255,255,255);
    wstawPiksel(-y+x0,x+y0,255,255,255);
    wstawPiksel(-x+x0,y+y0,255,255,255);

}
void Obraz::bezier(int x[],int y[])
{
    int i;
    double t;
    for(t = 0.0; t < 1.0; t += 0.0005)
    {
        double xt = pow(1-t, 3) * x[0] + 3 * t * pow (1-t, 2) * x[1] + 3 * pow (t, 2) * (1-t) * x[2] + pow (t, 3) * x[3];
        double yt = pow(1-t, 3) * y[0] + 3 * t * pow (1-t, 2) * y[1] + 3 * pow (t, 2) * (1-t) * y[2] + pow (t, 3) * y[3];

        wstawPiksel(yt,xt,255,255,255);
    }

    for(i=0; i<4;i++)
    {
        wstawPiksel(x[i],y[i],232,232,232);
    }
}

void Obraz::circle(int x0, int y0, int r)
{
    int x,y;
    float d;
    x = 0; //wartosci pocztkowe, zwieksza sie o jeden
    y = r;
    d=1-r;
    sym(x,y,x0,y0);
    while(x<y)
    {
        if (d <= 0)
        {
            d +=2*x+3;
            x++;//kolejna iteracja
        }
        else
        {
            d += 2*x+3-2*y+2;
            x++;
            y--;
        }
        qDebug("Piksel w miejscu x: %d y: %d x0: %d y0: %d",x,y,x0,y0);
        sym(x,y,x0,y0);
    }
}

void Obraz::linia(int x1, int y1, int x2, int y2)
{
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

    float dx = x2 - x1; //odleglosc dx
    float dy = fabs(y2-y1); //odleglosc dy

    float error = dx / 2.0f; //wartosc wyrazenia bledu
    int ystep = ( y1 < y2 ) ? 1 : -1;
    int y = (int)y1;

    int maxX = (int)x2; //do jakiego x2 mamy isc
    //x1 punk poczatkowy
    for(int x=(int)x1; x<maxX; x++)
    {
        if(spr)
        {
             wstawPiksel(x,y, 255, 255, 255); //w kierunku x
        }
        else
        {
             wstawPiksel(y,x, 255, 255, 255); //w kierunku wolnym y
        }
        error -= dy;
        if(error < 0)
        {
            //po ruchu wolnym modyfikacja wyrazenia bledu
            y += ystep;
            error += dx;
        }
    }
}

void Obraz::fillRect(int x1, int y1, int x2, int y2, int r, int g, int b)
{

}
