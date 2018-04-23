#ifndef DATABACKUP_H
#define DATABACKUP_H

#include <QDialog>
#include "stdafx.h"

namespace Ui {
class DataBackup;
}

class DataBackup : public QDialog
{
    Q_OBJECT

public:
    explicit DataBackup(QWidget *parent = 0);
    ~DataBackup();

private slots:
    void on_pushButton_backup_clicked();

    void on_pushButton_choosefile_clicked();

private:
    Ui::DataBackup *ui;
    QString filename;
};

#endif // DATABACKUP_H
