#include <iostream>
#include "EmployeeManager.h"
#include "EmployeeStaff.h"
#include <iostream>
using namespace std;

int main() {
   EmployeeManager manager(25);
   EmployeeStaff staff1("Michele");

   // Load data into the objects using the EmployeePerson class's functions
   manager.SetData("Michele", "Sales", "03-03-1975", 70000);
   staff1.SetData ("Bob",     "Sales", "02-02-1980", 50000);

   // Print the objects
   manager.PrintInfo();
   cout << "Annual bonus: " << manager.GetAnnualBonus() << endl;
   staff1.PrintInfo();
   cout << "Annual bonus: " << staff1.GetAnnualBonus() << endl;

   return 0;
}
