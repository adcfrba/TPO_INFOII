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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
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
    QLCDNumber *lcdNumber_pulso;
    QVBoxLayout *verticalLayout_6;
    QLabel *label__oxigenacion;
    QGraphicsView *graphicsView__oxigenacion;
    QLineEdit *lineEdit;
    QLCDNumber *lcdNumber_ox;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_gas;
    QGraphicsView *graphicsView_gas;
    QLCDNumber *lcdNumber_gas;
    QVBoxLayout *verticalLayout;
    QLabel *label_temperatura;
    QHBoxLayout *horizontalLayout_4;
    QSlider *verticalSlider;
    QLabel *label_slider;
    QLCDNumber *lcdNumber_temperatura;
    QProgressBar *progressBar;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_historial;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(601, 430);
        QPalette palette;
        QBrush brush(QColor(224, 227, 159, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        QBrush brush1(QColor(189, 155, 230, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush1);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        QBrush brush2(QColor(240, 240, 240, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        QBrush brush3(QColor(0, 120, 215, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
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
        QPalette palette1;
        QBrush brush4(QColor(255, 253, 239, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush4);
        QBrush brush5(QColor(47, 47, 47, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush5);
        centralwidget->setPalette(palette1);
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
        QPalette palette2;
        QBrush brush6(QColor(85, 85, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        QBrush brush7(QColor(0, 0, 0, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush7);
        QBrush brush8(QColor(120, 120, 120, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        label_nombre->setPalette(palette2);
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
        QPalette palette3;
        QBrush brush9(QColor(137, 137, 204, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush7);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        label_pulso->setPalette(palette3);
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Fixedsys")});
        font2.setBold(false);
        label_pulso->setFont(font2);
        label_pulso->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_pulso);

        graphicsView_pulso = new QGraphicsView(centralwidget);
        graphicsView_pulso->setObjectName("graphicsView_pulso");

        verticalLayout_7->addWidget(graphicsView_pulso);

        lcdNumber_pulso = new QLCDNumber(centralwidget);
        lcdNumber_pulso->setObjectName("lcdNumber_pulso");

        verticalLayout_7->addWidget(lcdNumber_pulso);


        horizontalLayout->addLayout(verticalLayout_7);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        label__oxigenacion = new QLabel(centralwidget);
        label__oxigenacion->setObjectName("label__oxigenacion");
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush7);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        label__oxigenacion->setPalette(palette4);
        label__oxigenacion->setFont(font2);
        label__oxigenacion->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label__oxigenacion);

        graphicsView__oxigenacion = new QGraphicsView(centralwidget);
        graphicsView__oxigenacion->setObjectName("graphicsView__oxigenacion");

        verticalLayout_6->addWidget(graphicsView__oxigenacion);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");

        verticalLayout_6->addWidget(lineEdit);

        lcdNumber_ox = new QLCDNumber(centralwidget);
        lcdNumber_ox->setObjectName("lcdNumber_ox");

        verticalLayout_6->addWidget(lcdNumber_ox);


        horizontalLayout->addLayout(verticalLayout_6);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_gas = new QLabel(centralwidget);
        label_gas->setObjectName("label_gas");
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush7);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        label_gas->setPalette(palette5);
        label_gas->setFont(font2);
        label_gas->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_gas);

        graphicsView_gas = new QGraphicsView(centralwidget);
        graphicsView_gas->setObjectName("graphicsView_gas");

        verticalLayout_5->addWidget(graphicsView_gas);

        lcdNumber_gas = new QLCDNumber(centralwidget);
        lcdNumber_gas->setObjectName("lcdNumber_gas");

        verticalLayout_5->addWidget(lcdNumber_gas);


        horizontalLayout->addLayout(verticalLayout_5);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_temperatura = new QLabel(centralwidget);
        label_temperatura->setObjectName("label_temperatura");
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush7);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        label_temperatura->setPalette(palette6);
        label_temperatura->setFont(font2);
        label_temperatura->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_temperatura);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        verticalSlider = new QSlider(centralwidget);
        verticalSlider->setObjectName("verticalSlider");
        verticalSlider->setOrientation(Qt::Vertical);

        horizontalLayout_4->addWidget(verticalSlider);

        label_slider = new QLabel(centralwidget);
        label_slider->setObjectName("label_slider");
        label_slider->setPixmap(QPixmap(QString::fromUtf8("images/caliente.png")));
        label_slider->setScaledContents(true);

        horizontalLayout_4->addWidget(label_slider);


        verticalLayout->addLayout(horizontalLayout_4);

        lcdNumber_temperatura = new QLCDNumber(centralwidget);
        lcdNumber_temperatura->setObjectName("lcdNumber_temperatura");

        verticalLayout->addWidget(lcdNumber_temperatura);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_4->addLayout(horizontalLayout);

        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName("progressBar");
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::Window, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush);
        progressBar->setPalette(palette7);
        progressBar->setFont(font2);
        progressBar->setValue(24);
        progressBar->setTextVisible(false);

        verticalLayout_4->addWidget(progressBar);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButton_historial = new QPushButton(centralwidget);
        pushButton_historial->setObjectName("pushButton_historial");
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_historial->sizePolicy().hasHeightForWidth());
        pushButton_historial->setSizePolicy(sizePolicy1);
        pushButton_historial->setMaximumSize(QSize(10000, 500));
        QPalette palette8;
        QBrush brush10(QColor(91, 90, 127, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush10);
        palette8.setBrush(QPalette::Active, QPalette::Button, brush9);
        QBrush brush11(QColor(255, 255, 255, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Active, QPalette::Light, brush11);
        QBrush brush12(QColor(23, 23, 70, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush12);
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush7);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::Light, brush11);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush7);
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette8.setBrush(QPalette::Disabled, QPalette::Light, brush11);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush8);
        pushButton_historial->setPalette(palette8);
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

        horizontalLayout_3->addWidget(pushButton_historial);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_4->addLayout(horizontalLayout_3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 601, 21));
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
        label_temperatura->setText(QCoreApplication::translate("MainWindow", "TEMPERATURA", nullptr));
        label_slider->setText(QString());
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
