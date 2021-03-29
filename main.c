#include "tokens.h"
#include "recursiveParser.h"
#include "tableParser.h"
#include "lex.yy.c"

void error(const char msg[]) {
    printf("%s na linha %d coluna %d \n", msg, line, column);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
    	printf("Informe o tipo do analisador: r (recursive) ou t (table)\n");
	return 0;
    }
    char tipo = *argv[1];
    if (tipo == 'r') {
    	nextsym();
	Programa();
    } else if (tipo == 't') {
        initStack();
        initTable();
        runTableParser();
    }
    return 0;
}
