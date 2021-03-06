#ifndef OBRAZ_H
#define OBRAZ_H

class Obraz
{
public:
    int szer, wys;
    unsigned char *dane;

    Obraz(int szer, int wys);
    void wstawPiksel(int x, int y, int r, int g, int b);
    void linia(int x1, int y1, int x2, int y2);
    void sym(int x, int y, int x0, int y0);
    void circle(int x0, int y0, int r);
    void bezier(int x[], int y[]);
    void fillRect(int x1, int y1, int x2, int y2, int r, int g, int b);
    void Elipsa(int x0, int y0, int promx, int promy, int r, int g, int b, float l);
};

#endif // OBRAZ_H
