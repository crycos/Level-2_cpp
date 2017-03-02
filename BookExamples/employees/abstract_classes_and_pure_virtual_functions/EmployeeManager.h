#ifndef EMPLOYEEMANAGER_H
#define EMPLOYEEMANAGER_H

#include "EmployeePerson.h"
#include <iostream>
#include <string>
using namespace std;

class EmployeeManager : public EmployeePerson {
   public:
      EmployeeManager();
      EmployeeManager(int nManaged);
      int GetNumManaged();
      void PrintInfo();
      int GetAnnualBonus();
   
   private:
      int numManaged;
};

#endif
