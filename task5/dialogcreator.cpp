#include "dialogcreator.h"
#include "ui_dialogcreator.h"

#include <QMessageBox>

DialogCreator::DialogCreator(QWidget *parent, MVC_Controller* controller): QDialog(parent), ui(new Ui::DialogCreator), m_controller(controller)
{
    ui->setupUi(this);
    this->setFixedSize(412, 441); // установка фиксированного размера (через QT Designer установка Fixed не влияет никак...)
}

DialogCreator::~DialogCreator()
{
    delete m_controller;
    delete ui;
}

// ОК
void DialogCreator::on_buttonBox_accepted()
{
    UsefulFunctions us;
    bool status = false;
    if (ui->textEdit->toPlainText().trimmed().isEmpty()
    || ui->textEdit_2->toPlainText().trimmed().isEmpty()
    || ui->textEdit_3->toPlainText().trimmed().isEmpty()
    || ui->textEdit_4->toPlainText().trimmed().isEmpty()
    || ui->textEdit_5->toPlainText().trimmed().isEmpty()
    || ui->textEdit_6->toPlainText().trimmed().isEmpty()) {
        QMessageBox Msgbox;
        Msgbox.setWindowTitle("Ошибка");
        Msgbox.setText("Ошибка: не все поля заполнены!");
        Msgbox.exec();
    }
    else {
        m_controller->addNewBook(ui->textEdit->toPlainText().trimmed().toStdString(),
                                 ui->textEdit_2->toPlainText().trimmed().toStdString(),
                                 us.toDouble(ui->textEdit_3->toPlainText().trimmed().toStdString()),
                                 ui->textEdit_4->toPlainText().trimmed().toStdString(),
                                 ui->textEdit_5->toPlainText().trimmed().toStdString(),
                                 us.toLong(ui->textEdit_6->toPlainText().trimmed().toStdString()));
        this->close();
    }
}

// ОТМЕНА
void DialogCreator::on_buttonBox_rejected()
{
    this->close();
}

