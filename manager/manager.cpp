#include "manager.h"

manager::manager(vector<string> v)
{
    ID = v[0];
    m_accout = v[1];
    m_password = v[2];
}


manager::~manager()
{
}

void manager::modifypassword(string password)
{
    m_password = password;
}
