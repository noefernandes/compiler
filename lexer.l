%{
#include <stdio.h>
#include <stdlib.h>
int yycolumn = 1;

typedef enum {
    op_assign, 
    op_assign_sum, 
    op_assign_sub, 
    op_assign_mult, 
    op_assign_div, 
    op_assign_conj_union, 
    op_assign_conj_intersection, 
    op_log_or, 
    op_log_and, 
    op_log_lte, 
    op_log_gte, 
    op_log_equal, 
    op_log_diff, 
    op_conj_intersection, 
    op_conj_union, 
    booleano, 
    inteiro, 
    real, 
    caractere, 
    palavra, 
    id, 
    key_bool, 
    key_caractere, 
    key_set, 
    key_continue, 
    key_while, 
    key_out, 
    key_int, 
    key_read, 
    key_for, 
    key_in, 
    key_break, 
    key_string, 
    key_main, 
    key_if, 
    key_else, 
    key_real, 
    key_register, 
    key_return, 
    key_return_nothing
} Token;

/* LL(1) parser */
Token tok;
void nextsym() { tok = yylex(); }
void error(const char msg[]) { printf(msg); }
void accept(Token s) { if (tok == s) nextsym(); else error("accept: unexpected token\n"); }

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
  start_line = prev_yylineno; start_column = yycolumn;                   \
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
"("         {return '(';}
")"         {return ')';}
"["         {return '[';}
"]"         {return ']';}
"{"         {return '{';}
"}"         {return '}';}
";"         {return ';';}
","         {return ',';}

 /* Operadores aritméticos */
[+]	 {return '+';}
[-]	 {return '-';}
[*]	 {return '*';}
"/"	 {return '/';}
[/^]	 {return '^';}
[/%]	 {return '%';}

 /* Operadores de atribuição */
[=]	     {return '=';}
"+="	 {return op_assign_sum;}
"-="	 {return op_assign_sub;}
"*="	 {return op_assign_mult;}
"/="	 {return op_assign_div;}
"\/\\="	 {return op_assign_conj_union;}
"\\\/="	 {return op_assign_conj_intersection;}

 /* Operadores Lógicos */
"~"	 {return '~';}
"||" {return op_log_or;}
"&&" {return op_log_and;}
">"	 {return '>';}
"<"	 {return '<';}
"<=" {return op_log_lte;}
">=" {return op_log_gte;}
"==" {return op_log_equal;}
"!=" {return op_log_diff;}

 /* Operadores de conjuntos */

	"\/\\"   {return op_conj_intersection;}
	"\\\/"	 {return op_conj_union;}

 /* Palavras reservadas */  

	booleano 	 {return key_bool;}
	caractere	 {return key_caractere;}
	conjunto	 {return key_set;}
	continue	 {return key_continue;}
	enquanto	 {return key_while;}
	escreva	 	 {return key_out;}
	inteiro	 	 {return key_int;}
	leia	 	 {return key_read;}
	para	 	 {return key_for;}
	em	 	     {return key_in;}
	pare	 	 {return key_break;}
	palavra		 {return key_string;}
	programa	 {return key_main;}
	se	 	     {return key_if;}
	senao	 	 {return key_else;}
	real	 	 {return key_real;}
	registro	 {return key_register;}
	retorne		 {return key_return;}
	vazio		 {return key_return_nothing;}

{BOOL}      {return booleano;}
{INT}       {return inteiro;}
{REAL}      {return real;}
{CARACTERE} {return caractere;}
{STRING}    {return palavra;}
{ID}        {return id;}

 /* Ignora comentários e espaços em branco */
\/\/[^\n]*  {}
[ \t\r\n]   {}
"\/*"            { BEGIN(C_COMMENT); }
<C_COMMENT>"*\/" { BEGIN(INITIAL); }
<C_COMMENT>\n   { }
<C_COMMENT>.    { }

<<EOF>>     {printf("(eof %u %u)\n", start_line, start_column); return 0;}

. 	    {printf("(ERROR,%s %u %u)\n",yytext, start_line, start_column); return 0;}

%%

void Expressao() {
    TLogico(); Exp1();
}

void Exp1() {
    switch(tok) {
        case op_log_or: accept(op_log_or); TLogico(); Exp1(); break;
    }
}

void TLogico() {
    FLogico(); TLogico1();
}

void TLogico1() {
    switch(tok) {
        case op_log_and: accept(op_log_and); FLogico(); TLogico1(); break;
    }
}

void FLogico() {
    switch(tok) {
        case '~': accept('~'); ExpRel(); break;
        default: ExpRel();
    }
}

void ExpRel() {
    ExpA(); ExpRel2();
}

void ExpRel2() {
    switch(tok) {
        case op_log_equal: accept(op_log_equal); ExpA(); break;
        case op_log_diff: accept(op_log_diff); ExpA(); break;
        case '<': accept('<'); ExpA(); break;
        case '>': accept('>'); ExpA(); break;
        case op_log_lte: accept(op_log_lte); ExpA(); break;
        case op_log_gte: accept(op_log_gte); ExpA(); break;
    }
}

void ExpA() {
    Termo(); ExpA1();
}

void ExpA1() {
    switch(tok) {
        case '-': accept('-'); Termo(); ExpA1(); break;
        case '+': accept('+'); Termo(); ExpA1(); break;
        case op_conj_intersection: accept(op_conj_intersection); Termo(); ExpA1(); break;
        case op_conj_union: accept(op_conj_union); Termo(); ExpA1(); break;
    }
}

void Termo() {
    Fator(); Termo1();
}

void Termo1() {
    switch(tok) {
        case '*': accept('*'); Fator(); Termo1(); break;
        case '/': accept('/'); Fator(); Termo1(); break;
        case '%': accept('%'); Fator(); Termo1(); break;
    }
}

void Fator() {
    ExpUnaria(); Fator2();
}

void Fator2() {
    switch(tok) {
        case '^': accept('^'); Fator(); break;
    }
}

void ExpUnaria() {
    switch(tok) {
        case '-': accept('-'); ExpBase(); break;
        case '+': accept('+'); ExpBase(); break;
        default: ExpBase();
    }
}

void ExpBase() {
    switch(tok) {
        case '(': accept('('); Expressao(); accept(')'); break;
        case id: accept(id); ExpId(); break;
        case inteiro: accept(inteiro); break;
        case real: accept(real); break;
        case caractere: accept(caractere); break;
        case palavra: accept(palavra); break;
        default: error("esperando '(', id, inteiro, real, caractere ou palavra\n");
    }
}

void ExpId() {
    switch(tok) {
        case '[': accept('['); Expressao(); accept(']'); break;
        case '(': accept('('); Expressao(); accept(')'); break;
    }
}

int main(int argc, char** argv) {
    nextsym();
    Expressao();
    return 0;
}
