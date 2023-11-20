#ifndef ALARMA_H
#define ALARMA_H

#include <QDialog>
#include "includes.h"

namespace Ui {
class alarma;
}

class alarma : public QDialog
{
    Q_OBJECT

public:
    explicit alarma(QWidget *parent = nullptr);
    ~alarma();

private:
    Ui::alarma *ui;
};

#endif // ALARMA_H
