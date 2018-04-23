#include "findworker.h"
#include "ui_findworker.h"

findworker::findworker(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::findworker)
{
    ui->setupUi(this);
    setWindowTitle("查询员工");
    QObject::connect(ui->pushButton_back,SIGNAL(clicked(bool)),this,SLOT(close()));
}

findworker::~findworker()
{
    delete ui;
}

void findworker::on_pushButton_find_clicked()
{

    string findname = ui->lineEdit_findname->text().trimmed().toStdString();

    //遍历查找并且记录下查询员工的在数据中所在的位置
    for(int i = 0;i < (int)Resources::m_worker.size();i++)
    {
        if(Resources::m_worker[i]->m_name == findname)
        {
            findwho = i;
        }
    }

    //如果查找到了，更新信息
    if(findwho != -1)
    {
        ui->lineEdit_ID->setText(QString::fromStdString(Resources::m_worker[findwho]->ID));
        ui->lineEdit_name->setText(QString::fromStdString(Resources::m_worker[findwho]->m_name));
        ui->lineEdit_department->setText(QString::fromStdString(Resources::m_worker[findwho]->m_department));
        ui->lineEdit_position->setText(QString::fromStdString(Resources::m_worker[findwho]->m_position));
        ui->lineEdit_address->setText(QString::fromStdString(Resources::m_worker[findwho]->m_adress));
        ui->lineEdit_wages->setText(QString::number( Resources::m_worker[findwho]->m_salary.FinalSalary,10,2));

        ui->lineEdit_levelwages->setText(QString::number(Resources::m_worker[findwho]->m_salary.LevelSalary,10,2));
        ui->lineEdit_positionwages->setText(QString::number(Resources::m_worker[findwho]->m_salary.PostSalary,10,2));
        ui->lineEdit_bouns->setText(QString::number(Resources::m_worker[findwho]->m_salary.Bonus,10,2));
        ui->lineEdit_deduction->setText(QString::number(Resources::m_worker[findwho]->m_salary.Deduction,10,2));
        ui->lineEdit_WithHoldingTax->setText(QString::number(Resources::m_worker[findwho]->m_salary.WithHoldingTax,10,2));
        ui->lineEdit_fanalwages->setText(QString::number(Resources::m_worker[findwho]->m_salary.FinalSalary,10,2));

        QMessageBox box(QMessageBox::Information,"消息","查询成功！");
        box.setStandardButtons (QMessageBox::Ok);
        box.setButtonText (QMessageBox::Ok,QString("确 定"));
        box.exec ();

        if(Resources::m_worker[findwho]->ConfirmInf() == 1)
        {
            QMessageBox box(QMessageBox::Information,"提示","员工职位信息有误，工资信息错误。\n建议修改信息");
            box.setStandardButtons (QMessageBox::Ok);
            box.setButtonText (QMessageBox::Ok,QString("确 定"));
            box.exec ();
        }
        if(Resources::m_worker[findwho]->ConfirmInf() == 2)
        {
            QMessageBox box(QMessageBox::Information,"提示","员工部门信息有误，工资信息错误。\n建议修改信息");
            box.setStandardButtons (QMessageBox::Ok);
            box.setButtonText (QMessageBox::Ok,QString("确 定"));
            box.exec ();
        }
    }
    else
        QMessageBox::critical(this ,
        "错误" , "没有该员工！",
        QMessageBox::Ok, 0, 0);
}

void findworker::on_pushButton_modify_clicked()
{
    //读取lineEdit中的数据
    vector<string> v;
    string ID = ui->lineEdit_ID->text().toStdString();
    v.push_back(ID);
    string name = ui->lineEdit_name->text().toStdString();
    v.push_back(name);
    string department = ui->lineEdit_department->text().toStdString();
    v.push_back(department);
    string position = ui->lineEdit_position->text().toStdString();
    v.push_back(position);
    string address = ui->lineEdit_address->text().toStdString();
    v.push_back(address);

    string bouns = ui->lineEdit_bouns->text().toStdString();
    v.push_back(bouns);
    string deduction = ui->lineEdit_deduction->text().toStdString();
    v.push_back(deduction);

    //如果查询到调用worker 的函数修改信息
    if(findwho != -1)
    {
        Resources::m_worker[findwho]->ModifyByManager(v);

        QMessageBox box(QMessageBox::Information,"消息","修改成功！");
        box.setStandardButtons (QMessageBox::Ok);
        box.setButtonText (QMessageBox::Ok,QString("确 定"));
        box.exec ();
    }

    else
        QMessageBox::critical(this ,
        "错误" , "请输入查询的员工",
        QMessageBox::Ok, 0, 0);

}
