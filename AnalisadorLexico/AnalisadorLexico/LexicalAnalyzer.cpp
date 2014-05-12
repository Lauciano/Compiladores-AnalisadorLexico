#include "LexicalAnalyzer.h"

LexicalAnalyzer::LexicalAnalyzer(){
	token = new vector<string>();
	type = new vector<string>();
	line = new vector<unsigned int>();
	restricted_word = new vector<string>();
	restricted_word->insert(restricted_word->end(), "program");
	restricted_word->insert(restricted_word->end(), "var");
	restricted_word->insert(restricted_word->end(), "integer");
	restricted_word->insert(restricted_word->end(), "real");
	restricted_word->insert(restricted_word->end(), "boolean");
	restricted_word->insert(restricted_word->end(), "procedure");
	restricted_word->insert(restricted_word->end(), "begin");
	restricted_word->insert(restricted_word->end(), "end");
	restricted_word->insert(restricted_word->end(), "if");
	restricted_word->insert(restricted_word->end(), "then");
	restricted_word->insert(restricted_word->end(), "else");
	restricted_word->insert(restricted_word->end(), "while");
	restricted_word->insert(restricted_word->end(), "do");
	restricted_word->insert(restricted_word->end(), "not");
}

int LexicalAnalyzer::analyze(ifstream *code){
	string *word;
	bool comentary = false;
	char reading[256], tk[256];
	unsigned int counter = 0;
	while (!code->eof()){
		code->getline(reading, 256);
		counter++;
		for (int i = 0; i < 256; /*Propositalmente Vazio*/){
			/* Conjuntos de Símbolos */
			/* Palavra Reservada */
			if (reading[i] == '_' || isLetter(reading[i])){

			}
			/* Símbolos Compostos */
			/* Comando de Atribuição */
			if (reading[i] == ':' && reading[i + 1] == '='){
				tk[0] = reading[i];	tk[1] = reading[i + 1];	tk[2] = '\0';
				token->insert(token->end(), *(new string(tk)));
				type->insert(type->end(), "Comando de Atribuição");
				line->insert(line->end(), counter);
				i += 2;
			}
			/* Operadores Relacionais */
			else if (reading[i] == '<' && reading[i + 1] == '='){
				tk[0] = reading[i];	tk[1] = reading[i + 1];	tk[2] = '\0';
				token->insert(token->end(), *(new string(tk)));
				type->insert(type->end(), "Operador relacional");
				line->insert(line->end(), counter);
				i += 2;
			}
			else if (reading[i] == '>' && reading[i + 1] == '='){
				tk[0] = reading[i];	tk[1] = reading[i + 1];	tk[2] = '\0';
				token->insert(token->end(), *(new string(tk)));
				type->insert(type->end(), "Operador relacional");
				line->insert(line->end(), counter);
				i += 2;
			}
			else if (reading[i] == '<' && reading[i + 1] == '>'){
				tk[0] = reading[i];	tk[1] = reading[i + 1];	tk[2] = '\0';
				token->insert(token->end(), *(new string(tk)));
				type->insert(type->end(), "Operador relacional");
				line->insert(line->end(), counter);
				i += 2;
			}
			/* Operadores Aditivos */
			else if (reading[i] == 'o' && reading[i + 1] == 'r'){
				tk[0] = reading[i];	tk[1] = reading[i + 1];	tk[2] = '\0';
				token->insert(token->end(), *(new string(tk)));
				type->insert(type->end(), "Operador aditivo");
				line->insert(line->end(), counter);
				i += 2;
			}
			/* Operadores Multiplicativo */
			else if (reading[i] == 'a' && reading[i + 1] == 'n' && reading[i + 2] == 'd'){
				tk[0] = reading[i];	tk[1] = reading[i + 1];	tk[2] = reading[i + 2]; tk[3] = '\0';
				token->insert(token->end(), *(new string(tk)));
				type->insert(type->end(), "Operador multiplicativo");
				line->insert(line->end(), counter);
				i += 3;
			}
			/********************/
			/* Símbolos Simples */
			/* Delimitadores */
			else if (reading[i] == ';' || reading[i] == '.' || reading[i] == ':' || reading[i] == '(' || reading[i] == ')' || reading[i] == ','){
				token->insert(token->end(), *(new string(&reading[i])));
				type->insert(type->end(), "Delimitador");
				line->insert(line->end(), counter);
				i++;
			}
			/* Operador Relacional */
			else if (reading[i] == '=' || reading[i] == '<' || reading[i] == '>'){
				token->insert(token->end(), *(new string(&reading[i])));
				type->insert(type->end(), "Operador relacional");
				line->insert(line->end(), counter);
				i++;
			}
			/* Operador Aditivo */
			else if (reading[i] == '+' || reading[i] == '-'){
				token->insert(token->end(), *(new string(&reading[i])));
				type->insert(type->end(), "Operador aditivo");
				line->insert(line->end(), counter);
				i++;
			}
			/* Operador Multiplicativo */
			else if (reading[i] == '*' || reading[i] == '/'){
				token->insert(token->end(), *(new string(&reading[i])));
				type->insert(type->end(), "Operador multiplicativo");
				line->insert(line->end(), counter);
				i++;
			}
		}
	}
}

bool LexicalAnalyzer::isLetter(char symbol){
	bool letter = symbol == 'a' || symbol == 'A';
	letter = letter || symbol == 'b' || symbol == 'B';
	letter = letter || symbol == 'c' || symbol == 'C';
	letter = letter || symbol == 'd' || symbol == 'D';
	letter = letter || symbol == 'e' || symbol == 'E';
	letter = letter || symbol == 'f' || symbol == 'F';
	letter = letter || symbol == 'g' || symbol == 'G';
	letter = letter || symbol == 'h' || symbol == 'H';
	letter = letter || symbol == 'i' || symbol == 'I';
	letter = letter || symbol == 'j' || symbol == 'J';
	letter = letter || symbol == 'k' || symbol == 'K';
	letter = letter || symbol == 'l' || symbol == 'L';
	letter = letter || symbol == 'm' || symbol == 'M';
	letter = letter || symbol == 'n' || symbol == 'N';
	letter = letter || symbol == 'o' || symbol == 'O';
	letter = letter || symbol == 'p' || symbol == 'P';
	letter = letter || symbol == 'q' || symbol == 'Q';
	letter = letter || symbol == 'r' || symbol == 'R';
	letter = letter || symbol == 's' || symbol == 'S';
	letter = letter || symbol == 't' || symbol == 'T';
	letter = letter || symbol == 'u' || symbol == 'U';
	letter = letter || symbol == 'v' || symbol == 'V';
	letter = letter || symbol == 'w' || symbol == 'W';
	letter = letter || symbol == 'x' || symbol == 'X';
	letter = letter || symbol == 'y' || symbol == 'Y';
	letter = letter || symbol == 'z' || symbol == 'Z';
	return letter;
}