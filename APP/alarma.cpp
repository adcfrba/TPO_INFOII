#include "alarma.h"
#include "ui_alarma.h"

alarma::alarma(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::alarma)
{
    ui->setupUi(this);

    QFontDatabase::addApplicationFont(":/new/fonts/Baymax.otf");
    QFontDatabase::addApplicationFont(":/new/fonts/Skull.otf");
    QFont font = QFont("Baymax", 50,1);
    QFont fontSecundario = QFont("Skull", 15,1);
    QPixmap boton_alarma ("C:/Users/notebook/Documents/INFO II 2023/TPO/TPO_INFOII/APP/images/advertencia");
    QIcon icon_alarma (boton_alarma);
    ui->pushButton_alarma->setIcon(icon_alarma);
    ui->pushButton_alarma->setIconSize(boton_alarma.rect().size());

    ui->label_alerta1->setFont(font);
    ui->label_alerta2->setFont(fontSecundario);
}

alarma::~alarma()
{
    delete ui;
}
