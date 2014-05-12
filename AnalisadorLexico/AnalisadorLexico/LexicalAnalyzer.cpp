#include "LexicalAnalyzer.h"

LexicalAnalyzer::LexicalAnalyzer(){
	token = new vector<lexToken>();
	restricted_word = new vector<string>();
	restricted_word->push_back("program");
	restricted_word->push_back("var");
	restricted_word->push_back("integer");
	restricted_word->push_back("real");
	restricted_word->push_back("boolean");
	restricted_word->push_back("procedure");
	restricted_word->push_back("begin");
	restricted_word->push_back("end");
	restricted_word->push_back("if");
	restricted_word->push_back("then");
	restricted_word->push_back("else");
	restricted_word->push_back("while");
	restricted_word->push_back("do");
	restricted_word->push_back("not");
}

int LexicalAnalyzer::analyze(ifstream *code){
	bool comentary = false;
	char reading[256], tk[256];
	unsigned int counter = 0;
	while (!code->eof()){
		code->getline(reading, 256);
		counter++;
		for (int i = 0; i < 256; /*Propositalmente Vazio*/){
			/* Símbolos Compostos */
			/* Comando de Atribuição */
			if (reading[i] == ':' && reading[i + 1] == '='){
				tk[0] = reading[i];	tk[1] = reading[i + 1];	tk[2] = '\0';
				lexToken newTok(counter, *(new string(tk)), *(new string("Comando de Atribuicao")));
				token->push_back(newTok);
				i += 2;
			}
			/* Operadores Relacionais */
			else if (reading[i] == '<' && reading[i + 1] == '='){
				tk[0] = reading[i];	tk[1] = reading[i + 1];	tk[2] = '\0';
				lexToken newTok(counter, *(new string(tk)), *(new string("Operador Relacional")));
				token->push_back(newTok);
				i += 2;
			}
			else if (reading[i] == '>' && reading[i + 1] == '='){
				tk[0] = reading[i];	tk[1] = reading[i + 1];	tk[2] = '\0';
				lexToken newTok(counter, *(new string(tk)), *(new string("Operador Relacional")));
				token->push_back(newTok);
				i += 2;
			}
			else if (reading[i] == '<' && reading[i + 1] == '>'){
				tk[0] = reading[i];	tk[1] = reading[i + 1];	tk[2] = '\0';
				lexToken newTok(counter, *(new string(tk)), *(new string("Operador Relacional")));
				token->push_back(newTok);
				i += 2;
			}
			/* Operadores Aditivos */
			else if (reading[i] == 'o' && reading[i + 1] == 'r'){
				tk[0] = reading[i];	tk[1] = reading[i + 1];	tk[2] = '\0';
				lexToken newTok(counter, *(new string(tk)), *(new string("Operador Aditivo")));
				token->push_back(newTok);
				i += 2;
			}
			/* Operadores Multiplicativo */
			else if (reading[i] == 'a' && reading[i + 1] == 'n' && reading[i + 2] == 'd' && reading[i + 3] != '_' && !isNumber(reading[i + 3])
				&& !isLetter(reading[i + 3])){
				tk[0] = reading[i];	tk[1] = reading[i + 1];	tk[2] = reading[i + 2]; tk[3] = '\0';
				lexToken newTok(counter, *(new string(tk)), *(new string("Operador Multiplicativo")));
				token->push_back(newTok);
				i += 3;
			}
			/********************/
			/* Símbolos Simples */
			/* Delimitadores */
			else if (reading[i] == ';' || reading[i] == '.' || reading[i] == ':' || reading[i] == '(' || reading[i] == ')' || reading[i] == ','){
				token->push_back(*(new string(&reading[i])));
				type->push_back("Delimitador");
				line->push_back(counter);
				i++;
			}
			/* Operador Relacional */
			else if (reading[i] == '=' || reading[i] == '<' || reading[i] == '>'){
				token->push_back(*(new string(&reading[i])));
				type->push_back("Operador relacional");
				line->push_back(counter);
				i++;
			}
			/* Operador Aditivo */
			else if (reading[i] == '+' || reading[i] == '-'){
				token->push_back(*(new string(&reading[i])));
				type->push_back("Operador aditivo");
				line->push_back(counter);
				i++;
			}
			/* Operador Multiplicativo */
			else if (reading[i] == '*' || reading[i] == '/'){
				token->push_back(*(new string(&reading[i])));
				type->push_back("Operador multiplicativo");
				line->push_back(counter);
				i++;
			}
			/*************************/
			/* Conjuntos de Símbolos */
			/* Palavra Reservada ou Identificador */
			else if (isLetter(reading[i])){
				int j = 0;
				tk[j] = reading[i++];
				for (j++; isLetter(reading[i]) || isNumber(reading[i]) || reading[i] == '_'; j++){
					tk[j] = reading[i++];
				}
				tk[j] = '\0';
				for (j = 0; j < restricted_word->size(); j++){
					if (!strcmp(tk, restricted_word->at(j).c_str())){
						string word(tk);
						lexToken lex(counter, word, "Palavra reservada");
						token->push_back(lex);
					}
					else {
						string word(tk);
						lexToken lex(counter, word, "Identificador");
						token->push_back(lex);
					}
				}
			}
			/* Números Inteiros ou Reais */
			else if (isNumber(reading[i])){
				int j = 0;
				tk[j] = reading[i++];
				for (j++; isNumber(reading[i]); j++){
					tk[j] = reading[i++];
				}
				if (reading[i] == '.'){
					tk[j] = reading[i];
					for (j++; isNumber(reading[i]); j++){
						tk[j] = reading[i++];
					}
					tk[j] = '\0';
					string word(tk);
					lexToken lex(counter, word, "Número real");
					token->push_back(lex);
				}
				else {
					tk[j] = '\0';
					string word(tk);
					lexToken lex(counter, word, "Número inteiro");
					token->push_back(lex);
				}
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

bool LexicalAnalyzer::isNumber(char symbol){
	switch (symbol){
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		return true;
	default:
		return false;
	}
}