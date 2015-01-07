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

	if (selector == 1){
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
		cout << endl << "X = " << bissection(p, a, b) << endl;
		polyDelete(p);
	}
	else if (selector == 2){
		poly *p = getPoly(1);
		poly *q = getPoly(2);
		poly *result = polyAdd(p, q);
		polyPrint(result);
		cout << endl;
		polyDelete(p);
		polyDelete(q);
		polyDelete(result);
	}
	else if (selector == 3){
		poly *p = getPoly(1);
		poly *q = getPoly(2);
		poly *result = polyMultiply(p, q);
		polyPrint(result);
		cout << endl;
		polyDelete(p);
		polyDelete(q);
		polyDelete(result);
	}
	else if (selector == 4){
		poly *p = getPoly(1);
		double x;
		cout << "Please enter the value of x :" << endl;
		cin >> x;
		cout << endl << "f(x) = " << polyEval(p, x) << endl;
		polyDelete(p);
	}
	else if (selector == 5){
		poly *p = getPoly(1);
		poly *q = polyPrime(p);
		cout << "f'(x) = ";
		polyPrint(q);
		cout << endl;
		polyDelete(p);
		polyDelete(q);
	}
	else if (selector == 6){
		poly *p = getPoly(1);
		poly *q = polyInteg(p);
		cout << "Integral of f(x) = ";
		polyPrint(q);
		cout << "+ C" << endl;
		polyDelete(p);
		polyDelete(q);
	}
	return;
}

