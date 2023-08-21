#include "historial.h"
#include "ox.h"
#include "temp.h"
#include "gas.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMainWindow"
#include "QMessageBox"
#include <QApplication>
#include <QtWidgets>
#include <QThread>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap boton_gas ("C:/Users/notebook/Documents/INFO II 2023/TPO/TPO_INFOII/APP/images/gas.png");
    QIcon icon_gas (boton_gas);
    ui->pushButton_gas->setIcon(icon_gas);
    ui->pushButton_gas->setIconSize(boton_gas.rect().size());
    QPixmap boton_ox ("C:/Users/notebook/Documents/INFO II 2023/TPO/TPO_INFOII/APP/images/celulas.png");
    QIcon icon_ox (boton_ox);
    ui->pushButton_ox->setIcon(icon_ox);
    ui->pushButton_ox->setIconSize(boton_ox.rect().size());
    QPixmap boton_temp ("C:/Users/notebook/Documents/INFO II 2023/TPO/TPO_INFOII/APP/images/temperatura.png");
    QIcon icon_temp (boton_temp);
    ui->pushButton_temp->setIcon(icon_temp);
    ui->pushButton_temp->setIconSize(boton_temp.rect().size());
    QPixmap boton_pulso ("C:/Users/notebook/Documents/INFO II 2023/TPO/TPO_INFOII/APP/images/corazon.png");
    QIcon icon_pulso (boton_pulso);
    ui->pushButton_pulso->setIcon(icon_pulso);
    ui->pushButton_pulso->setIconSize(boton_pulso.rect().size());

    QPalette colores = ui->pushButton_gas->palette();
    colores.setColor(QPalette::Window, QColor(Qt::white));
    ui->pushButton_gas->setPalette(colores);


    //progress bar
    for (int i = 0; i<100;i++)
    {
        QThread::msleep(50);
        ui->progressBar->setValue(i+1);
        qApp->processEvents(QEventLoop::AllEvents);
    }
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


void MainWindow::on_label_ox_img_linkHovered(const QString &link)
{
    //cout << "HOLA"<<endl;
}


void MainWindow::on_pushButton_ox_clicked()
{
    ox objOx;
    int rtn = objOx.exec();
}


void MainWindow::on_pushButton_gas_clicked()
{
    gas objGas;
    int rtn = objGas.exec();
}


void MainWindow::on_pushButton_temp_clicked()
{
    temp objTemp;
    int rtn = objTemp.exec();
}

