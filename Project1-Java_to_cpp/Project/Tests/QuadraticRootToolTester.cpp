/*
 * Main.cpp
 *
 *  Created on: May 14, 2015
 *      Author: Joshua
 */

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <typeinfo>
#include <cstdlib>

#include <cmath>

#include "ProgramParser.h"

/*
 * This program written with significant help/aid of library source from http://libexecstream.sourceforge.net/.
 *
 * The library is used to facilitate having this program launch another program and control it for testing purposes.
 */

//#define DEBUG

#ifdef _WIN32
#define EXECUTABLE_NAME "QuadraticRootTool.exe"
#endif

#ifndef _WIN32
#define EXECUTABLE_NAME "./QuadraticRootTool"
#endif

using namespace std;

// Useful utility functions.

template <typename T>
const T to(const string& sval)
{
        T val;
        stringstream ss;
        ss << sval;
        ss >> val;
        if(ss.fail())
                throw runtime_error((string)typeid(T).name() + " type wanted: " + sval);
        return val;
}

template <typename T>
const T is(const string& sval)
{
        T val;
        stringstream ss;
        ss << sval;
        ss >> val;
        return !ss.fail();
}

bool quadraticOutputFilter(string str)
{
	if(is<double>(str)) return true;

	if(str == string("two")) return true;

	if(str == string("one")) return true;

	if(str == string("no")) return true;

	return false;
}

bool doubleInRange(double expected, double actual, double eps = 0.001)
{
	if(isnan(expected) && isnan(actual)) return true;

	return abs(expected - actual) <= eps;
}

//struct QuadraticOutput
//{
//	double r1, r2;
//
//	string word;
//
//	QuadraticOutput(double r1, double r2, string word)
//	{
//		this->r1 = r1;
//		this->r2 = r2;
//
//		this->word = word;
//	}
//};

void printTestData(int i, string input, double e_r1, double e_r2, string e_word)
{
	cout << "Test " << i << ": " << endl;
	cout << "\tProgram input: " << input << endl;
	cout << "\tExpected program output:  ";
	if(!isnan(e_r1))
		cout << "r1 = " << e_r1 << ", ";
	if(!isnan(e_r2))
		cout << "r2 = " << e_r2 << ", ";
	cout << "root count word = \"" << e_word << "\"." << endl;
	cout << endl;
}

bool quadraticTest(string input, double e_r1, double e_r2, string e_word)
{
	vector<string> output = runIndividualTest(input, string(EXECUTABLE_NAME), quadraticOutputFilter);

	double r1, r2;
	string word;

	if(output.size() == 0)
	{
		r1 = NAN;
		r2 = NAN;

		word = string("Could not find expected word:  \"two\", \"one\", or \"no\"!");
	}
	else
	{
		if(output[0] == string("two") || output[0] == string("one") || output[0] == string("no"))
			word = output[0];
		else word = string("Could not find expected word:  \"two\", \"one\", or \"no\"!");

		if(output.size() > 1)
		{
			if(!is<double>(output[1]))
				r1 = NAN;
			else r1 = to<double>(output[1]);
		}
		else r1 = NAN;

		if(output.size() > 2)
		{
			if(!is<double>(output[2]))
				r2 = NAN;
			else r2 = to<double>(output[2]);
		}
		else r2 = NAN;
	}

	if(doubleInRange(e_r1, r1) && doubleInRange(e_r2, r2) && e_word == word)
	{
		cout << "\tTest passed!" << endl;
		return true;
	}
	else
	{
		cout << "\tTest failed:  r1 = " << r1 << ", r2 = " << r2 << ", root count word = \"" << word << "\".";
		return false;
	}
}

// Write the true test here.
int main()
{
	vector<string> tokens;
	bool allPassed = true;
	bool res;

	printTestData(0, string("1 3 1"), -0.381966, -2.61803, string("two"));
	res = quadraticTest(string("1 3 1"), -0.381966, -2.61803, string("two"));
	cout << endl;
	if(!res) allPassed = false;

	printTestData(1, string("1 2 1"), -1, NAN, string("one"));
	res = quadraticTest(string("1 2 1"), -1, NAN, string("one"));
	cout << endl;
	if(!res) allPassed = false;

	printTestData(2, string("1 2 3"), NAN, NAN, string("no"));
	res = quadraticTest(string("1 2 3"), NAN, NAN, string("no"));
	cout << endl;
	if(!res) allPassed = false;

	if(allPassed)
	{
		cout << "All tests successfully passed!" << endl;
	}
	else
	{
		cout << "Not all tests passed - see above for details." << endl;
	}
}

