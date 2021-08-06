#include<iostream>
#include<stdexcept>
#include<iomanip>
#include "comissionemployee.h"
using namespace std;
BasePlusComissionEmployee::BasePlusComissionEmployee(const string &first, const string &last, const string &ssn, double sales, double rate, double salary){
    firstName=first;
    lastName=last;
    socialSecurityNumber=ssn;
    setGrossSales(sales);
    setComissionRate(rate);
    setBaseSalary(salary);
}
void BasePlusComissionEmployee::setFirstName(const string &first){
    firstName=first;
}
string BasePlusComissionEmployee::getFirstName()const{
    return firstName;
}
void BasePlusComissionEmployee::setLastName(const string &last){
    lastName=last;
}
string BasePlusComissionEmployee::getLastName()const{
    return lastName;
}
void BasePlusComissionEmployee::setSecoialSecurityNumber(const string &ssn){
    socialSecurityNumber=ssn;
}
string BasePlusComissionEmployee::getSocialSecurityNumber()const{
    return socialSecurityNumber;
}
void BasePlusComissionEmployee::setGrossSales(double sales){
    if(sales>=0.0){
        grossSales=sales;
    }
    else{
        throw invalid_argument("gross must be >=0.0");
    }
}
double BasePlusComissionEmployee::getGrossSales()const{
    return grossSales;
}
void BasePlusComissionEmployee::setComissionRate(double rate){
    if(rate>=0.0 && rate<1.0){
        comissionRate=rate;
    }
    else{
        throw invalid_argument("ComissionRate must be >0.0 and <1.0");
    }
}
double BasePlusComissionEmployee::getComissionRate()const{
    return comissionRate;
}
void BasePlusComissionEmployee::setBaseSalary(double salary){
    if(salary>=0.0){
        baseSalary=salary;
    }
    else{
        throw invalid_argument("Salary must be >=0.0");
    }
}
double BasePlusComissionEmployee::getBaseSalary()const{
    return baseSalary;
}
double BasePlusComissionEmployee::earnings()const{
    return baseSalary + (comissionRate * grossSales);
}
void BasePlusComissionEmployee::print()const{
    cout<<"comission employee: "<<firstName<<' '<< lastName<<"\nsocial security number: "<<socialSecurityNumber;
    cout<<"\ngross sales: "<<grossSales<<"\ncomission rate: "<<comissionRate<<"\nbase Salary is: "<<baseSalary;
}
int main(){
    BasePlusComissionEmployee employee("Bob","Lewis","333-33-333",5000,.04,300);
    cout<<fixed<<setprecision(2);
    cout<<"Employee information obtained by get functions: \n";
    cout<<"\nFirst Name is: "<<employee.getFirstName();
    cout<<"\nLast Names is: "<<employee.getLastName();
    cout<<"\nSocial security number is: "<<employee.getSocialSecurityNumber();
    cout<<"\nGross sales is: "<<employee.getGrossSales();
    cout<<"\nComission rate is: "<<employee.getComissionRate()<<endl;
    cout<<"\nBase Salary is: "<<employee.getBaseSalary()<<endl;
    employee.setBaseSalary(1000);
    cout<<"\nUpdate employee information output by print function: \n"<< endl;
    employee.print();
    cout<<"\n\nEmployee's earnings: $"<<employee.earnings()<<endl;
}
