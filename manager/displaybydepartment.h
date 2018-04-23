#ifndef DISPLAYBYDEPARTMENT_H
#define DISPLAYBYDEPARTMENT_H

#include <QDialog>
#include <QStandardItemModel>
#include "stdafx.h"

namespace Ui {
class DisplayByDepartment;
}

class DisplayByDepartment : public QDialog
{
    Q_OBJECT

public:
    explicit DisplayByDepartment(QWidget *parent = 0);
    ~DisplayByDepartment();

private slots:
    void on_pushButton_search_clicked();

private:
    Ui::DisplayByDepartment *ui;
    QStandardItemModel  *model = new QStandardItemModel();
};

#endif // DISPLAYBYDEPARTMENT_H
