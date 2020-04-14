#include "resources.h"
#include "macro.h"
vector<worker*> Resources::m_worker = vector<worker*>();
vector<manager*> Resources::m_manager = vector<manager*>();
int Resources::whichworker = -1;
int Resources::whichmanager = -1;

vector<string> splite(const string &s, const string &c)//分割字符用的
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


Resources::Resources()
{


    fstream file;
    string inf;

	file.open(WORKER_PATH,ios::app|ios::out|ios::in);

    if (!file.is_open())
    {
           qDebug() << "creat worker file fail" << endl;
    }
    else
    {
        while (getline(file, inf))
        {
            vector<string> v;

            v = splite(inf," ");


            worker *tworker = new worker(v);
            m_worker.push_back(tworker);
        }
    }
    file.close();

	file.open(MANAGER_PATH,ios::app|ios::out|ios::in);
    if (!file.is_open())
    {
           qDebug() << "creat manager file fail" << endl;
    }
    else
    {
        while (getline(file,inf))
        {

            vector<string> v;
            v = splite(inf, " ");

            manager *tmanager = new manager(v);

            m_manager.push_back(tmanager);
        }
    }
    file.close();
}



