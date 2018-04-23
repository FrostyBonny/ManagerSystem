#include "datarecovery.h"
#include "ui_datarecovery.h"

DataRecovery::DataRecovery(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DataRecovery)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton_back,SIGNAL(clicked(bool)),this,SLOT(close()));
}

DataRecovery::~DataRecovery()
{
    delete ui;
}

vector<string> ssplite(const string &s, const string &c)//分割字符用的
{
    std::string::size_type pos1, pos2;
    vector<string> v;
    pos2 = s.find(c);
    pos1 = 0;
    while (std::string::npos != pos2)
    {
        v.push_back(s.substr(pos1, pos2 - pos1));

        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if (pos1 != s.length())
    {
        v.push_back(s.substr(pos1));
    }
    return v;
}

void DataRecovery::on_pushButton_choosefile_clicked()
{
    filename = QFileDialog::getOpenFileName(this,tr("选择TXT文件"),"",tr("Files(*.txt)"));
    ui->lineEdit->setText(filename);
}

void DataRecovery::on_pushButton_recover_clicked()
{
    Resources::m_worker.clear();

    string s = ui->lineEdit->text().trimmed().toStdString();

    fstream file;
    string inf;

    file.open(s,ios::app|ios::out|ios::in);

    if (!file.is_open())
    {
           qDebug() << "creat worker file fail" << endl;
    }
    else
    {
        while (getline(file, inf))
        {
            vector<string> v;

            v = ssplite(inf," ");


            worker *tworker = new worker(v);
            Resources::m_worker.push_back(tworker);
        }
    }
    file.close();

    QMessageBox box(QMessageBox::Information,"消息","恢复成功！");
    box.setStandardButtons (QMessageBox::Ok);
    box.setButtonText (QMessageBox::Ok,QString("确 定"));
    box.exec ();

//    file.open(s,ios::app|ios::out|ios::in);
//    if (!file.is_open())
//    {
//           qDebug() << "creat manager file fail" << endl;
//    }
//    else
//    {
//        while (getline(file,inf))
//        {

//            vector<string> v;
//            v = ssplite(inf, " ");

//            manager *tmanager = new manager(v);

//            Resources::m_manager.push_back(tmanager);
//        }
//    }
//    file.close();
}

void DataRecovery::on_pushButton_back_clicked()
{
    fstream file;
    file.open("E:\\doc\\manager.txt", ios::out);
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

}
