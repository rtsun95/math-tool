#include "poly.h"


poly::poly()
{
	p.polyCreate();
}


poly::~poly()
{
}

void printNegative(double n){
	if (n < 0) printf("-");
}

void printPositive(double n){
	if (n >= 0) printf("+");
}

void printExponenent(int n){
	if (n > 1) printf("x^%d ", n);
	else if (n == 1) printf("x ");
}

void printCoefficient(double n, int i){
	if (fabs(n) != 1) printf("%g", fabs(n));
	if (fabs(n) == 1 && i == 0) printf("1");
}

struct poly *polyCreate(){
	struct poly *p = malloc(sizeof(*p));
	p->coefficient = 0.0;
	p->position = -1;
	p->next = NULL;
	return p;
}


struct poly *polyDelete(struct poly *p){
	if (p == NULL) return NULL;
	while (p->next != NULL){
		int *tmp = p;
		p = p->next;
		free(tmp);
	}
	free(p);
	return NULL;
}



struct poly *polySetCoefficient(struct poly *p, int i, double value){
	struct poly *q = polyCreate();
	if (p->next == NULL){
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
	if (p == NULL) return;
	int *start = p;
	if (p->position == i) {
		p = start;
		return p->coefficient;
	}
	if (p->next == NULL){
		p = start;
		return 0;
	}
	else{
		p = start;
		return polyGetCoefficient(p->next, i);
	}
}

int polyDegree(struct poly *p){
	if (p == NULL) return 0;
	int *start = p;
	int max = 0;
	if (p->next != NULL) max = polyDegree(p->next);
	if (p->position > max) max = p->position;
	p = start;
	return max;
}

void polyPrint(struct poly *p){
	if (p == NULL) return;
	int i = polyDegree(p);
	int passedFirst = 0;
	for (i; i >= 0; i--){
		double coef = polyGetCoefficient(p, i);
		if (coef != 0){
			if (passedFirst){
				printNegative(coef);
				printPositive(coef);
				printf(" ");
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
		printf("0");
	}
	printf("\n");
}

struct poly *polyCopy(struct poly *p){
	if (p == NULL) return NULL;
	struct poly *q = polyCreate();
	int i;
	for (i = 0; i <= polyDegree(p); i++){
		q = polySetCoefficient(q, i, polyGetCoefficient(p, i));
	}
	return q;
}

struct poly *polyAdd(struct poly *p0, struct poly *p1) {
	if (p0 == NULL&&p1 == NULL) return NULL;
	int i;
	struct poly *p2 = polyCreate();
	if (p0 == NULL){
		p2 = polyCopy(p1);
		return p2;
	}
	else if (p1 == NULL){
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
	if (p0 == NULL&&p1 == NULL) return NULL;
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
	if (p == NULL)return NULL;
	int i;
	struct poly *p2 = polyCreate();
	for (i = polyDegree(p); i > 0; i--)
		p2 = polySetCoefficient(p2, (i - 1), i*polyGetCoefficient(p, i));
	return p2;
}

double polyEval(struct poly *p, double x){
	if (p == NULL) return 0;
	double result = 0;
	int i;
	for (i = 0; i <= polyDegree(p); i++){
		result += pow(x, i)*polyGetCoefficient(p, i);
	}
	return result;
}