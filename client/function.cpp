#include "function.h"
#include "ui_function.h"

FuncTion::FuncTion(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FuncTion)
{
    ui->setupUi(this);
    QIcon icon(":/Functionpic/find.png");
    ui->lineEdit->setPlaceholderText("请搜索");
    ui->singername->setPlaceholderText("歌手");
    ui->songname->setPlaceholderText("歌曲");
    ui->find->setIcon(icon);
    icon.addFile(":/Functionpic/liked.png");
    ui->likesongs->setIcon(icon);

    model = new QStandardItemModel(ui->tableView);
    QHeaderView* headerView = ui->tableView->horizontalHeader();
    headerView->setSectionResizeMode(QHeaderView::Stretch);
    headerView->setStyleSheet("QHeaderView::section {background-color: transparent; color: black; }");
    ui->tableView->setModel(model);//歌曲信息表
    ui->tableView->setItemDelegateForColumn(4,new daili);//重写第四列显示

    manager = new QNetworkAccessManager;
    connect(manager,&QNetworkAccessManager::finished,this,&FuncTion::replyFinshed);

    playlist = new QMediaPlaylist;//播放列表
    player = new QMediaPlayer;//播放成员
    player->setPlaylist(playlist);
    connect(player,&QMediaPlayer::positionChanged,this,&FuncTion::slots_positionChanged);//滑块位置移动
    connect(player,&QMediaPlayer::durationChanged,this,&FuncTion::slots_durationChanged);//滑块总长改变也就是改变歌曲

    connect(ui->horizontalSlider, &QSlider::sliderReleased, this, &FuncTion::on_horizontalSlider_sliderReleased);
    connect(ui->horizontalSlider, &QSlider::sliderReleased, player, &QMediaPlayer::play);//移动滑块 ，松开时才会播放
    connect(ui->horizontalSlider, &QSlider::sliderMoved, player, &QMediaPlayer::pause);//移动就会暂停


    clientSocket = new QTcpSocket(this);
    clientSocket->connectToHost("192.168.15.1",9001);//尝试连接服务器
    connect(clientSocket,&QTcpSocket::connected,this,&FuncTion::onConnected);//连接成功
    connect(clientSocket,&QTcpSocket::readyRead,this,&FuncTion::onreadyRead);//是否有数据可读

    connect(ui->nextsong,SIGNAL(clicked()),this,SLOT(songschanged()));//切换歌曲
    connect(ui->frontsong,SIGNAL(clicked()),this,SLOT(songschanged()));

    connect(ui->colorselect1,SIGNAL(clicked()),this,SLOT(backschanged()));//改变背景
    connect(ui->colorselect2,SIGNAL(clicked()),this,SLOT(backschanged()));
    connect(ui->colorselect3,SIGNAL(clicked()),this,SLOT(backschanged()));
    connect(ui->colorselect4,SIGNAL(clicked()),this,SLOT(backschanged()));

    pweather = new Weather;
    connect(pweather,&Weather::showmusic,this,&FuncTion::modelchanged);   //切换天气和音乐

}

void FuncTion::onConnected()
{
    qDebug()<<"播放器"<<endl;
}


FuncTion::~FuncTion()
{
    delete ui;
}

void FuncTion::parseJson(QByteArray jsonByte)//根据Json来解读数据
{
    QString name;
    QString artists;
    QString album;
    int id;
    int song_time;
    QString picid;
    //歌曲信息
    QJsonParseError json_error;
    QJsonDocument document =  QJsonDocument::fromJson(jsonByte,&json_error);
    if(json_error.error != QJsonParseError::NoError)
    {
       qDebug()<<json_error.errorString();
    }
    QJsonObject rootobj = document.object();//得到刚开始的object
    QJsonArray songarray = rootobj["result"].toObject()["songs"].toArray();//得到各个歌曲的数组
    for(const QJsonValue value : songarray)
    {
        QJsonObject object = value.toObject();
        name = object["name"].toString();
        artists = getstringartists(object["artists"].toArray());//这是不能该的左值 引用要用const
        album = object["album"].toObject()["name"].toString();
        qint64 result = static_cast<qint64>(object["album"].toObject()["picId"].toDouble());//强转
        picid = QString::number(result);
        id = object["id"].toInt();
        song_time = object["duration"].toInt()/1000;
        _song = new song;
        strcpy(_song->name,name.toStdString().c_str());
        strcpy(_song->artists,artists.toStdString().c_str());
        strcpy(_song->album,album.toStdString().c_str());
        _song->song_time = song_time;
        _song->id = id;
        strcpy(_song->picId , picid.toStdString().c_str());
        songs.push_back(*_song);//按顺序存入List中 在触发槽的时候 可以辨认时哪首歌曲；

        QString play_url = QString("http://music.163.com/song/media/outer/url?id=%1.mp3").arg(id);
        playlist->addMedia(QUrl(play_url));
        QStringList list;
        list<<"歌名"<<"歌手"<<"专辑"<<"时长"<<"收藏";
        model->setHorizontalHeaderLabels(list);
        QList<QStandardItem*> sti;
        sti<<new QStandardItem(name)<<new QStandardItem(artists)
          <<new QStandardItem(album)<<new QStandardItem(QString().number(song_time))<<new QStandardItem("undone");
        model->appendRow(sti);
    }

}

QString FuncTion::getstringartists(const QJsonArray &artists)//获取多个歌手名
{
    QStringList list;
    for(const QJsonValue &artist:artists)
    {
        list.push_back(artist.toObject()["name"].toString());
    }
    return list.join("/");//每个歌手已"/"分割
}


void FuncTion::replyFinshed(QNetworkReply *reply)//返回JSON码，获取歌曲信息
{
    QVariant ret = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);//接收状态，200表示页面访问成功
    if(ret == 200)//当正常为200的时候网页访问成功 所以才会触发parseJson(arreply)，就能把解读的数据写道LienView
    {
        QByteArray arreply =  reply->readAll();
        parseJson(arreply);
    }
}

void FuncTion::replyFinshed1(QNetworkReply *reply)//返回JSON码，获取专辑照片
{
    QVariant ret = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);//接收状态，200表示页面访问成功
    if(ret == 200)//当正常为200的时候网页访问成功 所以才会触发parseJson(arreply)，就能把解读的数据写道LienView
    {
        QByteArray arreply =  reply->readAll();
        QPixmap pixmap;
        if (pixmap.loadFromData(arreply)) {
            QSize newSize = ui->picture->size(); // 或者你想要的任何尺寸
            pixmap = pixmap.scaled(newSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            // 成功加载图片
            // 这里可以使用pixmap，例如设置到QLabel上
            // ui->imageLabel->setPixmap(pixmap);
            ui->picture->setPixmap(pixmap);
            applyAverageColorToFrame(ui->frame,pixmap);
            qDebug() << "Image downloaded successfully";
        }
    }
}


void FuncTion::on_tableView_clicked(const QModelIndex &index)//添加或删除喜欢歌曲
{
    if(index.column() != 4)
    {
        return ;
    }
    QVariant ret = model->data(index);//先保存释放前的数据
    QStandardItem *item = model->item(index.row(),index.column());//先释放掉 点击的位置
    delete item;
    if(ret == "done")
    {
        model->setItem(index.row(),index.column(),new QStandardItem("undone"));
        Msg msg;
        msg.type = NOLIKE;
        memcpy(msg.buf,&songs.at(index.row()),sizeof(songs.at(index.row())));
        clientSocket->write((char *)&msg,sizeof(msg));
    }
    else if(ret == "undone")
    {
        model->setItem(index.row(),index.column(),new QStandardItem("done"));
        Msg msg;
        msg.type = LIKE;
        memcpy(msg.buf,&songs.at(index.row()),sizeof(songs.at(index.row())));
        clientSocket->write((char *)&msg,sizeof(msg));
    }
}

void FuncTion::onreadyRead()//准备读取服务器数据
{
    Msg msg ;
    clientSocket->read((char *)&msg,sizeof(msg));
    int num = *(int *)msg.buf;
    if(msg.type == 4)
    {
        model->clear();
        songs.clear();//每次查找喜欢都要清空链表
        while(num--)
        {
            clientSocket->read((char *)&msg,sizeof(msg));
            song rm = *(song*)msg.buf;
            QList<QStandardItem*> sti;
            QString name(rm.name);
            QString artists(rm.artists);
            QString album(rm.album);
            songs.push_back(rm);//按顺序存入List中 在触发槽的时候 可以辨认时哪首歌曲；
            QStringList list;
            list<<"歌名"<<"歌手"<<"专辑"<<"时长"<<"收藏";
            model->setHorizontalHeaderLabels(list);
            QString play_url = QString("http://music.163.com/song/media/outer/url?id=%1.mp3").arg(rm.id);
            playlist->addMedia(QUrl(play_url));
            sti<<new QStandardItem(name)<<new QStandardItem(artists)
              <<new QStandardItem(album)<<new QStandardItem(QString().number(rm.song_time))<<new QStandardItem("done");
            model->appendRow(sti);
        }
    }

}

void FuncTion::modelchanged()
{
    this->show();
    pweather->close();
}

void FuncTion::on_tableView_doubleClicked(const QModelIndex &index)//双击开始音乐
{
    QNetworkAccessManager *manager1 = new QNetworkAccessManager;
    playlist->setCurrentIndex(index.row());
    currentsong = index.row();
    ui->singername->setText(songs.at(currentsong).name);
    ui->songname->setText(songs.at(currentsong).artists);
    QString encryptedString = encryptedId(songs.at(currentsong).picId);
    QString url = QString("http://p1.music.126.net/%1/%2.jpg").arg(encryptedString, songs.at(currentsong).picId);
    qDebug()<<url<<endl;
    manager1->get(QNetworkRequest(QUrl(url)));
    connect(manager1,&QNetworkAccessManager::finished,this,&FuncTion::replyFinshed1);
    player->play();
}


void FuncTion::slots_positionChanged(qint64 position)//滑块移动 调歌曲时间
{
    qint64 pos = position/1000;
    qint64 second = pos%60;
    qint64 minute = pos/60;
    ui->label_5->setText(QString("%1:%2").arg(minute,2,10,QChar('0')).arg(second,2,10,QChar('0')));
    ui->horizontalSlider->setValue(position);
}


void FuncTion::slots_durationChanged(qint64 duration)//歌曲总时长
{
    ui->horizontalSlider->setRange(0,duration);
    int minute = (duration/1000)/60;
    int second = (duration/1000)%60;
    ui->label_6->setText(QString("%1:%2").arg(minute,2,10,QChar('0')).arg(second,2,10,QChar('0')));
}


void FuncTion::on_horizontalSlider_sliderMoved(int position)//滑块移动 调歌曲进度
{
    player->setPosition(position);
}


void FuncTion::on_horizontalSlider_sliderReleased()//滑块释放
{
    player->setPosition(ui->horizontalSlider->value());
}

void FuncTion::songschanged()//上下首切换
{
    if(sender()->objectName() == "nextsong")
    {
        currentsong+=1;
    }
    else
    {
        currentsong-=1;
    }
    playlist->setCurrentIndex(currentsong);
    ui->singername->setText(songs.at(currentsong).name);
    ui->songname->setText(songs.at(currentsong).artists);
    player->play();
}



void FuncTion::on_likesongs_clicked()//查看喜欢列表
{
    Msg msg;
    msg.type = FINDLIKE;
    clientSocket->write((char *)&msg,sizeof(msg));
}

void FuncTion::on_find_clicked()//给歌曲关键词 得到Json
{
    songs.clear();
    model->clear();
    QString buf = ui->lineEdit->text();
    QString url =  QString("http://music.163.com/api/search/get/web?csrf_token=hlpretag=&hlposttag=&s=%1&type=1&offset=0&total=true&limit=10").arg(buf);
    manager->get(QNetworkRequest(QUrl(url)));//这里不触发，就不能找到网页并返回200
}

void FuncTion::on_pause_clicked()//音乐暂停和开始
{
    if(ui->pause->styleSheet().at(0) == "b")
    {
        player->pause();
        ui->pause->setStyleSheet("min-width:  48px;max-width:  48px; background-image: url(:/Functionpic/pause.png);min-height: 48px;max-height: 48px;border-radius: 24px;");
    }
    else
    {
        player->play();
        ui->pause->setStyleSheet("background-image: url(:/Functionpic/start.png);min-width:  48px;max-width:  48px;min-height: 48px;max-height: 48px;border-radius: 24px;");
    }
}

void FuncTion::backschanged()//切换主题颜色
{
    if(sender()->objectName() == "colorselect1")
    {
        pixmap.load(":/Functionpic/back1.jpg");
        ui->label->setPixmap(pixmap);
    }
    else if(sender()->objectName() == "colorselect2")
    {
        pixmap.load(":/Functionpic/back2.jpg");
        ui->label->setPixmap(pixmap);
    }
    else if(sender()->objectName() == "colorselect3")
    {
        pixmap.load(":/Functionpic/back.jpg");
        ui->label->setPixmap(pixmap);
    }
    else
    {
        pixmap.load(":/Functionpic/back3.jpg");
        ui->label->setPixmap(pixmap);
    }
}

void FuncTion::on_pushButton_clicked()//切换界面
{
    this->close();
    pweather->show();
}

QString FuncTion::encryptedId(const QString& id)
{
    QByteArray magic = "3go8&\$8*3*3h0k(2)2";
    QByteArray idBytes = id.toUtf8();
    int magicLen = magic.length();

    for (int i = 0; i < idBytes.length(); ++i) {
        idBytes[i] = idBytes[i] ^ magic[i % magicLen];
    }

    QByteArray md5 = QCryptographicHash::hash(idBytes, QCryptographicHash::Md5);
    QByteArray base64 = md5.toBase64();
    QString result = QString::fromLatin1(base64);
    result.replace("/", "_").replace("+", "-");

    return result;
}


QColor FuncTion::getAverageColor(const QPixmap& pixmap)
{
    QImage image = pixmap.toImage();

    if (image.isNull()) {
        return QColor(); // 返回无效颜色
    }

    long long totalRed = 0, totalGreen = 0, totalBlue = 0;
    int width = image.width();
    int height = image.height();
    int totalPixels = width * height;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            QColor pixelColor(image.pixel(x, y));
            totalRed += pixelColor.red();
            totalGreen += pixelColor.green();
            totalBlue += pixelColor.blue();
        }
    }

    int avgRed = totalRed / totalPixels;
    int avgGreen = totalGreen / totalPixels;
    int avgBlue = totalBlue / totalPixels;

    return QColor(avgRed, avgGreen, avgBlue);
}

void FuncTion::applyAverageColorToFrame(QFrame* frame, const QPixmap& pixmap)
{
    QColor avgColor = getAverageColor(pixmap);

    if (avgColor.isValid()) {
        // 创建一个新的调色板
        QPalette palette = frame->palette();

        // 设置 frame 的背景色为平均颜色
        palette.setColor(QPalette::Window, avgColor);

        // 应用新的调色板到 frame
        frame->setAutoFillBackground(true);
        frame->setPalette(palette);

        // 可选：如果你想要文本颜色与背景形成对比
        QColor textColor = avgColor.lightness() > 128 ? Qt::black : Qt::white;
        palette.setColor(QPalette::WindowText, textColor);
        frame->setPalette(palette);
    }
}

