#include "EmployeeStaff.h"
#include <iostream>
#include <string>
using namespace std;

// Default constructor 
EmployeeStaff::EmployeeStaff() {
   managerName = "";
} 

// ***********************************************************************

// Constructor with parameters
EmployeeStaff::EmployeeStaff(string reportsTo) {
   managerName = reportsTo;
} 

// ***********************************************************************

// Get the name of the manager

string EmployeeStaff::GetManagerName() {
   return managerName;
} 

// ***********************************************************************

void EmployeeStaff::PrintInfo() {
   cout << "Name: " << fullName << ", Department: " << departmentCode
        << ", Birthday: " << birthday << ", Salary: " << annualSalary 
        << ", Manager: " << GetManagerName() << endl;
} 

// ***********************************************************************

int EmployeeStaff::GetAnnualBonus() {
   int bonus = (annualSalary * .075);

   return bonus;
}
