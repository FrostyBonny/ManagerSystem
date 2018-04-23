#ifndef FINDPASSWORD_H
#define FINDPASSWORD_H

#include <QDialog>
#include <QLabel>
#include "stdafx.h"

namespace Ui {
class FindPassword;
}

class FindPassword : public QDialog
{
    Q_OBJECT

public:
    explicit FindPassword(QWidget *parent = 0);
    ~FindPassword();

private slots:
    void on_pushButton_find_clicked();



private:
    Ui::FindPassword *ui;
};

#endif // FINDPASSWORD_H
