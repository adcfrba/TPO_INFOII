#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qDebug() <<"Drivers:" << QSqlDatabase::drivers(); //me tira la lista de los drivers disponibles
    QSqlDatabase base = QSqlDatabase::addDatabase("QMYSQL");//creo la base de datos
    base.setHostName("localhost");//datos de la base de datos
    base.setUserName("root");
    base.setPassword("bAYMAX.TP0");

    bool ok = base.open();
    if(ok)
        qDebug() << "Se abrio OK";
    else
    {
        qDebug() << "No se pudo abrir";
        QSqlError err = base.lastError();
        qDebug() << err.text();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("");
    db.setDatabaseName("nombreDB");

    if(db.open())
    {
        QMessageBox::information(this, "Connection", "Db exitosa");
    }
    else
    {
        QMessageBox::information(this, "Not Connected", "Db no esta conectada");

    }
}

