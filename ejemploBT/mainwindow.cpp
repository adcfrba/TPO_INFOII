#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    discoverAgent  = new QBluetoothDeviceDiscoveryAgent(this);
    connect(discoverAgent, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)), this, SLOT(deviceDiscovered(QBluetoothDeviceInfo)));
    discoverAgent->start();
    socket = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_find_clicked()
{
    ui->listWidget_consola->clear();
    discoverAgent->stop();
    discoverAgent->start();
}

void MainWindow::on_pushButton_Parameter1_clicked()
{
    socket->write("Info2\n");
}

void MainWindow::on_pushButton_Parameter2_clicked()
{
    socket->write("R2052\n");
}

void MainWindow::deviceDiscovered( const QBluetoothDeviceInfo &device )
{
    ui->listWidget_consola->addItem(device.address().toString());
    ui->listWidget_consola->addItem(device.name());
}


void MainWindow::on_listWidget_consola_itemClicked(QListWidgetItem *item)
{
    string = item->text();
    static const QString serviceUuid(QStringLiteral("00001101-0000-1000-8000-00805F9B34FB"));
    socket->connectToService(QBluetoothAddress(string), QBluetoothUuid(serviceUuid), QIODevice::ReadWrite);
    string = "Seleccionado: " + string;
    ui->listWidget_consola->addItem(string);
    connect(socket, SIGNAL(readyRead()), this, SLOT(receive()));
}

void MainWindow::receive()
{
    CantBytesRecibidos = socket->bytesAvailable();
    DatosRecibidos = socket->readAll();
    trama += DatosRecibidos;

    if( trama.count() > 2 )
    {
        fAnalizarTrama = true;
        ui->listWidget_consola->addItem(trama);
    }
}

