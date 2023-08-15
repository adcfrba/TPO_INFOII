#include <QCoreApplication>
#include <QtSql>
#include <QtDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString serverNombre = "LOCALHOST\\SQLEXPRESS";
    QString dbNombre = "prueba";

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC"); //DRIVER para la conexión default

    db.setConnectOptions();


    return a.exec();
}
