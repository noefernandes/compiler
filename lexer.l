%{
#include <stdio.h>
#include <stdlib.h>
int yycolumn = 1;

typedef enum {op_assign, op_assign_sum, op_assign_sub, op_assign_mult, op_assign_div, op_assign_conj_union, op_assign_conj_intersection, op_log_or, op_log_and, op_log_lte, op_log_gte, op_log_equal, op_log_diff, 
op_conj_intersection, op_conj_union, booleano, inteiro, real, caractere, palavra, id, 
key_bool, key_caractere, key_set, key_continue, key_while, key_out, key_int, key_read, key_for, key_in, key_break, key_string, key_main, key_if, key_else, key_real, key_register, key_return, key_return_nothing} Token;

/* LL(1) parser */
Token tok;
void nextsym() { tok = yylex(); }
void error(const char msg[]) { printf(msg); }
void accept(Token s) { if (tok == s) nextsym(); else error("accept: unexpected token\n"); }

/* Nonterminals symbols */
void expressao();
void expA();
void expBase();

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
INT         [0]|-?[1-9][0-9]*
REAL        -?[0-9]+"."[0-9]*
CARACTERE   '[ -~]'
STRING      \"[ -~]*\"
OP          [-+*/^%=]
BOOL 	    verdadeiro|falso
 
%%
   /* Any indented text before the first rule goes at the top of the lexer.  */
   int start_line, start_column;
   int prev_yylineno = yylineno;

 /* Delimitadores. */
"("         {printf("(parenteses_esquerda %u %u)\n", start_line, start_column);}
")"         {printf("(parenteses_direita %u %u)\n", start_line, start_column);}
"["         {printf("(colchetes_esquerda %u %u)\n", start_line, start_column);}
"]"         {printf("(colchetes_direita %u %u)\n", start_line, start_column);}
"{"         {printf("(chaves_esquerda %u %u)\n", start_line, start_column);}
"}"         {printf("(chaves_direita %u %u)\n", start_line, start_column);}
";"         {printf("(ponto_e_virgula %u %u)\n", start_line, start_column);}
","         {printf("(virgula %u %u)\n", start_line, start_column);}

 /* Operadores aritméticos */
[+]	 {printf("(op_sum %u %u)\n", start_line, start_column);}
[-]	 {printf("(op_sub %u %u)\n", start_line, start_column);}
[*]	 {printf("(op_mult %u %u)\n", start_line, start_column);}
"/"	 {printf("(op_div %u %u)\n", start_line, start_column);}
[/^]	 {printf("(op_exp %u %u)\n", start_line, start_column);}
[/%]	 {printf("(op_mod %u %u)\n", start_line, start_column);}


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

	"\/\\"   {printf("(op_conj_intersection %u %u)\n", start_line, start_column);}
	"\\\/"	 {printf("(op_conj_union %u %u)\n", start_line, start_column);}

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
{INT}       {printf("(inteiro %s %u %u)\n",yytext, start_line, start_column);}
{REAL}      {printf("(real %s %u %u)\n",yytext, start_line, start_column);}
{CARACTERE} {printf("(caractere %s %u %u)\n",yytext, start_line, start_column);}
{STRING}    {printf("(palavra %s %u %u)\n",yytext, start_line, start_column);}
{ID}        {printf("(id \"%s\" %u %u)\n", yytext, start_line, start_column);}

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

void expressao() {
    expBase(); expA();
}

void expA() {
    switch(tok) {
        case '+': accept('+'); expBase(); expA(); break;
        case '-': accept('-'); expBase(); expA(); break;
    }
}

void expBase() {
    switch(tok) {
        case '(': accept('('); expressao(); accept(')'); break;
        case inteiro: accept(inteiro); break;
        default: error("esperando '(' ou inteiro\n");
    }
}

int main(int argc, char** argv) {
    nextsym();
    expressao();
    return 0;
}

