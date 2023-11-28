#include "temp.h"
#include "ui_temp.h"


temp::temp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::temp)
{
    ui->setupUi(this);
}

temp::~temp()
{
    delete ui;
}

void temp::on_buttonBox_accepted()
{

}

vector<lectura> temp::getVectorTemp(void)
{
    return vectorTemp;
}

void temp::setVectorTemp(const vector<lectura> newVectorTemp)
{
    vectorTemp = newVectorTemp;
}

void temp::cargarData(void)
{
    this->layout()->setSizeConstraint(QLayout::SetFixedSize);
    qDebug() <<"temp" << vectorTemp[0].getTemp();

    QBarSet *bien = new QBarSet ("Ultimas temperaturas");
    *bien << vectorTemp[4].getTemp() << vectorTemp[3].getTemp() << vectorTemp[2].getTemp() << vectorTemp[1].getTemp() << vectorTemp[0].getTemp();
    bien->setColor((QRgb(0x00A4BD)));

    QStackedBarSeries * seriesTemp = new QStackedBarSeries();
    seriesTemp->append(bien);

    QChart *chart = new QChart();

    chart->addSeries(seriesTemp);
    chart->setAnimationOptions(QChart::AllAnimations);
    QStringList dias ={ QString::fromStdString(vectorTemp[4].getFecha()) , QString::fromStdString(vectorTemp[3].getFecha()) , QString::fromStdString(vectorTemp[2].getFecha()) , QString::fromStdString(vectorTemp[1].getFecha()) , QString::fromStdString(vectorTemp[0].getFecha())};

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(dias);
    axisX->setTitleText("Días");
    chart->addAxis(axisX, Qt::AlignBottom);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(33,45);
    axisY->setTitleText("[&deg;C]");
    axisY->applyNiceNumbers();
    chart->addAxis(axisY, Qt::AlignLeft);
    seriesTemp->attachAxis(axisX);
    seriesTemp->attachAxis(axisY);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView * chartView = new QChartView(chart);
    chartView->setParent(ui->horizontalFrame);
    chartView->setFixedSize(ui->horizontalFrame->size());
    chartView->setRenderHint(QPainter::Antialiasing);
    QPalette colores = qApp->palette();
    colores.setColor(QPalette::Window, QRgb(0x0a369d));
    colores.setColor(QPalette::WindowText, QRgb(0x4472ca));
    qApp->setPalette(colores);
}




