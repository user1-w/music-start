#ifndef WEATHER_H
#define WEATHER_H

#include <QWidget>
#include<QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QStandardItemModel>
#include <QFile>
#include <QTextStream>
#include <QMap>
#include <QString>
#include <QDebug>

struct city//存放歌曲信息
{
    char cityname[128];
    int citykey;//搜索所需的城市键值
    char shidu[128];
    char wenduhigh[128];
    char wendulow[128];
    char week[64];//周几
    char type[64];//天气状况
};

namespace Ui {
class Weather;
}

class Weather : public QWidget
{
    Q_OBJECT

public:
    explicit Weather(QWidget *parent = nullptr);
    ~Weather();
    void parseJson(QByteArray jsonByte);
    void loadCityData(const QString& filePath);//从txt文件中读取键值和值
signals:
    void showmusic();

private slots:
    void on_pushButton_clicked();
    void replyFinshed(QNetworkReply* reply);
    void on_find_clicked();

private:
    Ui::Weather *ui;
    QNetworkAccessManager *manager;
    QStandardItemModel *model;
    QMap<QString, QString> cityCodeMap;
};

#endif // WEATHER_H
