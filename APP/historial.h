#ifndef HISTORIAL_H
#define HISTORIAL_H

#include <QDialog>

namespace Ui {
class Historial;
}

class Historial : public QDialog
{
    Q_OBJECT

public:
    explicit Historial(QWidget *parent = nullptr);
    ~Historial();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Historial *ui;
};

#endif // HISTORIAL_H
