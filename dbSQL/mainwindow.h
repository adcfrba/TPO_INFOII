#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QDebug>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QSqlTableModel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_nu_clicked();

    void on_pushButton_el_clicked();

    void on_pushButton_act_clicked();

    void on_pushButton_MOSTRAR_clicked();

private:
    Ui::MainWindow *ui;
    QSqlTableModel *mModel;
    QSqlDatabase m_db;
};
#endif // MAINWINDOW_H
