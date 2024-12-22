#ifndef DIALOGRECOMENDATION_H
#define DIALOGRECOMENDATION_H

#include "MVC.h"

#include <QDialog>

namespace Ui {
class DialogRecomendation;
}

class DialogRecomendation : public QDialog
{
    Q_OBJECT

public:
    explicit DialogRecomendation(QWidget *parent = nullptr, MVC_Controller* controller = nullptr);
    ~DialogRecomendation();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::DialogRecomendation *ui;
    MVC_Controller* m_controller;
};

#endif // DIALOGRECOMENDATION_H
