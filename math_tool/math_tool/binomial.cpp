#include <iostream>
#include <iomanip>
#include "binomial.h"

using namespace std;

binomial::binomial(){
	system("CLS");
	ask();
}

void binomial::ask(void) {
	binomiale_2();
}

void binomial::binomiale_2(void) {
	double probabilite;
	double nb_succes;
	double grandeur;
	double nb_lancer;
	double resultat;

	cout << "Enter the success probabilty" << endl;
	cin >> probabilite;
	cout << "Enter the number of success" << endl;
	cin >> nb_succes;
	cout << "Enter the size of the distribution" << endl;
	cin >> grandeur;

	nb_lancer = nb_succes;
	while (nb_lancer <= grandeur) {
		resultat = 1 - cdf(nb_lancer, nb_succes, probabilite);
		cout << defaultfloat;
		cout << "X= " << nb_lancer << "  :   ";
		cout << fixed << setprecision(10);
		cout << resultat << "%     " << endl;
		nb_lancer++;
	}
}


double binomial::factorial(double n) {
	double factorial = 1;
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

double binomial::combinaison(double n, int x) {
	double combinaison = factorial(n) / (factorial(x) * factorial(n - x));
	return combinaison;
}

double binomial::binom_formula(double n, double k, double prob) {
	double prob_compl = 1 - prob;
	double resultat = combinaison(n, k)*pow(prob, k)*pow(prob_compl, (n - k));
	return resultat;
}


double binomial::cdf(double nb_lancer, double nb_succes, double probabilite) {
	double x = 0;
	double reponse = 0;
	while (x < nb_succes) {
		reponse = reponse + binom_formula(nb_lancer, x, probabilite);
		x++;
	}
	return reponse;
}




