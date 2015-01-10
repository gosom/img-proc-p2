#include "warpsettingsdialog.h"
#include "ui_warpsettingsdialog.h"

#include <qdebug.h>

WarpSettingsDialog::WarpSettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WarpSettingsDialog)
{
    ui->setupUi(this);
     connect(this, SIGNAL(wrap_triggered(warpparams, warpparams)),
             parent, SLOT(on_wrap_triggered(warpparams, warpparams)));
}

WarpSettingsDialog::~WarpSettingsDialog()
{
    delete ui;
}

void WarpSettingsDialog::on_buttonBox_accepted()
{
    qDebug() << "Acccepted";
    warpparams x = {ui->amplitudeXDoubleSpinBox->value(),
                 ui->frequencyXDoubleSpinBox->value(),
                 ui->phaseXDoubleSpinBox->value()};
    warpparams y = {ui->amplitudeYDoubleSpinBox->value(),
                 ui->frequencyYDoubleSpinBox->value(),
                 ui->phaseYDoubleSpinBox->value()};
    emit wrap_triggered(x, y);
}
