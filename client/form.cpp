#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    ui->lineEdit->setPlaceholderText("昵称");
    ui->lineEdit_2->setPlaceholderText("密码");
    QMovie *movie = new QMovie(":/Register/2.gif");
    ui->label->setMovie(movie);
    movie->start();


    clientSocket = new QTcpSocket(this);
    clientSocket->connectToHost("192.168.15.1",9001);//尝试连接服务器
    connect(clientSocket,&QTcpSocket::connected,this,&Form::onConnected);//连接成功
    connect(clientSocket,&QTcpSocket::readyRead,this,&Form::onreadyRead);//是否有数据可读
}

Form::~Form()
{
    delete ui;
}

void Form::closeEvent(QCloseEvent *event)
{
    if(event->isAccepted())
    {
        showmain();
    }
}

void Form::onConnected()
{
    qDebug()<<"connected"<<endl;
}

void Form::onreadyRead()
{
    QString str = clientSocket->readAll();
    if(!strcmp(str.toStdString().c_str(),"registered sucessful"))
    {
        QMessageBox::information(this, "注册状态", "注册成功");
        showmain();
    }
    else if(!strcmp(str.toStdString().c_str(),"existed"))
    {
        QMessageBox::information(this, "注册状态", "账号密码已存在");
    }
}

void Form::on_pushButton_clicked()
{
    qDebug()<<"send data"<<endl;
    QMSG msg;//结构体用来传输注册的数据
    msg.type = REGISTER;
    QString str = ui->lineEdit->text();
    QString str_pw = ui->lineEdit_2->text();//读取再LineEdit上输入的内容
    //str.toStdString().c_str()先转为string类型再.c_str()转为char*
    registered_msg *rm = new registered_msg(str.toStdString().c_str(),str_pw.toStdString().c_str());
    memcpy(msg.buf,rm,sizeof(*rm));
    clientSocket->write((char *)&msg,sizeof(msg));
}
