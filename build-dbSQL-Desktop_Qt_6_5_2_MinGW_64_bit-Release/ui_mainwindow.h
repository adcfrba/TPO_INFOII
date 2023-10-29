/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_NOMBRE;
    QLineEdit *lineEdit_TEMP;
    QLineEdit *lineEdit_OXI;
    QLineEdit *lineEdit_PULSO;
    QLineEdit *lineEdit_FECHA;
    QLineEdit *lineEdit_GAS;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_nu;
    QPushButton *pushButton_el;
    QPushButton *pushButton_act;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_find;
    QPushButton *pushButton_on;
    QPushButton *pushButton_off;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(719, 310);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");

        verticalLayout->addWidget(tableView);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lineEdit_NOMBRE = new QLineEdit(centralwidget);
        lineEdit_NOMBRE->setObjectName("lineEdit_NOMBRE");

        horizontalLayout_2->addWidget(lineEdit_NOMBRE);

        lineEdit_TEMP = new QLineEdit(centralwidget);
        lineEdit_TEMP->setObjectName("lineEdit_TEMP");

        horizontalLayout_2->addWidget(lineEdit_TEMP);

        lineEdit_OXI = new QLineEdit(centralwidget);
        lineEdit_OXI->setObjectName("lineEdit_OXI");

        horizontalLayout_2->addWidget(lineEdit_OXI);

        lineEdit_PULSO = new QLineEdit(centralwidget);
        lineEdit_PULSO->setObjectName("lineEdit_PULSO");

        horizontalLayout_2->addWidget(lineEdit_PULSO);

        lineEdit_FECHA = new QLineEdit(centralwidget);
        lineEdit_FECHA->setObjectName("lineEdit_FECHA");

        horizontalLayout_2->addWidget(lineEdit_FECHA);

        lineEdit_GAS = new QLineEdit(centralwidget);
        lineEdit_GAS->setObjectName("lineEdit_GAS");

        horizontalLayout_2->addWidget(lineEdit_GAS);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton_nu = new QPushButton(centralwidget);
        pushButton_nu->setObjectName("pushButton_nu");

        horizontalLayout->addWidget(pushButton_nu);

        pushButton_el = new QPushButton(centralwidget);
        pushButton_el->setObjectName("pushButton_el");

        horizontalLayout->addWidget(pushButton_el);

        pushButton_act = new QPushButton(centralwidget);
        pushButton_act->setObjectName("pushButton_act");

        horizontalLayout->addWidget(pushButton_act);


        verticalLayout->addLayout(horizontalLayout);

        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");

        verticalLayout->addWidget(listWidget);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        pushButton_find = new QPushButton(centralwidget);
        pushButton_find->setObjectName("pushButton_find");

        horizontalLayout_4->addWidget(pushButton_find);

        pushButton_on = new QPushButton(centralwidget);
        pushButton_on->setObjectName("pushButton_on");

        horizontalLayout_4->addWidget(pushButton_on);

        pushButton_off = new QPushButton(centralwidget);
        pushButton_off->setObjectName("pushButton_off");

        horizontalLayout_4->addWidget(pushButton_off);


        verticalLayout->addLayout(horizontalLayout_4);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 719, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lineEdit_NOMBRE->setInputMask(QString());
        lineEdit_NOMBRE->setText(QString());
        lineEdit_NOMBRE->setPlaceholderText(QCoreApplication::translate("MainWindow", "Nombre", nullptr));
        lineEdit_TEMP->setText(QString());
        lineEdit_TEMP->setPlaceholderText(QCoreApplication::translate("MainWindow", "Temperatura", nullptr));
        lineEdit_OXI->setPlaceholderText(QCoreApplication::translate("MainWindow", "Oxigenacion", nullptr));
        lineEdit_PULSO->setPlaceholderText(QCoreApplication::translate("MainWindow", "Pulso", nullptr));
        lineEdit_FECHA->setPlaceholderText(QCoreApplication::translate("MainWindow", "Fecha", nullptr));
        lineEdit_GAS->setPlaceholderText(QCoreApplication::translate("MainWindow", "Gas", nullptr));
        pushButton_nu->setText(QCoreApplication::translate("MainWindow", "AGREGAR", nullptr));
        pushButton_el->setText(QCoreApplication::translate("MainWindow", "ELIMINAR", nullptr));
        pushButton_act->setText(QCoreApplication::translate("MainWindow", "ACTUALIZAR", nullptr));
        pushButton_find->setText(QCoreApplication::translate("MainWindow", "FIND", nullptr));
        pushButton_on->setText(QCoreApplication::translate("MainWindow", "ON", nullptr));
        pushButton_off->setText(QCoreApplication::translate("MainWindow", "OFF", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
