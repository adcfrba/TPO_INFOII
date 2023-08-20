#include "gas.h"
#include "ui_gas.h"

gas::gas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gas)
{
    ui->setupUi(this);
}

gas::~gas()
{
    delete ui;
}
