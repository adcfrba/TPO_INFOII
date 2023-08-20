#ifndef OX_H
#define OX_H

#include <QDialog>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>

namespace Ui {
class ox;
}

class ox : public QDialog
{
    Q_OBJECT

public:
    explicit ox(QWidget *parent = nullptr);
    ~ox();

private:
    Ui::ox *ui;
};

#endif // OX_H
