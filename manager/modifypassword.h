#ifndef MODIFYPASSWORD_H
#define MODIFYPASSWORD_H

#include <QDialog>
#include "stdafx.h"

namespace Ui {
class ModifyPassword;
}

class ModifyPassword : public QDialog
{
    Q_OBJECT

public:
    explicit ModifyPassword(QWidget *parent = 0);
    ~ModifyPassword();

private slots:
    void on_pushButto_modify_clicked();

private:
    Ui::ModifyPassword *ui;
};

#endif // MODIFYPASSWORD_H
