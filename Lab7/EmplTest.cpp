
#include <iostream>
#include "Employee.h"
#include "manager.h"
#include "supervisor.h"
using namespace std;


int main()
{
   Employee empl("Neil", 25.0);
   Manager mgr("Sheri", 1200.0, true);
   Supervisor sup("Richard", 780.0, "Accounting");


   cout << "For Employee:" << endl;
   cout << "Name: " << empl.getName() << endl;
   cout << "Pay: " << empl.pay(40.0) << endl;


   cout << "Changing the Employee's name..." << endl;
   empl.setName("Neil");
   cout << "New Name: " << empl.getName() << endl;


   cout << endl;
   cout << "For Manager:" << endl;
   cout << "Name: " << mgr.getName() << endl;
   cout << "Salaried: " << mgr.getSalaried() << endl;
   cout << "Pay: " << mgr.pay(40.0) << endl;


   cout << "Changing the Manager's salaried status..." << endl;
   mgr.setSalaried(false);
   cout << "New Pay: " << mgr.pay(40.0) << endl;

   cout << endl;


   cout << "For Supervisor:" << endl;
   cout << "Name: " << sup.getName() << endl;
   cout << "Pay: " << sup.pay() << endl;
   cout << "Dept: " << sup.getDept() << endl;
   sup.setPayRate(900.0);
   cout << "New Pay: " << sup.pay() << endl;
   return 0;
}