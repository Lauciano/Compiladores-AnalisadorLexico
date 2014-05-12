#include <fstream>
#include <string.h>
#include <vector>

using namespace std;

class lexToken {
public:
	lexToken(unsigned int line, string name, string classif){
		linha = line;
		nome = name;
		classificacao = classif;
	}
private:
	unsigned int linha;
	string nome;
	string classificacao;
};


class LexicalAnalyzer{
public:
	LexicalAnalyzer();
	~LexicalAnalyzer();
	int analyze(ifstream *code);
	bool checkRestriction(string word);
	bool isLetter(char symbol);
	bool isNumber(char symbol);
private:
	/* Tabela de Léxicos */
	vector<lexToken> *token;
	/* Lista de Palavras Reservadas */
	vector<string> *restricted_word;
};