#include "addworker.h"
#include "ui_addworker.h"

AddWorker::AddWorker(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddWorker)
{
    ui->setupUi(this);
    setWindowTitle("添加员工");//设置窗口名字
    QObject::connect(ui->pushButton_back,SIGNAL(clicked(bool)),this,SLOT(close()));//点击与关闭信号槽关联
}

AddWorker::~AddWorker()
{
    delete ui;
}

void AddWorker::on_pushButton_add_clicked()
{
    //收集框中的信息
    int flag_finish = 1;//标记是否可以add
    vector<string> inf;//string的vector信息
    string ID;
    //获取值，并且存入inf
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

    //进行输入判断
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

    //如果可行，加入员工
    if(flag_finish == 1)
    {

        worker *tworker = new worker(inf);//新建员工

        //遍历查重
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

        //文件写入
        fstream file;
        file.open("E:\\doc\\worker.txt", ios::app | ios::out);
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

        QMessageBox box(QMessageBox::Information,"消息","添加成功！");
        box.setStandardButtons (QMessageBox::Ok);
        box.setButtonText (QMessageBox::Ok,QString("确 定"));
        box.exec ();

    }
}
