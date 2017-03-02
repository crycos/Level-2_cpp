/*
 * ProgramParser.h
 *
 *  Created on: May 27, 2015
 *      Author: Joshua
 */

#ifndef PROGRAMPARSER_H_
#define PROGRAMPARSER_H_

#include <string>
#include <vector>

using namespace std;

// This, my friends, is defining a new type ("string_selector") as a POINTER to a FUNCTION.
typedef bool (*string_selector)(string);

// The core method for running an executable test program.
vector<string> runIndividualTest(string input, string program_name, string_selector filter);

#endif /* PROGRAMPARSER_H_ */
