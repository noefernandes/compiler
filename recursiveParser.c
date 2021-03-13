#include <stdio.h>
#include <stdlib.h>
#include "tokens.h"
#include "recursiveParser.h"

Token tok;

void nextsym() {
    tok = yylex();
}

void error(const char msg[]) {
    printf("%s", msg);
}

void accept(Token s) {
    if (tok == s) nextsym();
    else error("token inesperado\n");
}

void Expressao() {
    switch(tok) {
        case id:
        case inteiro:
        case real:
        case caractere:
        case palavra:
        case op_sub:
        case op_sum:
        case '~': TLogico(); Exp1(); break;
        default: error("esperando id, inteiro, real, caractere, palavra, -, + ou ~\n");
    }
}

void Exp1() {
    switch(tok) {
        case op_log_or: accept(op_log_or); TLogico(); Exp1(); break;
        case parenteses_direita: break;
        case ']': break;
        case ';': break;
        case virgula: break;
        default: error("esperando ||, ), ], ;, ou ,\n");
    }
}

void TLogico() {
    switch(tok) {
        case id:
        case inteiro:
        case real:
        case caractere:
        case palavra:
        case op_sub:
        case op_sum:
        case '~': FLogico(); TLogico1(); break;
        default: error("esperando id, inteiro, real, caractere, palavra, -, + ou ~\n");
    }
}

void TLogico1() {
    switch(tok) {
        case op_log_and: accept(op_log_and); FLogico(); TLogico1(); break;
        case parenteses_direita: break;
        case ']': break;
        case op_log_or: break;
        case ';': break;
        case virgula: break;
        default: error("esperando &&, ), ], ||, ;, ou ,\n");
    }
}

void FLogico() {
    switch(tok) {
        case id:
        case inteiro:
        case real:
        case caractere:
        case palavra:
        case op_sub:
        case op_sum: ExpRel(); break;
        case '~': accept('~'); ExpRel(); break;
        default: error("esperando id, inteiro, real, caractere, palavra, -, + ou ~\n");
    }
}

void ExpRel() {
    switch(tok) {
        case id:
        case inteiro:
        case real:
        case caractere:
        case palavra:
        case op_sub:
        case op_sum: ExpA(); ExpRel2(); break;
        default: error("esperando id, inteiro, real, caractere, palavra, -, ou +\n");
    }
}

void ExpRel2() {
    switch(tok) {
        case op_log_equal: accept(op_log_equal); ExpA(); break;
        case op_log_diff: accept(op_log_diff); ExpA(); break;
        case '<': accept('<'); ExpA(); break;
        case '>': accept('>'); ExpA(); break;
        case op_log_lte: accept(op_log_lte); ExpA(); break;
        case op_log_gte: accept(op_log_gte); ExpA(); break;
        case parenteses_direita: break;
        case ']': break;
        case op_log_and: break;
        case op_log_or: break;
        case ';': break;
        case virgula: break;
        default: error("ExpRel2\n");
    }
}

void ExpA() {
    switch(tok) {
        case id:
        case inteiro:
        case real:
        case caractere:
        case palavra:
        case op_sub:
        case op_sum: Termo(); ExpA1(); break;
        default: error("esperando (id, inteiro, real, caractere, palavra, -, ou +\n");
    }
}

void ExpA1() {
    switch(tok) {
        case op_sub: accept(op_sub); Termo(); ExpA1(); break;
        case op_sum: accept(op_sum); Termo(); ExpA1(); break;
        case op_conj_intersection: accept(op_conj_intersection); Termo(); ExpA1(); break;
        case op_conj_union: accept(op_conj_union); Termo(); ExpA1(); break;
        case parenteses_direita: break;
        case ']': break;
        case op_log_gte: break;
        case op_log_lte: break;
        case '<': break;
        case '>': break;
        case op_log_diff: break;
        case op_log_equal: break;
        case op_log_and: break;
        case op_log_or: break;
        case ';': break;
        case virgula: break;
        default: error("ExpA1\n");
    }
}

void Termo() {
    switch(tok) {
        case id:
        case inteiro:
        case real:
        case caractere:
        case palavra:
        case op_sub:
        case op_sum: Fator(); Termo1(); break;
        default: error("esperando (id, inteiro, real, caractere, palavra, -, ou +\n");
    }
}

void Termo1() {
    switch(tok) {
        case op_mult: accept(op_mult); Fator(); Termo1(); break;
        case op_div: accept(op_div); Fator(); Termo1(); break;
        case op_mod: accept(op_mod); Fator(); Termo1(); break;
        case parenteses_direita: break;
        case ']': break;
        case op_sub: break;
        case op_sum: break;
        case op_conj_intersection: break;
        case op_conj_union: break;
        case op_log_gte: break;
        case op_log_lte: break;
        case '<': break;
        case '>': break;
        case op_log_diff: break;
        case op_log_equal: break;
        case op_log_and: break;
        case op_log_or: break;
        case ';': break;
        case virgula: break;
        default: error("Termo1\n");
    }
}

void Fator() {
    switch(tok) {
        case id:
        case inteiro:
        case real:
        case caractere:
        case palavra:
        case op_sub:
        case op_sum: ExpUnaria(); Fator2(); break;
        default: error("esperando (id, inteiro, real, caractere, palavra, -, ou +\n");
    }
}

void Fator2() {
    switch(tok) {
        case '^': accept('^'); Fator(); break;
        case parenteses_direita: break;
        case ']': break;
        case op_sub: break;
        case op_sum: break;
        case op_mod: break;
        case op_div: break;
        case op_mult: break;
        case op_conj_intersection: break;
        case op_conj_union: break;
        case op_log_gte: break;
        case op_log_lte: break;
        case '<': break;
        case '>': break;
        case op_log_diff: break;
        case op_log_equal: break;
        case op_log_and: break;
        case op_log_or: break;
        case ';': break;
        case virgula: break;
        default: error("Fator2\n");
    }
}

void ExpUnaria() {
    switch(tok) {
        case op_sub: accept(op_sub); ExpBase(); break;
        case op_sum: accept(op_sum); ExpBase(); break;
        case id:
        case inteiro:
        case real:
        case caractere:
        case palavra: ExpBase(); break;
        default: error("esperando -, +, id, inteiro, real, caractere ou palavra\n");
    }
}

void ExpBase() {
    switch(tok) {
        case parenteses_esquerda: accept(parenteses_esquerda); Expressao(); accept(parenteses_direita); break;
        case id: accept(id); ExpId(); break;
        case inteiro: accept(inteiro); break;
        case real: accept(real); break;
        case caractere: accept(caractere); break;
        case palavra: accept(palavra); break;
        default: error("esperando (, id, inteiro, real, caractere ou palavra\n");
    }
}

void ExpId() {
    switch(tok) {
        case '[': accept('['); Expressao(); accept(']'); break;
        case parenteses_esquerda: accept(parenteses_esquerda); Expressao(); accept(parenteses_direita); break;
        case ponto: accept(ponto); accept(id); break;
        default: error("esperando [, ( ou .\n");
    }
}
