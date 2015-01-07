#include <iostream>
#include "binomial.h"
#include "poisson.h"
#include "poly.h"
#include "PolyMenu.h"
#include "Triangle.h"

using namespace std;

void mainscreen(){
	int selector;
	cout << "Please select which program you want to use:" << endl;
	cout << "1 : Polynomial operations" << endl;
	cout << "2 : Poisson distribution" << endl;
	cout << "3 : Binomial distribution" << endl;
	cin >> selector;
	if (selector == 1){
		polynomial();
	}
	else if (selector == 2){
		poisson();
	}
	else if (selector == 3){
		binomial();
	}
	else if (selector == 4){
		Triangle();
	}
	return;
}

int main(void){

	char restart;
	bool rec = true;
	while (rec == true) {
		system("CLS");
		mainscreen();
		cout << endl << endl << "Would you like to restart ? (y=yes/n=no)" << endl;
		cin >> restart;
		if (restart == 'y' || restart == 'Y') {
			rec = true;
		}
		else {
			rec = false;
		}
	}

	system("pause");
	return 0;
}