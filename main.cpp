#include "mainwindow.h"
#include <QTimer>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //timer->start(100);
    return a.exec();
}
