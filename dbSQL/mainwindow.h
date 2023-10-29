#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define CHECKSUM 5

#include <QMainWindow>
#include <QSqlDatabase>
#include <QDebug>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include "lectura.h"
#include <QSqlTableModel>
#include <QtBluetooth>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QBluetoothSocket>
#include <QListWidget>
#include <QBluetoothLocalDevice>
#include <QBluetoothAddress>
#include <QTimer>
#include <QDateTime>
#include <QByteArray>




QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QSqlTableModel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void cargarDatos(void);
    void mostrarDatos(void);


private slots:
    void on_pushButton_nu_clicked();

    void on_pushButton_el_clicked();

    void on_pushButton_act_clicked();

    void on_pushButton_find_clicked();

    void on_pushButton_on_clicked();

    void on_pushButton_off_clicked();

    void deviceDiscovered(const QBluetoothDeviceInfo &info);

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void receive();
    void analizarTrama(QStringList, lectura);


private:
    Ui::MainWindow *ui;
    QSqlTableModel * mModel;
    QSqlDatabase m_db;
    lectura datos;
    QBluetoothDeviceDiscoveryAgent *agent = new QBluetoothDeviceDiscoveryAgent;
    QBluetoothDeviceInfo remoteDeviceInfo;
    QBluetoothSocket *socket;
    QString dataSerial="";
    QTimer connectTimer;
    QString string, DatosRecibidos, trama;
    QStringList tramaExtraida;
    int8_t cxor;
    int8_t estadoRX;
    qint64 CantBytesRecibidos;
    bool k = false;
    bool finalizarTrama = false;
    QDateTime fecha;
};
#endif // MAINWINDOW_H
