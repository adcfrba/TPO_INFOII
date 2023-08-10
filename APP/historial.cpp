#include "historial.h"
#include "ui_historial.h"

Historial::Historial(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Historial)
{
    ui->setupUi(this);
}

Historial::~Historial()
{
    delete ui;
}

void Historial::on_buttonBox_accepted()
{

   // ui->treeWidget_historial->addTopLevelItem();
}


void Historial::on_buttonBox_rejected()
{

}

