#include <fstream>

using namespace std;

int main(int n_arg, char** args){
	//Vari�veis e Ponteiros
	ifstream *code;
	ofstream *lexc;
	string *f_name = new string(args[1]),
		*e_code = new string(".code"),
		*e_lexc = new string(".lexc");

	//Abertura de Arquivos
	code = new ifstream((*f_name + *e_code).c_str());
	lexc = new ofstream((*f_name + *e_lexc).c_str());

	//An�lise L�xica

	//Fechamento de Arquivos
	code->close;
	lexc->close;

	//Retorno
	return 0;
}