#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "dialogcreator.h"
#include "dialogdelete.h"
#include "dialogchange.h"
#include "dialogfile.h"
#include "dialogrecomendation.h"
#include <QDate>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(800, 469); // установка фиксированного размера (через QT Designer установка Fixed не влияет никак...)
    // MVC-запуск
    m_controller = new MVC_Controller(m_model, m_view);
    updateTableModel();
}

MainWindow::~MainWindow()
{
    delete m_controller;
    delete ui;
}

// обновление таблицы
void MainWindow::updateTableModel() {
    // установка модели в QTableView
    ui->tableView->setModel(m_view.getQItemModel(m_model));
    // автоматически выровнять размер колонок
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

// кнопка "Добавить"
void MainWindow::on_pushButton_clicked()
{
    // создание диалога и передача в него данных
    DialogCreator* dialog = new DialogCreator(this, m_controller);
    // отображение
    dialog->exec();
    updateTableModel();
}

// кнопка "Изменить"
void MainWindow::on_pushButton_2_clicked()
{
    // создание диалога и передача в него данных
    DialogChange* dialog = new DialogChange(this, m_controller);
    // отображение
    dialog->exec();
    updateTableModel();
}

// кнопка "Удалить"
void MainWindow::on_pushButton_3_clicked()
{
    if (m_model.getBooks().size() > 0) {
        // проверка на != nullptr (чтоб не вылетало)
        if (ui->tableView->selectionModel()) {
            // проверка на != nullptr   (чтоб не вылетало)
            if (!ui->tableView->selectionModel()->selectedRows().isEmpty()) {
                for (auto i=0; i<ui->tableView->selectionModel()->selectedRows().size(); i++) {
                    //qDebug() << "Цикл: " << i << "; Выделенная строка: " << ui->tableView->selectionModel()->selectedRows().at(i).row();
                    m_controller->deleteBook(ui->tableView->selectionModel()->selectedRows().at(i).row());
                }
                updateTableModel();
                return;
            }
        }
        // создание диалога и передача в него данных (если в итоге нет выделенных элементов)
        DialogDelete* dialog = new DialogDelete(this, m_controller);
        // отображение
        dialog->exec();
        updateTableModel();
    }
}

// кнопка "Рекомендации"
void MainWindow::on_pushButton_6_clicked()
{
    // создание диалога и передача в него данных
    DialogRecomendation* dialog = new DialogRecomendation(this, m_controller);
    // отображение
    dialog->exec();
    updateTableModel();
}

// кнопка "Импорт"
void MainWindow::on_pushButton_4_clicked()
{
    // создание диалога и передача в него данных
    DialogFile* dialog = new DialogFile(this, m_controller, 1);
    // отображение
    dialog->exec();
    updateTableModel();
}

// кнопка "Экспорт"
void MainWindow::on_pushButton_5_clicked()
{
    // создание диалога и передача в него данных
    DialogFile* dialog = new DialogFile(this, m_controller, 2);
    // отображение
    dialog->exec();
}

// кнопка "Прочитал"
void MainWindow::on_pushButton_7_clicked()
{
    setDateInTable(QDate::currentDate().toString("dd.MM.yyyy").toStdString());
}

// кнопка "Не читал"
void MainWindow::on_pushButton_8_clicked()
{
    setDateInTable("Не читал");
}

// кнопка "Забросил"
void MainWindow::on_pushButton_9_clicked()
{
    setDateInTable("Забросил");
}

// установка значения в поле даты
void MainWindow::setDateInTable(string text)
{
    if (m_model.getBooks().size() > 0) {
        // проверка на != nullptr (чтоб не вылетало)
        if (ui->tableView->selectionModel()) {
            // проверка на != nullptr   (чтоб не вылетало)
            if (!ui->tableView->selectionModel()->selectedRows().isEmpty()) {
                for (auto i=0; i<ui->tableView->selectionModel()->selectedRows().size(); i++) {
                    qDebug() << "Цикл: " << i << "; Выделенная строка: " << ui->tableView->selectionModel()->selectedRows().at(i).row();
                    m_model.setDate(ui->tableView->selectionModel()->selectedRows().at(i).row(), text);
                }
                updateTableModel();
            }
        }
    }
}

