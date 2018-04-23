#ifndef RESOURCES_H
#define RESOURCES_H
#include <vector>
#include "worker.h"
#include "manager.h"
#include <sstream>
#include <fstream>
#include <QDebug>
using namespace std;
class Resources
{
public:
    Resources();

    static vector<worker*> m_worker;
    static vector<manager*> m_manager;
    static int whichworker;
    static int whichmanager;
};

#endif // RESOURCES_H
