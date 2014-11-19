#include <iostream>
#include <vector>
#include <iomanip>
#include "poisson.h"

using namespace std;

void poisson::distribution(){
	ask();
	print();
}

void poisson::ask(){
	cout << "Please enter the parameter ¦Ë : " << endl;
	cin >> parameter;
	do{
		cout << "Please enter the desired size of the distribution" << endl;
		cin >> size;
		if (size < 0) cout << "Please enter a size greater than 0" << endl;
	} while (size < 0);
}

void poisson::print(){
	int count = 0;
	double cdf = 0;
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

double poisson::factorial_division(double y, int n){
	double result = 1;
	for (int i = n; i > 0; i--){
		result *= y / i;
	}
	return result;
}

double poisson::formula(double m, int x){
	if (x == 0) return exp(-m);
	else return exp(-m) * factorial_division(m, x);
}


