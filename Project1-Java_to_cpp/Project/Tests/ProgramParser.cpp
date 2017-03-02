/*
 * ProgramParser.cpp
 *
 *  Created on: May 27, 2015
 *      Author: Joshua
 */

#include <iostream>
#include "ProgramParser.h"
#include "exec-stream.h"

using namespace std;

// TestCore testing method.  Written in a generalized manner.
vector<string> runIndividualTest(string input, string program_name, string_selector filter)
{
	string s;
	vector<string> tokens;
	vector<string> returns;

	try
	{
		exec_stream_t process(program_name, "");
		process.in() << input << endl;

		int i = 0;

		// Tokenize all program output.
	    while( std::getline( process.out(), s ).good() )
	    {
	    	while(s.length() > 0)
	    	{
	    		i = s.find(' ');

	    		if(i == -1)
	    		{
	    			tokens.push_back(s);
	    			break;
	    		}

	    		tokens.push_back(s.substr(0, i));
	    		s = s.substr(i+1);
	    	}
	    }

		while(s.length() > 0)
		{
			i = s.find(' ');

			if(i == -1)
			{
				tokens.push_back(s);
				break;
			}

			tokens.push_back(s.substr(0, i));
			s = s.substr(i+1);
		}

	    // Determine the tokens to save.  Uses a function pointer to do so.
	    for(i=0; i < tokens.size(); i++)
	    {
	    	if(filter(tokens[i]))
	    	{
	    		returns.push_back(tokens[i]);
	    	}
	    }

	    //cout << endl;
	}
	catch(const std::exception &e)
	{
		cerr << "error: " << e.what() << endl;
		return vector<string>();
	}

	return returns;
}

