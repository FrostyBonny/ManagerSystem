#ifndef CWORKER_H
#define CWORKER_H

static string PostSalary[3]{ "boss","ass","worker" };

struct salary
{
    string LevelSalary;
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

    void CheckOwnWages();//查询工资
    void ModifyOwnInf();//改变自身信息
    void UpDateWages();
};

#endif // CWORKER_H
