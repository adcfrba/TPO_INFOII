#ifndef TEMP_H
#define TEMP_H

#include <QDialog>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include <QBarSeries>
#include <QBarSet>
#include <QLegend>

namespace Ui {
class temp;
}

class temp : public QDialog
{
    Q_OBJECT

public:
    explicit temp(QWidget *parent = nullptr);
    ~temp();

private:
    Ui::temp *ui;
};

#endif // TEMP_H
