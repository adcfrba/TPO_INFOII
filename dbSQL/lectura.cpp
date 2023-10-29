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

void lectura::nuevoData(QSqlDatabase bd)
{
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
}

void lectura::leerData(QSqlDatabase bd)
{
    if (!bd.open())
        qDebug() << "Error: connection with database failed";
    else
    {
        qDebug() << "Database: connection ok";
        QSqlDatabase::database().transaction();
        QSqlQuery qyData(bd);
        //qyData.prepare("SELECT * FROM lecturas WHERE ID IN (SELECT max(ID) FROM lecturas)");
        qyData.exec("SELECT * FROM lecturas WHERE ID IN (SELECT max(ID) FROM lecturas)");
        while(qyData.next())
        {
            nombre = qyData.value(1).toString().toStdString();
            temp = qyData.value(2).toFloat();
            oxi = qyData.value(3).toFloat();
            fecha = qyData.value(6).toString().toStdString();
            pulso = qyData.value(4).toInt();
            gas = qyData.value(5).toFloat();
            //qDebug()<<nombre<<temp<<oxi<<fecha<<pulso<<gas;
        }

    }
}
void lectura::actData(QSqlDatabase bd)
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
}
