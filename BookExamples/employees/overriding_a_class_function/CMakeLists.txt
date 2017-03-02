cmake_minimum_required(VERSION 3.6)
project(Employee_Class_Overriding)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp EmployeePerson.cpp EmployeeManager.h EmployeeManager.cpp EmployeeStaff.h EmployeeStaff.cpp)
add_executable(Employee_Class_Overriding ${SOURCE_FILES})