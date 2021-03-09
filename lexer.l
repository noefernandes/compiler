%{
#include <stdio.h>
#include <stdlib.h>
int yycolumn = 1;
int line, column;

typedef enum {op_assign, op_assign_sum, op_assign_sub, op_assign_mult, op_assign_div, op_assign_conj_union, op_assign_conj_intersection, op_log_or, op_log_and, op_log_lte, op_log_gte, op_log_equal, op_log_diff, op_mod, parenteses_esquerda, parenteses_direita, op_mult, op_div, op_sum, op_sub, virgula, ponto,  
op_conj_intersection, op_conj_union, booleano, inteiro, real, caractere, palavra, id, 
key_bool, key_caractere, key_set, key_continue, key_while, key_out, key_int, key_read, key_for, key_in, key_break, key_string, key_main, key_if, key_else, key_real, key_register, key_return, key_return_nothing, eof} Token;

/* LL(1) parser */
Token tok;
void nextsym() { tok = yylex(); }
void error(const char msg[]);
void accept(Token s) { if (tok == s) nextsym(); else error("token inesperado\n"); }

/* Nonterminals symbols */
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

/* This is executed before every action. */
#define YY_USER_ACTION                                                   \
  line = start_line = prev_yylineno; column = start_column = yycolumn;                   \
  if (yylineno == prev_yylineno) yycolumn += yyleng;                     \
  else {                                                                 \
    for (yycolumn = 1; yytext[yyleng - yycolumn] != '\n'; ++yycolumn) {} \
    prev_yylineno = yylineno;                                            \
  }
%}

%option yylineno
%option noyywrap nounput noinput
%x C_COMMENT

ID          [a-zA-Z][a-zA-Z0-9]*
INT         [0]|[1-9][0-9]*
REAL        [0-9]+"."[0-9]*
CARACTERE   '[ -~]'
STRING      \"[ -~]*\"
OP          [-+*/^%=]
BOOL 	    verdadeiro|falso
 
%%
   /* Any indented text before the first rule goes at the top of the lexer.  */
   int start_line, start_column;
   int prev_yylineno = yylineno;

 /* Delimitadores. */
"("         {return parenteses_esquerda;}
")"         {return parenteses_direita;}
"["         {return '[';}
"]"         {return ']';}
"{"         {return '{';}
"}"         {return '}';}
";"         {return ';';}
","         {return virgula;}
"."	    {return ponto;}

 /* Operadores aritméticos */
[+]	 {return op_sum;}
[-]	 {return op_sub;}
[*]	 {return op_mult;}
"/"	 {return op_div;}
[/^]	 {return '^';}
[/%]	 {return op_mod;}


 /* Operadores de atribuição */
[=]	 {printf("(op_assign %u %u)\n", start_line, start_column);}
"+="	 {printf("(op_assign_sum %u %u)\n", start_line, start_column);}
"-="	 {printf("(op_assign_sub %u %u)\n", start_line, start_column);}
"*="	 {printf("(op_assign_mult %u %u)\n", start_line, start_column);}
"/="	 {printf("(op_assign_div %u %u)\n", start_line, start_column);}
"\/\\="	 {printf("(op_assign_conj_union %u %u)\n", start_line, start_column);}
"\\\/="	 {printf("(op_assign_conj_intersection %u %u)\n", start_line, start_column);}

 /* Operadores Lógicos */
"~"	 {printf("(op_log_not %u %u)\n", start_line, start_column);}
"||"	 {printf("(op_log_or %u %u)\n", start_line, start_column);}
"&&"	 {printf("(op_log_and %u %u)\n", start_line, start_column);}
">"	 {printf("(op_log_gt %u %u)\n", start_line, start_column);}
"<"	 {printf("(op_log_lt %u %u)\n", start_line, start_column);}
"<="	 {printf("(op_log_lte %u %u)\n", start_line, start_column);}
">="	 {printf("(op_log_gte %u %u)\n", start_line, start_column);}
"=="	 {printf("(op_log_equal %u %u)\n", start_line, start_column);}
"!="	 {printf("(op_log_diff %u %u)\n", start_line, start_column);}

 /* Operadores de conjuntos */

	"\/\\"   {return op_conj_intersection;}
	"\\\/"	 {return op_conj_union;}

 /* Palavras reservadas */
	
	booleano 	 {printf("(key_bool %u %u)\n", start_line, start_column);}
	caractere	 {printf("(key_caractere %u %u)\n", start_line, start_column);}
	conjunto	 {printf("(key_set %u %u)\n", start_line, start_column);}	
	continue	 {printf("(key_continue %u %u)\n", start_line, start_column);}
	enquanto	 {printf("(key_while %u %u)\n", start_line, start_column);}
	escreva	 	 {printf("(key_out %u %u)\n", start_line, start_column);}
	inteiro	 	 {printf("(key_int %u %u)\n", start_line, start_column);}
	leia	 	 {printf("(key_read %u %u)\n", start_line, start_column);}
	para	 	 {printf("(key_for %u %u)\n", start_line, start_column);}
	em	 	 {printf("(key_in %u %u)\n", start_line, start_column);}
	pare	 	 {printf("(key_break %u %u)\n", start_line, start_column);}
	palavra		 {printf("(key_string %u %u)\n", start_line, start_column);}
	programa	 {printf("(key_main %u %u)\n", start_line, start_column);}
	se	 	 {printf("(key_if %u %u)\n", start_line, start_column);} 
	senao	 	 {printf("(key_else %u %u)\n", start_line, start_column);}
	real	 	 {printf("(key_real %u %u)\n", start_line, start_column);}
	registro	 {printf("(key_register %u %u)\n", start_line, start_column);}
	retorne		 {printf("(key_return %u %u)\n", start_line, start_column);}
	vazio		 {printf("(key_return_nothing %u %u)\n", start_line, start_column);}


{BOOL}      {printf("(booleano %s %u %u)\n",yytext, start_line, start_column);}
{INT}       {return inteiro;}
{REAL}      {return real;}
{CARACTERE} {printf("(caractere %s %u %u)\n",yytext, start_line, start_column);}
{STRING}    {printf("(palavra %s %u %u)\n",yytext, start_line, start_column);}
{ID}        {return id;}

 /* Ignora comentários e espaços em branco */
\/\/[^\n]*  {}
[ \t\r\n]   {}
"\/*"            { BEGIN(C_COMMENT); }
<C_COMMENT>"*\/" { BEGIN(INITIAL); }
<C_COMMENT>\n   { }
<C_COMMENT>.    { }

<<EOF>>     {return eof;}

. 	    {printf("(ERROR,%s %u %u)\n",yytext, start_line, start_column); return 0;}

%%

void error(const char msg[]) {
    printf("erro na linha %u coluna %u\n", line, column);
    printf(msg);
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

int main(int argc, char** argv) {
    nextsym();
    Expressao();
    return 0;
}
