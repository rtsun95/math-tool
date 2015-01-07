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
	switch (selector)
	{
	case 1:
		poly *p = getPoly(1);
		double a, b;
		cout << "Left border?" << endl;
		cin >> a;
		cout << endl << "Right border?" << endl;
		cin >> b;
		while (polyEval(p, a) / polyEval(p, b) < 0){
			cout << endl << "f(a) and f(b) have the same sign, please retry";
			cout << "Left border?" << endl;
			cin >> a;
			cout << endl << "Right border?" << endl;
			cin >> b;
		}
		bissection(p, a, b);
		break;
	case 2:
		poly *p = getPoly(1);
		poly *q = getPoly(2);
		polyAdd(p, q);
		break;
	case 3:
		poly *p = getPoly(1);
		poly *q = getPoly(2);
		polyMultiply(p, q);
		break;
	case 4:
		poly *p = getPoly(1);
		double x;
		cout << "Please enter the value of x :" << endl;
		cin >> x;
		polyEval(p, x);
		break;
	case 5:
		poly *p = getPoly(1);
		polyPrime(p);
		break;
	case 6:
		poly *p = getPoly(1);
		polyInteg(p);
		break;
	default:
		break;
	}
	return;
}

