#include <fstream>
#include <vector>
#include <stdio.h>
#include <list>

using namespace std;

class lexToken
{
	int linha;
	string nome;
	string classificacao;

public:
	lexToken(int line, string name, string classif){
		linha = line;
		nome = name;
		classificacao = classif;
	}
};

int main(int n_arg, char** args){
	//Variáveis e Ponteiros
	ifstream *code;
	char c;
	ofstream *lexc;
	string l_reserv[] = {"program", "var", "integer","real","boolean",
		"procedure","begin","end","if", "then","else","while","do","not"};
	string *f_name = new string(args[1]),
		*e_code = new string(".txt"),
		*e_lexc = new string(".out");

	std::list<lexToken> list;

	//Abertura de Arquivos
	//ISSO AQUI TEM ERRO LAU, CONSERTA AÍ. VOU ASSUMIR QUE CODE e LEXC ESTÃO FUNCIONANDO
	//O meu intellisense tá dizendo aqui que o operador "+" não pode ser usado com esses operandos aí
	//code = new ifstream((*f_name + *e_code).c_str());
	//lexc = new ofstream((*f_name + *e_lexc).c_str());
	//Vou fazer a escrita em C, depois se você quiser mudar beleza.
	FILE *input, *output;
	input = fopen((char*)(f_name),"r");
	output = fopen((char*)(e_lexc),"w");
	

	//Análise Léxica
	/*Inicio do autômato, estado 1*/
	while((c = fgetc(input)) =! EOF){




	//Fechamento de Arquivos
	code->close;
	lexc->close;

	//Retorno
	return 0;
}