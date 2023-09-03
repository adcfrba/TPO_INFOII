#include "lectura.h"

float lectura::getTemp() const
{
    return temp;
}

void lectura::setTemp(float newTemp)
{
    temp = newTemp;
}

int lectura::getPulso() const
{
    return pulso;
}

void lectura::setPulso(int newPulso)
{
    pulso = newPulso;
}

float lectura::getOxi() const
{
    return oxi;
}

void lectura::setOxi(float newOxi)
{
    oxi = newOxi;
}

float lectura::getGas() const
{
    return gas;
}

void lectura::setGas(float newGas)
{
    gas = newGas;
}

string lectura::getNombre() const
{
    return nombre;
}

void lectura::setNombre(const string &newNombre)
{
    nombre = newNombre;
}

string lectura::getFecha() const
{
    return fecha;
}

void lectura::setFecha(const string &newFecha)
{
    fecha = newFecha;
}

lectura::lectura()
{
    temp = 0.0;
    pulso = 0;
    oxi = 0.0;
    gas = 0;
    nombre = " ";
    fecha = " ";
}

lectura::lectura(float _temp, int _pulso, float _oxi, float _gas, string _nombre, string _fecha)
{
    temp = _temp;
    pulso = _pulso;
    oxi = _oxi;
    gas = _gas;
    nombre = _nombre;
    fecha = _fecha;
}

int lectura::nuevoData(QSqlDatabase bd)
{
    if (!bd.open()) //checqueamos si se conecto o no
    {
        qDebug() << "Error: connection with database failed";
        return(0);
    }
    else
    {
        qDebug() << "Database: connection ok";
        QSqlDatabase::database().transaction();
        QSqlQuery qyInsert(bd);
        qyInsert.prepare("INSERT INTO lecturas(NOMBRE, TEMP, OXI, PULSO, GAS, FECHA) VALUES(:NOMBRE, :TEMP, :OXI, :PULSO, :GAS, :FECHA)");
        //ACA TENEMOS LAS LECTURAS
        qyInsert.bindValue(":NOMBRE", QString::fromStdString(nombre));
        qyInsert.bindValue(":TEMP",temp);
        qyInsert.bindValue(":OXI",oxi);
        qyInsert.bindValue(":PULSO",pulso);
        qyInsert.bindValue(":GAS",gas);
        qyInsert.bindValue(":FECHA", QString::fromStdString(fecha));
        qyInsert.exec();

        QSqlDatabase::database().commit();
        bd.close();
        return(1);
    }
}

int lectura::leerData(QSqlDatabase bd)
{
    if (!bd.open())
    {
        qDebug() << "Error: connection with database failed";
        return(0);
    }
    else
    {
        qDebug() << "Database: connection ok";
        QSqlDatabase::database().transaction();
        QSqlQuery qyData(bd);
        qyData.prepare("SELECT NOMBRE, FECHA, TEMP, OXI, PULSO, GAS, FECHA FROM lecturas WHERE MAX(id)");
        qyData.exec();
        nombre = qyData.value("NOMBRE").toString().toStdString();
        temp = qyData.value("TEMP").toFloat();
        oxi = qyData.value("OXI").toFloat();
        fecha = qyData.value("FECHA").toString().toStdString();
        pulso = qyData.value("PULSO").toInt();
        gas = qyData.value("GAS").toFloat();
    }
}
int lectura::actData(QSqlDatabase bd)
{
    if (!bd.open())
    {
        qDebug() << "Error: connection with database failed";
        return(0);
    }
    else
    {
        QSqlDatabase::database().transaction();

        QSqlQuery qyUpdate(bd);
        qyUpdate.prepare("UPDATE lecturas SET NOMBRE=:NOMBRE, TEMP=:TEMP, OXI=:OXI, PULSO=:PULSO, GAS=:GAS WHERE FECHA=:FECHA");
        //NUEVMAENTE LAS LECTURAS
        qyUpdate.bindValue(":TEMP", temp);
        qyUpdate.bindValue(":OXI", oxi);
        qyUpdate.bindValue(":PULSO", pulso);
        qyUpdate.bindValue(":GAS", gas);
        qyUpdate.bindValue(":NOMBRE", QString::fromStdString(nombre));
        qyUpdate.bindValue(":FECHA", QString::fromStdString(fecha));//se usa la fecha
        qyUpdate.exec();

        qDebug() <<"Error: "<<qyUpdate.lastError();
        QSqlDatabase::database().commit();
        bd.close();
        return(1);
    }
}
void lectura::tiempoRealData(QSqlDatabase bd)
{
    if (!bd.open())
    {
        qDebug() << "Error: connection with database failed";
        return;
    }
    else
    {

    }
}
