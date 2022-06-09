#include <iostream>
using namespace std;

struct date {
	int day;
	int month;
	int year;
};

struct Pessoa {
	char mat_aln[10];
	char id_liv[5];
	char cha;
	date diahj;
	date dataa;
};

int operator-( date a, date b);

void linha(char a, int b);

double multatotal(Pessoa a[], int b, date c);

void exibir(Pessoa a, Pessoa * b);
