#ifndef CHECKWAGES_H
#define CHECKWAGES_H

#include <QDialog>
#include "stdafx.h"

namespace Ui {
class CheckWages;
}

class CheckWages : public QDialog
{
    Q_OBJECT

public:
    explicit CheckWages(QWidget *parent = 0);
    ~CheckWages();

private slots:
    void on_pushButton_find_clicked();

private:
    Ui::CheckWages *ui;
};

#endif // CHECKWAGES_H
