#include <iostream>
#include "poly.h"
#include "PolyMenu.h"

using namespace std;

void polynomial(){
	system("CLS");
	int selector;
	cout << "Please select a function:" << endl;
	cout << "1 : Polynomial solver" << endl;
	cout << "2 : Polynomial sum" << endl;
	cout << "3 : Polynomial product" << endl;
	cout << "4 : Evaluate a polynomial" << endl;
	cout << "5 : Derive a polynomial" << endl;
	cout << "6 : Integrate a polynomial" << endl;
	cin >> selector;
	system("CLS");
	switch (selector)
	{
	case 1:
		poly *p = getPoly();
		bissection(p);
		break;
	case 2:
		poly *p = getPoly();
		poly *q = getPoly();
		polyAdd(p, q);
		break;
	case 3:
		poly *p = getPoly();
		poly *q = getPoly();
		polyMultiply(p, q);
		break;
	case 4:
		poly *p = getPoly();
		double x;
		cout << "Please enter the value of x :" << endl;
		cin >> x;
		polyEval(p, x);
		break;
	case 5:
		poly *p = getPoly();
		polyDegree(p);
		break;
	case 6:
		poly *p = getPoly();
		polyInteg(p);
		break;
	default:
		break;
	}
	return;
}

