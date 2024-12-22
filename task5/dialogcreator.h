#ifndef DIALOGCREATOR_H
#define DIALOGCREATOR_H

#include "MVC.h"

#include <QDialog>

namespace Ui {
class DialogCreator;
}

class DialogCreator : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCreator(QWidget *parent = nullptr, MVC_Controller* controller = nullptr);
    ~DialogCreator();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::DialogCreator *ui;
    MVC_Controller* m_controller;
};

#endif // DIALOGCREATOR_H
