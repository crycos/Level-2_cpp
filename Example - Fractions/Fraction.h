/*
 * Fraction.h
 *
 *  Created on: Jun 2, 2015
 *      Author: Joshua
 */

#ifndef FRACTION_H_
#define FRACTION_H_

#include <iostream>
using namespace std;

class Fraction {
public:
	Fraction(double, double);
	virtual ~Fraction();

public:
	double num, denom;
};

Fraction operator*(Fraction a, Fraction b);
ostream& operator<<(ostream &out, Fraction f);

#endif /* FRACTION_H_ */
