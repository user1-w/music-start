#include "weather.h"
#include "ui_weather.h"

Weather::Weather(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Weather)
{
    ui->setupUi(this);
    ui->lineEdit->setPlaceholderText("请搜索");
    loadCityData(":/weather/city.txt");
    model = new QStandardItemModel(ui->tableView);
    manager = new QNetworkAccessManager;
    connect(manager,&QNetworkAccessManager::finished,this,&Weather::replyFinshed);
}

Weather::~Weather()
{
    delete ui;
}

void Weather::parseJson(QByteArray jsonByte)
{
//    QJsonParseError json_error;
//    QJsonDocument document =  QJsonDocument::fromJson(jsonByte,&json_error);
//    if(json_error.error != QJsonParseError::NoError)
//    {
//       qDebug()<<json_error.errorString();
//    }
//    QJsonObject rootobj = document.object();//得到刚开始的object
//    QJsonArray songarray = rootobj["result"].toObject()["songs"].toArray();//得到各个歌曲的数组
//    for(const QJsonValue value : songarray)
//    {
//        QJsonObject object = value.toObject();
//        name = object["name"].toString();
//        artists = getstringartists(object["artists"].toArray());//这是不能该的左值 引用要用const
//        album = object["album"].toObject()["name"].toString();
//        id = object["id"].toInt();
//        song_time = object["duration"].toInt()/1000;
//        _song = new song;
//        strcpy(_song->name,name.toStdString().c_str());
//        strcpy(_song->artists,artists.toStdString().c_str());
//        strcpy(_song->album,album.toStdString().c_str());
//        _song->song_time = song_time;
//        _song->id = id;
//        songs.push_back(*_song);//按顺序存入List中 在触发槽的时候 可以辨认时哪首歌曲；

//        QString play_url = QString("http://music.163.com/song/media/outer/url?id=%1.mp3").arg(id);
//        playlist->addMedia(QUrl(play_url));
//        QStringList list;
//        list<<"歌名"<<"歌手"<<"专辑"<<"时长"<<"收藏";
//        model->setHorizontalHeaderLabels(list);
//        QList<QStandardItem*> sti;
//        sti<<new QStandardItem(name)<<new QStandardItem(artists)
//          <<new QStandardItem(album)<<new QStandardItem(QString().number(song_time))<<new QStandardItem("undone");
//        model->appendRow(sti);
//    }
}

void Weather::loadCityData(const QString &filePath)
{
    QFile file(filePath);
       if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
       {
           qDebug() << "无法打开文件";
           return;
       }
       QTextStream in(&file);
       in.setCodec("UTF-8");
       while (!in.atEnd()) {
           QString line = in.readLine();
           QStringList parts = line.split("\t");
           if (parts.size() == 2) {
               QString code = parts[0];
               QString city = parts[1];
               cityCodeMap[city] = code;
           }
       }

       file.close();
}

void Weather::on_pushButton_clicked()
{
    showmusic();
}

void Weather::replyFinshed(QNetworkReply *reply)
{

    QVariant ret = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);//接收状态，200表示页面访问成功
    if(ret == 200)//当正常为200的时候网页访问成功 所以才会触发parseJson(arreply)，就能把解读的数据写道LienView
    {
        QByteArray arreply =  reply->readAll();
        parseJson(arreply);
    }
}


void Weather::on_find_clicked()
{
    QString citydata = ui->lineEdit->text();
    qDebug() << cityCodeMap.value(citydata) << endl;
}
