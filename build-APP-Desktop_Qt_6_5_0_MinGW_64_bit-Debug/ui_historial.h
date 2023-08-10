/********************************************************************************
** Form generated from reading UI file 'historial.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORIAL_H
#define UI_HISTORIAL_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Historial
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_historialModal;
    QHBoxLayout *horizontalLayout;
    QTreeWidget *treeWidget_historial;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Historial)
    {
        if (Historial->objectName().isEmpty())
            Historial->setObjectName("Historial");
        Historial->resize(600, 300);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Historial->sizePolicy().hasHeightForWidth());
        Historial->setSizePolicy(sizePolicy);
        QPalette palette;
        QBrush brush(QColor(47, 47, 47, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        QBrush brush1(QColor(240, 240, 240, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        Historial->setPalette(palette);
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/historial-medico.png"), QSize(), QIcon::Normal, QIcon::Off);
        Historial->setWindowIcon(icon);
        Historial->setModal(true);
        verticalLayout = new QVBoxLayout(Historial);
        verticalLayout->setObjectName("verticalLayout");
        label_historialModal = new QLabel(Historial);
        label_historialModal->setObjectName("label_historialModal");
        QPalette palette1;
        QBrush brush2(QColor(189, 155, 230, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        QBrush brush3(QColor(0, 0, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        QBrush brush4(QColor(120, 120, 120, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        label_historialModal->setPalette(palette1);
        QFont font;
        font.setFamilies({QString::fromUtf8("MS Serif")});
        font.setPointSize(15);
        font.setBold(true);
        label_historialModal->setFont(font);
        label_historialModal->setFrameShape(QFrame::Box);
        label_historialModal->setFrameShadow(QFrame::Plain);
        label_historialModal->setLineWidth(3);
        label_historialModal->setMidLineWidth(2);
        label_historialModal->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_historialModal);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        treeWidget_historial = new QTreeWidget(Historial);
        treeWidget_historial->setObjectName("treeWidget_historial");
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(treeWidget_historial->sizePolicy().hasHeightForWidth());
        treeWidget_historial->setSizePolicy(sizePolicy1);
        treeWidget_historial->setMaximumSize(QSize(580, 16777215));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("MS Serif")});
        treeWidget_historial->setFont(font1);

        horizontalLayout->addWidget(treeWidget_historial);


        verticalLayout->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(Historial);
        buttonBox->setObjectName("buttonBox");
        QPalette palette2;
        QBrush brush5(QColor(16, 0, 24, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush5);
        QBrush brush6(QColor(121, 99, 147, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush6);
        buttonBox->setPalette(palette2);
        QFont font2;
        font2.setFamilies({QString::fromUtf8("MS Serif")});
        font2.setBold(true);
        buttonBox->setFont(font2);
        buttonBox->setCursor(QCursor(Qt::PointingHandCursor));
        buttonBox->setAutoFillBackground(false);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close|QDialogButtonBox::Ok|QDialogButtonBox::Reset);
        buttonBox->setCenterButtons(true);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(Historial);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Historial, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Historial, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Historial);
    } // setupUi

    void retranslateUi(QDialog *Historial)
    {
        Historial->setWindowTitle(QCoreApplication::translate("Historial", "Historial", nullptr));
        label_historialModal->setText(QCoreApplication::translate("Historial", "HISTORIAL DE USUARIO", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget_historial->headerItem();
        ___qtreewidgetitem->setText(5, QCoreApplication::translate("Historial", "Hora", nullptr));
        ___qtreewidgetitem->setText(4, QCoreApplication::translate("Historial", "Fecha", nullptr));
        ___qtreewidgetitem->setText(3, QCoreApplication::translate("Historial", "Gas ", nullptr));
        ___qtreewidgetitem->setText(2, QCoreApplication::translate("Historial", "Oxigenacion", nullptr));
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("Historial", "PPM", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("Historial", "Nombre", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Historial: public Ui_Historial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORIAL_H
