#ifndef EMPLOYEEMANAGER_H
#define EMPLOYEEMANAGER_H

#include <iostream>
#include <string>
#include "EmployeePerson.h"
using namespace std;

class EmployeeManager : public EmployeePerson {
   public:
      EmployeeManager();
      EmployeeManager(int nManaged);
      int GetNumManaged();
      void PrintInfo();
   private:
      int numManaged;
};

#endif

