#ifndef TOKENS_H
#define TOKENS_H
#include "lrParser.h"

typedef enum yytokentype Token;

void error(const char msg[]);
void printToken(Token token);

#endif
