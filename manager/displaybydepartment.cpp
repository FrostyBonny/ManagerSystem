#include "displaybydepartment.h"
#include "ui_displaybydepartment.h"

DisplayByDepartment::DisplayByDepartment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DisplayByDepartment)
{
    ui->setupUi(this);
    setWindowTitle("部门展示");
    QObject::connect(ui->pushButton_back,SIGNAL(clicked(bool)),this,SLOT(close()));

    //初始化tabelview
    model->setColumnCount(5);
    model->setHeaderData(0,Qt::Horizontal,QString::fromStdString("ID"));
    model->setHeaderData(1,Qt::Horizontal,QString::fromStdString("名字"));
    model->setHeaderData(2,Qt::Horizontal,QString::fromStdString("部门"));
    model->setHeaderData(3,Qt::Horizontal,QString::fromStdString("职位"));
    model->setHeaderData(4,Qt::Horizontal,QString::fromStdString("地址"));

    ui->tableView->setModel(model);

    for(int i = 0;i < 4;i++)
    {
        ui->tableView->setColumnWidth(i,70);
    }
    ui->tableView->setColumnWidth(4,110);

    //更新tabelview的值
    for(int i = 0;i < (int)Resources::m_worker.size();i++)
    {
        model->setItem(i,0,new QStandardItem(QString::fromStdString(Resources::m_worker[i]->ID)));
        model->item(i,0)->setTextAlignment(Qt::AlignCenter);
        model->setItem(i,1,new QStandardItem(QString::fromStdString(Resources::m_worker[i]->m_name)));
        model->setItem(i,2,new QStandardItem(QString::fromStdString(Resources::m_worker[i]->m_department)));
        model->setItem(i,3,new QStandardItem(QString::fromStdString(Resources::m_worker[i]->m_position)));
        model->setItem(i,4,new QStandardItem(QString::fromStdString(Resources::m_worker[i]->m_adress)));
    }
}

DisplayByDepartment::~DisplayByDepartment()
{
    delete ui;
}

void DisplayByDepartment::on_pushButton_search_clicked()
{
    int whichline = 0;
    int ishave = 0;
    string department = ui->lineEdit->text().trimmed().toStdString();

    //清除所有的tabel信息
    model->removeRows(0,model->rowCount());

    //根据录入框的信息更新tabelview信息
    for(int i = 0;i < (int)Resources::m_worker.size();i++)
    {
        if(Resources::m_worker[i]->m_department == department)
        {
            ishave = 1;
            model->setItem(whichline,0,new QStandardItem(QString::fromStdString(Resources::m_worker[i]->ID)));
            model->item(whichline,0)->setTextAlignment(Qt::AlignCenter);
            model->setItem(whichline,1,new QStandardItem(QString::fromStdString(Resources::m_worker[i]->m_name)));
            model->setItem(whichline,2,new QStandardItem(QString::fromStdString(Resources::m_worker[i]->m_department)));
            model->setItem(whichline,3,new QStandardItem(QString::fromStdString(Resources::m_worker[i]->m_position)));
            model->setItem(whichline++,4,new QStandardItem(QString::fromStdString(Resources::m_worker[i]->m_adress)));
        }
    }

    //输出提示信息
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
