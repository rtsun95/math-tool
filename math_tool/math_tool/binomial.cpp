#include <iostream>
#include <iomanip>
#include "binomial.h"
 
using namespace std;



binomial::binomial()
{
	char restart;
	bool rec = true;
	while (rec == true) {
		binomiale_2();
		cout << endl << endl << "Do you want to restart? (y = yes, n = no) " << endl;
		cin >> restart;
		if (restart == 'y' || restart == 'Y') {
			rec = true;
		}
		else {
			rec = false;
		}
	}
}


binomial::~binomial()
{
}



double factoriel(double n) {
	double factoriel = 1;
	if (n < 0) {
		cout << "Erreur !" << endl;
	}
	if (n == 0) {
		factoriel = 1;
	}
	else {
		while (n > 0) {
			factoriel = n*factoriel;
			n--;
		}
	}
	return factoriel;
}

double combinaison(double n, double x) {
	double combinaison = factoriel(n) / (factoriel(x) * factoriel(n - x));
	return combinaison;
}

double binomiale(double n, double k, double prob) {
	double prob_compl = 1 - prob;
	double resultat = combinaison(n, k)*pow(prob, k)*pow(prob_compl, (n - k));
	return resultat;
}


double cdf(double nb_lancer, double nb_succes, double probabilite) {
	double x = 0;
	double reponse = 0;
	while (x < nb_succes) {
		reponse = reponse + binomiale(nb_lancer, x, probabilite);
		x++;
	}
	return reponse;
}


void binomiale_2(void) {
	double probabilite;
	double nb_succes;
	double grandeur;
	double nb_lancer;
	double resultat;

	cout << "Entrer la probabilite de succes" << endl;
	cin >> probabilite;
	cout << "Entrer le nombre de succes" << endl;
	cin >> nb_succes;
	cout << "Entrer la grandeur de la distribution" << endl;
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