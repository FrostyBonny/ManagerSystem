#include "modifypassword.h"
#include "ui_modifypassword.h"

ModifyPassword::ModifyPassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifyPassword)
{
    ui->setupUi(this);
    setWindowTitle("修改密码");
    QObject::connect(ui->pushButton_back,SIGNAL(clicked(bool)),this,SLOT(close()));
}

ModifyPassword::~ModifyPassword()
{
    delete ui;
}

void ModifyPassword::on_pushButto_modify_clicked()
{
    //获取信息
    string oldpassword = ui->lineEdit_password->text().toStdString();
    string newpassword = ui->lineEdit_newpassword->text().toStdString();
    //对比操作
    if(oldpassword != Resources::m_manager[Resources::whichmanager]->m_password)
    {
        QMessageBox::critical(this ,
        "错误" , "原密码错误",
        QMessageBox::Ok, 0, 0);
        return;
    }
    else
    {
        Resources::m_manager[Resources::whichmanager]->modifypassword(newpassword);
        QMessageBox box(QMessageBox::Information,"消息","修改成功！");
        box.setStandardButtons (QMessageBox::Ok);
        box.setButtonText (QMessageBox::Ok,QString("确 定"));
        box.exec ();
    }
}
