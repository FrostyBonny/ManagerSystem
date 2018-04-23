#include "workerdialog.h"
#include "ui_workerdialog.h"

WorkerDialog::WorkerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WorkerDialog)
{
    ui->setupUi(this);
    setWindowTitle("员工");
    //QObject::connect(ui->pushButton_back,SIGNAL(clicked(bool)),this,SLOT(close()));
}

WorkerDialog::~WorkerDialog()
{
    delete ui;
}

void WorkerDialog::on_pushButton_CheckWages_clicked()
{

    CheckWages *chewages1 = new CheckWages();

    this->hide();
    chewages1->show();
    chewages1->exec();
    this->show();
}

void WorkerDialog::on_pushButton_back_clicked()
{
    //同步信息
    fstream file;
    file.open("E:\\doc\\worker.txt", ios::out);
    if (!file.is_open())
    {
        qDebug() << "open file fail" << endl;
    }
    else
    {

        for (int i = 0; i < (int)Resources::m_worker.size(); i++)
        {
            //file << ID << " " << accout << " " << password << " " << name
            //	<< " " << department << " " << position << " " << address;
            file << Resources::m_worker[i]->ID << " " << Resources::m_worker[i]->m_accout << " " << Resources::m_worker[i]->m_password << " "
                 << Resources::m_worker[i]->m_name << " " << Resources::m_worker[i]->m_department << " " << Resources::m_worker[i]->m_position << " "
                 << Resources::m_worker[i]->m_adress << endl;
        }

        file.close();
    }

    this->close();
    this->parentWidget()->show();
}

void WorkerDialog::on_pushButton_ModifyInf_clicked()
{
    this->hide();
    WorkerModifyDialog1->show();
    WorkerModifyDialog1->exec();
    this->show();
}
