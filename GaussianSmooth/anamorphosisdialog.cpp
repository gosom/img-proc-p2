#include "anamorphosisdialog.h"
#include "ui_anamorphosisdialog.h"

AnamorphosisDialog::AnamorphosisDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnamorphosisDialog)
{
    ui->setupUi(this);
    connect(this, SIGNAL(anamorphosis_triggered(int)),
            parent, SLOT(on_anamorphosis_triggered(int)));
}

AnamorphosisDialog::~AnamorphosisDialog()
{
    delete ui;
}

void AnamorphosisDialog::on_buttonBox_accepted()
{
    int rmin = ui->rminLineEdit->text().toInt();
    emit anamorphosis_triggered(rmin);
}
