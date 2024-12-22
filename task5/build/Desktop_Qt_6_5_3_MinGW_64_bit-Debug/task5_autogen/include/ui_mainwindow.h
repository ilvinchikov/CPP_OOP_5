/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableView *tableView;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 469);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(20, 60, 761, 261));
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(20, 30, 101, 24));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(130, 30, 101, 24));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(240, 30, 101, 24));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(570, 30, 101, 24));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(680, 30, 101, 24));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(410, 30, 151, 24));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(460, 330, 101, 24));
        pushButton_7->setStyleSheet(QString::fromUtf8("background-color: rgb(18, 138, 0);\n"
"color: rgb(255, 255, 255);"));
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(680, 330, 101, 24));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy);
        pushButton_8->setStyleSheet(QString::fromUtf8("background-color: rgb(165, 0, 3);\n"
"color: rgb(255, 255, 255);"));
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(570, 330, 101, 24));
        sizePolicy.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy);
        pushButton_9->setStyleSheet(QString::fromUtf8("background-color: rgb(185, 108, 0);\n"
"color: rgb(255, 255, 255);"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\243\321\207\320\265\321\202 \320\277\321\200\320\276\321\207\320\270\321\202\320\260\320\275\320\275\320\276\320\271 \320\273\320\270\321\202\320\265\321\200\320\260\321\202\321\203\321\200\321\213", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\320\230\320\274\320\277\320\276\321\200\321\202", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "\320\255\320\272\321\201\320\277\320\276\321\200\321\202", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\272\320\276\320\274\320\265\320\275\320\264\320\260\321\206\320\270\320\270", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\321\207\320\270\321\202\320\260\320\273", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "\320\235\320\265 \321\207\320\270\321\202\320\260\320\273", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\261\321\200\320\276\321\201\320\270\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
