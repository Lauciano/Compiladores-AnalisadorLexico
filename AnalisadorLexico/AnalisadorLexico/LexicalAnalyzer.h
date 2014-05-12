#include <fstream>

using namespace std;

class LexicalAnalyzer{
public:
	LexicalAnalyzer();
	int analyze(ofstream *lexc, ifstream *code);
};