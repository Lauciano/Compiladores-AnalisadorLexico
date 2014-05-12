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
private:
	/* Tabela de Léxicos */
	vector<string> *token;
	vector<string> *type;
	vector<unsigned int> *line;
	/* Lista de Palavras Reservadas */
	vector<string> *restricted_word;
};