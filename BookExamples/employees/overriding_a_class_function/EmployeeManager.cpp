#include <iostream>
#include "EmployeeManager.h"
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
        << ", Staff managed: " << numManaged << endl;

   return;
} 

