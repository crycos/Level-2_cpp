/*
 * Fraction.cpp
 *
 *  Created on: Jun 2, 2015
 *      Author: Joshua
 */

#include "Fraction.h"

Fraction::Fraction()
{
	num = 0;
	denom = 1;
}

Fraction::Fraction(double num, double denom) {
	this->num = num;
	this->denom = denom;
}

Fraction::~Fraction() {

}

Fraction operator*(Fraction a, Fraction b)
{
	double finalNum = a.num * b.num;
	double finalDenom = b.denom * b.denom;

	return Fraction(finalNum, finalDenom);
}

ostream& operator<<(ostream &out, Fraction f)
{
	return out << f.num << "/" << f.denom;
}
