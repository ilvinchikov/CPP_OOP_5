#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "MVC.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateTableModel();

    void setDateInTable(string text);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::MainWindow *ui;
    MVC_Model m_model;
    MVC_View m_view;
    MVC_Controller* m_controller;
};
#endif // MAINWINDOW_H
