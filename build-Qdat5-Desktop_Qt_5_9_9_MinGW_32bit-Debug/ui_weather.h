/********************************************************************************
** Form generated from reading UI file 'weather.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEATHER_H
#define UI_WEATHER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Weather
{
public:
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QPushButton *find;
    QTableView *tableView;

    void setupUi(QWidget *Weather)
    {
        if (Weather->objectName().isEmpty())
            Weather->setObjectName(QStringLiteral("Weather"));
        Weather->resize(1200, 1000);
        pushButton = new QPushButton(Weather);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(0, 0, 200, 50));
        lineEdit = new QLineEdit(Weather);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(200, 0, 700, 50));
        find = new QPushButton(Weather);
        find->setObjectName(QStringLiteral("find"));
        find->setGeometry(QRect(900, 0, 300, 50));
        tableView = new QTableView(Weather);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(200, 50, 1000, 800));

        retranslateUi(Weather);

        QMetaObject::connectSlotsByName(Weather);
    } // setupUi

    void retranslateUi(QWidget *Weather)
    {
        Weather->setWindowTitle(QApplication::translate("Weather", "Form", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Weather", "\351\237\263\344\271\220", Q_NULLPTR));
        find->setText(QApplication::translate("Weather", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Weather: public Ui_Weather {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEATHER_H
