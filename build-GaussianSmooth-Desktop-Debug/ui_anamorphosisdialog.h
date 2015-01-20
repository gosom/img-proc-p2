/********************************************************************************
** Form generated from reading UI file 'anamorphosisdialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANAMORPHOSISDIALOG_H
#define UI_ANAMORPHOSISDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AnamorphosisDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *rminLabel;
    QLineEdit *rminLineEdit;

    void setupUi(QDialog *AnamorphosisDialog)
    {
        if (AnamorphosisDialog->objectName().isEmpty())
            AnamorphosisDialog->setObjectName(QString::fromUtf8("AnamorphosisDialog"));
        AnamorphosisDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(AnamorphosisDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        formLayoutWidget = new QWidget(AnamorphosisDialog);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(20, 10, 171, 80));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        rminLabel = new QLabel(formLayoutWidget);
        rminLabel->setObjectName(QString::fromUtf8("rminLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, rminLabel);

        rminLineEdit = new QLineEdit(formLayoutWidget);
        rminLineEdit->setObjectName(QString::fromUtf8("rminLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, rminLineEdit);


        retranslateUi(AnamorphosisDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AnamorphosisDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AnamorphosisDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AnamorphosisDialog);
    } // setupUi

    void retranslateUi(QDialog *AnamorphosisDialog)
    {
        AnamorphosisDialog->setWindowTitle(QApplication::translate("AnamorphosisDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        rminLabel->setText(QApplication::translate("AnamorphosisDialog", "rmin", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AnamorphosisDialog: public Ui_AnamorphosisDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANAMORPHOSISDIALOG_H
