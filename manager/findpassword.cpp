#include "findpassword.h"
#include "ui_findpassword.h"

FindPassword::FindPassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindPassword)
{
    ui->setupUi(this);
    setWindowTitle("找回密码");
    QObject::connect(ui->pushButton_back,SIGNAL(clicked(bool)),this,SLOT(close()));
}

FindPassword::~FindPassword()
{
    delete ui;
}

void FindPassword::on_pushButton_find_clicked()
{
    //提示信息
    if(!ui->radioButton_manager->isChecked()&&!ui->radioButton_worker->isChecked())
    {
        QMessageBox box(QMessageBox::Warning,"警告","请选择一个身份！");
        box.setStandardButtons (QMessageBox::Ok);
        box.setButtonText (QMessageBox::Ok,QString("确 定"));
        box.exec ();
        return;
    }

    if(!ui->lineEdit->text().trimmed().isEmpty())
    {
        string accout = ui->lineEdit->text().toStdString();

        //判断输入的为哪个身份并且进行对应的操作
        if(ui->radioButton_worker->isChecked())
        {
            for(int i = 0;i < (int)Resources::m_worker.size();i++)
            {
                if(Resources::m_worker[i]->m_accout == accout)
                {
                    QString s = QString("你的密码为：%1").arg(QString::fromStdString(Resources::m_worker[i]->m_password));
                    QMessageBox box(QMessageBox::Information,"提示",s);
                    box.setStandardButtons (QMessageBox::Ok);
                    box.setButtonText (QMessageBox::Ok,QString("确 定"));
                    box.exec ();

                    return;
                }
            }
        }

        if(ui->radioButton_manager->isChecked())
        {
            for(int i = 0;i < (int)Resources::m_manager.size();i++)
            {
                if(Resources::m_manager[i]->m_accout == accout)
                {
                    //ui->label_password->setText( QString::fromStdString(Resources::m_manager[i]->m_password));
                    QString s = QString("你的密码为：%1").arg(QString::fromStdString(Resources::m_manager[i]->m_password));
                    QMessageBox box(QMessageBox::Information,"提示",s);
                    box.setStandardButtons (QMessageBox::Ok);
                    box.setButtonText (QMessageBox::Ok,QString("确 定"));
                    box.exec ();
                    return;
                }
            }
        }

        QMessageBox::critical(this ,
        "错误" , "没有该账户！",
        QMessageBox::Ok, 0, 0);
    }
    else
        QMessageBox::critical(this ,
        "错误" , "请输入账号",
        QMessageBox::Ok, 0, 0);
}
