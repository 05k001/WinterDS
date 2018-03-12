#ifndef _MANAGER_H
#define _MANAGER_H

#include "Employee.h"

class Manager : public Employee {
public:
   Manager(string theName,
       float thePayRate,
       bool isSalaried);

   bool getSalaried() const;


   float pay(float hoursWorked) const;
   void setSalaried(bool val);

protected:
   bool salaried;
};


//Manager method definitions.

void Manager::setSalaried(bool val)
{
   salaried = val;

}

Manager::Manager(string theName,
   float thePayRate,
   bool isSalaried)
   : Employee(theName, thePayRate)
{
   salaried = isSalaried;
}

bool Manager::getSalaried() const
{
   return salaried;
}

float Manager::pay(float hoursWorked) const
{
   if (salaried)
       return payRate;
   // else
   return Employee::pay(hoursWorked);
}

#endif