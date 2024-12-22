#include "dialogchange.h"
#include "ui_dialogchange.h"

#include <QMessageBox>

DialogChange::DialogChange(QWidget *parent, MVC_Controller* controller): QDialog(parent), ui(new Ui::DialogChange), m_controller(controller)
{
    ui->setupUi(this);
    this->setFixedSize(413, 510); // установка фиксированного размера (через QT Designer установка Fixed не влияет никак...)
}

DialogChange::~DialogChange()
{
    delete m_controller;
    delete ui;
}

// ОК
void DialogChange::on_buttonBox_accepted()
{
    UsefulFunctions us;
    bool status = false;
    if (ui->textEdit->toPlainText().trimmed().isEmpty()
    || ui->textEdit_2->toPlainText().trimmed().isEmpty()
    || ui->textEdit_3->toPlainText().trimmed().isEmpty()
    || ui->textEdit_4->toPlainText().trimmed().isEmpty()
    || ui->textEdit_5->toPlainText().trimmed().isEmpty()
    || ui->textEdit_6->toPlainText().trimmed().isEmpty()
    || ui->textEdit_7->toPlainText().trimmed().isEmpty()) {
        QMessageBox Msgbox;
        Msgbox.setWindowTitle("Ошибка");
        Msgbox.setText("Ошибка: не все поля заполнены!");
        Msgbox.exec();
    }
    else if (us.toLong(ui->textEdit_7->toPlainText().trimmed().toStdString()) > m_controller->getModel().getBooks().size()
    || us.toLong(ui->textEdit_7->toPlainText().trimmed().toStdString()) == 0) {
        QMessageBox Msgbox;
        Msgbox.setWindowTitle("Ошибка");
        Msgbox.setText("Ошибка: такой порядковый номер не существует.");
        Msgbox.exec();
    }
    else if (us.toLong(ui->textEdit_7->toPlainText().trimmed().toStdString()) > 0 && us.toLong(ui->textEdit_7->toPlainText().trimmed().toStdString()) <= m_controller->getModel().getBooks().size()) {
        m_controller->changeBook(us.toLong(ui->textEdit_7->toPlainText().trimmed().toStdString())-1,
                                 ui->textEdit->toPlainText().trimmed().toStdString(),
                                 ui->textEdit_2->toPlainText().trimmed().toStdString(),
                                 us.toDouble(ui->textEdit_3->toPlainText().trimmed().toStdString()),
                                 ui->textEdit_4->toPlainText().trimmed().toStdString(),
                                 ui->textEdit_5->toPlainText().trimmed().toStdString(),
                                 us.toLong(ui->textEdit_6->toPlainText().trimmed().toStdString()));
        this->close();
    }
    else {
        QMessageBox Msgbox;
        Msgbox.setWindowTitle("Ошибка");
        Msgbox.setText("Ошибка: порядковый номер не является целым положительным числом, больше нуля.");
        Msgbox.exec();
    }
}

// ОТМЕНА
void DialogChange::on_buttonBox_rejected()
{
    this->close();
}

