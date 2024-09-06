#ifndef SQLITEOPERTOR_H
#define SQLITEOPERTOR_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

class SqliteOpertor
{
public:
    SqliteOpertor();

    bool openDb(void);

    void closeDb(void);

    void normalExec(QString sql);

    void normalQuery(QSqlQuery &sqlQuery,QString sql);

private:
    QSqlDatabase database;
};

#endif // SQLITEOPERTOR_H
