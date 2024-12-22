#include "dialogfile.h"
#include "ui_dialogfile.h"

#include <QMessageBox>

DialogFile::DialogFile(QWidget *parent, MVC_Controller* controller, int mode): QDialog(parent), ui(new Ui::DialogFile), m_controller(controller), m_mode(mode)
{
    ui->setupUi(this);
    this->setFixedSize(400, 157); // установка фиксированного размера (через QT Designer установка Fixed не влияет никак...)
}

DialogFile::~DialogFile()
{
    delete m_controller;
    delete ui;
}

// кнопка ОК
void DialogFile::on_buttonBox_accepted()
{
    switch (m_mode) {
    case 1: // импорт
        m_controller->Import(ui->textEdit->toPlainText().trimmed().toStdString());
        break;
    case 2: // экспорт
        m_controller->Export(ui->textEdit->toPlainText().trimmed().toStdString());
        break;
    default:
        QMessageBox Msgbox;
        Msgbox.setWindowTitle("Ошибка");
        Msgbox.setText("Ошибка. Некорректный режим: это экспорт или импорт?");
        Msgbox.exec();
        break;
    }
}

// кнопка ОТМЕНА
void DialogFile::on_buttonBox_rejected()
{
    this->close();
}

