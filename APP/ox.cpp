#include "ox.h"
#include "ui_ox.h"

ox::ox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ox)
{
    ui->setupUi(this);
    this->layout()->setSizeConstraint(QLayout::SetFixedSize);

    QLineSeries *series = new QLineSeries();
    *series << QPointF(0, 6) << QPointF(9, 4) << QPointF(15, 20) << QPointF(25, 12) << QPointF(29, 26);
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

    axisX->append("15 dias", 10);
    axisX->append("10 dias", 20);
    axisX->append("5 dias", 30);
    axisX->setRange(0, 30);

    axisY->append("Bajo", 10);
    axisY->append("Aceptable", 20);
    axisY->append("Alto", 30);
    axisY->setRange(0, 30);

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

ox::~ox()
{
    delete ui;
}
