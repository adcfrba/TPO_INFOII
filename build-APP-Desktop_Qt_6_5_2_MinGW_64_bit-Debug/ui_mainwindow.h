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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
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
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_nombre;
    QSpacerItem *verticalSpacer_2;
    QFrame *line;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_pulso;
    QPushButton *pushButton_pulso;
    QLCDNumber *lcdNumber_pulso;
    QSpacerItem *horizontalSpacer_6;
    QFrame *line_2;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_6;
    QLabel *label__oxigenacion;
    QPushButton *pushButton_ox;
    QLCDNumber *lcdNumber_ox;
    QSpacerItem *horizontalSpacer_7;
    QFrame *line_3;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_gas;
    QPushButton *pushButton_gas;
    QLCDNumber *lcdNumber_gas;
    QSpacerItem *horizontalSpacer_8;
    QFrame *line_4;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *verticalLayout;
    QLabel *label_temperatura;
    QPushButton *pushButton_temp;
    QLCDNumber *lcdNumber_temperatura;
    QFrame *line_5;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_historial;
    QSpacerItem *horizontalSpacer_2;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(727, 328);
        QPalette palette;
        QBrush brush(QColor(39, 44, 84, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(146, 180, 244, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(207, 222, 231, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush3(QColor(68, 114, 202, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush3);
        QBrush brush4(QColor(109, 132, 232, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush4);
        QBrush brush5(QColor(189, 155, 230, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush5);
        QBrush brush6(QColor(245, 255, 56, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Link, brush6);
        QBrush brush7(QColor(255, 164, 89, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::LinkVisited, brush7);
        QBrush brush8(QColor(10, 54, 157, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush4);
        QBrush brush9(QColor(240, 240, 240, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush9);
        palette.setBrush(QPalette::Inactive, QPalette::Link, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush4);
        QBrush brush10(QColor(0, 120, 215, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush10);
        palette.setBrush(QPalette::Disabled, QPalette::Link, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush8);
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
        QBrush brush11(QColor(255, 253, 239, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush11);
        QBrush brush12(QColor(47, 47, 47, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush12);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush11);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush12);
        centralwidget->setPalette(palette1);
        verticalLayout_4 = new QVBoxLayout(centralwidget);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_4->addItem(verticalSpacer_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
        label_nombre = new QLabel(centralwidget);
        label_nombre->setObjectName("label_nombre");
        label_nombre->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_nombre->sizePolicy().hasHeightForWidth());
        label_nombre->setSizePolicy(sizePolicy);
        label_nombre->setMinimumSize(QSize(581, 60));
        label_nombre->setSizeIncrement(QSize(0, 0));
        label_nombre->setBaseSize(QSize(0, 0));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Highlight, brush5);
        palette2.setBrush(QPalette::Active, QPalette::Link, brush6);
        palette2.setBrush(QPalette::Active, QPalette::LinkVisited, brush7);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Highlight, brush9);
        palette2.setBrush(QPalette::Inactive, QPalette::Link, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Highlight, brush10);
        palette2.setBrush(QPalette::Disabled, QPalette::Link, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        label_nombre->setPalette(palette2);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("MS Serif")});
        font1.setPointSize(22);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setStrikeOut(false);
        font1.setStyleStrategy(QFont::PreferDefault);
        label_nombre->setFont(font1);
        label_nombre->setFocusPolicy(Qt::StrongFocus);
        label_nombre->setAutoFillBackground(false);
        label_nombre->setFrameShape(QFrame::NoFrame);
        label_nombre->setFrameShadow(QFrame::Raised);
        label_nombre->setLineWidth(0);
        label_nombre->setMidLineWidth(0);
        label_nombre->setTextFormat(Qt::RichText);
        label_nombre->setScaledContents(true);
        label_nombre->setAlignment(Qt::AlignCenter);
        label_nombre->setWordWrap(false);
        label_nombre->setMargin(0);
        label_nombre->setIndent(0);

        horizontalLayout_2->addWidget(label_nombre);


        verticalLayout_4->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_4->addItem(verticalSpacer_2);

        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setWindowModality(Qt::NonModal);
        line->setMinimumSize(QSize(1, 0));
        QFont font2;
        font2.setPointSize(18);
        font2.setBold(false);
        line->setFont(font2);
        line->setAutoFillBackground(false);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        label_pulso = new QLabel(centralwidget);
        label_pulso->setObjectName("label_pulso");
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush8);
        palette3.setBrush(QPalette::Active, QPalette::Highlight, brush5);
        palette3.setBrush(QPalette::Active, QPalette::Link, brush6);
        palette3.setBrush(QPalette::Active, QPalette::LinkVisited, brush7);
        palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush8);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush8);
        palette3.setBrush(QPalette::Inactive, QPalette::Highlight, brush9);
        palette3.setBrush(QPalette::Inactive, QPalette::Link, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush7);
        palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush8);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush8);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush8);
        palette3.setBrush(QPalette::Disabled, QPalette::Highlight, brush10);
        palette3.setBrush(QPalette::Disabled, QPalette::Link, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush7);
        palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush8);
        label_pulso->setPalette(palette3);
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Fixedsys")});
        font3.setPointSize(12);
        font3.setBold(false);
        font3.setUnderline(true);
        label_pulso->setFont(font3);
        label_pulso->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_pulso);

        pushButton_pulso = new QPushButton(centralwidget);
        pushButton_pulso->setObjectName("pushButton_pulso");
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_pulso->sizePolicy().hasHeightForWidth());
        pushButton_pulso->setSizePolicy(sizePolicy1);
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipBase, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush3);
        pushButton_pulso->setPalette(palette4);
        pushButton_pulso->setCursor(QCursor(Qt::ArrowCursor));
        pushButton_pulso->setAutoDefault(false);
        pushButton_pulso->setFlat(true);

        verticalLayout_7->addWidget(pushButton_pulso);

        lcdNumber_pulso = new QLCDNumber(centralwidget);
        lcdNumber_pulso->setObjectName("lcdNumber_pulso");
        lcdNumber_pulso->setLayoutDirection(Qt::LeftToRight);
        lcdNumber_pulso->setAutoFillBackground(false);
        lcdNumber_pulso->setFrameShape(QFrame::Box);
        lcdNumber_pulso->setFrameShadow(QFrame::Raised);
        lcdNumber_pulso->setSmallDecimalPoint(false);

        verticalLayout_7->addWidget(lcdNumber_pulso);


        horizontalLayout->addLayout(verticalLayout_7);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName("line_2");
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        label__oxigenacion = new QLabel(centralwidget);
        label__oxigenacion->setObjectName("label__oxigenacion");
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush8);
        palette5.setBrush(QPalette::Active, QPalette::Highlight, brush5);
        palette5.setBrush(QPalette::Active, QPalette::Link, brush6);
        palette5.setBrush(QPalette::Active, QPalette::LinkVisited, brush7);
        palette5.setBrush(QPalette::Active, QPalette::AlternateBase, brush8);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush8);
        palette5.setBrush(QPalette::Inactive, QPalette::Highlight, brush9);
        palette5.setBrush(QPalette::Inactive, QPalette::Link, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush7);
        palette5.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush8);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush8);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush8);
        palette5.setBrush(QPalette::Disabled, QPalette::Highlight, brush10);
        palette5.setBrush(QPalette::Disabled, QPalette::Link, brush6);
        palette5.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush7);
        palette5.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush8);
        label__oxigenacion->setPalette(palette5);
        label__oxigenacion->setFont(font3);
        label__oxigenacion->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label__oxigenacion);

        pushButton_ox = new QPushButton(centralwidget);
        pushButton_ox->setObjectName("pushButton_ox");
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_ox->sizePolicy().hasHeightForWidth());
        pushButton_ox->setSizePolicy(sizePolicy2);
        pushButton_ox->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_ox->setFlat(true);

        verticalLayout_6->addWidget(pushButton_ox);

        lcdNumber_ox = new QLCDNumber(centralwidget);
        lcdNumber_ox->setObjectName("lcdNumber_ox");
        lcdNumber_ox->setFrameShape(QFrame::Box);
        lcdNumber_ox->setFrameShadow(QFrame::Raised);

        verticalLayout_6->addWidget(lcdNumber_ox);


        horizontalLayout->addLayout(verticalLayout_6);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);

        line_3 = new QFrame(centralwidget);
        line_3->setObjectName("line_3");
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_3);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_gas = new QLabel(centralwidget);
        label_gas->setObjectName("label_gas");
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush8);
        palette6.setBrush(QPalette::Active, QPalette::Highlight, brush5);
        palette6.setBrush(QPalette::Active, QPalette::Link, brush6);
        palette6.setBrush(QPalette::Active, QPalette::LinkVisited, brush7);
        palette6.setBrush(QPalette::Active, QPalette::AlternateBase, brush8);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush8);
        palette6.setBrush(QPalette::Inactive, QPalette::Highlight, brush9);
        palette6.setBrush(QPalette::Inactive, QPalette::Link, brush6);
        palette6.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush7);
        palette6.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush8);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush8);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush8);
        palette6.setBrush(QPalette::Disabled, QPalette::Highlight, brush10);
        palette6.setBrush(QPalette::Disabled, QPalette::Link, brush6);
        palette6.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush7);
        palette6.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush8);
        label_gas->setPalette(palette6);
        label_gas->setFont(font3);
        label_gas->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_gas);

        pushButton_gas = new QPushButton(centralwidget);
        pushButton_gas->setObjectName("pushButton_gas");
        sizePolicy2.setHeightForWidth(pushButton_gas->sizePolicy().hasHeightForWidth());
        pushButton_gas->setSizePolicy(sizePolicy2);
        pushButton_gas->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_gas->setFlat(true);

        verticalLayout_5->addWidget(pushButton_gas);

        lcdNumber_gas = new QLCDNumber(centralwidget);
        lcdNumber_gas->setObjectName("lcdNumber_gas");
        lcdNumber_gas->setFrameShape(QFrame::Box);
        lcdNumber_gas->setFrameShadow(QFrame::Raised);

        verticalLayout_5->addWidget(lcdNumber_gas);


        horizontalLayout->addLayout(verticalLayout_5);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        line_4 = new QFrame(centralwidget);
        line_4->setObjectName("line_4");
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_4);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_temperatura = new QLabel(centralwidget);
        label_temperatura->setObjectName("label_temperatura");
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush8);
        palette7.setBrush(QPalette::Active, QPalette::Highlight, brush5);
        palette7.setBrush(QPalette::Active, QPalette::Link, brush6);
        palette7.setBrush(QPalette::Active, QPalette::LinkVisited, brush7);
        palette7.setBrush(QPalette::Active, QPalette::AlternateBase, brush8);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush8);
        palette7.setBrush(QPalette::Inactive, QPalette::Highlight, brush9);
        palette7.setBrush(QPalette::Inactive, QPalette::Link, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush7);
        palette7.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush8);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush8);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush8);
        palette7.setBrush(QPalette::Disabled, QPalette::Highlight, brush10);
        palette7.setBrush(QPalette::Disabled, QPalette::Link, brush6);
        palette7.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush7);
        palette7.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush8);
        label_temperatura->setPalette(palette7);
        label_temperatura->setFont(font3);
        label_temperatura->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_temperatura);

        pushButton_temp = new QPushButton(centralwidget);
        pushButton_temp->setObjectName("pushButton_temp");
        sizePolicy1.setHeightForWidth(pushButton_temp->sizePolicy().hasHeightForWidth());
        pushButton_temp->setSizePolicy(sizePolicy1);
        pushButton_temp->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_temp->setFlat(true);

        verticalLayout->addWidget(pushButton_temp);

        lcdNumber_temperatura = new QLCDNumber(centralwidget);
        lcdNumber_temperatura->setObjectName("lcdNumber_temperatura");

        verticalLayout->addWidget(lcdNumber_temperatura);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_4->addLayout(horizontalLayout);

        line_5 = new QFrame(centralwidget);
        line_5->setObjectName("line_5");
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        verticalLayout_4->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButton_historial = new QPushButton(centralwidget);
        pushButton_historial->setObjectName("pushButton_historial");
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButton_historial->sizePolicy().hasHeightForWidth());
        pushButton_historial->setSizePolicy(sizePolicy3);
        pushButton_historial->setMinimumSize(QSize(102, 37));
        pushButton_historial->setMaximumSize(QSize(182, 52));
        QPalette palette8;
        QBrush brush13(QColor(91, 90, 127, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush13);
        palette8.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush14(QColor(255, 255, 255, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Active, QPalette::Light, brush14);
        QBrush brush15(QColor(164, 188, 207, 255));
        brush15.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush15);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush);
        palette8.setBrush(QPalette::Active, QPalette::Highlight, brush1);
        QBrush brush16(QColor(0, 0, 0, 255));
        brush16.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush16);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Light, brush14);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush15);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Highlight, brush1);
        QBrush brush17(QColor(120, 120, 120, 255));
        brush17.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush17);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::Light, brush14);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush17);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush);
        pushButton_historial->setPalette(palette8);
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Fixedsys")});
        font4.setPointSize(12);
        font4.setBold(false);
        pushButton_historial->setFont(font4);
        pushButton_historial->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_historial->setMouseTracking(false);
        pushButton_historial->setFocusPolicy(Qt::NoFocus);
        pushButton_historial->setAcceptDrops(false);
        pushButton_historial->setLayoutDirection(Qt::LeftToRight);
        pushButton_historial->setAutoFillBackground(false);
        pushButton_historial->setStyleSheet(QString::fromUtf8(" background-color: rgb(39, 44, 84);\n"
" border-style: solid;\n"
" border-width:1px;\n"
" border-radius:8px;\n"
" max-width:180px;\n"
" max-height:50px;\n"
" min-width:100px;\n"
" min-height:35px;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("images/historial-medico.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QString::fromUtf8("images/historial-medico.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_historial->setIcon(icon1);
        pushButton_historial->setAutoDefault(false);
        pushButton_historial->setFlat(true);

        horizontalLayout_3->addWidget(pushButton_historial);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_4->addLayout(horizontalLayout_3);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        QFont font5;
        font5.setFamilies({QString::fromUtf8("MS Serif")});
        font5.setBold(false);
        statusbar->setFont(font5);
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 727, 21));
        menubar->setFont(font5);
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        pushButton_historial->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "BAYMAX", nullptr));
        label_nombre->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>BAYMAX </p></body></html>", nullptr));
        label_pulso->setText(QCoreApplication::translate("MainWindow", "Pulso", nullptr));
        pushButton_pulso->setText(QString());
        label__oxigenacion->setText(QCoreApplication::translate("MainWindow", "Oxigenacion", nullptr));
        pushButton_ox->setText(QString());
        label_gas->setText(QCoreApplication::translate("MainWindow", "Monoxido de carbono", nullptr));
        pushButton_gas->setText(QString());
        label_temperatura->setText(QCoreApplication::translate("MainWindow", "Temperatura", nullptr));
        pushButton_temp->setText(QString());
#if QT_CONFIG(whatsthis)
        pushButton_historial->setWhatsThis(QCoreApplication::translate("MainWindow", "Ver historial de mediciones del usuario", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_historial->setText(QCoreApplication::translate("MainWindow", "Historial", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
