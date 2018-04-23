#ifndef MANAGER_H
#define MANAGER_H
#include <vector>
#include <string>
using namespace std;

class manager
{
public:
    manager(vector<string> v);
    ~manager();

    string ID;

    string m_password;
    string m_accout;

    void modifypassword(string password);
};

#endif // MANAGER_H
