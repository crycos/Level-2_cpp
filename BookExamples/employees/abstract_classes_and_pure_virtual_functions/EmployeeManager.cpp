#include "EmployeeManager.h"
#include <iostream>
#include <string>
using namespace std;

// Default constructor
EmployeeManager::EmployeeManager() {
   numManaged = 0;
} 

// ***********************************************************************

// Constructor with parameters 
EmployeeManager::EmployeeManager(int nManaged) {
   numManaged = nManaged;
} 

// ***********************************************************************

// Get the number of people managed
int EmployeeManager::GetNumManaged() {
   return numManaged;
} 

// ***********************************************************************

void EmployeeManager::PrintInfo() {
   cout << "Name: " << fullName << ", Department: " << departmentCode
        << ", Birthday: " << birthday << ", Salary: " << annualSalary 
        << ", Staff managed: " << GetNumManaged() << endl;
} 

// ***********************************************************************

int EmployeeManager::GetAnnualBonus() {
   int bonus = (annualSalary * .1);

   return bonus;
}
