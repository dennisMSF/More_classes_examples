#include<iostream>
#include<stdexcept>
#include<iomanip>
#include "comissionemployee_2.h"
using namespace std;
ComissionEmployee::ComissionEmployee(const string &first, const string &last, const string &ssn, double sales, double rate){
    firstName=first;
    lastName=last;
    socialSecurityNumber=ssn;
    setGrossSales(sales);
    setComissionRate(rate);
}
void ComissionEmployee::setFirstName(const string &first){
    firstName=first;
}
string ComissionEmployee::getFirstName()const{
    return firstName;
}
void ComissionEmployee::setLastName(const string &last){
    lastName=last;
}
string ComissionEmployee::getLastName()const{
    return lastName;
}
void ComissionEmployee::setSecoialSecurityNumber(const string &ssn){
    socialSecurityNumber=ssn;
}
string ComissionEmployee::getSocialSecurityNumber()const{
    return socialSecurityNumber;
}
void ComissionEmployee::setGrossSales(double sales){
    if(sales>=0.0){
        grossSales=sales;
    }
    else{
        throw invalid_argument("gross must be >=0.0");
    }
}
double ComissionEmployee::getGrossSales()const{
    return grossSales;
}
void ComissionEmployee::setComissionRate(double rate){
    if(rate>=0.0 && rate<1.0){
        comissionRate=rate;
    }
    else{
        throw invalid_argument("ComissionRate must be >0.0 and <1.0");
    }
}
double ComissionEmployee::getComissionRate()const{
    return comissionRate;
}
double ComissionEmployee::earnings()const{
    return comissionRate * grossSales;
}
void ComissionEmployee::print()const{
    cout<<"comission employee: "<<firstName<<' '<< lastName<<"\nsocial security number: "<<socialSecurityNumber;
    cout<<"\ngross sales: "<<grossSales<<"\ncomission rate: "<<comissionRate;
}
/*
int main(){
    ComissionEmployee employee("Sue","Jones","222-222-222",10000,.06);
    cout<<fixed<<setprecision(2);
    cout<<"Employee information obtained by get functions: \n";
    cout<<"\nFirst Name is: "<<employee.getFirstName();
    cout<<"\nLast Names is: "<<employee.getLastName();
    cout<<"\nSocial security number is: "<<employee.getSocialSecurityNumber();
    cout<<"\nGross sales is: "<<employee.getGrossSales();
    cout<<"\nComission rate is: "<<employee.getComissionRate()<<endl;
    employee.setGrossSales(8000);
    employee.setComissionRate(.1);
    cout<<"\nUpdate employee information output by print function: \n"<< endl;
    employee.print();
    cout<<"\n\nEmployee's earnings: $"<<employee.earnings()<<endl;
}
*/
