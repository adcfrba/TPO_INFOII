/********************************************************************************
** Form generated from reading UI file 'alarma.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALARMA_H
#define UI_ALARMA_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_alarma
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_alarma;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_alerta1;
    QLabel *label_alerta2;
    QFrame *line;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *alarma)
    {
        if (alarma->objectName().isEmpty())
            alarma->setObjectName(QString::fromUtf8("alarma"));
        alarma->resize(619, 320);
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
        QBrush brush4(QColor(10, 54, 157, 255));
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
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush4);
        QBrush brush8(QColor(240, 240, 240, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::Link, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush4);
        QBrush brush9(QColor(0, 120, 215, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush9);
        palette.setBrush(QPalette::Disabled, QPalette::Link, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush4);
        alarma->setPalette(palette);
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("dialog-warning");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        alarma->setWindowIcon(icon);
        verticalLayout_2 = new QVBoxLayout(alarma);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_alarma = new QPushButton(alarma);
        pushButton_alarma->setObjectName(QString::fromUtf8("pushButton_alarma"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_alarma->sizePolicy().hasHeightForWidth());
        pushButton_alarma->setSizePolicy(sizePolicy);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("images/advertencia.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_alarma->setIcon(icon1);
        pushButton_alarma->setFlat(true);

        horizontalLayout->addWidget(pushButton_alarma);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_alerta1 = new QLabel(alarma);
        label_alerta1->setObjectName(QString::fromUtf8("label_alerta1"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_alerta1->sizePolicy().hasHeightForWidth());
        label_alerta1->setSizePolicy(sizePolicy1);
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        QBrush brush10(QColor(164, 188, 207, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush10);
        label_alerta1->setPalette(palette1);
        label_alerta1->setLayoutDirection(Qt::LeftToRight);
        label_alerta1->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_alerta1);

        label_alerta2 = new QLabel(alarma);
        label_alerta2->setObjectName(QString::fromUtf8("label_alerta2"));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        label_alerta2->setPalette(palette2);
        label_alerta2->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_alerta2);


        horizontalLayout->addLayout(verticalLayout_3);


        verticalLayout_2->addLayout(horizontalLayout);

        line = new QFrame(alarma);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        buttonBox = new QDialogButtonBox(alarma);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        QFont font;
        font.setPointSize(8);
        buttonBox->setFont(font);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ignore|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(alarma);
        QObject::connect(buttonBox, SIGNAL(accepted()), alarma, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), alarma, SLOT(reject()));

        QMetaObject::connectSlotsByName(alarma);
    } // setupUi

    void retranslateUi(QDialog *alarma)
    {
        alarma->setWindowTitle(QCoreApplication::translate("alarma", "EMERGENCIA", nullptr));
        pushButton_alarma->setText(QString());
        label_alerta1->setText(QCoreApplication::translate("alarma", "\302\241ALERTA!", nullptr));
        label_alerta2->setText(QCoreApplication::translate("alarma", "Usuario con malestar, contactar de inmediato con ayuda", nullptr));
    } // retranslateUi

};

namespace Ui {
    class alarma: public Ui_alarma {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALARMA_H
