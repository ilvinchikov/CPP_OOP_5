#include "dialogdelete.h"
#include "ui_dialogdelete.h"
#include <QMessageBox>

DialogDelete::DialogDelete(QWidget *parent, MVC_Controller* controller): QDialog(parent), ui(new Ui::DialogDelete), m_controller(controller)
{
    ui->setupUi(this);
    this->setFixedSize(416, 137); // установка фиксированного размера (через QT Designer установка Fixed не влияет никак...)
}

DialogDelete::~DialogDelete()
{
    delete m_controller;
    delete ui;
}

// ОК
void DialogDelete::on_buttonBox_accepted()
{
    UsefulFunctions us;
    if (ui->textEdit->toPlainText().trimmed().isEmpty()) {
        QMessageBox Msgbox;
        Msgbox.setWindowTitle("Ошибка");
        Msgbox.setText("Ошибка: не все поля заполнены!");
        Msgbox.exec();
    }
    else if (us.toLong(ui->textEdit->toPlainText().trimmed().toStdString()) > 0 && us.toLong(ui->textEdit->toPlainText().trimmed().toStdString()) <= m_controller->getModel().getBooks().size()) {
        m_controller->deleteBook(us.extractLong(ui->textEdit->toPlainText().trimmed().toStdString())-1);
        this->close();
    }
    else if(us.toLong(ui->textEdit->toPlainText().trimmed().toStdString()) > m_controller->getModel().getBooks().size()) {
        QMessageBox Msgbox;
        Msgbox.setWindowTitle("Ошибка");
        Msgbox.setText("Ошибка: такой порядковый номер не существует.");
        Msgbox.exec();
    }
    else {
        QMessageBox Msgbox;
        Msgbox.setWindowTitle("Ошибка");
        Msgbox.setText("Ошибка: введите положительное целое число, больше нуля!");
        Msgbox.exec();
    }
}

// ОТМЕНА
void DialogDelete::on_buttonBox_rejected()
{
    this->close();
}

