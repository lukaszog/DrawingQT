#include "widok.h"
#include <QPainter>
#include <QMouseEvent>
#include <QImage>

Widok::Widok(QWidget *parent) :
    QWidget(parent)
{
    im = NULL;
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
void Widok::mouseMoveEvent(QMouseEvent *e)
{
    if(im == NULL) return;
    im->wstawPiksel(e->x(), e->y(),255,255,255);
    update();
}

void Widok::setObraz(Obraz *nowy)
{
    im = nowy;
}
