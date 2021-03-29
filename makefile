make:
	flex lexer.l
	bison lrParser.y
	gcc -o x_compiler tokens.c tableParser.c recursiveParser.c main.c
