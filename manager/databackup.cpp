#include "databackup.h"
#include "ui_databackup.h"

DataBackup::DataBackup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DataBackup)
{
    ui->setupUi(this);
    setWindowTitle("数据备份");
    QObject::connect(ui->pushButton_back,SIGNAL(clicked(bool)),this,SLOT(close()));
}

DataBackup::~DataBackup()
{
    delete ui;
}

void DataBackup::on_pushButton_backup_clicked()
{
    //如果输入框不为空，则在指定路径录入员工和管理员的信息
    if(!ui->lineEdit->text().isEmpty())
    {
        QString s = QString("%1/manager.txt").arg(QString::fromStdString(ui->lineEdit->text().toStdString()));

        fstream file;
        file.open(s.toStdString(), ios::out);
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

        s = QString("%1/worker.txt").arg(QString::fromStdString(ui->lineEdit->text().toStdString()));
        file.open(s.toStdString(), ios::out);
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

        QMessageBox box(QMessageBox::Information,"消息","备份完成！");
        box.setStandardButtons (QMessageBox::Ok);
        box.setButtonText (QMessageBox::Ok,QString("确 定"));
        box.exec ();
    }


}

void DataBackup::on_pushButton_choosefile_clicked()
{
    filename = QFileDialog::getExistingDirectory(this,"选择文件","./");
    ui->lineEdit->setText(filename);
}
