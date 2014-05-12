#include <fstream>
#include <vector>

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