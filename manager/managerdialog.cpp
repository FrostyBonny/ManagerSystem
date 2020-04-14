#include "managerdialog.h"
#include "ui_managerdialog.h"
#include "macro.h"

ManagerDialog::ManagerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManagerDialog)
{
    ui->setupUi(this);
    setWindowTitle("管理员");
}

ManagerDialog::~ManagerDialog()
{
    delete ui;
}

void ManagerDialog::on_pushButton_back_clicked()
{
    //将文件中的数据读取到程序中并且保存
    fstream file;
	file.open(MANAGER_PATH, ios::out);
    if (!file.is_open())
    {
        qDebug() << "open file fail" << endl;
    }
    else
    {

        for (int i = 0; i < (int)Resources::m_manager.size(); i++)
        {
            //file << ID << " " << accout << " " << password << " " << name
            //	<< " " << department << " " << position << " " << address;
            file << Resources::m_manager[i]->ID << " " << Resources::m_manager[i]->m_accout << " " << Resources::m_manager[i]->m_password << endl;
        }

        file.close();
    }

	file.open(WORKER_PATH, ios::out);
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

//各个功能页面的跳转
void ManagerDialog::on_pushButton_findworker_clicked()
{
    findworker *findworker1 = new findworker();
    this->hide();
    findworker1->show();
    findworker1->exec();
    this->show();
}

void ManagerDialog::on_pushButton_addworker_clicked()
{
    AddWorker *addworker1 = new AddWorker();
    this->hide();
    addworker1->show();
    addworker1->exec();
    this->show();
}

void ManagerDialog::on_pushButton_changepassword_clicked()
{
    ModifyPassword *modifypassword1 = new ModifyPassword();
    this->hide();
    modifypassword1->show();
    modifypassword1->exec();
    this->show();
}

void ManagerDialog::on_pushButton_savedate_clicked()
{
    DataBackup *databackup1 = new DataBackup();
    this->hide();
    databackup1->show();
    databackup1->exec();
    this->show();
}

void ManagerDialog::on_pushButton_displayworker_clicked()
{
    DisplayWorker *displayworker1 = new DisplayWorker();
    this->hide();
    displayworker1->show();
    displayworker1->exec();
    this->show();
}

void ManagerDialog::on_pushButton_displaybydepartment_clicked()
{
    DisplayByDepartment *displaybydepartment1 = new DisplayByDepartment();
    this->hide();
    displaybydepartment1->show();
    displaybydepartment1->exec();
    this->show();
}

void ManagerDialog::on_pushButton_analys_clicked()
{
    Analys *analys1 = new Analys();
    this->hide();
    analys1->show();
    analys1->exec();
    this->show();
}

void ManagerDialog::on_pushButton_recover_clicked()
{
    DataRecovery *datarecovery1 = new DataRecovery();
    this->hide();
    datarecovery1->show();
    datarecovery1->exec();
    this->show();
}
