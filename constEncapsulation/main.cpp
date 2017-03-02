/*
 * main.cpp
 *
 *  Created on: Jun 5, 2015
 *      Author: Joshua
 */

#include <iostream>
#include "CustomVector.h"
#include "Fraction.h"

using namespace std;

int main()
{
	CustomVector<Fraction> vec;

	vec.add(Fraction(3, 4));
	vec.add(Fraction(1, 2));

	const CustomVector<Fraction> constVec = vec;

	cout << "Vector contents: " << endl;

	cout << constVec << endl;

	cout << "Vector size: " << vec.size() << endl;

}

//int main()
//{
//	CustomVector<Fraction*> vec;
//
//	vec.add(new Fraction(3, 4));
//	vec.add(new Fraction(1, 2));
//
//	const CustomVector<Fraction*> constVec = vec;
//	const Fraction* f = constVec[0];
//
//	cout << *f << " vs ";
//
//	//f->num = 7;
//	vec[0]->num = 7;
//
//	cout << *f;
//
//	cout << endl << endl << *vec[0] << " " << *vec[1];
//}
