#include "register.h"
#include "ui_register.h"
#include "macro.h"
#include <QString>

Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    setWindowTitle("注册");
    QLabel *warning;
    warning = ui->label_9;
    warning->setVisible(false);
}

Register::~Register()
{
    delete ui;
}

void Register::on_lineEdit_ConfirmPassword_editingFinished()
{
    //判断不一致是否出现
    QLabel *warning;
    warning = ui->label_9;

    string password = ui->lineEdit_Passwword->text().toStdString();
    string passwordagain = ui->lineEdit_ConfirmPassword->text().toStdString();
    if(password != passwordagain)
    {
        warning->setVisible(true);
    }
    else
    {
        warning->setVisible(false);
    }
}


void Register::on_pushButton_back_clicked()
{
    this->close();
}

void Register::on_pushButton_register_clicked()
{
    //获取信息
    int flag_finish = 1;
    vector<string> inf;
    if(ui->radioButton_Worker->isChecked())
    {
       string ID;
       ID = to_string(Resources::m_worker.size() + 1);
       inf.push_back(ID);
       string accout = ui->lineEdit_accout->text().trimmed().toStdString();
       inf.push_back(accout);
       string password = ui->lineEdit_Passwword->text().trimmed().toStdString();
       inf.push_back(password);
       string name = ui->lineEdit_name->text().trimmed().toStdString();
       inf.push_back(name);
       string department = ui->lineEdit_departmen->text().trimmed().toStdString();
       inf.push_back(department);
       string position = ui->lineEdit_position->text().trimmed().toStdString();
       inf.push_back(position);
       string address = ui->lineEdit_address->text().trimmed().toStdString();
       inf.push_back(address);

       if(ui->lineEdit_accout->text().trimmed().isEmpty())
       {
           QMessageBox::critical(this ,
           "错误" , "请输入账户",
           QMessageBox::Ok, 0, 0);
           flag_finish = 0;
       }

       else if(ui->lineEdit_Passwword->text().trimmed().isEmpty())
       {
           QMessageBox::critical(this ,
           "错误" , "请输入密码",
           QMessageBox::Ok, 0, 0);
           flag_finish = 0;
       }

       else if(ui->lineEdit_ConfirmPassword->text().trimmed().isEmpty())
       {
           QMessageBox::critical(this ,
           "错误" , "请输入确认密码",
           QMessageBox::Ok, 0, 0);
           flag_finish = 0;
       }

       else if(ui->lineEdit_name->text().trimmed().isEmpty())
       {
           QMessageBox::critical(this ,
           "错误" , "请输入名字",
           QMessageBox::Ok, 0, 0);
           flag_finish = 0;
       }

       else if(ui->lineEdit_departmen->text().trimmed().isEmpty())
       {
           QMessageBox::critical(this ,
           "错误" , "请输入部门",
           QMessageBox::Ok, 0, 0);
       }

       else if(ui->lineEdit_position->text().trimmed().isEmpty())
       {
           QMessageBox::critical(this ,
           "错误" , "请输入岗位",
           QMessageBox::Ok, 0, 0);
           flag_finish = 0;
       }

       else if(ui->lineEdit_address->text().trimmed().isEmpty())
       {
           QMessageBox::critical(this ,
           "错误" , "请输入地址",
           QMessageBox::Ok, 0, 0);
           flag_finish = 0;
       }

       else if(!ui->label_9->isHidden())
       {
           QMessageBox::critical(this ,
           "错误" , "两次密码不一致",
           QMessageBox::Ok, 0, 0);
           flag_finish = 0;
       }

       //判断是否可行
       if(flag_finish == 1)
       {

           worker *tworker = new worker(inf);

           for(int i = 0;i < (int)Resources::m_worker.size();i++)
           {
               if(Resources::m_worker[i]->m_accout == tworker->m_accout)
               {
                   QMessageBox::critical(this ,
                   "错误" , "已经存在该账户",
                   QMessageBox::Ok, 0, 0);
                   return;
               }
           }
           Resources::m_worker.push_back(tworker);

           fstream file;
		   file.open(WORKER_PATH, ios::app | ios::out);
           if (!file.is_open())
           {
               qDebug() << "open worker txt file fail" << endl;
           }
           else
           {
               file << ID << " " << accout << " " << password << " " << name
                    << " " << department << " " << position << " " << address << endl;
               file.close();
           }

           QMessageBox box(QMessageBox::Information,"消息","注册成功！");
           box.setStandardButtons (QMessageBox::Ok);
           box.setButtonText (QMessageBox::Ok,QString("确 定"));
           box.exec ();

       }

    }

    //管理员选项按下时操作
    if(ui->radioButton_manager->isChecked())
    {
       // 获取信息
        string ID;
        ID= to_string(Resources::m_manager.size() + 1);
        inf.push_back(ID);
        string accout = ui->lineEdit_accout->text().trimmed().toStdString();
        inf.push_back(accout);
        string password = ui->lineEdit_Passwword->text().trimmed().toStdString();
        inf.push_back(password);
        string name = ui->lineEdit_name->text().trimmed().toStdString();
        inf.push_back(name);
        string department = ui->lineEdit_departmen->text().trimmed().toStdString();
        inf.push_back(department);
        string position = ui->lineEdit_position->text().trimmed().toStdString();
        inf.push_back(position);
        string address = ui->lineEdit_address->text().trimmed().toStdString();
        inf.push_back(address);

        //提示信息
        if(ui->lineEdit_accout->text().trimmed().isEmpty())
        {
            QMessageBox::critical(this ,
            "错误" , "请输入账户",
            QMessageBox::Ok, 0, 0);
            flag_finish = 0;
        }

        else if(ui->lineEdit_Passwword->text().trimmed().isEmpty())
        {
            QMessageBox::critical(this ,
            "错误" , "请输入密码",
            QMessageBox::Ok, 0, 0);
            flag_finish = 0;
        }

        else if(ui->lineEdit_ConfirmPassword->text().trimmed().isEmpty())
        {
            QMessageBox::critical(this ,
            "错误" , "请输入确认密码",
            QMessageBox::Ok, 0, 0);
            flag_finish = 0;
        }

        else if(ui->lineEdit_name->text().trimmed().isEmpty())
        {
            QMessageBox::critical(this ,
            "错误" , "请输入名字",
            QMessageBox::Ok, 0, 0);
            flag_finish = 0;
        }

        else if(ui->lineEdit_departmen->text().trimmed().isEmpty())
        {
            QMessageBox::critical(this ,
            "错误" , "请输入部门",
            QMessageBox::Ok, 0, 0);
        }

        else if(ui->lineEdit_position->text().trimmed().isEmpty())
        {
            QMessageBox::critical(this ,
            "错误" , "请输入岗位",
            QMessageBox::Ok, 0, 0);
            flag_finish = 0;
        }

        else if(ui->lineEdit_address->text().trimmed().isEmpty())
        {
            QMessageBox::critical(this ,
            "错误" , "请输入地址",
            QMessageBox::Ok, 0, 0);
            flag_finish = 0;
        }

        else if(!ui->label_9->isHidden())
        {
            QMessageBox::critical(this ,
            "错误" , "两次密码不一致",
            QMessageBox::Ok, 0, 0);
            flag_finish = 0;
        }

        if(flag_finish == 1)
        {

            manager *tmanager = new manager(inf);

            //查重
            for(int i = 0;i < (int)Resources::m_manager.size();i++)
            {
                if(Resources::m_manager[i]->m_accout == tmanager->m_accout)
                {
                    QMessageBox::critical(this ,
                    "错误" , "已经存在该账户",
                    QMessageBox::Ok, 0, 0);
                    return;
                }
            }

            Resources::m_manager.push_back(tmanager);

            //文件录入
            fstream file;
			file.open(MANAGER_PATH, ios::app | ios::out);
            if (!file.is_open())
            {
                qDebug() << "open manager txt file fail" << endl;

            }
            else
            {
                file << ID << " " << accout << " " << password << endl;
                file.close();
            }

            QMessageBox box(QMessageBox::Information,"消息","注册成功！");
            box.setStandardButtons (QMessageBox::Ok);
            box.setButtonText (QMessageBox::Ok,QString("确 定"));
            box.exec ();
        }
    }

    if(!ui->radioButton_manager->isChecked()&&!ui->radioButton_Worker->isChecked())
    {
        QMessageBox box(QMessageBox::Warning,"警告","请选择一个身份！");
        box.setStandardButtons (QMessageBox::Ok);
        box.setButtonText (QMessageBox::Ok,QString("确 定"));
        box.exec ();
    }
}
