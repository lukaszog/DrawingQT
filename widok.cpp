#include "widok.h"
#include <QPainter>
#include <QMouseEvent>
#include <QImage>

Widok::Widok(QWidget *parent) :
    QWidget(parent)
{
    im = NULL;
    klik =0;
}

void Widok::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.fillRect(0, 0, width(), height(), Qt::magenta);
    if (im) {
        QImage c(im->dane, im->szer, im->wys, QImage::Format_RGB32);
        p.drawImage(0, 0, c);
    }
}
void Widok::mousePressEvent(QMouseEvent *e)
{
   /* if(im == NULL) return;
    im->wstawPiksel(e->x(), e->y(),255,255,255);
    update(); */

    if (e->button() == Qt::LeftButton)
    {
      klik++;
      if(klik==1)
      {
         x1 = e->x();
         y1 = e->y();
         qDebug("%d",klik);
      }
    }
    if(klik == 2)
    {
        x2 = e->x();
        y2 = e->y();

        qDebug("x1: %d y1: %d\n x2: %d y2: %d", x1,y1,x2,y2);
        im->linia(y1,x1,y2,x2);
    }

}

void Widok::setObraz(Obraz *nowy)
{
    im = nowy;
}
