#include <iostream>
#include <vector>
#include <iomanip>
#include "poisson.h"

using namespace std;

poisson::poisson(){
	system("CLS");
	ask();
}

void poisson::ask(void){
	distribution();
}

void  poisson::distribution(void){
	cout << "Please enter the parameter : " << endl;
	cin >> parameter;
	do{
		cout << "Please enter the desired size of the distribution" << endl;
		cin >> size;
		if (size < 0) cout << "Please enter a size greater than 0" << endl;
	} while (size < 0);
	distribution_print();
}

void  poisson::distribution_print(){
	int count = 0;
	double cdf = 0;
	double answer;
	while (size >= count){
		answer = formula(parameter, count);
		//if (answer < 0.0000000001) answer = 0;
		cdf += answer;
		cout << "X=" << setw(4) << count << " :  ";
		if (answer > 0.00000000001) cout << fixed << setprecision(8) << answer << "     ";
		else cout << scientific << setprecision(3) << answer << "     ";
		cout << fixed << setprecision(5) << cdf << endl;
		count++;
	}
}

double  poisson::factorial_division(double _y, int _n){
	double result = 1;
	for (int i = _n; i > 0; i--){
		result *= _y / i;
	}
	return result;
}

double  poisson::formula(double _m, int _x){
	if (_x == 0) return exp(-_m);
	else return exp(-_m) * factorial_division(_m, _x);
}


