cmake_minimum_required(VERSION 3.3)
project(HW1_Tests)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Test suite for programs
set(HELPER_FILES ProgramParser.cpp exec-stream.cpp)
add_executable(QuadraticRootToolTester QuadraticRootToolTester.cpp ${HELPER_FILES})
add_executable(GradeCalculatorTester GradeCalculatorTester.cpp ${HELPER_FILES})
add_executable(CreditCardValidatorTester CreditCardValidatorTester.cpp ${HELPER_FILES})
