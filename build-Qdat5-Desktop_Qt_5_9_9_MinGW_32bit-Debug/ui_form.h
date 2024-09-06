/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(505, 512);
        Form->setStyleSheet(QLatin1String("\n"
"background-color: rgb(255, 255, 255);"));
        pushButton = new QPushButton(Form);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(80, 360, 331, 51));
        pushButton->setStyleSheet(QLatin1String("font-size: 40px;\n"
"font-weight: bold;\n"
"background-color: rgba(255, 255, 255, 0.3);\n"
""));
        lineEdit = new QLineEdit(Form);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(170, 160, 251, 51));
        lineEdit->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0.3);\n"
"QLineEdit {\n"
"            color: black;\n"
"        }\n"
"QLineEdit:focus {\n"
"            color: black;\n"
"        }\n"
"QLineEdit:placeholder {\n"
"            color: gray;\n"
"        }\n"
"\n"
"QLineEdit:focus:placeholder {\n"
"            color: transparent;\n"
"        }"));
        lineEdit_2 = new QLineEdit(Form);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(170, 240, 251, 51));
        lineEdit_2->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0.3);"));
        label_3 = new QLabel(Form);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(80, 260, 41, 20));
        label_3->setStyleSheet(QLatin1String("font-size: 20px;\n"
"\n"
"font-weight: bold;\n"
"background-color: rgba(255, 255, 255, 0);\n"
""));
        label_2 = new QLabel(Form);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 170, 62, 20));
        label_2->setStyleSheet(QLatin1String("font-size: 20px;\n"
"font-weight: bold;\n"
"\n"
"background-color: rgba(255, 255, 255, 0);"));
        label = new QLabel(Form);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 505, 512));
        label->setStyleSheet(QStringLiteral(""));
        label->raise();
        pushButton->raise();
        lineEdit->raise();
        lineEdit_2->raise();
        label_3->raise();
        label_2->raise();
        QWidget::setTabOrder(lineEdit, lineEdit_2);
        QWidget::setTabOrder(lineEdit_2, pushButton);

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Form", "\346\263\250\345\206\214", Q_NULLPTR));
        lineEdit->setText(QString());
        lineEdit_2->setText(QString());
        label_3->setText(QApplication::translate("Form", "\345\257\206\347\240\201", Q_NULLPTR));
        label_2->setText(QApplication::translate("Form", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
