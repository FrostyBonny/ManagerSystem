#ifndef REGISTER_H
#define REGISTER_H
#include "stdafx.h"
#include <QDialog>

namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = 0);
    ~Register();

private slots:
    void on_lineEdit_ConfirmPassword_editingFinished();

    void on_pushButton_back_clicked();

    void on_pushButton_register_clicked();

private:
    Ui::Register *ui;
};

#endif // REGISTER_H
