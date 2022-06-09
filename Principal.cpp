#include <locale.h>
#include "biblioteca.h"

int main() {
	system("chcp 1252 > nul");
	int tam, atraso{}, mess{}, inte{ 1 };
	float multatot, multaa{};
	char ch;
	cout << "Qual o n�mero de devolu��es para hoje? ";
	cin >> tam; //l� o teamaho do vetor din�mico
	Pessoa* vet = new Pessoa[tam]; //cria o vetor dn�mico do tipo pessoa
	cout << "Qual a data de devolu��o: ";
	cin >> vet[0].diahj.day >> ch >> vet[0].diahj.month >> ch >> vet[0].diahj.year; // l� a data do dia atual
	linha('-', 43); //fun��o linha sendo executada 
	for (int i = 0; i < tam; i++) {
		int ind = i;
		cout << "Aluno ";
		cout << right;
		cout.width(7);
		cout << ": ";
		cin >> vet[i].mat_aln; //recebendo o matr�cula do aluno
		cout << "Livro ";
		cout << right;
		cout.width(7);
		cout << ": ";
		cin >> vet[i].id_liv; //recebendo o id do livro
		cout << "Empr�stimo : ";
		cin >> vet[i].dataa.day >> vet->cha >> vet[i].dataa.month >> vet->cha >> vet[i].dataa.year; // recebendo a data do dio empr�stimo do livro
		atraso = operator-(vet->diahj, vet[i].dataa); // chamando a fun��o operator
		cout << "Atraso ";
		cout << right;
		cout.width(6);
		cout << ": ";
		cout << atraso << " dia(s)" << endl; //imprimindo o retorno da fun��o operator-
		while (atraso <= 3) {
			inte = 0;
			atraso += 3;
		}
		atraso *= inte;//caso seja maior que 3 ele ser� multiplicado por 1, caso entre no while, a vari�vel mudar� o valor e passar� a ser 0 e o valor da multa tamb�m
		inte = 1;
		multaa = (atraso * float(0.8)); // fazendo o teste para saber se o retorno � menor que 3 dias;
		cout << fixed;
		cout.precision(2);
		cout << "Multa ";
		cout << right;
		cout.width(7);
		cout << ": ";
		cout << "R$" << multaa << endl; // imprimindo o valor da multa
		while ((i + 1) < tam) { //para que a linha n�o se repita na �ltima execu��o foi criado o seguinte teste
			linha('-', 33);
			i += tam;
		}
		i = ind;//vari�vel criada apenas para recuperar o valor do ind�ce do for
	}
	linha('-', 43);//fun��o linha sendo executada

	mess = vet->diahj.month;
	const char meses[13][10]{ // matriz criada para tornar mais f�cil a impress�o do nome do m�s no resumo do dia
		{" "},{"Janeiro"},{"Fevereiro"},{"Mar�o"},{"Abril"},{"Maio"},{"Junho"},{"Julho"},{"Agosto"},{"Setembro"},{"Outubro"},{"Novembro"},{"Dezembro"}
	};
	locale C("C");
	cout.imbue(C);
	cout << "Resumo do dia ";
	cout.width(2);
	cout.fill('0');
	cout << vet->diahj.day; 
	cout << " de " << mess[meses] << " de " << vet->diahj.year << endl; //impress�o da data do dia atual com o m�s por extenso
	cout << endl;

	for (int h{}; h < tam; h++) { // for para chamar a fun��o exibir de cada resultado recebido dentro do �ltimo for
		exibir(*vet, &vet[h]);
	}
	locale pt("");
	cout.imbue(pt);
	multatot = multatotal(vet, tam, vet->diahj); //chama a fun��o total
	cout << "Total em multas: R$" << multatot << endl;
	linha('-', 43);
	cout << "Encerrando programa...";

	delete [] vet;
}
