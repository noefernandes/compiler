make:
	flex lexer.l
	gcc -o x_compiler tokens.c tableParser.c recursiveParser.c main.c
