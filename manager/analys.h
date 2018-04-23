#ifndef ANALYS_H
#define ANALYS_H

#include <QDialog>
#include <QStandardItemModel>
#include "stdafx.h"

namespace Ui {
class Analys;
}

class Analys : public QDialog
{
    Q_OBJECT

public:
    explicit Analys(QWidget *parent = 0);
    ~Analys();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::Analys *ui;
    QStandardItemModel  *model = new QStandardItemModel();
};

#endif // ANALYS_H
