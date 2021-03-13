make:
	flex lexer.l
	gcc -o lexer tableParser.c recursiveParser.c lex.yy.c
