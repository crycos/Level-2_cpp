#include "EmployeePerson.h"
#include <iostream>
#include <string>
using namespace std;

// Default constructor. Set protected variables to the empty string or 0
EmployeePerson::EmployeePerson() {
   fullName = "";
   departmentCode = "";
   birthday = "";
   annualSalary = 0;
} 

// ***********************************************************************

// Constructor with parameters to set the private variables
EmployeePerson::EmployeePerson(string empFullName, string empDepartmentCode,
                               string empBirthday, int empAnnualSalary) {
   SetData(empFullName, empDepartmentCode, empBirthday, empAnnualSalary);
} 
   
// ***********************************************************************

void EmployeePerson::SetData(string empFullName, string empDepartmentCode,
                             string empBirthday, int empAnnualSalary) {
   fullName       = empFullName;
   departmentCode = empDepartmentCode;
   birthday       = empBirthday;
   annualSalary   = empAnnualSalary;
} 

// ***********************************************************************

void EmployeePerson::PrintInfo() {
   cout << "Name: " << fullName << ", Department: " << departmentCode
        << ", Birthday: " << birthday << ", Salary: " << annualSalary 
        << endl;
}

// ***********************************************************************

int EmployeePerson::GetAnnualBonus() {
   return 0;
}
