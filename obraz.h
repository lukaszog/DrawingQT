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
    void fillRect(int x1, int y1, int x2, int y2, int r, int g, int b);
};

#endif // OBRAZ_H
