#ifndef TABLEPARSER_H
#define TABLEPARSER_H

#include "tokens.h"
#define TOKENS_COUNT 374
#define NONTERMINAL_BEGIN_INDEX 320

struct item {
    Token data;
    struct item *next;
} *top;

struct item* tabela[TOKENS_COUNT][TOKENS_COUNT];

/* Stack */
void push(Token value);
Token pop();
void initStack();
void printStack();

/* Table */
void initTable();
struct item *list(int arg_count, ...);
void runTableParser();
void printTable();

#endif
