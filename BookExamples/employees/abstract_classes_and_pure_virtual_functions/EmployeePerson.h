#ifndef EMPLOYEEPERSON_H
#define EMPLOYEEPERSON_H

#include <iostream>
#include <string>
using namespace std;

class EmployeePerson {
   public:
      EmployeePerson();
      EmployeePerson(string empFullName, string empDepartmentCode, 
                     string empBirthday, int empAnnualSalary);
      void SetData(string empFullName, string empDepartmentCode, 
                   string empBirthday, int empAnnualSalary);
      virtual void PrintInfo() = 0;
      virtual int GetAnnualBonus() = 0;
      
   protected:
      string fullName;         // In the format last name, first name
      string departmentCode;
      string birthday;
      int annualSalary;
};

#endif
