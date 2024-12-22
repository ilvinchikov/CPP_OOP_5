/********************************************************************************
** Form generated from reading UI file 'dialogcreator.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCREATOR_H
#define UI_DIALOGCREATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_DialogCreator
{
public:
    QDialogButtonBox *buttonBox;
    QTextEdit *textEdit;
    QLabel *label;
    QLabel *label_2;
    QTextEdit *textEdit_2;
    QLabel *label_3;
    QTextEdit *textEdit_3;
    QLabel *label_4;
    QTextEdit *textEdit_4;
    QLabel *label_5;
    QTextEdit *textEdit_5;
    QLabel *label_6;
    QTextEdit *textEdit_6;

    void setupUi(QDialog *DialogCreator)
    {
        if (DialogCreator->objectName().isEmpty())
            DialogCreator->setObjectName("DialogCreator");
        DialogCreator->resize(412, 441);
        buttonBox = new QDialogButtonBox(DialogCreator);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(40, 400, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        textEdit = new QTextEdit(DialogCreator);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(20, 40, 371, 31));
        label = new QLabel(DialogCreator);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 20, 371, 16));
        label_2 = new QLabel(DialogCreator);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 80, 371, 16));
        textEdit_2 = new QTextEdit(DialogCreator);
        textEdit_2->setObjectName("textEdit_2");
        textEdit_2->setGeometry(QRect(20, 100, 371, 31));
        label_3 = new QLabel(DialogCreator);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 140, 371, 16));
        textEdit_3 = new QTextEdit(DialogCreator);
        textEdit_3->setObjectName("textEdit_3");
        textEdit_3->setGeometry(QRect(20, 160, 371, 31));
        label_4 = new QLabel(DialogCreator);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 200, 371, 16));
        textEdit_4 = new QTextEdit(DialogCreator);
        textEdit_4->setObjectName("textEdit_4");
        textEdit_4->setGeometry(QRect(20, 220, 371, 31));
        label_5 = new QLabel(DialogCreator);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 260, 371, 16));
        textEdit_5 = new QTextEdit(DialogCreator);
        textEdit_5->setObjectName("textEdit_5");
        textEdit_5->setGeometry(QRect(20, 280, 371, 31));
        label_6 = new QLabel(DialogCreator);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 320, 371, 16));
        textEdit_6 = new QTextEdit(DialogCreator);
        textEdit_6->setObjectName("textEdit_6");
        textEdit_6->setGeometry(QRect(20, 340, 371, 31));

        retranslateUi(DialogCreator);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, DialogCreator, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, DialogCreator, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(DialogCreator);
    } // setupUi

    void retranslateUi(QDialog *DialogCreator)
    {
        DialogCreator->setWindowTitle(QCoreApplication::translate("DialogCreator", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\272\320\275\320\270\320\263\320\270", nullptr));
        label->setText(QCoreApplication::translate("DialogCreator", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        label_2->setText(QCoreApplication::translate("DialogCreator", "\320\232\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\217", nullptr));
        label_3->setText(QCoreApplication::translate("DialogCreator", "\320\236\321\206\320\265\320\275\320\272\320\260 (\320\262\320\265\321\211\320\265\321\201\321\202\320\262\320\265\320\275\320\275\320\276\320\265 \321\207\320\270\321\201\320\273\320\276)", nullptr));
        label_4->setText(QCoreApplication::translate("DialogCreator", "\320\220\320\262\321\202\320\276\321\200", nullptr));
        label_5->setText(QCoreApplication::translate("DialogCreator", "\320\224\320\260\321\202\320\260 \320\277\321\200\320\276\321\207\321\202\320\265\320\275\320\270\321\217", nullptr));
        label_6->setText(QCoreApplication::translate("DialogCreator", "\320\241\320\273\320\276\320\266\320\275\320\276\321\201\321\202\321\214 (\321\206\320\265\320\273\320\276\320\265 \321\207\320\270\321\201\320\273\320\276)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogCreator: public Ui_DialogCreator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCREATOR_H
