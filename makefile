make-rp: recursiveParser.c lex.yy.c
	flex lexer.l
	gcc -o lexer recursiveParser.c lex.yy.c
