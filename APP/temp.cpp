#include "temp.h"
#include "ui_temp.h"


temp::temp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::temp)
{
    ui->setupUi(this);

    this->layout()->setSizeConstraint(QLayout::SetFixedSize);

    QBarSet *bien = new QBarSet ("Aceptable");
    *bien <<36.6 <<37.2 <<37 << 37 << 36.5 << 36 << 36.8;
    bien->setColor((QRgb(0x00A4BD)));
    QBarSet *abajo = new QBarSet("Muy Bajo");
    *abajo << 28 << 29.8 << 30.5 << 34.5 << 32 << 34 << 35 << 34.8 << 34;
    abajo->setColor((QRgb(0x0a369d)));
    QBarSet *alto = new QBarSet("Muy alto");
    *alto << 38.2 << 38.5 << 37.9 << 38.7 << 38.1 << 37.8 << 37.6 << 39.3;
    alto->setColor((QRgb(0xD70707)));



    QStackedBarSeries * seriesTemp = new QStackedBarSeries();
    seriesTemp->append(abajo);
    seriesTemp->append(bien);
    seriesTemp->append(alto);

    QChart *chart = new QChart();

    chart->addSeries(seriesTemp);
    chart->setTitle("Ultimas temperaturas");
    //chart->setTitleFont(QFont::Fantasy);
    chart->setAnimationOptions(QChart::AllAnimations);
    QStringList dias ={ "Lunes" , "Martes" , "Miercoles" , "Jueves" , "Viernes" , "Sabado" , "Domingo"};

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(dias);
    axisX->setTitleText("Días");
    chart->addAxis(axisX, Qt::AlignBottom);
    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(27,50);
    axisY->setTitleText("[&deg;C]");
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

temp::~temp()
{
    delete ui;
}

void temp::on_buttonBox_accepted()
{
    //chart->setAnimationOptions(QChart );
}




