#include <iostream>
#include <string>
#include "EmployeeStaff.h"
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
        << ", Birthday: " << birthday << ", Salary: " << annualSalary;
   cout << ", Manager: " << GetManagerName() << endl;
}

