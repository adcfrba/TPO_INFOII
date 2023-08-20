
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include <QBarSeries>
#include <QBarSet>
#include <QLegend>
#include <QBarCategoryAxis>
#include <QHorizontalStackedBarSeries>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_historial_clicked();

    void on_label_ox_img_linkHovered(const QString &link);

    void on_pushButton_ox_clicked();

    void on_pushButton_gas_clicked();

    void on_pushButton_temp_clicked();

private:
    Ui::MainWindow *ui;
    void tablaRefresh(void);
};

#endif // MAINWINDOW_H
