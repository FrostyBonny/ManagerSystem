#ifndef DATARECOVERY_H
#define DATARECOVERY_H

#include <QDialog>
#include "stdafx.h"

namespace Ui {
class DataRecovery;
}

class DataRecovery : public QDialog
{
    Q_OBJECT

public:
    explicit DataRecovery(QWidget *parent = 0);
    ~DataRecovery();

private slots:
    void on_pushButton_choosefile_clicked();

    void on_pushButton_recover_clicked();

    void on_pushButton_back_clicked();

private:
    Ui::DataRecovery *ui;
    QString filename;
};

#endif // DATARECOVERY_H
