#ifndef DIALOGFILE_H
#define DIALOGFILE_H

#include "MVC.h"

#include <QDialog>

namespace Ui {
class DialogFile;
}

class DialogFile : public QDialog
{
    Q_OBJECT

public:
    explicit DialogFile(QWidget *parent = nullptr, MVC_Controller* controller = nullptr, int mode = 0);
    ~DialogFile();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::DialogFile *ui;
    MVC_Controller* m_controller;
    int m_mode;
};

#endif // DIALOGFILE_H
