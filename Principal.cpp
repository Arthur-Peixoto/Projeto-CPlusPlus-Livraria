#include <locale.h>
#include "biblioteca.h"

int main() {
	system("chcp 1252 > nul");
	int tam, atraso{}, mess{}, inte{ 1 };
	float multatot, multaa{};
	char ch;
	cout << "Qual o número de devoluções para hoje? ";
	cin >> tam; //lê o teamaho do vetor dinâmico
	Pessoa* vet = new Pessoa[tam]; //cria o vetor dnâmico do tipo pessoa
	cout << "Qual a data de devolução: ";
	cin >> vet[0].diahj.day >> ch >> vet[0].diahj.month >> ch >> vet[0].diahj.year; // lê a data do dia atual
	linha('-', 43); //função linha sendo executada 
	for (int i = 0; i < tam; i++) {
		int ind = i;
		cout << "Aluno ";
		cout << right;
		cout.width(7);
		cout << ": ";
		cin >> vet[i].mat_aln; //recebendo o matrícula do aluno
		cout << "Livro ";
		cout << right;
		cout.width(7);
		cout << ": ";
		cin >> vet[i].id_liv; //recebendo o id do livro
		cout << "Empréstimo : ";
		cin >> vet[i].dataa.day >> vet->cha >> vet[i].dataa.month >> vet->cha >> vet[i].dataa.year; // recebendo a data do dio empréstimo do livro
		atraso = operator-(vet->diahj, vet[i].dataa); // chamando a função operator
		cout << "Atraso ";
		cout << right;
		cout.width(6);
		cout << ": ";
		cout << atraso << " dia(s)" << endl; //imprimindo o retorno da função operator-
		while (atraso <= 3) {
			inte = 0;
			atraso += 3;
		}
		atraso *= inte;//caso seja maior que 3 ele será multiplicado por 1, caso entre no while, a variável mudará o valor e passará a ser 0 e o valor da multa também
		inte = 1;
		multaa = (atraso * float(0.8)); // fazendo o teste para saber se o retorno é menor que 3 dias;
		cout << fixed;
		cout.precision(2);
		cout << "Multa ";
		cout << right;
		cout.width(7);
		cout << ": ";
		cout << "R$" << multaa << endl; // imprimindo o valor da multa
		while ((i + 1) < tam) { //para que a linha não se repita na última execução foi criado o seguinte teste
			linha('-', 33);
			i += tam;
		}
		i = ind;//variável criada apenas para recuperar o valor do indíce do for
	}
	linha('-', 43);//função linha sendo executada

	mess = vet->diahj.month;
	const char meses[13][10]{ // matriz criada para tornar mais fácil a impressão do nome do mês no resumo do dia
		{" "},{"Janeiro"},{"Fevereiro"},{"Março"},{"Abril"},{"Maio"},{"Junho"},{"Julho"},{"Agosto"},{"Setembro"},{"Outubro"},{"Novembro"},{"Dezembro"}
	};
	locale C("C");
	cout.imbue(C);
	cout << "Resumo do dia ";
	cout.width(2);
	cout.fill('0');
	cout << vet->diahj.day; 
	cout << " de " << mess[meses] << " de " << vet->diahj.year << endl; //impressão da data do dia atual com o mês por extenso
	cout << endl;

	for (int h{}; h < tam; h++) { // for para chamar a função exibir de cada resultado recebido dentro do último for
		exibir(*vet, &vet[h]);
	}
	locale pt("");
	cout.imbue(pt);
	multatot = multatotal(vet, tam, vet->diahj); //chama a função total
	cout << "Total em multas: R$" << multatot << endl;
	linha('-', 43);
	cout << "Encerrando programa...";

	delete [] vet;
}
