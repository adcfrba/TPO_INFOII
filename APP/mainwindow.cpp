#include "historial.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMainWindow"
#include "QMessageBox"
#include <QApplication>
#include <QtWidgets>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pix_slider ("C:/Users/notebook/Documents/INFO II 2023/TPO/TPO_INFOII/APP/images/caliente.png");
    ui->label_slider->setPixmap(pix_slider);

    QLineSeries *oxi = new QLineSeries();
    oxi->append(0,6);
    oxi->append(2,4);
    oxi->append(3,8);
    oxi->append(7,4);
    oxi->append(10,5);

    *oxi << QPointF(11,1) << QPointF(13,3) << QPointF(17,6) << QPointF(18,3) << QPointF(20,2);

    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(oxi);
    chart->setTitle("Grafico");

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    //chartView->setParent(ui->lineEdit);
    //chartView->setFixedSize(ui->vert);
    /*
     *
    QLineSeries *series = new QLineSeries();
    series->append(0,6);
    series->append(2,4);
    series->append(3,8);
    series->append(7,4);
    series->append(10,5);

    *series << QPointF(11,1) << QPointF(13,3) << QPointF(17,6) << QPointF(18,3) << QPointF(20,2);

    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->setTitle("Grafico");

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(ui->horizontalFrame);


*/
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

