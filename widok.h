#ifndef WIDOK_H
#define WIDOK_H

#include <QWidget>
#include <obraz.h>

class Widok : public QWidget
{
Q_OBJECT
public:
    explicit Widok(QWidget *parent = 0);
    void setObraz(Obraz *nowy);
    int x1,x2,y1,y2,klik;
protected:
    Obraz *im;

    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);

signals:

public slots:

};

#endif // WIDOK_H
