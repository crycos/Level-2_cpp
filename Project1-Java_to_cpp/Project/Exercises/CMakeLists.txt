cmake_minimum_required(VERSION 3.3)
project(HW1_student)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# HW Project Files / executables
add_executable(CreditCardValidator CreditCardValidator.cpp)
add_executable(GradeCalculator GradeCalculator.cpp)
add_executable(QuadraticRootTool QuadraticRootTool.cpp)
