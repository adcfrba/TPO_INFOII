#ifndef OX_H
#define OX_H
#include <includes.h>

namespace Ui {
class ox;
}

class ox : public QDialog
{
    Q_OBJECT

public:
    explicit ox(QWidget *parent = nullptr);
    ~ox();


    float getValor() const;
    void setValor(float newValor);

private:
    Ui::ox *ui;
    float valor;
};

#endif // OX_H
