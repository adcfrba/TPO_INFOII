#ifndef LECTURA_H
#define LECTURA_H
#include "includes.h"

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

    int nuevoData(QSqlDatabase);
    int leerData(QSqlDatabase);
    int actData(QSqlDatabase);
    void tiempoRealData(QSqlDatabase);
};

#endif // LECTURA_H
