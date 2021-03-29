#include "tokens.h"
#include "recursiveParser.h"
#include "tableParser.h"
#include "lrParser.tab.c"

void error(const char msg[]) {
    printf("%s na linha %d coluna %d \n", msg, line, column);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
    	printf("Informe o tipo do analisador: r (recursive), t (table) ou a (lr parser)\n");
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
    } else if (tipo == 'a') {
	yyparse();
    }
    return 0;
}
