#include "historial.h"
#include "ui_historial.h"

Historial::Historial(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Historial)
{
    ui->setupUi(this);
    mModel = new QSqlTableModel(this);
    mModel->setTable("Lecturas");
    mModel->select();
    ui->tableView_historial->setModel(mModel);
    QFont font = QFont("Baymax", 30,1);
    QFont fontSecundario = QFont("Skull", 12,1);
    ui->label_historialModal->setFont(font);
    ui->tableView_historial->setFont(fontSecundario);
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

