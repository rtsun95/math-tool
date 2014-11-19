#include<memory>
#include<iostream>

using namespace std;
#pragma once


class poly
{
	shared_ptr<poly> p;

	double coefficient;
	int position;
	unique_ptr<poly> next;

	poly *polyCreate();
	void printNegative(double n);
	void printPositive(double n);
	void printExponenent(int n);
	void printCoefficient(double n, int i);
	poly *polyDelete(poly *p);
	double polyGetCoefficient(poly *p, int i);
	int polyDegree(poly *p);

public:
	poly ();
	poly *polySetCoefficient(poly *p, int i, double value);
	poly *polyCopy(poly *p);
	poly *polyAdd(poly *p0, poly *p1);
	poly *polyMultiply(poly *p0, poly *p1);
	poly *polyPrime(poly *p);
	double polyEval(poly *p, double x);
	void polyPrint(poly *p);
};

