#ifndef ADDWORKER_H
#define ADDWORKER_H

#include <QDialog>
#include "stdafx.h"

namespace Ui {
class AddWorker;
}

class AddWorker : public QDialog
{
    Q_OBJECT

public:
    explicit AddWorker(QWidget *parent = 0);
    ~AddWorker();

private slots:
    void on_pushButton_add_clicked();

private:
    Ui::AddWorker *ui;
};

#endif // ADDWORKER_H
