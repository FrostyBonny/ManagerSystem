#ifndef WORKER_H
#define WORKER_H

#include <vector>
#include <string>
using namespace std;


static string PostSalary[3]{ "员工","助手","经理" };
static string SalaryLevel[3]{"后勤部门","技术部门","财务部门"};

struct salary
{
    double LevelSalary;
    double PostSalary;//zhi wei gong zi
    double Bonus;//jiang ji
    double Deduction;//kou kuan
    double WithHoldingTax;// sui shouda
    double FinalSalary;
};

class worker
{
public:
    worker(vector<string> v);
    ~worker();

    string m_password;
    string m_accout;

    string ID;
    string m_name;
    string m_department;//部门
    string m_position;//职位
    string m_adress;
    salary m_salary;

    void ModifyOwnInf(vector<string> v);//改变自身信息
    void UpDateWages();
    void ModifyByManager(vector<string> v);
    int ConfirmInf();
};
#endif // WORKER_H
