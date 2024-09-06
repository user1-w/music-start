#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QCloseEvent>
#include <QMovie>
#include <comment.h>
#include <QTcpSocket>

namespace Ui {
class Form;
}



class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

public slots:

void closeEvent(QCloseEvent *event) override;
void onConnected();
void onreadyRead();

signals:
    void showmain();
private slots:
    void on_pushButton_clicked();

private:
    Ui::Form *ui;
    QTcpSocket *clientSocket;
};

#endif // FORM_H
