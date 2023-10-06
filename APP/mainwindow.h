
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "includes.h"
#include "ox.h"
#include "temp.h"
#include "historial.h"
#include "gas.h"
#include "lectura.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setupMain(void);
    void mostrarDatos(void);
    vector<lectura>leerVector(QSqlDatabase);

private slots:
    void on_pushButton_historial_clicked();

    void on_pushButton_ox_clicked();

    void on_pushButton_gas_clicked();

    void on_pushButton_temp_clicked();

    void deviceDiscovered(const QBluetoothDeviceInfo &info);

    void conectarBT(QListWidgetItem *item);

    void receive();
    void analizarTrama(QStringList, lectura);



private:
    Ui::MainWindow *ui;
    void tablaRefresh(void);
    QSqlDatabase m_db;
    lectura datos;
    gas objGas;
    ox objOx;
    vector<lectura>datosVector;
    temp objTemp;

    QTimer connectTimer;
    QString string, DatosRecibidos, trama;
    QStringList tramaExtraida;
    qint64 CantBytesRecibidos;
    bool k = false;
    bool finalizarTrama = false;
    QDateTime fecha;
    QBluetoothDeviceDiscoveryAgent *agent = new QBluetoothDeviceDiscoveryAgent;
    QBluetoothDeviceInfo remoteDeviceInfo;
    QBluetoothSocket *socket;
};

#endif // MAINWINDOW_H
