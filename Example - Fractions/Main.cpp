/*
 * HelloWorld.cpp
 *
 *  Created on: May 26, 2015
 *      Author: Joshua
 */

#include <iostream>
#include <vector>

#include "Fraction.h"

using namespace std;

int main()
{
	Fraction f1(2, 3);
	Fraction f2(5, 7);

	cout << f1 << " * " << f2 << " = ";

	Fraction f3 = f1 * f2;

	cout << f3 << endl;
}


