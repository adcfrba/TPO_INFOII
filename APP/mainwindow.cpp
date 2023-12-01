#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMainWindow"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupMain();
    qDebug() <<"Drivers:" << QSqlDatabase::drivers(); //DRIVERS DISPONIBLES
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("C:/sqlite/gui/databases/mydb.sqlite"); //BASE DE DATOS, VIVE EN LA PC

    if (!m_db.open()) //CHECK OPEN
    {
        qDebug() << "Error: connection with database failed";
    }
    else
    {
        qDebug() << "Database: connection ok";
        QSqlDatabase::database().transaction();
        datos.leerData(m_db); //OBTENER DATA Y GUARDAR EN EL OBJETO
        mostrarDatos();
        datosVector=leerVector(m_db);

        QSqlDatabase::database().commit();
        m_db.close();
    }

    //BLUETOOTH
    connect(agent, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),this, SLOT(deviceDiscovered(QBluetoothDeviceInfo)));
    agent->start(); //BUSQUEDA DE DISPOSITIVOS
    socket = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol);
}

MainWindow::~MainWindow()
{
    delete ui;
    socket->disconnectFromService();
    socket->close();
}

void MainWindow::deviceDiscovered(const QBluetoothDeviceInfo &info)
{
    qDebug() << "Nombre del dispositivo:" << info.name();
    qDebug() << "Dirección MAC del dispositivo:" << info.address().toString();
    if (info.name() == "baymaxINFO2023")
        conectarBT(info);
}

void MainWindow::on_pushButton_historial_clicked()
{
    Historial objHistorial;
    int rtn = objHistorial.exec();//se abre
}


void MainWindow::on_pushButton_ox_clicked()
{
    if (!m_db.open())
    {
        qDebug() << "Error: connection with database failed";
    }
    else
    {
        QSqlDatabase::database().transaction();
        datos.leerData(m_db);
        mostrarDatos();
        datosVector=leerVector(m_db);
        objOx.setVectorOx(datosVector);
        objOx.cargarData();
        QSqlDatabase::database().commit();
        m_db.close();
        int rtn = objOx.exec();
    }

}


void MainWindow::on_pushButton_gas_clicked()
{
    if (!m_db.open())
    {
        qDebug() << "Error: connection with database failed";
    }
    else
    {
        QSqlDatabase::database().transaction();
        datos.leerData(m_db);
        mostrarDatos();
        objGas.setDataGas(datos.getGas());
        objGas.cargarData();
        QSqlDatabase::database().commit();
        m_db.close();
        int rtn = objGas.exec();
    }

}


void MainWindow::on_pushButton_temp_clicked()
{
    if (!m_db.open())
    {
        qDebug() << "Error: connection with database failed";
    }
    else
    {
        QSqlDatabase::database().transaction();
        datos.leerData(m_db);
        mostrarDatos();
        datosVector=leerVector(m_db);
        objTemp.setVectorTemp(datosVector);
        objTemp.cargarData();
        QSqlDatabase::database().commit();
        m_db.close();
        int rtn = objTemp.exec();
    }

}


void MainWindow::mostrarDatos(void)
{
    ui->lcdNumber_gas->display(datos.getGas());
    ui->lcdNumber_ox->display(datos.getOxi());
    ui->lcdNumber_temperatura->display(datos.getTemp());
}

vector<lectura> MainWindow::leerVector(QSqlDatabase bd)
{
    vector <lectura> vector;
    lectura aux;
    QSqlQuery qyDataVector(bd);
    qyDataVector.exec("SELECT * FROM lecturas ORDER BY ID DESC"); //TOMA ULTIMA ENTRADA DE LA BASE DE DATOS

    for(int i = 0; i < 5; i++)
    {
        qyDataVector.next();
        aux.setNombre(qyDataVector.value(1).toString().toStdString());
        aux.setTemp(qyDataVector.value(2).toFloat());
        aux.setOxi(qyDataVector.value(3).toFloat());
        aux.setFecha(qyDataVector.value(6).toString().toStdString());
        aux.setPulso(qyDataVector.value(4).toInt());
        aux.setGas(qyDataVector.value(5).toFloat());
        vector.push_back(aux);
    }
    return(vector);
}


void MainWindow::setupMain(void)
{
    QFontDatabase::addApplicationFont(":/new/fonts/Baymax.otf");
    QFontDatabase::addApplicationFont(":/new/fonts/Skull.otf");
    QFont fontTitulo = QFont("Baymax",55,1);
    QFont fontSecundario = QFont("Skull", 15,-1);

    ui->label_nombre->setFont(fontTitulo);
    ui->label_gas->setFont(fontSecundario);
    ui->label_temperatura->setFont(fontSecundario);
    ui->label__oxigenacion->setFont(fontSecundario);

    QPixmap boton_recarga ("C:/Users/notebook/Documents/INFO II 2023/TPO/TPO_INFOII/APP/images/cargando-flechas");
    QIcon icon_recarga (boton_recarga);
    ui->pushButton_recargar->setIcon(icon_recarga);
    ui->pushButton_recargar->setIconSize(boton_recarga.rect().size());
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

    ui->label_conexion->setText("¡Bienvenido!");
}

void MainWindow::conectarBT(const QBluetoothDeviceInfo &info)
{
    string = info.address().toString(); //DIRECCIÓN DEL DEVICE
    static const QString serviceUuid (QStringLiteral("00001101-0000-1000-8000-00805F9B34FB"));
    socket->connectToService(QBluetoothAddress(string), QBluetoothUuid(serviceUuid),QIODevice::ReadWrite);
    if(socket->state()==1) //ServiceLookupState
    {
        socket->write("OK");
        qDebug() << "Conexión: "<< string;
        connect(socket, SIGNAL(readyRead()), this, SLOT(receive()));
    }
}


void MainWindow::receive()
{
    CantBytesRecibidos = socket->bytesAvailable();
    DatosRecibidos = socket->readAll();
    trama += DatosRecibidos;
    qDebug() << trama;


    if(trama.back() =='>')
    {
        tramaExtraida = trama.split('-',Qt::SkipEmptyParts);
        if(tramaExtraida.size() == 7)
            analizarTrama(tramaExtraida, datos, SENSORES);

        else if (tramaExtraida.size() == 3 && tramaExtraida[1] == "¡ALERTA!")
             analizarTrama(tramaExtraida, datos, ALERTA);

        else if (tramaExtraida.size() == 3 && tramaExtraida[1] == "DESCONECTADO")
            analizarTrama(tramaExtraida, datos, DESCONECTADO);
    }
    trama.clear();
}

void MainWindow::analizarTrama(QStringList tramaAnalizar, lectura datos, int entrada)
{
    int rtn = 0;
    double checksum =0;
    int aux = 0;

    if (entrada == 0)
    {
        for(int i = 1; i < CHECKSUM; i++)
            checksum+= tramaAnalizar[i].toDouble();
        aux = CHECKSUM;
    }
    else
    {
        checksum = tramaAnalizar[1].toDouble();
        aux = 1;
    }

    if(checksum == tramaAnalizar[aux].toDouble())
    {
        qDebug()<<aux;
        switch(entrada)
        {
        case SENSORES:
            ui->label_conexion->setText("Sensando...no moverse...");
            QSqlDatabase::database().transaction();
            qDebug()<<"Trama sin fallas";
            fecha = QDateTime::currentDateTime();
            datos.setFecha(fecha.toString("dd/MM/yy h:m:s ap").toStdString());
            datos.setTemp((float)tramaAnalizar[1].toDouble());
            datos.setGas((float)tramaAnalizar[2].toDouble());
            datos.setOxi((float)tramaAnalizar[3].toDouble());
            datos.setPulso(0); //HASTA CONSEGUIR EL SENSOR
            //datos.setPulso(tramaAnalizar[4].toInt());
            datos.setNombre("BaymaxInfoII");
            datos.nuevoData(m_db);
            QSqlDatabase::database().commit();
            m_db.close();
            mostrarDatos();
            break;
        case ALERTA:
            rtn = objAlarma.exec();
            ui->label_conexion->setText("EMERGENCIA");
            break;
        case DESCONECTADO:
            ui->label_conexion->setText("Persona desconectada");
            break;
        }
    }
    else
        qDebug()<<"Trama con fallas" << checksum;
}



void MainWindow::on_pushButton_recargar_clicked()
{
    if (!m_db.open())
    {
        qDebug() << "Error: connection with database failed";
    }
    else
    {
        QSqlDatabase::database().transaction();
        datos.leerData(m_db);
        mostrarDatos();
        QSqlDatabase::database().commit();
        m_db.close();
    }

}

