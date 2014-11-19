#include <iostream>
#include <iomanip>

#include "math_operator.h"

using namespace std;


math_operator::math_operator(){
	int n = 0;
}

int math_operator::factorial(int n) {
	int factorial = 1;
	if (n < 0) {
		cout << "Error !" << endl;
	}
	if (n == 0) {
		factorial = 1;
	}
	else {
		while (n > 0) {
			factorial = n*factorial;
			n--;
		}
	}
	return factorial;
}
