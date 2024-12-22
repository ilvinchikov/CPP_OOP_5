#ifndef DIALOGCHANGE_H
#define DIALOGCHANGE_H

#include "MVC.h"

#include <QDialog>

namespace Ui {
class DialogChange;
}

class DialogChange : public QDialog
{
    Q_OBJECT

public:
    explicit DialogChange(QWidget *parent = nullptr, MVC_Controller* controller = nullptr);
    ~DialogChange();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::DialogChange *ui;
    MVC_Controller* m_controller;
};

#endif // DIALOGCHANGE_H
