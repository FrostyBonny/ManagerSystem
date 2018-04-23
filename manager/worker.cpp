
#include "worker.h"

worker::worker(vector<string> v)
{
    m_accout = v[1];
    m_password = v[2];

    ID = v[0];
    m_name = v[3];
    m_department = v[4];
    m_position = v[5];
    m_adress = v[6];

    m_salary.Bonus = 0;
    m_salary.Deduction = 0;

    UpDateWages();
}


worker::~worker()
{
}



void worker::ModifyOwnInf(vector<string> v)
{
    if(v[0] != "") m_name = v[0];
    if(v[1] != "") m_department = v[1];
    if(v[2] != "") m_position = v[2];
    if(v[3] != "") m_adress = v[3];

    UpDateWages();

}

double CalTax(double s)
{
    double rs,rat;
    if(rs=s-3500,rs<500)
        rat=0.05;
    else if(rs>=500 && rs<2000)
        rat=0.1;
    else if(rs>=2000 && rs<5000)
        rat=0.15;
    else if(rs>=5000 && rs<20000)
        rat=0.2;
    else if(rs>=20000 && rs<40000)
        rat=0.25;
    else if(rs>=40000 && rs<60000)
        rat=0.3;
    else if(rs>=60000 && rs<80000)
        rat=0.35;
    else if(rs>=80000 && rs<100000)
        rat=0.4;
    else if(rs>=100000)
        rat=0.45;
    return rat*rs;
}


void worker::UpDateWages()
{
    //cal salary
    for (int i = 0; i < 3; i++)
    {
        if (PostSalary[i] == m_position)
        {
            m_salary.PostSalary = i;
        }
    }
    m_salary.PostSalary++;

    for(int i = 0;i < 3;i++)
    {
        if(SalaryLevel[i] == m_department)
        {
            m_salary.LevelSalary = i;
        }
    }
    m_salary.LevelSalary++;

    m_salary.PostSalary = m_salary.PostSalary * 2500;
    m_salary.LevelSalary = m_salary.LevelSalary * 1300;

    if(m_salary.LevelSalary + m_salary.PostSalary  + m_salary.Bonus - m_salary.Deduction > 3500)
        m_salary.WithHoldingTax = CalTax(m_salary.LevelSalary + m_salary.PostSalary
                                         + m_salary.Bonus - m_salary.Deduction);
    else m_salary.WithHoldingTax = 0;

    m_salary.FinalSalary = m_salary.LevelSalary + m_salary.PostSalary + m_salary.Bonus - m_salary.Deduction - m_salary.WithHoldingTax;
}

void worker::ModifyByManager(vector<string> v)
{

    ID = v[0];
    m_name = v[1];
    m_department = v[2];
    m_position = v[3];
    m_adress = v[4];

    m_salary.Bonus = atof(v[5].data());
    m_salary.Deduction = atof(v[6].data());

    UpDateWages();
}

int worker::ConfirmInf()
{
    int flag1 = -1,flag2 = -1;
    for (int i = 0; i < 3; i++)
    {
        if (PostSalary[i] == m_position)
        {
            flag1 = i;
        }
    }
    if(flag1 == -1)
        return 1;

    for(int i = 0;i < 3;i++)
    {
        if(SalaryLevel[i] == m_department)
        {
            flag2 = i;
        }
    }
    if(flag2 == -1)
        return 2;
    return 0;
}
