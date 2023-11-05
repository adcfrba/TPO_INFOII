#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMainWindow"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupMain();
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
        QSqlDatabase::database().transaction();
        datos.leerData(m_db); //obtenemos los datos y lo guardamos en el objeto
        mostrarDatos();
        datosVector=leerVector(m_db); //ox

        QSqlDatabase::database().commit();
        m_db.close();
    }

    //BLUETOOTH
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

void MainWindow::deviceDiscovered(const QBluetoothDeviceInfo &info)
{
    //Imprime información sobre el dispositivo descubierto
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
    ui->lcdNumber_pulso->display(datos.getPulso());
    ui->lcdNumber_temperatura->display(datos.getTemp());
}

vector<lectura> MainWindow::leerVector(QSqlDatabase bd)
{
    vector <lectura> vector;
    lectura aux;
    QSqlQuery qyDataVector(bd);
    qyDataVector.exec("SELECT * FROM lecturas ORDER BY ID DESC");

    for(int i = 0; i < 5; i++)
    {
        qyDataVector.next();
        aux.setNombre(qyDataVector.value(1).toString().toStdString());
        aux.setTemp(qyDataVector.value(2).toFloat());
        aux.setOxi(qyDataVector.value(3).toFloat());
        aux.setFecha(qyDataVector.value(6).toString().toStdString());
        aux.setPulso(qyDataVector.value(4).toInt());
        aux.setGas(qyDataVector.value(5).toFloat());
        //qDebug()<<"A VER"<<aux.getNombre()<<aux.getTemp()<<aux.getOxi()<<aux.getFecha()<<aux.getPulso()<<aux.getGas();
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
    ui->label_pulso->setFont(fontSecundario);
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
    QPixmap boton_pulso ("C:/Users/notebook/Documents/INFO II 2023/TPO/TPO_INFOII/APP/images/corazon.png");
    QIcon icon_pulso (boton_pulso);
    ui->pushButton_pulso->setIcon(icon_pulso);
    ui->pushButton_pulso->setIconSize(boton_pulso.rect().size());
    QPixmap boton_historial("C:/Users/notebook/Documents/INFO II 2023/TPO/TPO_INFOII/APP/images/historial-medico.png");
    QIcon icon_historial (boton_historial);
    ui->pushButton_historial->setIcon(icon_historial);
    ui->pushButton_historial->setFont(fontSecundario);
}

void MainWindow::conectarBT(const QBluetoothDeviceInfo &info)
{
    string = info.address().toString(); //nos guarda la dirección del device en nuestro string
    static const QString serviceUuid (QStringLiteral("00001101-0000-1000-8000-00805F9B34FB"));
    socket->connectToService(QBluetoothAddress(string), QBluetoothUuid(serviceUuid),QIODevice::ReadWrite);
    if(socket->state()==1) //ServiceLookupState
    {
        socket->write("OK");
        qDebug() << "Conexión: "<< string;
        connect(socket, SIGNAL(readyRead()), this, SLOT(receive()));
        //QMessageBox::information(this, tr("BEYMAX"), tr("Conexión con BT exitosa"));
    }
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
            //ui->listWidget->addItem(trama);
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
        datos.setFecha(fecha.toString("dd/MM/yy h:m:s ap").toStdString());
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
        qDebug()<<"Trama con fallas" << checksum; //OJO QUE EL CHECKSUM SUMA TODO, TENGO QUE RESTAR EL CHECKSUM Y LOS BARRAS

    }

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

