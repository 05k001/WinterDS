#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

#include <string>
using namespace std;

class Employee {
public:
   Employee(string theName, float thePayRate);

   string getName() const;
   float getPayRate() const;

   float pay(float hoursWorked) const;
   void setName(string s);
  

protected:
   string name;
   float payRate;
};

/*
* Employee method definitions.
*/

void Employee::setName(string s)
{
   name = s;
}

Employee::Employee(string theName, float thePayRate)
{
   name = theName;
   payRate = thePayRate;
}

string Employee::getName() const
{
   return name;
}

float Employee::getPayRate() const
{
   return payRate;
}

float Employee::pay(float hoursWorked) const
{
   return hoursWorked * payRate;
}
#endif