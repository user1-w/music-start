#ifndef FUNCTION_H
#define FUNCTION_H

#include <QWidget>
#include <QMovie>
#include<QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QStandardItemModel>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "daili.h"
#include <QTcpSocket>
#include <stdio.h>
#include <QPixmap>
#include "weather.h"

#define LIKE 3;
#define FINDLIKE 4;
#define NOLIKE 5;

namespace Ui {
class FuncTion;
}

struct song//存放歌曲信息
{
    char name[128];
    char artists[128];
    char album[128];
    int id;
    int song_time;
    char picId[128];
};

struct Msg//发向客户端
{
    char buf[1022];
    short int type;
};

class FuncTion : public QWidget
{
    Q_OBJECT

public:
    explicit FuncTion(QWidget *parent = nullptr);
    ~FuncTion();
    void parseJson(QByteArray jsonByte);
    QString getstringartists(const QJsonArray &artists);
    QString encryptedId(const QString &id);
    QColor getAverageColor(const QPixmap &pixmap);//得到专辑照片的平均RGB
    void applyAverageColorToFrame(QFrame *frame, const QPixmap &pixmap);//将RGB应用的对应控件
public slots:
    void replyFinshed(QNetworkReply* reply);
    void replyFinshed1(QNetworkReply* reply);
    void slots_positionChanged(qint64 position);//滑块位置 也就是歌曲播放位置
    void slots_durationChanged(qint64 duration);//总时长

    void on_horizontalSlider_sliderReleased();//滑块是否释放

    void onConnected();//连接服务器
    void onreadyRead();

    void modelchanged();
private slots:
    void on_tableView_clicked(const QModelIndex &index);//添加喜欢
    void on_tableView_doubleClicked(const QModelIndex &index);//双击播放
    void on_horizontalSlider_sliderMoved(int position);//歌曲播放位置
    void songschanged();//歌曲切换
    void on_likesongs_clicked();//查看喜欢列表
    void on_find_clicked();//搜索歌曲
    void on_pause_clicked();
    void backschanged();
    void on_pushButton_clicked();//切换界面

signals:
    void showmain();

private:
    Ui::FuncTion *ui;
    QNetworkAccessManager *manager;
    QStandardItemModel *model;
    QMediaPlayer *player;
    QMediaPlaylist *playlist;
    QList<song> songs;
    QMovie *movie;
    QIcon *pause;
    QTcpSocket *clientSocket;
    song *_song;
    QPixmap pixmap;
    int currentsong;
    Weather *pweather;
};

#endif // FUNCTION_H
