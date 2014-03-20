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
    if (e->button() == Qt::LeftButton)
    {
      klik++;

      //bezier
      if(klik==1) { x[0] = e->x(); qDebug("zapidalem %d",x[0]); y[0] = e->y();}
      if(klik==2) { x[1] = e->x(); y[1] = e->y();}
      if(klik==4) { x[2] = e->x(); y[2] = e->y();}
      if(klik==5) { x[3] = e->x(); y[3] = e->y();}

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

       // im->linia(y1,x1,y2,x2);
    }

    if(klik == 4)
    {
        int k;
        for(k=0; k<4; k++)
        {
            qDebug("nr: %d x: %d y: %d \n",k,x[k],y[k]);
        }
        im->bezier(x,y);
    }

}

void Widok::setObraz(Obraz *nowy)
{
    im = nowy;
}
