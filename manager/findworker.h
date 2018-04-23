#ifndef FINDWORKER_H
#define FINDWORKER_H

#include <QDialog>
#include "stdafx.h"

namespace Ui {
class findworker;
}

class findworker : public QDialog
{
    Q_OBJECT

public:
    explicit findworker(QWidget *parent = 0);
    ~findworker();

private slots:
    void on_pushButton_find_clicked();

    void on_pushButton_modify_clicked();

private:
    Ui::findworker *ui;
    int findwho = -1;
};

#endif // FINDWORKER_H
