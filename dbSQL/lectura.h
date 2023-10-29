#ifndef LECTURA_H
#define LECTURA_H
#include <string>
#include <QDebug>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <iostream>
#include <cmath>
using namespace std;

class lectura
{
private:
    float temp;
    int pulso;
    float oxi;
    float gas;
    string nombre;
    string fecha;

public:
    lectura();
    lectura(float, int, float, float, string, string);
    float getTemp() const;
    void setTemp(float newTemp);
    int getPulso() const;
    void setPulso(int newPulso);
    float getOxi() const;
    void setOxi(float newOxi);
    float getGas() const;
    void setGas(float newGas);
    string getNombre() const;
    void setNombre(const string &newNombre);
    string getFecha() const;
    void setFecha(const string &newFecha);

    void nuevoData(QSqlDatabase);
    void leerData(QSqlDatabase);
    void actData(QSqlDatabase);
};

#endif // LECTURA_H
