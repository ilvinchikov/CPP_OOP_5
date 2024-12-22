#include "dialogrecomendation.h"
#include "ui_dialogrecomendation.h"

DialogRecomendation::DialogRecomendation(QWidget *parent, MVC_Controller* controller): QDialog(parent), ui(new Ui::DialogRecomendation), m_controller(controller)
{
    ui->setupUi(this);
    this->setFixedSize(800, 300); // установка фиксированного размера (через QT Designer установка Fixed не влияет никак...)
    // установка модели в QTableView
    ui->tableView->setModel(m_controller->getView().getQItemModelRecomended(m_controller->getModel()));
    // автоматически выровнять размер колонок
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

DialogRecomendation::~DialogRecomendation()
{
    delete m_controller;
    delete ui;
}

// OK
void DialogRecomendation::on_buttonBox_accepted()
{
    this->close();
}

// ОТМЕНА
void DialogRecomendation::on_buttonBox_rejected()
{
    this->close();
}

