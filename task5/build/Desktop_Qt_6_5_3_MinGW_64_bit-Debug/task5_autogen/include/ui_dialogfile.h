/********************************************************************************
** Form generated from reading UI file 'dialogfile.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGFILE_H
#define UI_DIALOGFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_DialogFile
{
public:
    QDialogButtonBox *buttonBox;
    QTextEdit *textEdit;
    QLabel *label;

    void setupUi(QDialog *DialogFile)
    {
        if (DialogFile->objectName().isEmpty())
            DialogFile->setObjectName("DialogFile");
        DialogFile->resize(400, 157);
        buttonBox = new QDialogButtonBox(DialogFile);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(20, 100, 361, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        textEdit = new QTextEdit(DialogFile);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(20, 50, 361, 31));
        label = new QLabel(DialogFile);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 20, 361, 16));

        retranslateUi(DialogFile);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, DialogFile, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, DialogFile, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(DialogFile);
    } // setupUi

    void retranslateUi(QDialog *DialogFile)
    {
        DialogFile->setWindowTitle(QCoreApplication::translate("DialogFile", "\320\224\320\270\320\260\320\273\320\276\320\263", nullptr));
        label->setText(QCoreApplication::translate("DialogFile", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\204\320\260\320\271\320\273\320\260 (\321\201 \321\200\320\260\321\210\320\270\321\200\320\265\320\275\320\270\320\265\320\274). \320\235\320\260\320\277\321\200\320\270\320\274\320\265\321\200: Books.csv", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogFile: public Ui_DialogFile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGFILE_H
