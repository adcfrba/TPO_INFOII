#include "ox.h"
#include "ui_ox.h"

ox::ox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ox)
{
    ui->setupUi(this);

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
}

ox::~ox()
{
    delete ui;
}
