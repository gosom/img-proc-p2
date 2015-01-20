/********************************************************************************
** Form generated from reading UI file 'warpsettingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WARPSETTINGSDIALOG_H
#define UI_WARPSETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WarpSettingsDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *amplitudeXLabel;
    QDoubleSpinBox *amplitudeXDoubleSpinBox;
    QLabel *frequencyXLabel;
    QDoubleSpinBox *frequencyXDoubleSpinBox;
    QLabel *phaseXLabel;
    QDoubleSpinBox *phaseXDoubleSpinBox;
    QLabel *amplitudeYLabel;
    QDoubleSpinBox *amplitudeYDoubleSpinBox;
    QLabel *frequencyYLabel;
    QDoubleSpinBox *frequencyYDoubleSpinBox;
    QLabel *phaseYLabel;
    QDoubleSpinBox *phaseYDoubleSpinBox;

    void setupUi(QDialog *WarpSettingsDialog)
    {
        if (WarpSettingsDialog->objectName().isEmpty())
            WarpSettingsDialog->setObjectName(QString::fromUtf8("WarpSettingsDialog"));
        WarpSettingsDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(WarpSettingsDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        formLayoutWidget = new QWidget(WarpSettingsDialog);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(19, 9, 241, 191));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setContentsMargins(0, 0, 0, 0);
        amplitudeXLabel = new QLabel(formLayoutWidget);
        amplitudeXLabel->setObjectName(QString::fromUtf8("amplitudeXLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, amplitudeXLabel);

        amplitudeXDoubleSpinBox = new QDoubleSpinBox(formLayoutWidget);
        amplitudeXDoubleSpinBox->setObjectName(QString::fromUtf8("amplitudeXDoubleSpinBox"));
        amplitudeXDoubleSpinBox->setDecimals(4);
        amplitudeXDoubleSpinBox->setMaximum(1);
        amplitudeXDoubleSpinBox->setSingleStep(0.1);
        amplitudeXDoubleSpinBox->setValue(0);

        formLayout->setWidget(0, QFormLayout::FieldRole, amplitudeXDoubleSpinBox);

        frequencyXLabel = new QLabel(formLayoutWidget);
        frequencyXLabel->setObjectName(QString::fromUtf8("frequencyXLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, frequencyXLabel);

        frequencyXDoubleSpinBox = new QDoubleSpinBox(formLayoutWidget);
        frequencyXDoubleSpinBox->setObjectName(QString::fromUtf8("frequencyXDoubleSpinBox"));
        frequencyXDoubleSpinBox->setMinimum(0.1);
        frequencyXDoubleSpinBox->setMaximum(256.99);
        frequencyXDoubleSpinBox->setSingleStep(0.1);

        formLayout->setWidget(1, QFormLayout::FieldRole, frequencyXDoubleSpinBox);

        phaseXLabel = new QLabel(formLayoutWidget);
        phaseXLabel->setObjectName(QString::fromUtf8("phaseXLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, phaseXLabel);

        phaseXDoubleSpinBox = new QDoubleSpinBox(formLayoutWidget);
        phaseXDoubleSpinBox->setObjectName(QString::fromUtf8("phaseXDoubleSpinBox"));
        phaseXDoubleSpinBox->setSingleStep(0.1);

        formLayout->setWidget(2, QFormLayout::FieldRole, phaseXDoubleSpinBox);

        amplitudeYLabel = new QLabel(formLayoutWidget);
        amplitudeYLabel->setObjectName(QString::fromUtf8("amplitudeYLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, amplitudeYLabel);

        amplitudeYDoubleSpinBox = new QDoubleSpinBox(formLayoutWidget);
        amplitudeYDoubleSpinBox->setObjectName(QString::fromUtf8("amplitudeYDoubleSpinBox"));
        amplitudeYDoubleSpinBox->setDecimals(4);
        amplitudeYDoubleSpinBox->setMinimum(0);
        amplitudeYDoubleSpinBox->setMaximum(1);
        amplitudeYDoubleSpinBox->setSingleStep(0.1);
        amplitudeYDoubleSpinBox->setValue(0);

        formLayout->setWidget(3, QFormLayout::FieldRole, amplitudeYDoubleSpinBox);

        frequencyYLabel = new QLabel(formLayoutWidget);
        frequencyYLabel->setObjectName(QString::fromUtf8("frequencyYLabel"));

        formLayout->setWidget(4, QFormLayout::LabelRole, frequencyYLabel);

        frequencyYDoubleSpinBox = new QDoubleSpinBox(formLayoutWidget);
        frequencyYDoubleSpinBox->setObjectName(QString::fromUtf8("frequencyYDoubleSpinBox"));
        frequencyYDoubleSpinBox->setMinimum(0.1);
        frequencyYDoubleSpinBox->setMaximum(256.99);
        frequencyYDoubleSpinBox->setSingleStep(0.1);

        formLayout->setWidget(4, QFormLayout::FieldRole, frequencyYDoubleSpinBox);

        phaseYLabel = new QLabel(formLayoutWidget);
        phaseYLabel->setObjectName(QString::fromUtf8("phaseYLabel"));

        formLayout->setWidget(5, QFormLayout::LabelRole, phaseYLabel);

        phaseYDoubleSpinBox = new QDoubleSpinBox(formLayoutWidget);
        phaseYDoubleSpinBox->setObjectName(QString::fromUtf8("phaseYDoubleSpinBox"));
        phaseYDoubleSpinBox->setMinimum(0);
        phaseYDoubleSpinBox->setMaximum(99.99);
        phaseYDoubleSpinBox->setSingleStep(0.1);

        formLayout->setWidget(5, QFormLayout::FieldRole, phaseYDoubleSpinBox);


        retranslateUi(WarpSettingsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), WarpSettingsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), WarpSettingsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(WarpSettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *WarpSettingsDialog)
    {
        WarpSettingsDialog->setWindowTitle(QApplication::translate("WarpSettingsDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        amplitudeXLabel->setText(QApplication::translate("WarpSettingsDialog", "Amplitude x", 0, QApplication::UnicodeUTF8));
        frequencyXLabel->setText(QApplication::translate("WarpSettingsDialog", "Frequency x", 0, QApplication::UnicodeUTF8));
        phaseXLabel->setText(QApplication::translate("WarpSettingsDialog", "Phase x", 0, QApplication::UnicodeUTF8));
        amplitudeYLabel->setText(QApplication::translate("WarpSettingsDialog", "Amplitude y", 0, QApplication::UnicodeUTF8));
        frequencyYLabel->setText(QApplication::translate("WarpSettingsDialog", "Frequency y", 0, QApplication::UnicodeUTF8));
        phaseYLabel->setText(QApplication::translate("WarpSettingsDialog", "Phase y", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class WarpSettingsDialog: public Ui_WarpSettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WARPSETTINGSDIALOG_H
