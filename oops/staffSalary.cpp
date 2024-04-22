#include<bits/stdc++.h>
using namespace std;

class Employee{
    protected:
    string name_;
    public:
    virtual void ProcessSalary()= 0; //pure virtual function 
    virtual ~Employee(){}
};
class Engineer: public Employee{
    public:
   Engineer(const string& name){ name_ = name;}
   void ProcessSalary(){
    cout<<name_<<" : Process Salary of Engineer  "<<endl;
   }
};
class Manager: public Engineer{
    Engineer *report_[10];
    public:
    Manager(const string& name) : Engineer(name) {}
    void ProcessSalary(){ 
        cout<<name_<<": Process salary of Manager"<<endl;
    }
};
class Director: public Manager{
    Manager *report_[10];

    public:
    Director(const string& name) : Manager(name) {}

    void ProcessSalary(){
        cout<<name_<<": Process salary of Director"<<endl;
    }
};
class SalesExc : public Employee{
    public:
    SalesExc(const string& name){ name_ = name;}
    void ProcessSalary(){
        cout<<name_<<": Process Salary of the Sales Exc"<<endl;
    }

    
};




int main(){
    Engineer e1("Rohit"), e2("Shanvi"), e3("Ryan");
    Manager m1("Siddhu"), m2("Modi");
    SalesExc s1("Arun"), s2("Varun");
    Director d1("Supreme");


    Employee *staff[] = {&e1, &e2, &e3, &m1, &m2, &s1, &s2, &d1};
    for(int i =0;i<sizeof(staff)/sizeof(Employee*);i++){
        staff[i] -> ProcessSalary(); 
    }
}