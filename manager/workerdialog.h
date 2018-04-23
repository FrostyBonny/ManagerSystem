#ifndef WORKERDIALOG_H
#define WORKERDIALOG_H

#include <QDialog>
#include "stdafx.h"
#include "checkwages.h"
#include "workermodifydialog.h"

namespace Ui {
class WorkerDialog;
}

class WorkerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WorkerDialog(QWidget *parent = 0);
    ~WorkerDialog();

private slots:
    void on_pushButton_CheckWages_clicked();

    void on_pushButton_back_clicked();

    void on_pushButton_ModifyInf_clicked();

private:
    Ui::WorkerDialog *ui;

    WorkerModifyDialog *WorkerModifyDialog1 = new WorkerModifyDialog();
};

#endif // WORKERDIALOG_H
