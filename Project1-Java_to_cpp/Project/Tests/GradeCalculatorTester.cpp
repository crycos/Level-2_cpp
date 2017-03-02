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

#include <sstream>
#include <cmath>

#include "ProgramParser.h"

/*
 * This program written with significant help/aid of library source from http://libexecstream.sourceforge.net/.
 *
 * The library is used to facilitate having this program launch another program and control it for testing purposes.
 */

//#define DEBUG

#ifdef _WIN32
#define EXECUTABLE_NAME "GradeCalculator.exe"
#endif

#ifndef _WIN32
#define EXECUTABLE_NAME "./GradeCalculator"
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

bool gradeCurverOutputFilter(string str)
{
	if(is<int>(str)) return true;

	if(str == string("A")) return true;

	if(str == string("B")) return true;

	if(str == string("C")) return true;

	if(str == string("D")) return true;

	if(str == string("E")) return true;

	if(str == string("F")) return true;

	return false;
}

bool doubleInRange(double expected, double actual, double eps = 0.001)
{
	if(isnan(expected) && isnan(actual)) return true;

	return abs(expected - actual) <= eps;
}

void printTestData(int i, const vector<int>& scores, const vector<string>& grades)
{
	cout << "Test " << i << ": " << endl;
	cout << "\tProgram input / expected output: " << endl;
	for(int j=0; j < scores.size(); j++)
	{
		cout << "\tStudent " << j << ": " << "score = " << scores[j] << ", grade = " << grades[j] << endl;
	}

	cout << endl;
}

bool gradeCurverTest(const vector<int>& scores, const vector<string>& grades)
{
	stringstream inputBuilder;
	inputBuilder << scores.size() << endl;

	for(int i=0; i < scores.size(); i++)
	{
		inputBuilder << scores[i] << " ";
	}

	inputBuilder << endl;

	vector<string> output = runIndividualTest(inputBuilder.str(), string(EXECUTABLE_NAME), gradeCurverOutputFilter);

	if(output.size() < 3)
	{
		cout << "Test seems to have crashed or behaved unexpectedly.  (There will always be at least one grade entered.)" << endl;
//		cout << "Output size: " << output.size() << endl;
//		for(int i=0; i < output.size(); i++)
//		{
//			cout << output[i] << endl;
//		}
		return false;
	}
	else
	{
		bool flag = true;
		int gradeCount;
		int indexOffset;
		int delta;

		if(!is<int>(output[2]))
		{
			cout << "\tErrors: " << endl;
			cout << "\tProgram didn't repeat the number of grades to be entered!" << endl;
			flag = false;
			gradeCount = output.size() / 3;  // Assumption - only the data from each line will be detected.  (most common issue)
			delta = 0;
		}
		else
		{
			gradeCount = to<int>(output[0]);
			delta = 1;  // To skip the grade count in the future.
		}

		for(int i = 0; i < gradeCount; i++)
		{
			int index, score;
			string grade;

			int j = 3 * i + delta;

			index = to<int>(output[j]);
			score = to<int>(output[j+1]);
			grade =         output[j+2];

			if(score != scores[index] || grade != grades[index])
			{
				if(flag)
				{
					cout << "\tErrors: " << endl;
				}
				flag = false;

				cout << "\tStudent " << index << ": score = " << score << ", grade = " << grade << endl;
			}
		}

		if(flag)
		{
			cout << "\tTest passed!" << endl;
			return true;
		}
		else
			return false;
	}
}

// Write the true test here.
int main()
{
	vector<string> tokens;
	bool allPassed = true;
	bool res;

	vector<int> scores;
	vector<string> grades;

	int scoresArr1[] = {40, 55, 70, 58};
	string gradesArr1[] = {"C", "B", "A", "B"};
	scores = vector<int>(scoresArr1, scoresArr1 + sizeof(scoresArr1) / sizeof(scoresArr1[0]));
	grades = vector<string>(gradesArr1, gradesArr1 + sizeof(gradesArr1) / sizeof(gradesArr1[0]));

	printTestData(0, scores, grades);
	res = gradeCurverTest(scores, grades);
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

