#ifndef WARPSETTINGSDIALOG_H
#define WARPSETTINGSDIALOG_H
#include "imgwarp.h"
#include <QDialog>

namespace Ui {
class WarpSettingsDialog;
}

class WarpSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WarpSettingsDialog(QWidget *parent = 0);
    ~WarpSettingsDialog();

private slots:
    void on_buttonBox_accepted();

signals:
    void wrap_triggered(warpparams x, warpparams y);

private:
    Ui::WarpSettingsDialog *ui;
};

#endif // WARPSETTINGSDIALOG_H
