/********************************************************************************
** Form generated from reading UI file 'historial.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORIAL_H
#define UI_HISTORIAL_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Historial
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label_historialModal;
    QHBoxLayout *horizontalLayout;
    QTableView *tableView_historial;
    QSpacerItem *verticalSpacer_2;
    QDialogButtonBox *buttonBox_hist;

    void setupUi(QDialog *Historial)
    {
        if (Historial->objectName().isEmpty())
            Historial->setObjectName(QString::fromUtf8("Historial"));
        Historial->resize(643, 399);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Historial->sizePolicy().hasHeightForWidth());
        Historial->setSizePolicy(sizePolicy);
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
        Historial->setPalette(palette);
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/historial-medico.png"), QSize(), QIcon::Normal, QIcon::Off);
        Historial->setWindowIcon(icon);
        Historial->setModal(true);
        verticalLayout = new QVBoxLayout(Historial);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout->addItem(verticalSpacer);

        label_historialModal = new QLabel(Historial);
        label_historialModal->setObjectName(QString::fromUtf8("label_historialModal"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_historialModal->sizePolicy().hasHeightForWidth());
        label_historialModal->setSizePolicy(sizePolicy1);
        label_historialModal->setSizeIncrement(QSize(100, 100));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Highlight, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Highlight, brush1);
        QBrush brush10(QColor(120, 120, 120, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush10);
        label_historialModal->setPalette(palette1);
        QFont font;
        font.setFamily(QString::fromUtf8("MS Serif"));
        font.setPointSize(15);
        font.setBold(true);
        label_historialModal->setFont(font);
        label_historialModal->setAutoFillBackground(false);
        label_historialModal->setFrameShape(QFrame::Box);
        label_historialModal->setFrameShadow(QFrame::Raised);
        label_historialModal->setLineWidth(0);
        label_historialModal->setMidLineWidth(0);
        label_historialModal->setScaledContents(true);
        label_historialModal->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_historialModal);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tableView_historial = new QTableView(Historial);
        tableView_historial->setObjectName(QString::fromUtf8("tableView_historial"));
        sizePolicy.setHeightForWidth(tableView_historial->sizePolicy().hasHeightForWidth());
        tableView_historial->setSizePolicy(sizePolicy);
        tableView_historial->setMinimumSize(QSize(0, 250));
        tableView_historial->setFocusPolicy(Qt::NoFocus);
        tableView_historial->setLayoutDirection(Qt::LeftToRight);
        tableView_historial->setFrameShape(QFrame::Box);
        tableView_historial->setFrameShadow(QFrame::Raised);
        tableView_historial->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView_historial->setDragDropOverwriteMode(false);
        tableView_historial->setAlternatingRowColors(true);
        tableView_historial->setTextElideMode(Qt::ElideMiddle);
        tableView_historial->setGridStyle(Qt::DotLine);
        tableView_historial->setCornerButtonEnabled(true);
        tableView_historial->horizontalHeader()->setVisible(true);
        tableView_historial->horizontalHeader()->setHighlightSections(false);
        tableView_historial->verticalHeader()->setVisible(false);

        horizontalLayout->addWidget(tableView_historial);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        verticalLayout->addItem(verticalSpacer_2);

        buttonBox_hist = new QDialogButtonBox(Historial);
        buttonBox_hist->setObjectName(QString::fromUtf8("buttonBox_hist"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(buttonBox_hist->sizePolicy().hasHeightForWidth());
        buttonBox_hist->setSizePolicy(sizePolicy2);
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush11(QColor(164, 188, 207, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush11);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush11);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush11);
        palette2.setBrush(QPalette::Active, QPalette::Highlight, brush1);
        QBrush brush12(QColor(39, 44, 84, 128));
        brush12.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush12);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush11);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush11);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush11);
        palette2.setBrush(QPalette::Inactive, QPalette::Highlight, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush12);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush11);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush11);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush11);
        palette2.setBrush(QPalette::Disabled, QPalette::Highlight, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush12);
#endif
        buttonBox_hist->setPalette(palette2);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Consolas"));
        font1.setBold(true);
        buttonBox_hist->setFont(font1);
        buttonBox_hist->setCursor(QCursor(Qt::PointingHandCursor));
        buttonBox_hist->setAutoFillBackground(false);
        buttonBox_hist->setStyleSheet(QString::fromUtf8("background-color: rgb(164, 188, 207);\n"
"selection-background-color: rgb(146, 180, 244);\n"
"color: rgb(39, 44, 84);\n"
""));
        buttonBox_hist->setOrientation(Qt::Horizontal);
        buttonBox_hist->setStandardButtons(QDialogButtonBox::Ok|QDialogButtonBox::Reset);
        buttonBox_hist->setCenterButtons(true);

        verticalLayout->addWidget(buttonBox_hist);


        retranslateUi(Historial);
        QObject::connect(buttonBox_hist, SIGNAL(accepted()), Historial, SLOT(accept()));
        QObject::connect(buttonBox_hist, SIGNAL(rejected()), Historial, SLOT(reject()));

        QMetaObject::connectSlotsByName(Historial);
    } // setupUi

    void retranslateUi(QDialog *Historial)
    {
        Historial->setWindowTitle(QCoreApplication::translate("Historial", "Historial", nullptr));
        label_historialModal->setText(QCoreApplication::translate("Historial", "HISTORIAL DE USUARIO", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Historial: public Ui_Historial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORIAL_H
