#include "historial.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMainWindow"
#include "QMessageBox"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_historial_clicked()
{
    Historial objHistorial;

    int rtn = objHistorial.exec();//se abre
}

