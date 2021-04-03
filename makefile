make:
	flex lexer.l
	bison lrParser.y
	gcc -o x_compiler tokens.c tableParser.c recursiveParser.c main.c

test-all: test-r test-t test-a

test-r: $(wildcard algorithms/*.x)
	for i in $?; do \
	    echo $$i; \
	    ./x_compiler r < $$i; \
	done

test-t: $(wildcard algorithms/*.x)
	for i in $?; do \
	    echo $$i; \
	    ./x_compiler t < $$i; \
	done

test-a: $(wildcard algorithms/*.x)
	for i in $?; do \
	    echo $$i; \
	    ./x_compiler a < $$i; \
	done
