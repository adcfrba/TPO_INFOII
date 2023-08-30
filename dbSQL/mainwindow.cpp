#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlError>
#include <QSqlTableModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qDebug() <<"Drivers:" << QSqlDatabase::drivers(); //me tira la lista de los drivers disponibles
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("C:/sqlite/gui/databases/mydb.sqlite"); //seteamos la base de datos

    if (!m_db.open()) //checqueamos si se conecto o no
    {
        qDebug() << "Error: connection with database failed";
    }
    else
    {
        qDebug() << "Database: connection ok";
        QMessageBox::information(this, "Conectada", "Se logro che");
    }
    mModel = new QSqlTableModel(this);
    mModel->setTable("Lecturas");
    mModel->select();
    ui->tableView->setModel(mModel);
    /*
    QSqlDatabase::addDatabase("QSQLITE");
    mDatabase.setHostName("127.0.0.1");//datos de la base de datos
    mDatabase.setDatabaseName("baymaxdata");
    mDatabase.setUserName("root");
    mDatabase.setPassword("bAYMAX.TP0");
    mDatabase.setPort(3306);



    if(!mDatabase.open())
    {
        QMessageBox::critical(this, "Error", mDatabase.lastError().text());
        return;
    }
    mModel = new QSqlTableModel(this);
    mModel->setTable("users");
    mModel->select();
    ui->tableView->setModel(mModel);
*/
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

}


void MainWindow::on_pushButton_nu_clicked()
{
    //mModel->insertRow(mModel->rowCount());
    m_db.open();
    QSqlDatabase::database().transaction();
    QSqlQuery qyInsert(m_db);
    qyInsert.prepare("INSERT INTO lecturas(NOMBRE, TEMP, OXI, PULSO, GAS) VALUES(:NOMBRE, :TEMP, :OXI, :PULSO, :GAS)");
    qyInsert.bindValue(":NOMBRE",ui->lineEdit_NOMBRE->text());
    qyInsert.bindValue(":TEMP",ui->lineEdit_TEMP->text());
    qyInsert.bindValue(":OXI",ui->lineEdit_OXI->text());
    qyInsert.bindValue(":PULSO",ui->lineEdit_PULSO->text());
    qyInsert.bindValue(":GAS",ui->lineEdit_GAS->text());
    qyInsert.exec();

    QSqlDatabase::database().commit();
    m_db.close();
}


void MainWindow::on_pushButton_el_clicked()
{
    //mModel->removeRow(ui->tableView->currentIndex().row());
    m_db.open();
    QSqlDatabase::database().transaction();

    QSqlQuery qyDelete(m_db);
    qyDelete.prepare("DELETE FROM lecturas WHERE NOMBRE=:NOMBRE"); //eliminamos data segun nombre
    qyDelete.bindValue(":NOMBRE",ui->lineEdit_NOMBRE->text());
    qyDelete.exec();

    qDebug() <<"Error: "<<qyDelete.lastError();
    QSqlDatabase::database().commit();
    m_db.close();
}


void MainWindow::on_pushButton_act_clicked()
{
    m_db.open();
    QSqlDatabase::database().transaction();

    QSqlQuery qyUpdate(m_db);
    qyUpdate.prepare("UPDATE lecturas SET TEMP=:TEMP, OXI=:OXI, PULSO=:PULSO, GAS=:GAS WHERE NOMBRE=:NOMBRE");
    qyUpdate.bindValue(":TEMP",ui->lineEdit_TEMP->text());
    qyUpdate.bindValue(":OXI",ui->lineEdit_OXI->text());
    qyUpdate.bindValue(":PULSO",ui->lineEdit_PULSO->text());
    qyUpdate.bindValue(":GAS",ui->lineEdit_GAS->text());
    qyUpdate.bindValue(":NOMBRE",ui->lineEdit_NOMBRE->text()); //se usa el NOMBRE para reconocer cual editar
    qyUpdate.exec();

    qDebug() <<"Error: "<<qyUpdate.lastError();
    QSqlDatabase::database().commit();
    m_db.close();

}


void MainWindow::on_pushButton_MOSTRAR_clicked()
{
    /*
    m_db.open();
    QSqlDatabase::database().transaction();
    mModel->select();

    QSqlDatabase::database().commit();
    m_db.close();
*/
}

