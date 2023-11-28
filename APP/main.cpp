#include "includes.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>


int main(int argc, char *argv[])
{ 
    QApplication a(argc, argv);
    MainWindow w;
    w.setAnimated(true);
    w.show();

    return a.exec();
}
