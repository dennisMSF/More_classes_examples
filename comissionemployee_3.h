#include<string>
#include"comissionemployee_2.h"
class BasePlusComissionEmployee:public ComissionEmployee{
public:
    BasePlusComissionEmployee(const string&,const string&,const string&,double=0.0,double=0.0,double=0.0);
    void setBaseSalary(double);
    double getBaseSalary()const;
    double earnings()const;
    void print()const;
private:
    double baseSalary;
};
