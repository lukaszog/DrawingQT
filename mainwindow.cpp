#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdlib.h>
#include <math.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->przycisk, SIGNAL(clicked()), this, SLOT(reakcja() ) );    
    connect(&timer, SIGNAL(timeout()), this, SLOT(klatkaAnimacji()));
    timer.start(33);

    ui->przycisk->setText("Nowa nazwa");
    qDebug("Rozmiar widgeta: %d %d", ui->widget->width(), ui->widget->height());

    obraz = new Obraz(400, 400);
    /*for (int i = 0; i < 10000; ++i)     {
        obraz->wstawPiksel(rand()%300, rand()%200, 0, rand(), 0);
    }*/

    // int c = 16;
    /* for (int i = 0; i < c; ++i)
    {
        float a = 3.1416*2*i/c;
        obraz->linia(150, 150, 150 + 100*cos(a), 150 + 100*sin(a));
    } */

    //gwiazda
    //obraz->linia(0,0,200,400);

    obraz->circle(200,150,100);

    ui->widget->update();
    ui->widget->setObraz(obraz);
}

void MainWindow::klatkaAnimacji()
{
    for (int i = 0; i < 1000; ++i)     {
        obraz->fillRect(rand()%obraz->szer, rand()%obraz->wys,
                        rand()%obraz->szer, rand()%obraz->wys,
                        rand(), rand(), rand());
    }
    ui->widget->update();
}

void MainWindow::reakcja()
{
    for (int i = 0; i < 10000; ++i)     {
        obraz->wstawPiksel(rand()%300, rand()%200, 0, rand(), 0);
    }
    ui->widget->update();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
