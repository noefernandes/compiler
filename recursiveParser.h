#ifndef RECURSIVE_PARSER_H
#define RECURSIVE_PARSER_H

#include "tokens.h"

void nextsym();
void error(const char msg[]);
void accept(Token s);

/* Nonterminals symbols */

void Instrucoes();
void Instrucoes2();

void Instrucao();
void InstrucaoRepeticao();
void InstrucaoIO();
void InstrucaoSaida();
void Bloco();

void LacoPara();
void LacoParaConjunto();
void LacoEnquanto();

void Expressao();
void Exp1();
void TLogico();
void TLogico1();
void FLogico();
void ExpRel();
void ExpRel2();
void ExpA();
void ExpA1();
void Termo();
void Termo1();
void Fator();
void Fator2();
void ExpUnaria();
void ExpBase();
void ExpId();

#endif
