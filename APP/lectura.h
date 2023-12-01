#ifndef LECTURA_H
#define LECTURA_H
#include "includes.h"
using namespace std;

class lectura
{
private:
    float temp;
    float oxi;
    float gas;
    string nombre;
    string fecha;

public:
    lectura();
    lectura(float, float, float, string, string);
    float getTemp() const;
    void setTemp(float newTemp);
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
