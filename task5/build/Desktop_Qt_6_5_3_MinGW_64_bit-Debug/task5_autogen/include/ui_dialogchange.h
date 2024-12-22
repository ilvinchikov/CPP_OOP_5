/********************************************************************************
** Form generated from reading UI file 'dialogchange.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCHANGE_H
#define UI_DIALOGCHANGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_DialogChange
{
public:
    QDialogButtonBox *buttonBox;
    QTextEdit *textEdit_5;
    QTextEdit *textEdit_4;
    QLabel *label_5;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_6;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QLabel *label_2;
    QLabel *label_3;
    QTextEdit *textEdit_3;
    QTextEdit *textEdit_6;
    QTextEdit *textEdit_7;
    QLabel *label_7;

    void setupUi(QDialog *DialogChange)
    {
        if (DialogChange->objectName().isEmpty())
            DialogChange->setObjectName("DialogChange");
        DialogChange->resize(413, 510);
        buttonBox = new QDialogButtonBox(DialogChange);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(50, 470, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        textEdit_5 = new QTextEdit(DialogChange);
        textEdit_5->setObjectName("textEdit_5");
        textEdit_5->setGeometry(QRect(20, 340, 371, 31));
        textEdit_4 = new QTextEdit(DialogChange);
        textEdit_4->setObjectName("textEdit_4");
        textEdit_4->setGeometry(QRect(20, 280, 371, 31));
        label_5 = new QLabel(DialogChange);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 320, 371, 16));
        label = new QLabel(DialogChange);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 80, 371, 16));
        label_4 = new QLabel(DialogChange);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 260, 371, 16));
        label_6 = new QLabel(DialogChange);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 380, 371, 16));
        textEdit = new QTextEdit(DialogChange);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(20, 100, 371, 31));
        textEdit_2 = new QTextEdit(DialogChange);
        textEdit_2->setObjectName("textEdit_2");
        textEdit_2->setGeometry(QRect(20, 160, 371, 31));
        label_2 = new QLabel(DialogChange);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 140, 371, 16));
        label_3 = new QLabel(DialogChange);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 200, 371, 16));
        textEdit_3 = new QTextEdit(DialogChange);
        textEdit_3->setObjectName("textEdit_3");
        textEdit_3->setGeometry(QRect(20, 220, 371, 31));
        textEdit_6 = new QTextEdit(DialogChange);
        textEdit_6->setObjectName("textEdit_6");
        textEdit_6->setGeometry(QRect(20, 400, 371, 31));
        textEdit_7 = new QTextEdit(DialogChange);
        textEdit_7->setObjectName("textEdit_7");
        textEdit_7->setGeometry(QRect(20, 40, 371, 31));
        label_7 = new QLabel(DialogChange);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 20, 371, 16));

        retranslateUi(DialogChange);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, DialogChange, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, DialogChange, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(DialogChange);
    } // setupUi

    void retranslateUi(QDialog *DialogChange)
    {
        DialogChange->setWindowTitle(QCoreApplication::translate("DialogChange", "\320\230\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320\265 \320\272\320\275\320\270\320\263\320\270", nullptr));
        label_5->setText(QCoreApplication::translate("DialogChange", "\320\224\320\260\321\202\320\260 \320\277\321\200\320\276\321\207\321\202\320\265\320\275\320\270\321\217", nullptr));
        label->setText(QCoreApplication::translate("DialogChange", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        label_4->setText(QCoreApplication::translate("DialogChange", "\320\220\320\262\321\202\320\276\321\200", nullptr));
        label_6->setText(QCoreApplication::translate("DialogChange", "\320\241\320\273\320\276\320\266\320\275\320\276\321\201\321\202\321\214 (\321\206\320\265\320\273\320\276\320\265 \321\207\320\270\321\201\320\273\320\276)", nullptr));
        label_2->setText(QCoreApplication::translate("DialogChange", "\320\232\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\217", nullptr));
        label_3->setText(QCoreApplication::translate("DialogChange", "\320\236\321\206\320\265\320\275\320\272\320\260 (\320\262\320\265\321\211\320\265\321\201\321\202\320\262\320\265\320\275\320\275\320\276\320\265 \321\207\320\270\321\201\320\273\320\276)", nullptr));
        label_7->setText(QCoreApplication::translate("DialogChange", "\320\237\320\276\321\200\321\217\320\264\320\272\320\276\320\262\321\213\320\271 \320\275\320\276\320\274\320\265\321\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogChange: public Ui_DialogChange {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCHANGE_H
