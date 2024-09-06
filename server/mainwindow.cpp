#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    server = new QTcpServer(this);
    server->listen(QHostAddress::Any,9001);//监听端口
    connect(server,&QTcpServer::newConnection,this,&MainWindow::clientconnect);
    sqliteOP = new SqliteOpertor;
    sqliteOP->openDb();
//    sqliteOP->normalExec("create table user(name varchar(128),password varchar(128))");
//    sqliteOP->normalExec("create table like(name varchar(128),artists varchar(128),album varchar(128),id int,song_time int)");
}

MainWindow::~MainWindow()
{
    sqliteOP->closeDb();
    delete ui;
}

void MainWindow::clientconnect()
{
    clientSocket = server->nextPendingConnection();//得到连接客户端的套接字
    connect(clientSocket,&QTcpSocket::readyRead,this,&MainWindow::onReadyread);
}

void MainWindow::onReadyread()
{
    clientSocket = qobject_cast<QTcpSocket*>(sender());
    if(clientSocket)
    {
        QMSG msg ;
        clientSocket->read((char *)&msg,sizeof(msg));
        if(msg.type == 2)
        {
            qDebug()<<"send successful"<<endl;
            registered_msg *rm = (registered_msg*)msg.buf;
            QSqlQuery sqlQuery;
            sqliteOP->normalQuery(sqlQuery,QString("SELECT * FROM user WHERE name = '%1' and password = '%2'").arg(rm->name).arg(rm->passwd));
            while(sqlQuery.next())//判断上面的查询语句是否查到相同账号密码，相同就为真
            {
                clientSocket->write("existed");
                return ;
            }
            QString sql = QString("insert into user values('%1','%2')").arg(rm->name).arg(rm->passwd);
//            QString sql = QString("DELET TABLE user;");//删除表数据
//            QString sql = QString("DROP TABLE user;");//删除表
            sqliteOP->normalExec(sql);
            clientSocket->write("registered sucessful");
        }
        else if(msg.type == 1)//登录判断
        {
            registered_msg *rm = (registered_msg*)msg.buf;//artists varchar(128),album varchar(128),id int,song_time int)
            QSqlQuery sqlQuery;//查询到的结果在这里
            sqliteOP->normalQuery(sqlQuery,QString("SELECT * FROM user WHERE name = '%1' and password = '%2'").arg(rm->name).arg(rm->passwd));
            while(sqlQuery.next())//判断上面的查询语句是否查到相同账号密码，相同就为真
            {
                clientSocket->write("login sucessful");
                return ;
            }
            clientSocket->write("login failed");
        }


        else if(msg.type == 3)//收藏歌曲数据库
        {
            song *rm = (song*)msg.buf;
            QSqlQuery sqlQuery;
            sqliteOP->normalQuery(sqlQuery,QString("SELECT * FROM like WHERE name = '%1' and artists = '%2' and album = '%3'"
                                                   " and id = %4 and song_time = %5").
                                  arg(rm->name).arg(rm->artists).arg(rm->album).arg(rm->id).arg(rm->song_time));
            while(sqlQuery.next())//判断上面的查询语句是否查到相同账号密码，相同就为真
            {
                clientSocket->write("like failed");
                qDebug()<<sqlQuery.value("name")<<sqlQuery.value("artists")<<sqlQuery.value("id");
                return ;
            }
            QString sql = QString("insert into like values('%1','%2','%3','%4','%5')").
                    arg(rm->name).arg(rm->artists).arg(rm->album).arg(rm->id).arg(rm->song_time);
//            QString sql = QString("DELET TABLE user;");
//            QString sql = QString("DROP TABLE user;");
            sqliteOP->normalExec(sql);
            clientSocket->write("like sucessful");
        }


        else if(msg.type == 4)//查看收藏歌曲数据库
        {
            QSqlQuery sqlQuery;
            sqliteOP->normalQuery(sqlQuery,QString("SELECT * FROM like"));
            int recordCount = 0;
            while(sqlQuery.next()) // 计算记录总数 不然客户端不知道何时结束
            {
                recordCount++;
            }
            *(int*)msg.buf = recordCount;
            msg.type = 4;
            clientSocket->write((char *)&msg, sizeof(msg));

            sqlQuery.first();// 重新执行查询以遍历结果
            sqlQuery.previous();

            while(sqlQuery.next())//判断上面的查询语句是否查到相同账号密码，相同就为真
            {

                song _song;
                strcpy(_song.name,sqlQuery.value("name").toString().toStdString().c_str());//将QVariant转为char*
                strcpy(_song.artists,sqlQuery.value("artists").toString().toStdString().c_str());
                strcpy(_song.album,sqlQuery.value("album").toString().toStdString().c_str());
                _song.id = sqlQuery.value("id").toInt();
                _song.song_time = sqlQuery.value("song_time").toInt();
                memcpy(msg.buf,&_song,sizeof(_song));
                clientSocket->write((char *)&msg,sizeof(msg));
            }
        }

        else if(msg.type == 5)//收藏歌曲数据库
        {
            song *rm = (song*)msg.buf;
            QSqlQuery sqlQuery;
            sqliteOP->normalQuery(sqlQuery,QString("SELECT * FROM like WHERE name = '%1' and artists = '%2' and album = '%3'"
                                                   " and id = %4 and song_time = %5").
                                  arg(rm->name).arg(rm->artists).arg(rm->album).arg(rm->id).arg(rm->song_time));
            while(sqlQuery.next())//判断上面的查询语句是否查到相同账号密码，相同就为真
            {
                qDebug()<<sqlQuery.value("name")<<sqlQuery.value("artists")<<sqlQuery.value("id");
                QString sql = QString("DELETE FROM like WHERE name = '%1' and artists = '%2' and album = '%3'"
                                      " and id = %4 and song_time = %5").
                     arg(rm->name).arg(rm->artists).arg(rm->album).arg(rm->id).arg(rm->song_time);
                sqliteOP->normalExec(sql);
                return ;
            }
        }

    }
}

