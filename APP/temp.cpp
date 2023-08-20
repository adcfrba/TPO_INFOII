#include "temp.h"
#include "ui_temp.h"

temp::temp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::temp)
{
    ui->setupUi(this);

    QBarSet *set0 = new QBarSet("Temperatura");
    *set0 << 28 << 34 << 31 << 33 << 34 << 33;

    QBarSeries * series = new QBarSeries();
    series->append(set0);
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Temperatura");
    chart->setAnimationOptions(QChart::AllAnimations);
    QStringList valores;
    valores << "25" << "26" << "27" << "28" << "29" << "30" << "31" << "32" << "33" << "34" << "35" << "36" << "37" << "38" << "39" << "40";
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(valores);
    chart->createDefaultAxes();
    chart->setAxisX(axis, series);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView * chartView = new QChartView(chart);
    chartView->setParent(ui->horizontalLayout);
    chartView->setRenderHint(QPainter::Antialiasing);
    QPalette colores = qApp->palette();
    colores.setColor(QPalette::Window, QRgb(0x0a369d));
    colores.setColor(QPalette::WindowText, QRgb(0x4472ca));
    qApp->setPalette(colores);


}

temp::~temp()
{
    delete ui;
}
