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
#define EXECUTABLE_NAME "CreditCardValidator.exe"
#endif

#ifndef _WIN32
#define EXECUTABLE_NAME "./CreditCardValidator"
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

bool creditCardOutputFilter(string str)
{
	if(str == string("valid") || str == string("valid.") ||
	   str == string("invalid") || str == string("invalid."))
		return true;

	return false;
}

void printTestData(int i, string ccNum, string validity)
{
	cout << "Test " << i << ": " << endl;
	cout << "\tProgram expected input / output: " << ccNum << " is " << validity <<  "." << endl;
	cout << endl;
}

bool creditCardTest(string ccNum, string validity)
{
	vector<string> output = runIndividualTest(ccNum + "\n", string(EXECUTABLE_NAME), creditCardOutputFilter);

	string word;

	if(output.size() == 0)
	{
		cout << "\tCould not find expected word:  \"valid\" or \"invalid\"!" << endl;
		return false;
	}
	else
	{
		if(output[0].substr(0, validity.length()) == validity)
		{
			cout << "\tSuccess!" << endl;
			return true;
		}
		else
		{
			cout << "\tError: program says " << ccNum << " is " << output[0] << "." << endl;
			return false;
		}
	}
}

// Write the true test here.
int main()
{
	vector<string> tokens;
	bool allPassed = true;
	bool res;

	printTestData(0, string("4388576018410707"), string("valid"));
	res = creditCardTest(string("4388576018410707"), string("valid"));
	cout << endl;
	if(!res) allPassed = false;

	printTestData(1, string("4388576018402626"), string("invalid"));
	res = creditCardTest(string("4388576018402626"), string("invalid"));
	cout << endl;
	if(!res) allPassed = false;

	printTestData(2, string("6011326990276123"), string("invalid"));
	res = creditCardTest(string("6011326990276123"), string("invalid"));
	cout << endl;
	if(!res) allPassed = false;

	printTestData(3, string("5436863455832646"), string("valid"));
	res = creditCardTest(string("5436863455832646"), string("valid"));
	cout << endl;
	if(!res) allPassed = false;

	printTestData(4, string("48706286977"), string("invalid"));  // Too short!
	res = creditCardTest(string("48706286977"), string("invalid"));
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

	string temp;
	cout << endl << "Enter any string to end the program." << endl;
	cin >> temp;
}

