#ifndef OX_H
#define OX_H
#include <lectura.h>
#include <vector>
using namespace std;

namespace Ui {
class ox;
}

class ox : public QDialog
{
    Q_OBJECT

public:
    explicit ox(QWidget *parent = nullptr);
    ~ox();

    vector<lectura>getVectorOx(void);
    void setVectorOx(vector<lectura> newVectorOx);

    void cargarData(void);

private:
    Ui::ox *ui;
    vector<lectura>vectorOx;
};

#endif // OX_H
