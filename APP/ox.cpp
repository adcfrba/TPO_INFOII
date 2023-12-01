#include "ox.h"
#include "ui_ox.h"

ox::ox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ox)
{
    ui->setupUi(this);
}

ox::~ox()
{
    delete ui;
}

vector<lectura> ox::getVectorOx(void)
{
    return vectorOx;
}

void ox::setVectorOx(vector<lectura> newVectorOx)
{
    vectorOx = newVectorOx;
}

void ox::cargarData(void)
{
    this->layout()->setSizeConstraint(QLayout::SetFixedSize);
    qDebug() <<"oxigeno" << vectorOx[0].getOxi();
    QLineSeries *series = new QLineSeries();
    series->append(0,vectorOx[2].getOxi());
    series->append(5,vectorOx[1].getOxi());
    series->append(10,vectorOx[0].getOxi());
    QPen pen(QRgb(0x00A4BD));

    pen.setWidth(5);
    series->setPen(pen);

    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->setTitle("Oxigenación en sangre");
    chart->setAnimationOptions(QChart::AllAnimations);
    QFont font;
    font.setPixelSize(18);
    chart->setTitleFont(font);
    chart->setTitleBrush(QBrush(Qt::blue));

    QCategoryAxis *axisX = new QCategoryAxis();
    QCategoryAxis *axisY = new QCategoryAxis();

    axisX->setRange(-1, 11);
    axisX->append(QString::fromStdString(vectorOx[2].getFecha()), 0);
    axisX->append(QString::fromStdString(vectorOx[1].getFecha()), 9.5);
    axisX->append(QString::fromStdString(vectorOx[0].getFecha()), 10);
    axisX->AxisLabelsPositionOnValue;
    axisX->setGridLineVisible(true);

    axisY->append("Bajo", 80);
    axisY->append("Aceptable", 100);
    axisY->setRange(50, 120);
    axisY->setGridLineVisible(true);
    axisY->setGridLineColor(QRgb(0x0a369d));

    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);
    chart->setTitle("Oxigenacion en sangre");
    series->attachAxis(axisX);
    series->attachAxis(axisY);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(ui->horizontalFrame);
    chartView->setFixedSize(ui->horizontalFrame->size());
    QPalette colores = qApp->palette();
    colores.setColor(QPalette::Window, QRgb(0x0a369d));
    colores.setColor(QPalette::WindowText, QRgb(0x4472ca));
    qApp->setPalette(colores);
}




