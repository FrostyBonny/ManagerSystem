#ifndef DISPLAYWORKER_H
#define DISPLAYWORKER_H

#include <QDialog>
#include <QStandardItemModel>
#include "stdafx.h"

namespace Ui {
class DisplayWorker;
}

class DisplayWorker : public QDialog
{
    Q_OBJECT

public:
    explicit DisplayWorker(QWidget *parent = 0);
    ~DisplayWorker();

private slots:

    void updata();

    void on_pushButton_sort_clicked();

    void on_pushButton_delet_clicked();


    void on_pushButton_back_clicked();

private:
    Ui::DisplayWorker *ui;
    QStandardItemModel  *model = new QStandardItemModel();
};

#endif // DISPLAYWORKER_H
