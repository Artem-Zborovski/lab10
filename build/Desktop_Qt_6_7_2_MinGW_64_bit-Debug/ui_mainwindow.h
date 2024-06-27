/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *orel;
    QPushButton *res;
    QLabel *resul;
    QPushButton *noth;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        orel = new QPushButton(centralwidget);
        orel->setObjectName("orel");
        orel->setGeometry(QRect(70, 350, 121, 61));
        res = new QPushButton(centralwidget);
        res->setObjectName("res");
        res->setGeometry(QRect(590, 350, 121, 61));
        resul = new QLabel(centralwidget);
        resul->setObjectName("resul");
        resul->setGeometry(QRect(260, 10, 241, 50));
        noth = new QPushButton(centralwidget);
        noth->setObjectName("noth");
        noth->setGeometry(QRect(260, 100, 250, 250));
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/c1.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        noth->setIcon(icon);
        noth->setIconSize(QSize(250, 250));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        orel->setText(QCoreApplication::translate("MainWindow", "OREL", nullptr));
        res->setText(QCoreApplication::translate("MainWindow", "RESHKA", nullptr));
        resul->setText(QString());
        noth->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
