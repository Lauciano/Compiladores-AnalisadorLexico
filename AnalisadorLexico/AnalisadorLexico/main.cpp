#include <fstream>
#include <vector>

using namespace std;

int main(int n_arg, char** args){
	//Variáveis e Ponteiros
	ifstream *code;
	ofstream *lexc;
	vector<string> l_reserv = {"program", "var", "integer","real","boolean",
		"procedure","begin","end","if", "then","else","while","do","not"};
	string *f_name = new string(args[1]),
		*e_code = new string(".code"),
		*e_lexc = new string(".lexc");

	//Abertura de Arquivos
	code = new ifstream((*f_name + *e_code).c_str());
	lexc = new ofstream((*f_name + *e_lexc).c_str());

	//Análise Léxica

	//Fechamento de Arquivos
	code->close;
	lexc->close;

	//Retorno
	return 0;
}