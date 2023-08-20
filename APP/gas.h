#ifndef GAS_H
#define GAS_H

#include <QDialog>

namespace Ui {
class gas;
}

class gas : public QDialog
{
    Q_OBJECT

public:
    explicit gas(QWidget *parent = nullptr);
    ~gas();

private:
    Ui::gas *ui;
};

#endif // GAS_H
