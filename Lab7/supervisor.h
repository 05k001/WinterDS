#ifndef _SUPERVISOR_H
#define _SUPERVISOR_H
#include "Employee.h"
class Supervisor : public Manager {
public:
   Supervisor(string name, float salary, string dept);
   string getDept();
   void setDept(string s);
   float pay();
   void setPayRate(float salary);
private:
   string dept;
   float salary;
};
Supervisor::Supervisor(string name, float salary, string dep) :Manager(name, salary, true){
   dept = dep;
}
void Supervisor::setDept(string s){
   dept = s;
}
string Supervisor::getDept(){
   return dept;
}

void Supervisor::setPayRate(float s)
{
   salary = s;
}
float Supervisor::pay()
{
   return salary;
}
#endif