#ifndef ANAMORPHOSISDIALOG_H
#define ANAMORPHOSISDIALOG_H

#include <QDialog>

namespace Ui {
class AnamorphosisDialog;
}

class AnamorphosisDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AnamorphosisDialog(QWidget *parent = 0);
    ~AnamorphosisDialog();

private:
    Ui::AnamorphosisDialog *ui;

private slots:
    void on_buttonBox_accepted();

signals:
    void anamorphosis_triggered(int rmin);
};

#endif // ANAMORPHOSISDIALOG_H
