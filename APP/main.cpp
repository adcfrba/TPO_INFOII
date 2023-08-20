#include "historial.h"
#include "ox.h"
#include "temp.h"
#include "gas.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>


int main(int argc, char *argv[])
{ 
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
