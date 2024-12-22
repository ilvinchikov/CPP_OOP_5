/********************************************************************************
** Form generated from reading UI file 'dialogrecomendation.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGRECOMENDATION_H
#define UI_DIALOGRECOMENDATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_DialogRecomendation
{
public:
    QDialogButtonBox *buttonBox;
    QTableView *tableView;

    void setupUi(QDialog *DialogRecomendation)
    {
        if (DialogRecomendation->objectName().isEmpty())
            DialogRecomendation->setObjectName("DialogRecomendation");
        DialogRecomendation->resize(800, 300);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DialogRecomendation->sizePolicy().hasHeightForWidth());
        DialogRecomendation->setSizePolicy(sizePolicy);
        buttonBox = new QDialogButtonBox(DialogRecomendation);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(20, 240, 761, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        tableView = new QTableView(DialogRecomendation);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(20, 20, 761, 192));
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

        retranslateUi(DialogRecomendation);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, DialogRecomendation, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, DialogRecomendation, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(DialogRecomendation);
    } // setupUi

    void retranslateUi(QDialog *DialogRecomendation)
    {
        DialogRecomendation->setWindowTitle(QCoreApplication::translate("DialogRecomendation", "\320\240\320\265\320\272\320\276\320\274\320\265\320\275\320\264\320\260\321\206\320\270\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogRecomendation: public Ui_DialogRecomendation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGRECOMENDATION_H
