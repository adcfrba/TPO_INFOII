/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_nombre;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_pulso;
    QGraphicsView *graphicsView_pulso;
    QListWidget *listWidget_pulso;
    QVBoxLayout *verticalLayout_6;
    QLabel *label__oxigenacion;
    QGraphicsView *graphicsView__oxigenacion;
    QListWidget *listWidget_oxigenacion;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_gas;
    QGraphicsView *graphicsView_gas;
    QListWidget *listWidget_gas;
    QPushButton *pushButton_historial;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(599, 430);
        QPalette palette;
        QBrush brush(QColor(47, 47, 47, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        QBrush brush1(QColor(189, 155, 230, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush1);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        QBrush brush2(QColor(240, 240, 240, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        QBrush brush3(QColor(245, 245, 245, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        QBrush brush4(QColor(0, 120, 215, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush3);
        MainWindow->setPalette(palette);
        QFont font;
        font.setBold(false);
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/saludable.png"), QSize(), QIcon::Normal, QIcon::On);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setEnabled(true);
        verticalLayout_4 = new QVBoxLayout(centralwidget);
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_nombre = new QLabel(centralwidget);
        label_nombre->setObjectName("label_nombre");
        label_nombre->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_nombre->sizePolicy().hasHeightForWidth());
        label_nombre->setSizePolicy(sizePolicy);
        label_nombre->setMinimumSize(QSize(581, 45));
        label_nombre->setSizeIncrement(QSize(0, 0));
        label_nombre->setBaseSize(QSize(0, 0));
        QPalette palette1;
        QBrush brush5(QColor(85, 85, 255, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush5);
        QBrush brush6(QColor(0, 0, 0, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        QBrush brush7(QColor(120, 120, 120, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        label_nombre->setPalette(palette1);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("MS Serif")});
        font1.setPointSize(20);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setUnderline(true);
        font1.setStrikeOut(false);
        font1.setStyleStrategy(QFont::PreferDefault);
        label_nombre->setFont(font1);
        label_nombre->setFocusPolicy(Qt::StrongFocus);
        label_nombre->setFrameShape(QFrame::NoFrame);
        label_nombre->setFrameShadow(QFrame::Plain);
        label_nombre->setLineWidth(1);
        label_nombre->setTextFormat(Qt::AutoText);
        label_nombre->setScaledContents(true);
        label_nombre->setAlignment(Qt::AlignCenter);
        label_nombre->setMargin(0);
        label_nombre->setIndent(-1);

        horizontalLayout_2->addWidget(label_nombre);


        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        label_pulso = new QLabel(centralwidget);
        label_pulso->setObjectName("label_pulso");
        QPalette palette2;
        QBrush brush8(QColor(137, 137, 204, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush8);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        label_pulso->setPalette(palette2);
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Fixedsys")});
        font2.setBold(false);
        label_pulso->setFont(font2);
        label_pulso->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_pulso);

        graphicsView_pulso = new QGraphicsView(centralwidget);
        graphicsView_pulso->setObjectName("graphicsView_pulso");

        verticalLayout_7->addWidget(graphicsView_pulso);

        listWidget_pulso = new QListWidget(centralwidget);
        listWidget_pulso->setObjectName("listWidget_pulso");

        verticalLayout_7->addWidget(listWidget_pulso);


        horizontalLayout->addLayout(verticalLayout_7);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        label__oxigenacion = new QLabel(centralwidget);
        label__oxigenacion->setObjectName("label__oxigenacion");
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush8);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        label__oxigenacion->setPalette(palette3);
        label__oxigenacion->setFont(font2);
        label__oxigenacion->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label__oxigenacion);

        graphicsView__oxigenacion = new QGraphicsView(centralwidget);
        graphicsView__oxigenacion->setObjectName("graphicsView__oxigenacion");

        verticalLayout_6->addWidget(graphicsView__oxigenacion);

        listWidget_oxigenacion = new QListWidget(centralwidget);
        listWidget_oxigenacion->setObjectName("listWidget_oxigenacion");

        verticalLayout_6->addWidget(listWidget_oxigenacion);


        horizontalLayout->addLayout(verticalLayout_6);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_gas = new QLabel(centralwidget);
        label_gas->setObjectName("label_gas");
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush8);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        label_gas->setPalette(palette4);
        label_gas->setFont(font2);
        label_gas->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_gas);

        graphicsView_gas = new QGraphicsView(centralwidget);
        graphicsView_gas->setObjectName("graphicsView_gas");

        verticalLayout_5->addWidget(graphicsView_gas);

        listWidget_gas = new QListWidget(centralwidget);
        listWidget_gas->setObjectName("listWidget_gas");

        verticalLayout_5->addWidget(listWidget_gas);


        horizontalLayout->addLayout(verticalLayout_5);


        verticalLayout_4->addLayout(horizontalLayout);

        pushButton_historial = new QPushButton(centralwidget);
        pushButton_historial->setObjectName("pushButton_historial");
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_historial->sizePolicy().hasHeightForWidth());
        pushButton_historial->setSizePolicy(sizePolicy1);
        pushButton_historial->setMaximumSize(QSize(10000, 500));
        QPalette palette5;
        QBrush brush9(QColor(91, 90, 127, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush8);
        QBrush brush10(QColor(255, 255, 255, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::Light, brush10);
        QBrush brush11(QColor(23, 23, 70, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush11);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::Light, brush10);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush7);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush8);
        palette5.setBrush(QPalette::Disabled, QPalette::Light, brush10);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush7);
        pushButton_historial->setPalette(palette5);
        pushButton_historial->setFont(font2);
        pushButton_historial->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_historial->setFocusPolicy(Qt::NoFocus);
        pushButton_historial->setAcceptDrops(false);
        pushButton_historial->setLayoutDirection(Qt::LeftToRight);
        pushButton_historial->setAutoFillBackground(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("images/historial-medico.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_historial->setIcon(icon1);
        pushButton_historial->setAutoDefault(false);
        pushButton_historial->setFlat(false);

        verticalLayout_4->addWidget(pushButton_historial);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 599, 21));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("MS Serif")});
        font3.setBold(false);
        menubar->setFont(font3);
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        statusbar->setFont(font3);
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        pushButton_historial->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "BAYMAX", nullptr));
        label_nombre->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>BAYMAX </p></body></html>", nullptr));
        label_pulso->setText(QCoreApplication::translate("MainWindow", "PULSO", nullptr));
        label__oxigenacion->setText(QCoreApplication::translate("MainWindow", "OXIGENACION", nullptr));
        label_gas->setText(QCoreApplication::translate("MainWindow", "MONOXIDO DE CARBONO", nullptr));
#if QT_CONFIG(whatsthis)
        pushButton_historial->setWhatsThis(QCoreApplication::translate("MainWindow", "Ver historial de mediciones del usuario", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_historial->setText(QCoreApplication::translate("MainWindow", "HISTORIAL", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
