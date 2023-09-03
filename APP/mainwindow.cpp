#include "historial.h"
#include "ox.h"
#include "temp.h"
#include "gas.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMainWindow"


void setupMain(void)
{


}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QFontDatabase::addApplicationFont(":/new/fonts/Baymax.otf");
    QFontDatabase::addApplicationFont(":/new/fonts/Skull.otf");
    QFont fontTitulo = QFont("Baymax",55,1);
    QFont fontSecundario = QFont("Skull", 15,-1);
    ui->setupUi(this);
    ui->label_nombre->setFont(fontTitulo);
    ui->label_gas->setFont(fontSecundario);
    ui->label_pulso->setFont(fontSecundario);
    ui->label_temperatura->setFont(fontSecundario);
    ui->label__oxigenacion->setFont(fontSecundario);
    qDebug() <<"Drivers:" << QSqlDatabase::drivers(); //me tira la lista de los drivers disponibles

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
    QPixmap boton_historial("C:/Users/notebook/Documents/INFO II 2023/TPO/TPO_INFOII/APP/images/historial-medico.png");
    QIcon icon_historial (boton_historial);
    ui->pushButton_historial->setIcon(icon_historial);
    ui->pushButton_historial->setFont(fontSecundario);

    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("C:/sqlite/gui/databases/mydb.sqlite"); //seteamos la base de datos

    if (!m_db.open()) //checqueamos si se conecto o no
    {
        qDebug() << "Error: connection with database failed";
        ui->lcdNumber_gas->display(datos.getGas());
        ui->lcdNumber_ox->display(datos.getOxi());
        ui->lcdNumber_pulso->display(datos.getPulso());
        ui->lcdNumber_temperatura->display(datos.getTemp());
    }
    else
    {
        qDebug() << "Database: connection ok";
        //QMessageBox::information(this, "Conectada", "Se logro che");
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


