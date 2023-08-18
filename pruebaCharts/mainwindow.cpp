#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //consttructor
    QLineSeries *series = new QLineSeries();

    //datos
    series->append(0,6);
    series->append(2,4);
    series->append(5,8);
    series->append(7,3);
    series->append(10,6);
    series->append(12,2);

    //puntos
    *series << QPointF(11,1) << QPointF(13,3) << QPointF(17,6) << QPointF(18,3) << QPointF(20,2);


    //QChart
    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series); //tengo que añadir el chart que elegimos
    chart->setTitle("HOLAAA");
    chart->createDefaultAxes();

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(ui->horizontalLayoutWidget);

}

MainWindow::~MainWindow()
{
    delete ui;
}

