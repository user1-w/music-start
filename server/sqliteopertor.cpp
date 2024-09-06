


#include "sqliteopertor.h"

SqliteOpertor::SqliteOpertor()
{
    if(QSqlDatabase::contains("qt_sql_default_connection")==true)
    {
        database = QSqlDatabase::database("qt_sql_default_connection");

    }
    else
    {
        database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName("MyDataBase.db");
    }
}
// 打开数据库
bool SqliteOpertor::openDb()
{
    if (!database.open())
    {
        qDebug() << "Error: Failed to connect database." << database.lastError();
    }
    else
    {
        // do something

    }
    return true;
}

void SqliteOpertor::closeDb(void)
{
    database.close();
}

//通用执行函数
void SqliteOpertor::normalExec(QString sql)
{
    QSqlQuery sqlQuery;
    if(!sqlQuery.exec(sql))
    {
        qDebug()<<sqlQuery.lastError();
    }
    else
    {
        qDebug()<<"ok";
    }
}

//通用查询函数
void SqliteOpertor::normalQuery(QSqlQuery & sqlQuery, QString sql)
{
    if(!sqlQuery.exec(sql))
    {
        qDebug()<<sqlQuery.lastError();
    }
    else
    {
        qDebug()<<"ok"<<endl;
    }
}

