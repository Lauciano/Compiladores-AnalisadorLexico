#include <fstream>
#include <vector>

using namespace std;

int main(int n_arg, char** args){
	//Vari�veis e Ponteiros
	ifstream *code;
	ofstream *lexc;
	string l_reserv[] = {"program", "var", "integer","real","boolean",
		"procedure","begin","end","if", "then","else","while","do","not"};
	string *f_name = new string(args[1]),
		*e_code = new string(".txt"),
		*e_lexc = new string(".out");

	//Abertura de Arquivos
	code = new ifstream((*f_name + *e_code).c_str());
	lexc = new ofstream((*f_name + *e_lexc).c_str());

	//An�lise L�xica

	/*Inicio do aut�mato, estado 1*/



	//Fechamento de Arquivos
	code->close;
	lexc->close;

	//Retorno
	return 0;
}