#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFile file(":/style.qss");//使用qss文件 改变样式
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    this->setStyleSheet(in.readAll());//将qss文件内的样式内容 写到style
    file.close();


    pForm = new Form();
    connect(pForm,&Form::showmain,this,&MainWindow::show);

    clientSocket = new QTcpSocket(this);
    clientSocket->connectToHost("192.168.15.1",9001);//尝试连接服务器
    connect(clientSocket,&QTcpSocket::connected,this,&MainWindow::onConnected);//连接成功
    connect(clientSocket,&QTcpSocket::readyRead,this,&MainWindow::onreadyRead);//是否有数据可读
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onConnected()
{

}

void MainWindow::onreadyRead()
{
    QString str = clientSocket->readAll();
    qDebug()<<str<<endl;

    if(!strcmp(str.toStdString().c_str(),"login sucessful"))
    {
        QMessageBox::information(this, "登录状态", "登录成功");
        pfunc = new FuncTion;
        this->close();
        pfunc->show();
    }
    else if(!strcmp(str.toStdString().c_str(),"login failed"))
    {
        QMessageBox::information(this, "登录状态", "登录失败，账号或密码错误");
    }
}


void MainWindow::on_pushButton_clicked()//登录
{
    QMSG msg;
    msg.type = LOGIN;
    QString str = ui->lineEdit->text();
    QString str_pw = ui->lineEdit_2->text();
    registered_msg *rm = new registered_msg(str.toStdString().c_str(),str_pw.toStdString().c_str());
    memcpy(msg.buf,rm,sizeof(*rm));
    clientSocket->write((char *)&msg,sizeof(msg));
}

void MainWindow::on_pushButton_2_clicked()//注册
{
//    QMSG msg;//结构体用来传输注册的数据
//    msg.type = 2;
//    QString str = ui->lineEdit->text();
//    QString str_pw = ui->lineEdit_2->text();//读取再LineEdit上输入的内容
//    //str.toStdString().c_str()先转为string类型再.c_str()转为char*
//    registered_msg *rm = new registered_msg(str.toStdString().c_str(),str_pw.toStdString().c_str(),sex);
//    memcpy(msg.buf,rm,sizeof(*rm));
//    clientSocket->write((char *)&msg,sizeof(msg));
    this->close();
    pForm->show();
}
