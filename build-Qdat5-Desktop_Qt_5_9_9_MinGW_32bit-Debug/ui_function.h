/********************************************************************************
** Form generated from reading UI file 'function.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FUNCTION_H
#define UI_FUNCTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FuncTion
{
public:
    QLabel *label;
    QLabel *label_3;
    QLabel *label_2;
    QSlider *horizontalSlider;
    QLabel *label_5;
    QLabel *label_6;
    QTableView *tableView;
    QLineEdit *lineEdit;
    QPushButton *find;
    QPushButton *likesongs;
    QPushButton *colorselect1;
    QPushButton *colorselect2;
    QPushButton *colorselect3;
    QPushButton *colorselect4;
    QPushButton *pushButton;
    QFrame *frame;
    QLabel *picture;
    QLineEdit *singername;
    QLineEdit *songname;
    QPushButton *frontsong;
    QPushButton *pause;
    QPushButton *nextsong;

    void setupUi(QWidget *FuncTion)
    {
        if (FuncTion->objectName().isEmpty())
            FuncTion->setObjectName(QStringLiteral("FuncTion"));
        FuncTion->resize(1200, 1000);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        FuncTion->setFont(font);
        FuncTion->setCursor(QCursor(Qt::ArrowCursor));
        FuncTion->setStyleSheet(QStringLiteral(""));
        label = new QLabel(FuncTion);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 1200, 1000));
        label->setStyleSheet(QStringLiteral("image: url(:/Functionpic/back.jpg);"));
        label_3 = new QLabel(FuncTion);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(510, 10, 123, 145));
        label_2 = new QLabel(FuncTion);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 700, 1200, 300));
        horizontalSlider = new QSlider(FuncTion);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(80, 770, 1011, 31));
        horizontalSlider->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255,0.3);"));
        horizontalSlider->setOrientation(Qt::Horizontal);
        label_5 = new QLabel(FuncTion);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(0, 770, 81, 31));
        label_5->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255,0.3);\n"
"font: 75 italic 14pt \"Comic Sans MS\";\n"
"border-width:0;\n"
"border-style:outset;\n"
"border-radius: 20px;"));
        label_6 = new QLabel(FuncTion);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(1090, 770, 81, 31));
        label_6->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255,0.3);\n"
"font: 75 italic 14pt \"Comic Sans MS\";\n"
"border-width:0;\n"
"border-style:outset;\n"
"border-radius: 20px;"));
        tableView = new QTableView(FuncTion);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(200, 50, 1000, 721));
        tableView->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255,0);\n"
"border-color: rgb(255, 255, 255,0);\n"
""));
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setShowGrid(true);
        tableView->setGridStyle(Qt::SolidLine);
        tableView->horizontalHeader()->setVisible(true);
        tableView->horizontalHeader()->setHighlightSections(true);
        tableView->verticalHeader()->setVisible(false);
        lineEdit = new QLineEdit(FuncTion);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(200, 0, 701, 50));
        lineEdit->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255,0.3);\n"
"border-width:0;\n"
"border-style:outset;\n"
"border-radius: 20px;\n"
""));
        find = new QPushButton(FuncTion);
        find->setObjectName(QStringLiteral("find"));
        find->setGeometry(QRect(900, 0, 300, 50));
        find->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #dcdfe6;\n"
"    padding: 10px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #caffb9;\n"
"    color: #409eff;\n"
"}\n"
"\n"
"QPushButton:pressed, QPushButton:checked {\n"
"	background-color: rgb(255, 255, 255,0.3);\n"
"    border: 1px solid #3a8ee6;\n"
"    color: #409eff;\n"
"}\n"
""));
        likesongs = new QPushButton(FuncTion);
        likesongs->setObjectName(QStringLiteral("likesongs"));
        likesongs->setGeometry(QRect(0, 120, 200, 50));
        likesongs->setStyleSheet(QLatin1String("font: 57 16pt \"Dubai Medium\";\n"
"text-decoration: underline;\n"
"background-color: rgb(255, 255, 255,0);\n"
"border-color: rgb(255, 116, 23);\n"
"color: rgb(0, 0, 0);\n"
""));
        colorselect1 = new QPushButton(FuncTion);
        colorselect1->setObjectName(QStringLiteral("colorselect1"));
        colorselect1->setGeometry(QRect(0, 240, 200, 50));
        colorselect1->setStyleSheet(QLatin1String("font: 57 16pt \"Dubai Medium\";\n"
"text-decoration: underline;\n"
"background-color: rgb(255, 255, 255,0);\n"
"border-color: rgb(255, 116, 23);\n"
"color: rgb(255, 224, 151);\n"
""));
        colorselect2 = new QPushButton(FuncTion);
        colorselect2->setObjectName(QStringLiteral("colorselect2"));
        colorselect2->setGeometry(QRect(0, 330, 200, 50));
        colorselect2->setStyleSheet(QLatin1String("font: 57 16pt \"Dubai Medium\";\n"
"text-decoration: underline;\n"
"background-color: rgb(255, 255, 255,0);\n"
"border-color: rgb(255, 116, 23);\n"
"color: rgb(255, 170, 255);\n"
""));
        colorselect3 = new QPushButton(FuncTion);
        colorselect3->setObjectName(QStringLiteral("colorselect3"));
        colorselect3->setGeometry(QRect(0, 440, 200, 50));
        colorselect3->setStyleSheet(QLatin1String("font: 57 16pt \"Dubai Medium\";\n"
"text-decoration: underline;\n"
"background-color: rgb(255, 255, 255,0);\n"
"border-color: rgb(255, 116, 23);\n"
"color: rgb(14, 26, 255);\n"
""));
        colorselect4 = new QPushButton(FuncTion);
        colorselect4->setObjectName(QStringLiteral("colorselect4"));
        colorselect4->setGeometry(QRect(0, 530, 200, 50));
        colorselect4->setStyleSheet(QLatin1String("font: 57 16pt \"Dubai Medium\";\n"
"text-decoration: underline;\n"
"background-color: rgb(255, 255, 255,0);\n"
"border-color: rgb(255, 116, 23);\n"
"color: rgb(120, 255, 129);\n"
""));
        pushButton = new QPushButton(FuncTion);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(0, 0, 200, 51));
        frame = new QFrame(FuncTion);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 810, 1200, 191));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        picture = new QLabel(frame);
        picture->setObjectName(QStringLiteral("picture"));
        picture->setGeometry(QRect(20, 20, 141, 121));
        singername = new QLineEdit(frame);
        singername->setObjectName(QStringLiteral("singername"));
        singername->setGeometry(QRect(220, 40, 221, 41));
        singername->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255,0.3);\n"
"text-decoration: underline;\n"
"font: 14pt \"Arial\";\n"
"color: rgb(255, 170, 0);\n"
"border-width:0;\n"
"border-style:outset;\n"
"border-radius: 20px;\n"
""));
        songname = new QLineEdit(frame);
        songname->setObjectName(QStringLiteral("songname"));
        songname->setGeometry(QRect(220, 100, 221, 41));
        songname->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255,0.3);\n"
"border-width:0;\n"
"border-style:outset;\n"
"border-radius: 20px;\n"
""));
        frontsong = new QPushButton(frame);
        frontsong->setObjectName(QStringLiteral("frontsong"));
        frontsong->setGeometry(QRect(550, 70, 48, 48));
        frontsong->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255,0.3);\n"
"image: url(:/Functionpic/frontsong.png);\n"
"	 min-width:  48px;\n"
"	max-width:  48px;\n"
"    min-height: 48px;\n"
"    max-height: 48px;\n"
"    border-radius: 24px;"));
        pause = new QPushButton(frame);
        pause->setObjectName(QStringLiteral("pause"));
        pause->setGeometry(QRect(670, 70, 48, 48));
        pause->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255,0.3);\n"
"background-image: url(:/Functionpic/start.png);\n"
"	 min-width:  48px;\n"
"	max-width:  48px;\n"
"    min-height: 48px;\n"
"    max-height: 48px;\n"
"\n"
"    border-radius: 24px;"));
        nextsong = new QPushButton(frame);
        nextsong->setObjectName(QStringLiteral("nextsong"));
        nextsong->setGeometry(QRect(800, 70, 48, 48));
        nextsong->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255,0.3);\n"
"image: url(:/Functionpic/nextsongs.png);\n"
"	 min-width:  48px;\n"
"	max-width:  48px;\n"
"    min-height: 48px;\n"
"    max-height: 48px;\n"
"    border-radius: 24px;"));
        label_2->raise();
        label->raise();
        label_3->raise();
        horizontalSlider->raise();
        label_6->raise();
        label_5->raise();
        lineEdit->raise();
        find->raise();
        likesongs->raise();
        tableView->raise();
        colorselect1->raise();
        colorselect2->raise();
        colorselect3->raise();
        colorselect4->raise();
        pushButton->raise();
        frame->raise();

        retranslateUi(FuncTion);

        QMetaObject::connectSlotsByName(FuncTion);
    } // setupUi

    void retranslateUi(QWidget *FuncTion)
    {
        FuncTion->setWindowTitle(QApplication::translate("FuncTion", "Form", Q_NULLPTR));
        label->setText(QString());
        label_3->setText(QString());
        label_2->setText(QString());
        label_5->setText(QString());
        label_6->setText(QString());
        find->setText(QApplication::translate("FuncTion", "\346\220\234\347\264\242", Q_NULLPTR));
        likesongs->setText(QApplication::translate("FuncTion", "\345\226\234\346\254\242", Q_NULLPTR));
        colorselect1->setText(QApplication::translate("FuncTion", "\346\230\216\346\230\237", Q_NULLPTR));
        colorselect2->setText(QApplication::translate("FuncTion", "\347\262\211\350\211\262", Q_NULLPTR));
        colorselect3->setText(QApplication::translate("FuncTion", "\347\273\217\345\205\270", Q_NULLPTR));
        colorselect4->setText(QApplication::translate("FuncTion", "\345\212\250\346\274\253", Q_NULLPTR));
        pushButton->setText(QApplication::translate("FuncTion", "\346\237\245\347\234\213\345\244\251\346\260\224", Q_NULLPTR));
        picture->setText(QString());
        singername->setText(QString());
        frontsong->setText(QString());
        pause->setText(QString());
        nextsong->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FuncTion: public Ui_FuncTion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FUNCTION_H
