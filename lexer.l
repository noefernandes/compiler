%{
#include <stdio.h>
#include <stdlib.h>
int yycolumn = 1;

/* Forward declarations */
void report(const char* ttype, int line, int column);

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
"("         {printf("(parenteses esquerda %u %u)\n", start_line, start_column);}
")"         {printf("(parenteses direita %u %u)\n", start_line, start_column);}
"["         {printf("(colchetes esquerda %u %u)\n", start_line, start_column);}
"]"         {printf("(colchetes direita %u %u)\n", start_line, start_column);}
"{"         {printf("(abre chaves esquerda %u %u)\n", start_line, start_column);}
"}"         {printf("(abre chaves direita %u %u)\n", start_line, start_column);}
";"         {printf("(ponto-e-vírgula %u %u)\n", start_line, start_column);}
","         {printf("(vírgula %u %u)\n", start_line, start_column);}

 /* Operadores aritméticos */
[+]	 {printf("(op_sum %u %u)\n", start_line, start_column);}
"++"	 {printf("(op_add_one %u %u)\n", start_line, start_column);}
[-]	 {printf("(op_sub %u %u)\n", start_line, start_column);}
[*]	 {printf("(op_mult %u %u)\n", start_line, start_column);}
[//]	 {printf("(op_div %u %u)\n", start_line, start_column);}
[/^]	 {printf("(op_exp %u %u)\n", start_line, start_column);}
[/%]	 {printf("(op_mod %u %u)\n", start_line, start_column);}


 /* Operadores de atribuição */
[=]	 {printf("(op_assing %u %u)\n", start_line, start_column);}

 /* Operadores Lógicos */
	"||"	 {printf("(op_log_or %u %u)\n", start_line, start_column);}
	"&&"	 {printf("(op_log_and %u %u)\n", start_line, start_column);}
	">"	 {printf("(op_log_gt %u %u)\n", start_line, start_column);}
	"<"	 {printf("(op_log_lt %u %u)\n", start_line, start_column);}
	"<="	 {printf("(op_log_lte %u %u)\n", start_line, start_column);}
	">="	 {printf("(op_log_gte %u %u)\n", start_line, start_column);}
	"=="	 {printf("(op_log_equal %u %u)\n", start_line, start_column);}
	"!="	 {printf("(op_log_diff %u %u)\n", start_line, start_column);}

 /* Palavras reservadas */
	
	booleano 	 {printf("(key_bool %u %u)\n", start_line, start_column);}
	caractere	 {printf("(key_caractere %u %u)\n", start_line, start_column);}
	conjunto	 {printf("(key_set %u %u)\n", start_line, start_column);}	
	continue	 {printf("(key_continue %u %u)\n", start_line, start_column);}
	enquanto	 {printf("(key_while %u %u)\n", start_line, start_column);}
	escreva	 	 {printf("(key_out %u %u)\n", start_line, start_column);}
	inteiro	 	 {printf("(key_int %u %u)\n", start_line, start_column);}
	leia	 	 {printf("(key_in %u %u)\n", start_line, start_column);}
	para	 	 {printf("(key_for %u %u)\n", start_line, start_column);}
	pare	 	 {printf("(key_break %u %u)\n", start_line, start_column);}
	palavra		 {printf("(key_string %u %u)\n", start_line, start_column);}
	programa	 {printf("(key_main %u %u)\n", start_line, start_column);}
	se	 	 {printf("(key_if %u %u)\n", start_line, start_column);} 
	senao	 	 {printf("(key_else %u %u)\n", start_line, start_column);}
	real	 	 {printf("(key_real %u %u)\n", start_line, start_column);}
	registro	 {printf("(key_register %u %u)\n", start_line, start_column);}
	retorne		 {printf("(key_return %u %u)\n", start_line, start_column);}

{BOOL}      {printf("(booleano %s %u %u)\n",yytext, start_line, start_column);}
{INT}       {printf("(inteiro %s %u %u)\n",yytext, start_line, start_column);}
{REAL}      {printf("(real %s %u %u)\n",yytext, start_line, start_column);}
{CARACTERE} {printf("(caractere %s %u %u)\n",yytext, start_line, start_column);}
{STRING}    {printf("(string %s %u %u)\n",yytext, start_line, start_column);}
{ID}        {printf("(id \"%s\" %u %u)\n", yytext, start_line, start_column);}

 /* Ignora comentários e espaços em branco */
\/\/[^\n]*  {}
[ \t\r\n]   {}

<<EOF>>     {printf("(eof %u %u)\n", start_line, start_column); return 0;}

. 	    {printf("(ERROR,%s %u %u)\n",yytext, start_line, start_column); return 0;}

%%

void report(const char* t, int l, int c) {
  printf("Encountered %s \"%.*s\" at %d:%d\n", t, (int)yyleng, yytext, l, c);
}

int main(int argc, char** argv) {
  while (yylex() > 0) {}
  return 0;
}
