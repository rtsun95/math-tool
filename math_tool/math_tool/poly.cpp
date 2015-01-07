#include <iostream>
#include "poly.h"

using namespace std;

void printNegative(double n){
	if (n < 0) cout << "-";
}

void printPositive(double n){
	if (n >= 0)  cout << "+";
}

void printExponenent(int n){
	if (n > 1)  cout << "x^" << n;
	else if (n == 1)  cout << "x ";
}

void printCoefficient(double n, int i){
	if (fabs(n) != 1)  cout << fabs(n);
	if (fabs(n) == 1 && i == 0)  cout << "1";
}

struct poly *polyCreate(){
	struct poly *p = new poly[1];
	p->coefficient = 0.0;
	p->position = -1;
	p->next = nullptr;
	return p;
}


struct poly *polyDelete(struct poly *p){
	if (p == nullptr) return nullptr;
	while (p->next != nullptr){
		poly *tmp = p;
		p = p->next;
		delete tmp;
	}
	delete p;
	return nullptr;
}



struct poly *polySetCoefficient(struct poly *p, int i, double value){
	struct poly *q = polyCreate();
	if (p->next == nullptr){
		p->next = q;
		p->position = i;
		p->coefficient = value;
		return p;
	}
	else{
		q->next = p->next;
		q->position = i;
		q->coefficient = value;
		p->next = q;
		return p;
	}
}

double polyGetCoefficient(struct poly *p, int i){
	if (p == nullptr) return 0;
	poly *start = p;
	if (p->position == i) {
		p = start;
		return p->coefficient;
	}
	if (p->next == nullptr){
		p = start;
		return 0;
	}
	else{
		p = start;
		return polyGetCoefficient(p->next, i);
	}
}

int polyDegree(struct poly *p){
	if (p == nullptr) return 0;
	poly *start = p;
	int max = 0;
	if (p->next != nullptr) max = polyDegree(p->next);
	if (p->position > max) max = p->position;
	p = start;
	return max;
}

void polyPrint(struct poly *p){
	if (p == nullptr) return;
	int i = polyDegree(p);
	int passedFirst = 0;
	for (i; i >= 0; i--){
		double coef = polyGetCoefficient(p, i);
		if (coef != 0){
			if (passedFirst){
				printNegative(coef);
				printPositive(coef);
				cout << " ";
				printCoefficient(coef, i);
				printExponenent(i);
			}
			else{
				printNegative(coef);
				printCoefficient(coef, i);
				printExponenent(i);
				passedFirst = 1;
			}
		}
	}
	if (passedFirst == 0){
		cout << "0";
	}
}

struct poly *polyCopy(struct poly *p){
	if (p == nullptr) return nullptr;
	struct poly *q = polyCreate();
	int i;
	for (i = 0; i <= polyDegree(p); i++){
		q = polySetCoefficient(q, i, polyGetCoefficient(p, i));
	}
	return q;
}

struct poly *polyAdd(struct poly *p0, struct poly *p1) {
	if (p0 == nullptr&&p1 == nullptr) return nullptr;
	int i;
	struct poly *p2 = polyCreate();
	if (p0 == nullptr){
		p2 = polyCopy(p1);
		return p2;
	}
	else if (p1 == nullptr){
		p2 = polyCopy(p0);
		return p2;
	}
	int max = polyDegree(p0);
	if (polyDegree(p1) > max) max = polyDegree(p1);
	for (i = 0; i <= max; i++){
		p2 = polySetCoefficient(p2, i, (polyGetCoefficient(p0, i) + polyGetCoefficient(p1, i)));
	}
	return p2;
}

struct poly *polyMultiply(struct poly *p0, struct poly *p1){
	if (p0 == nullptr&&p1 == nullptr) return nullptr;
	int i, j;
	struct poly *p2 = polyCreate();
	for (i = 0; i <= polyDegree(p0); i++){
		struct poly *temp = p2;
		struct poly *p3 = polyCreate();
		for (j = 0; j <= polyDegree(p1); j++){
			p3 = polySetCoefficient(p3, (i + j), polyGetCoefficient(p0, i)*polyGetCoefficient(p1, j));
		}
		p2 = polyAdd(p2, p3);
		polyDelete(temp);
		polyDelete(p3);
	}

	return p2;
}

struct poly *polyPrime(struct poly *p){
	if (p == nullptr)return nullptr;
	int i;
	struct poly *p2 = polyCreate();
	for (i = polyDegree(p); i > 0; i--)
		p2 = polySetCoefficient(p2, (i - 1), i*polyGetCoefficient(p, i));
	return p2;
}

struct poly *polyInteg(struct poly *p){
	if (p == nullptr)return nullptr;
	int i;
	struct poly *p2 = polyCreate();
	for (i = polyDegree(p); i > 0; i--)
		p2 = polySetCoefficient(p2, (i + 1), i/polyGetCoefficient(p, i));
	return p2;
}

double polyEval(struct poly *p, double x){
	if (p == nullptr) return 0;
	double result = 0;
	int i;
	for (i = 0; i <= polyDegree(p); i++){
		result += pow(x, i)*polyGetCoefficient(p, i);
	}
	return result;
}

double bissection(struct poly *p, double a, double b){
	//x will be a guess of the root between a and b while fx is f(x)
	double x, fx;
	for (int i = 0; i < 100000; i++)
	{
		//Check if a or b is a root
		if (polyEval(p,a) <= 0.0001) return a;
		else if (polyEval(p, b) <= 0.0001) return b;
		

		//we assign x as the middle point of a and b
		x = (a + b) / 2.0;
		//we apply the function f to x to obtain f(x)
		fx = polyEval(p, x);
		//if f(x) is close enough to zero (smaller than epsilon), return the value of x
		if (fabs(fx) <= 0.0001)
			return x;
		//if f(x) is not big enough, if f(x) is positive, set x as the new value of b
		if (fx > 0.0)
			b = x;
		//if f(x) is not big enough, if f(x) is negative, set x as the new value of b
		else
			a = x;
	}
	//if the maximum value of iterations is reached, just return the value of x
	return x;
}

struct poly *getPoly(int x){
	system("CLS");
	struct poly *p = polyCreate();
	int number_coefficient;
	cout << "Please enter the number of non-zero coeffiecient in the polynomial #" << x << endl;
	cin >> number_coefficient;
	for (int i = 1; i <= number_coefficient; i++){
		int power;
		double coefficient;
		cout << "What is the coefficient #" << i << "?" << endl;
		cin >> coefficient;
		cout << "What is the degree of the coefficient?" << endl;
		cin >> power;
		polySetCoefficient(p, power, coefficient);
	}
	return p;
}