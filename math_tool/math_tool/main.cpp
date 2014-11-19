#include <iostream>
#include "binomial.h"
#include "poisson.h"

using namespace std;

bool mainscreen(){
	int selector;
	cout << "Please select witch program you want to use:" << endl;
	cout << "1 : Polynomial operations" << endl;
	cout << "2 : Poisson distribution" << endl;
	cout << "3 : Binomial distribution" << endl;
	cin >> selector;
	/*if (selector == 1){
	polynomial();
	return true;
	}*/
	if (selector == 2){
		poisson();
		return true;
	}
	if (selector == 3){
		binomial();
		return true;
	}
	else return false;
}

int main(void){

	do{
		mainscreen();
	} while (false);

	system("pause");
	return 0;
}