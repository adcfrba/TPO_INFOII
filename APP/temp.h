#ifndef TEMP_H
#define TEMP_H
/*
#include <QDialog>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include <QBarSeries>
#include <QBarSet>
#include <QLegend>
*/
#include <lectura.h>
#include <vector>

namespace Ui {
class temp;
}

class temp : public QDialog
{
    Q_OBJECT

public:
    explicit temp(QWidget *parent = nullptr);
    ~temp();

    vector<lectura> getVectorTemp(void);
    void setVectorTemp(const vector<lectura> newVectorTemp);
    void cargarData(void);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::temp *ui;
    vector<lectura>vectorTemp;
};

#endif // TEMP_H
