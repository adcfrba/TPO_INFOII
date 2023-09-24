#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMainWindow"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupMain();
    conexionSerial();
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


}

MainWindow::~MainWindow()
{
    delete ui;
    serial->close(); //tenemos que cerrarlo
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
    objOx.setVectorOx(datosVector);
    objOx.cargarData();
    int rtn = objOx.exec();
}


void MainWindow::on_pushButton_gas_clicked()
{
    //qDebug()<<"main"<<datos.getGas();
    objGas.setDataGas(datos.getGas());
    objGas.cargarData();
    //qDebug()<<"main otra vez"<<objGas.getDataGas();
    int rtn = objGas.exec();
}


void MainWindow::on_pushButton_temp_clicked()
{
    objTemp.setVectorTemp(datosVector);
    objTemp.cargarData();
    int rtn = objTemp.exec();
}

void MainWindow::cargarDatos(void) //funcion para tomar las lecturas del micro y añadirlas al objeto
{
    datos.setFecha("17/09/23");
    datos.setNombre("Adam Bareiro");
    datos.setOxi(99.8);
    datos.setPulso(96);
    datos.setTemp(37.76);
    datos.setGas(0.2);
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

void MainWindow::conexionSerial(void)
{
    serial = new QSerialPort();
    //CONFIGURACIÓN DE LA CONEXIÓN SERIAL
    serial->setPortName("COM3"); //tenemos que verlo en el micro, lo configuramos despues
    serial->setBaudRate(QSerialPort::Baud9600); //nuevamente, se puede configurar
    serial->setParity(QSerialPort::NoParity);
    serial->setDataBits(QSerialPort::Data8);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->setStopBits(QSerialPort::OneStop);

    serial->open(QIODevice::ReadOnly); //SOLO LECTURA
    connect(serial, SIGNAL(readyRead()),this, SLOT(recibirSerial()));//esperamos la señal que nos genera el obj cuando un dispositivo se conecta y lo mandamos al obj del main
}

void MainWindow::recibirSerial(void)
{
    QByteArray buff;
    buff = serial->readLine(); //lo que se reciba, se guarda temporalmente
    dataSerial += buff;


    //procesamiento de la info
    //agrego a datos
    datos.nuevoData(m_db);//se agrega a la base de datos
}
