#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "tokens.h"
#include "tableParser.h"

Token tokStack, tokInput;

void push(Token value) {
    struct item *tmp;
    tmp = malloc(sizeof(struct item));
    tmp->data = value;

    tmp->next = top;
    top = tmp;
}

Token pop() {
    struct item *tmp;
    Token n;
    tmp = top;
    n = tmp->data;
    top = top->next;
    free(tmp);
    return n;
}

void initStack() {
    top = NULL;
}

void initTable() {
    for (int i=0; i<TOKENS_COUNT; i++) {
        for (int j=0; j<TOKENS_COUNT; j++) {
            tabela[i][j] = NULL;
        }
    }

    tabela[TExpressao][op_sum] = list(2, TExpA1, TExpA);
    tabela[TExpressao][inteiro] = list(2, TExpA1, TExpA);
    tabela[TExpA1][op_sum] = list(3, TExpA1, TExpA, op_sum);
    tabela[TExpA1][eof] = list(1, eof);
    tabela[TExpA][inteiro] = list(1, inteiro);
}

struct item* list(int arg_count, ...) {
    va_list ap;
    va_start(ap, arg_count);
    
    struct item* begin;
    begin = malloc(sizeof(struct item));
    begin->data = va_arg(ap, Token);
    begin->next = NULL;
    
    struct item *before;
    before = begin;
    
    for (int i = 2; i <= arg_count; i++) {
        struct item *tmp;
        tmp = malloc(sizeof(struct item));
        tmp->data = va_arg(ap, Token);
        tmp->next = NULL;
        
        before->next = tmp;
        before = tmp;
    }
    
    va_end(ap);
    return begin;
}

void runTableParser() {
    push(eof);
    push(TExpressao);
    tokStack = top->data;
    tokInput = yylex();
    do {
	if (tokStack < NONTERMINAL_BEGIN_INDEX) {
	    if (tokStack == tokInput) {
		pop();
		tokInput = yylex();
	    } else {
		printf("error\n");
		break;
	    }
	} else {
	    struct item *tmp;
	    tmp = tabela[tokStack][tokInput];
	    if (tmp != NULL) {
		pop();
		while (tmp) {
		    push(tmp->data);
		    tmp = tmp->next;
		}
	    } else {
		printf("error\n");
		break;
	    }
	}

    	tokStack = top->data;
    } while (tokStack != eof);
    if (tokStack == eof)
        printf("OK\n");
}

void printTable() {
    for (int i=0; i<TOKENS_COUNT; i++) {
        for (int j=0; j<TOKENS_COUNT; j++) {
            struct item *tmp;
            tmp = tabela[i][j];
	    if (tmp != NULL) {
            	printf("%d, %d: ", i, j);
                while (tmp) {
                    printf("%d ", tmp->data);
                    tmp = tmp->next;
                }
                printf("\n");
            }
        }
    }
    printf("\n");
}
