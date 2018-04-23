#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "register.h"
#include "findpassword.h"
#include "workerdialog.h"
#include "stdafx.h"
#include "managerdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_Register_clicked();

    void on_pushButton_FindPassword_clicked();

    void on_pushButton_Login_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Register *register1 = new Register();
    FindPassword *findpassword1 = new FindPassword();

};

#endif // MAINWINDOW_H
