#include <fstream>
#include <vector>
#include <list>

using namespace std;


int main(int n_arg, char** args){
	//Vari�veis e Ponteiros
	ifstream *code;
	char c;
	ofstream *lexc;
	//string l_reserv[] = {"program", "var", "integer","real","boolean",
	//	"procedure","begin","end","if", "then","else","while","do","not"};
	char input[256] = "TextLex.txt", output[256] = "TextLex.out";
	//strcmp(input, args[1]);
	//strcmp(output, args[1]);
	//strcat(input, ".txt");
	//strcat(output, ".out");

	//std::list<lexToken> list;

	//Abertura de Arquivos
	//ISSO AQUI TEM ERRO LAU, CONSERTA A�. VOU ASSUMIR QUE CODE e LEXC EST�O FUNCIONANDO
	//O meu intellisense t� dizendo aqui que o operador "+" n�o pode ser usado com esses operandos a�
	code = new ifstream(input);
	lexc = new ofstream(output);
	//Vou fazer a escrita em C, depois se voc� quiser mudar beleza.
	//FILE *input, *output;
	//input = fopen((char*)(f_name),"r");
	//output = fopen((char*)(e_lexc),"w");
	

	//An�lise L�xica

	//Fechamento de Arquivos
	code->close();
	lexc->close();

	//Retorno
	return 0;
}