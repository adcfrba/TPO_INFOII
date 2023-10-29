#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include<QBluetoothDeviceDiscoveryAgent>
#include<QBluetoothSocket>
#include<QListWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_find_clicked();

    void on_pushButton_Parameter1_clicked();

    void on_pushButton_Parameter2_clicked();

    void deviceDiscovered( const QBluetoothDeviceInfo &device );

    void on_listWidget_consola_itemClicked(QListWidgetItem *item);

    void receive();

private:
    Ui::MainWindow *ui;
    //QBluetoothDeviceDiscoveryAgent *discoverAgent = new QBluetoothDeviceDiscoveryAgent(this);
    QBluetoothDeviceDiscoveryAgent *discoverAgent;
    QBluetoothSocket *socket;
    QString string, DatosRecibidos, trama;
    qint64 CantBytesRecibidos;
    bool k = false;
    bool fAnalizarTrama = false;
};

#endif // MAINWINDOW_H


/*
PARA VER LO DEL COMPILADOR
https://doc.qt.io/qtcreator/creator-tool-chains.html
*/
