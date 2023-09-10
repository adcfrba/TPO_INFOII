#include "gas.h"
#include "ui_gas.h"

gas::gas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gas)
{
    ui->setupUi(this);
}

void gas::cargarData(void)
{
    mono = new QBarSet("Monoxido de Carbono");
    mono->append(dataGas) ;//data
    qDebug() <<"Data" << dataGas;
    QHorizontalBarSeries *series = new QHorizontalBarSeries();
    series->append(mono);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Niveles de C02 en el ambiente");
    chart->setAnimationOptions(QChart::AllAnimations);

    QStringList gases;
    gases << "Monoxido de carbono";
    QBarCategoryAxis *axisY = new QBarCategoryAxis();
    axisY->append(gases);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
    QValueAxis *axisX = new QValueAxis();
    axisX->setMax((qreal)dataGas + (0.5*dataGas));
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);
    axisX->applyNiceNumbers();

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(ui->horizontalFrame);
    chartView->setFixedSize(ui->horizontalFrame->size());
    QPalette colores = qApp->palette();
    colores.setColor(QPalette::Window, QRgb(0x0a369d));
    colores.setColor(QPalette::WindowText, QRgb(0x4472ca));
    qApp->setPalette(colores);
}

gas::~gas()
{
    delete ui;
}

float gas::getDataGas() const
{
    return dataGas;
}

void gas::setDataGas(const float newDataGas)
{
    dataGas = newDataGas;
}


