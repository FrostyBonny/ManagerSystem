#ifndef WORKERMODIFYDIALOG_H
#define WORKERMODIFYDIALOG_H

#include <QDialog>
#include "stdafx.h"

namespace Ui {
class WorkerModifyDialog;
}

class WorkerModifyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WorkerModifyDialog(QWidget *parent = 0);
    ~WorkerModifyDialog();

private slots:
    void on_pushButton_Modify_clicked();

private:
    Ui::WorkerModifyDialog *ui;
};

#endif // WORKERMODIFYDIALOG_H
