#include "analys.h"
#include "ui_analys.h"

Analys::Analys(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Analys)
{
    ui->setupUi(this);
    setWindowTitle("数据分析");
    QObject::connect(ui->pushButton_back,SIGNAL(clicked(bool)),this,SLOT(close()));

    //设置tableview的参数
    model->setColumnCount(5);
    model->setHeaderData(0,Qt::Horizontal,QString::fromStdString("ID"));
    model->setHeaderData(1,Qt::Horizontal,QString::fromStdString("名字"));
    model->setHeaderData(2,Qt::Horizontal,QString::fromStdString("部门"));
    model->setHeaderData(3,Qt::Horizontal,QString::fromStdString("职位"));
    model->setHeaderData(4,Qt::Horizontal,QString::fromStdString("地址"));

    //关联model
    ui->tableView->setModel(model);

    //设置宽度
    for(int i = 0;i < 4;i++)
    {
        ui->tableView->setColumnWidth(i,70);
    }
    ui->tableView->setColumnWidth(4,110);

    //计算工资总和平均工资
    double sum = 0;
    double avg= 0;
    for(int i = 0;i < (int)Resources::m_worker.size();i++)
    {
        sum += Resources::m_worker[i]->m_salary.FinalSalary;
        model->setItem(i,0,new QStandardItem(QString::fromStdString(Resources::m_worker[i]->ID)));
        model->item(i,0)->setTextAlignment(Qt::AlignCenter);
        model->setItem(i,1,new QStandardItem(QString::fromStdString(Resources::m_worker[i]->m_name)));
        model->setItem(i,2,new QStandardItem(QString::fromStdString(Resources::m_worker[i]->m_department)));
        model->setItem(i,3,new QStandardItem(QString::fromStdString(Resources::m_worker[i]->m_position)));
        model->setItem(i,4,new QStandardItem(QString::fromStdString(Resources::m_worker[i]->m_adress)));
    }
    avg = sum/(double)Resources::m_worker.size();

    //放入文本框
    ui->lineEdit_sum->setText(QString::number(sum,10,2));
    ui->lineEdit_avg->setText(QString::number(avg,10,2));
}

Analys::~Analys()
{
    delete ui;
}

//分析按钮事件
void Analys::on_pushButton_2_clicked()
{
    int ishave = 0;
    string inf = ui->lineEdit->text().trimmed().toStdString();
    if(!ui->radioButton_department->isChecked() && !ui->radioButton_position->isChecked())
    {
        QMessageBox::critical(this ,
        "错误" , "请选择部门或者职位！",
        QMessageBox::Ok, 0, 0);
        return;
    }


    if(ui->radioButton_department->isChecked())
    {
        double sum = 0;
        double avg = 0;
        int whichline = 0;
        model->removeRows(0,model->rowCount());

        //如果职位查询可行，更新tabel
        for(int i = 0;i < (int)Resources::m_worker.size();i++)
        {
            if(Resources::m_worker[i]->m_department == inf)
            {
                ishave = 1;
                model->setItem(whichline,0,new QStandardItem(QString::fromStdString(Resources::m_worker[i]->ID)));
                model->item(whichline,0)->setTextAlignment(Qt::AlignCenter);
                model->setItem(whichline,1,new QStandardItem(QString::fromStdString(Resources::m_worker[i]->m_name)));
                model->setItem(whichline,2,new QStandardItem(QString::fromStdString(Resources::m_worker[i]->m_department)));
                model->setItem(whichline,3,new QStandardItem(QString::fromStdString(Resources::m_worker[i]->m_position)));
                model->setItem(whichline++,4,new QStandardItem(QString::fromStdString(Resources::m_worker[i]->m_adress)));
                sum += Resources::m_worker[i]->m_salary.FinalSalary;
            }
        }
        ui->lineEdit_sum->setText(QString::fromStdString(to_string(sum)));
        ui->lineEdit_avg->setText(QString::fromStdString(to_string(avg)));

        if(ishave == 1)
        {
            QMessageBox box(QMessageBox::Information,"消息","查询成功！");
            box.setStandardButtons (QMessageBox::Ok);
            box.setButtonText (QMessageBox::Ok,QString("确 定"));
            box.exec ();
        }
        else
            QMessageBox::critical(this ,
            "错误" , "没有该部门人员",
            QMessageBox::Ok, 0, 0);
    }

    //如果部门查询可行，更新tabel
    if(ui->radioButton_position->isChecked())
    {
        double sum = 0;
        double avg = 0;
        int whichline = 0;
        model->removeRows(0,model->rowCount());
        for(int i = 0;i < (int)Resources::m_worker.size();i++)
        {
            if(Resources::m_worker[i]->m_position == inf)
            {
                ishave = 1;
                model->setItem(whichline,0,new QStandardItem(QString::fromStdString(Resources::m_worker[i]->ID)));
                model->item(whichline,0)->setTextAlignment(Qt::AlignCenter);
                model->setItem(whichline,1,new QStandardItem(QString::fromStdString(Resources::m_worker[i]->m_name)));
                model->setItem(whichline,2,new QStandardItem(QString::fromStdString(Resources::m_worker[i]->m_department)));
                model->setItem(whichline,3,new QStandardItem(QString::fromStdString(Resources::m_worker[i]->m_position)));
                model->setItem(whichline++,4,new QStandardItem(QString::fromStdString(Resources::m_worker[i]->m_adress)));
                sum += Resources::m_worker[i]->m_salary.FinalSalary;
            }
        }
        ui->lineEdit_sum->setText(QString::number(sum,10,2));
        ui->lineEdit_avg->setText(QString::number(avg,10,2));

        //提示框信息
        if(ishave == 1)
        {
            QMessageBox box(QMessageBox::Information,"消息","查询成功！");
            box.setStandardButtons (QMessageBox::Ok);
            box.setButtonText (QMessageBox::Ok,QString("确 定"));
            box.exec ();
        }
        else
            QMessageBox::critical(this ,
            "错误" , "没有该职位人员",
            QMessageBox::Ok, 0, 0);
    }


}
