#ifndef GAS_H
#define GAS_H
#include "includes.h"

namespace Ui {
class gas;
}

class gas : public QDialog
{
    Q_OBJECT

public:
    explicit gas(QWidget *parent = nullptr);
    ~gas();

    float getDataGas() const;
    void setDataGas(const float newDataGas);
    void cargarData(void);

private slots:

private:
    Ui::gas *ui;
    float dataGas;
    QBarSet *mono;
};

#endif // GAS_H
