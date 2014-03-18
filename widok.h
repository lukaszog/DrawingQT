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
protected:
    Obraz *im;

    void paintEvent(QPaintEvent *);
    void mouseMoveEvent(QMouseEvent *);

signals:

public slots:

};

#endif // WIDOK_H
