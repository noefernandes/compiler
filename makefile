make:
	flex lexer.l
	gcc -o lexer tokens.c tableParser.c recursiveParser.c lex.yy.c
