#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "obraz.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void reakcja();
    void klatkaAnimacji();
protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    Obraz *obraz;
    QTimer timer;
};

#endif // MAINWINDOW_H
