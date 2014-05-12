#include <fstream>
#include <vector>

using namespace std;

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