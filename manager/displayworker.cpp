#include "displayworker.h"
#include "ui_displayworker.h"

DisplayWorker::DisplayWorker(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DisplayWorker)
{
    ui->setupUi(this);
    setWindowTitle("展示员工");
    QObject::connect(ui->pushButton_back,SIGNAL(clicked(bool)),this,SLOT(close()));

    //对tabelview的初始化
    model->setColumnCount(6);
    model->setHeaderData(0,Qt::Horizontal,QString::fromStdString("ID"));
    model->setHeaderData(1,Qt::Horizontal,QString::fromStdString("工资"));
    model->setHeaderData(2,Qt::Horizontal,QString::fromStdString("名字"));
    model->setHeaderData(3,Qt::Horizontal,QString::fromStdString("部门"));
    model->setHeaderData(4,Qt::Horizontal,QString::fromStdString("职位"));
    model->setHeaderData(5,Qt::Horizontal,QString::fromStdString("地址"));

    ui->tableView->setModel(model);

    for(int i = 0;i < 5;i++)
    {
        ui->tableView->setColumnWidth(i,70);
    }
    ui->tableView->setColumnWidth(5,110);

    this->updata();
}

DisplayWorker::~DisplayWorker()
{
    delete ui;
}

bool cmp(const worker *a,const worker *b)
{
    return a->m_salary.FinalSalary < b->m_salary.FinalSalary;
}

void DisplayWorker::on_pushButton_sort_clicked()
{
    //排序
    sort(Resources::m_worker.begin(), Resources::m_worker.end(), cmp);
    updata();

    //提示信息
    QMessageBox box(QMessageBox::Information,"消息","排序完成！");
    box.setStandardButtons (QMessageBox::Ok);
    box.setButtonText (QMessageBox::Ok,QString("确 定"));
    box.exec ();
}

void DisplayWorker::on_pushButton_delet_clicked()
{
    int DeletWorker = -1;

    //获取信息并遍历查询
    string ID = ui->lineEdit_delet->text().trimmed().toStdString();
    for(int i = 0;i < (int)Resources::m_worker.size();i++)
    {
        if(Resources::m_worker[i]->ID == ID)
        {
            DeletWorker = i;
            break;
        }
    }

    //提示信息，并且更新ID信息
    if(DeletWorker != -1)
    {
        Resources::m_worker.erase(Resources::m_worker.begin() + DeletWorker);

        updata();
        QMessageBox box(QMessageBox::Information,"消息","删除成功！");
        box.setStandardButtons (QMessageBox::Ok);
        box.setButtonText (QMessageBox::Ok,QString("确 定"));
        box.exec ();

    }
    else
        QMessageBox::critical(this ,
        "错误" , "没有该员工",
        QMessageBox::Ok, 0, 0);

}

//更新数据
void DisplayWorker::updata()
{
    model->removeRows(0,model->rowCount());
    for(int i = 0;i < (int)Resources::m_worker.size();i++)
    {
        model->setItem(i,0,new QStandardItem(QString::fromStdString(Resources::m_worker[i]->ID)));
        model->item(i,0)->setTextAlignment(Qt::AlignCenter);
        model->setItem(i,1,new QStandardItem(QString::number(Resources::m_worker[i]->m_salary.FinalSalary,10,2)));
        model->setItem(i,2,new QStandardItem(QString::fromStdString(Resources::m_worker[i]->m_name)));
        model->setItem(i,3,new QStandardItem(QString::fromStdString(Resources::m_worker[i]->m_department)));
        model->setItem(i,4,new QStandardItem(QString::fromStdString(Resources::m_worker[i]->m_position)));
        model->setItem(i,5,new QStandardItem(QString::fromStdString(Resources::m_worker[i]->m_adress)));

    }
}


void DisplayWorker::on_pushButton_back_clicked()
{
    //更新ID信息
    for(int i = 0;i < (int)Resources::m_worker.size();i++)
    {
        Resources::m_worker[i]->ID = to_string(i + 1);
    }
}
