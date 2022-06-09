#include "biblioteca.h"
#include <locale.h>

int operator-( date a, date b)
{
	int sub1{}, sub2{}, som1{}, dias{}, meses{},dia{},mes{};
	dias = b.day;
	meses = b.month;
	dia = a.day;
	mes = a.month;


	while (mes > meses) {
		for (int a = meses; a < mes; a++) {
			int ind = a; //salvando o indíce do for
			while (a == 1 || a == 3 || a == 5 || a == 7 || a == 8 || a == 10 || a == 12) {
				som1 += 31; //caso o for percorra um mês com um número correspondente, ele soma a  quantidade de dias do mês correspondente
				while ((dia - dias) <=-28) {
					dia += 31; //função criada para caso o número de dia do emprestimo seja maior que o dia atual
					som1 = 0;
				}
				a++;
					while(a == 8)//função criada para caso o mês correspondente ao a++ seja agosto 
					{
						++a;
					 }
			}
			a = ind; //recebendo o indíce de volta
			while (a == 2) {
				som1 += 28;//caso o for percorra um mês com um número correspondente, ele soma a  quantidade de dias do mês correspondente
				while ((dia - dias) <= -25) { //função criada para caso o número de dia do emprestimo seja maior que o dia atual
					dia += 28;
					som1 = 0;
				}
				a++;
			}
			a = ind;//recebendo o indíce de volta
			while (a == 4 || a == 6 || a == 9 || a == 11) {
				som1 += 30;//caso o for percorra um mês com um número correspondente, ele soma a  quantidade de dias do mês correspondente
				while ((dia - dias) <= -28) { //função criada para caso o número de dia do emprestimo seja maior que o dia atual
					dia += 30;
					som1 = 0;
				}
				a++;
			}
			a = ind;//recebendo o indíce de volta
		}
		mes -= meses; //equação criada para sair do for
	}
	sub2 = dia - dias; //recebendo a subtração da quantidade de dias
	som1 += sub2; //somando a quantidade de dias 

	return som1;
}

void linha(char a, int b)
{
	int v{};
	do {
		cout << a;
		v++;
	}
	while (b > v);
	cout << endl;
}

double multatotal(Pessoa a[], int b, date c)
{
	int inte = 1;
	float atraso{}, multas{}, teste{};
	for (int p = 0; p < b; p++) {
		atraso = operator-(c,a[p].dataa); // chamando a função para receeber a quantidade de dias totais 
		teste = atraso;
		while (teste <= 3) { //teste para saber se a quantidade de dias é igual ou menor que 3
			inte = 0;
			teste +=3;
		}
		atraso *= inte;
		inte = 1;
		atraso *= float(0.8);
		multas += atraso; // somando toda as multas em uma variável
	}
	return multas;
}

void exibir(Pessoa a, Pessoa * b)
{
	float inte{ 1 }, multadia{};
	locale C("C");
	cout.imbue(C);
	cout << b->mat_aln << " " << b->id_liv << " "; //imprimindo as informações do empréstimo
	cout.width(2);
	cout.fill('0');
	cout << b->dataa.day << "/";
	cout.width(2);
	cout.fill('0');
	cout << b->dataa.month << "/";
	cout << b->dataa.year << " ";
	locale pt("");
	cout.imbue(pt);
	multadia = operator-(a.diahj, b->dataa); //usando o operator- para receber a diferença de dias
	while (multadia <= 3) {//teste para saber se a quantidade de dias é igual ou menor que 3
		inte = 0;
		multadia += 3;
	}
	multadia *= inte;
	inte = 1;
	cout << "-> R$" << multadia * float(0.8); // calcula o preco da multa do livro em específico
	cout << endl;
}


	