#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("C:/sqlite/gui/databases/mydb.sqlite"); //seteamos la base de datos
    if (!m_db.open())
        qDebug() << "Error: connection with database failed";
    else
    {
        qDebug() << "Database: connection ok";
        QSqlDatabase::database().transaction();
        datos.leerData(m_db); //obtenemos los datos y lo guardamos en el objeto
        //mostrarDatos();
        QSqlDatabase::database().commit();
        m_db.close();
    }


    // BLUETOOTH
    connect(agent, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),this, SLOT(deviceDiscovered(QBluetoothDeviceInfo)));
    agent->start(); //inicia la busqueda de dispositivos
    socket = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol);
}

MainWindow::~MainWindow()
{
    delete ui;
    socket->disconnectFromService();
    socket->close();
}

//BT

void MainWindow::deviceDiscovered(const QBluetoothDeviceInfo &info)
{
    ui->listWidget->addItem(info.address().toString());
    // Imprime información sobre el dispositivo descubierto
    //qDebug() << "Nombre del dispositivo:" << info.name();
    //qDebug() << "Dirección MAC del dispositivo:" << info.address().toString();
}

void MainWindow::on_pushButton_find_clicked()
{
    ui->listWidget->clear();
    agent->stop();
    agent->start();
    qDebug() << "error"<< socket->errorString();
}


void MainWindow::on_pushButton_on_clicked()
{
    socket->write("A");
}


void MainWindow::on_pushButton_off_clicked()
{
    ui->listWidget->clear();
}


void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    string = item->text(); //nos guarda la dirección del device en nuestro string
    static const QString serviceUuid (QStringLiteral("00001101-0000-1000-8000-00805F9B34FB"));
    socket->connectToService(QBluetoothAddress(string), QBluetoothUuid(serviceUuid),QIODevice::ReadWrite);
    qDebug() << "Conexión: "<< socket->errorString();
    connect(socket, SIGNAL(readyRead()), this, SLOT(receive()));
}


void MainWindow::receive()
{
    CantBytesRecibidos = socket->bytesAvailable();
    DatosRecibidos = socket->readAll();
    trama += DatosRecibidos;

    if(trama.back() =='>' && finalizarTrama == false)
    {
        finalizarTrama = true;

        tramaExtraida = trama.split('-',Qt::SkipEmptyParts);
        if(tramaExtraida.size() == 7)
        {
            analizarTrama(tramaExtraida, datos);
            ui->listWidget->addItem(trama);
        }
        trama.clear();
        finalizarTrama = false;
    }
    trama.clear();
}

void MainWindow::analizarTrama(QStringList tramaAnalizar, lectura datos)
{
    double checksum =0;

    for(int i = 1; i < CHECKSUM; i++)
        checksum+= tramaAnalizar[i].toDouble();

    if(checksum == tramaAnalizar[CHECKSUM].toDouble() && m_db.open())
    {
        qDebug() << "Database: connection ok";
        QSqlDatabase::database().transaction();
        qDebug()<<"Trama sin fallas";
        fecha = QDateTime::currentDateTime();
        datos.setFecha(fecha.toString("dd/MM/yy").toStdString());
        datos.setTemp((float)tramaAnalizar[1].toDouble());
        datos.setGas((float)tramaAnalizar[2].toDouble());
        datos.setOxi((float)tramaAnalizar[3].toDouble());
        datos.setPulso(tramaAnalizar[4].toInt());
        datos.setNombre("ANTO");
        datos.nuevoData(m_db);
        QSqlDatabase::database().commit();
        m_db.close();
        //mando data con datos
    }
    else
    {
        qDebug()<<"Trama con fallas" << checksum << endl; //OJO QUE EL CHECKSUM SUMA TODO, TENGO QUE RESTAR EL CHECKSUM Y LOS BARRAS

    }

}


// DATABASE

void MainWindow::on_pushButton_nu_clicked()
{
    if (!m_db.open()) //checqueamos si se conecto o no
       qDebug() << "Error: connection with database failed";
    else
    {
        qDebug() << "Database: connection ok";
        QSqlDatabase::database().transaction();
        cargarDatos(); //la idea es que aca los datos se agreguen con las lecturas
        datos.nuevoData(m_db);
        cout << "testeo: "<<datos.getTemp()<<endl;
        QSqlDatabase::database().commit();
        m_db.close();
        qDebug() << "Database: desconectada";
    }
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
    qDebug() << "Database: desconectada";
}


void MainWindow::on_pushButton_act_clicked()
{
    if (!m_db.open())
        qDebug() << "Error: connection with database failed";
    else
    {
        QSqlDatabase::database().transaction();
        cargarDatos(); //nueva info
        datos.actData(m_db);
        QSqlDatabase::database().commit();
        m_db.close();
        qDebug() << "Database: desconectada";
    }
}


void MainWindow::cargarDatos(void) //funcion para tomar las lecturas del micro y añadirlas al objeto
{
    datos.setFecha("17/09/23");
    datos.setNombre("Adam Bareiro");
    datos.setOxi(99.8);
    datos.setPulso(96);
    datos.setTemp(37.76);
    datos.setGas(0.01);
}
