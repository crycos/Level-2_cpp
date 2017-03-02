fndef EMPLOYEESTAFF_H
#define EMPLOYEESTAFF_H

#include "EmployeePerson.h"
#include <iostream>
#include <string>
using namespace std;

class EmployeeStaff : public EmployeePerson {
   public:
      EmployeeStaff();
      EmployeeStaff(string reportsTo);
      string GetManagerName();
      void PrintInfo();
      int GetAnnualBonus();
   private:
      string managerName;
};

#endif
