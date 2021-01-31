%{
#include <stdio.h>
#include <stdlib.h>

%}

%option yylineno
%option noyywrap

ID          [a-zA-Z][a-zA-Z0-9]*
INT         [0]|-?[1-9][0-9]*
REAL        -?[0-9]+"."[0-9]*
CARACTERE   '[ -~]'
STRING      \"[ -~]*\"
OP          [-+*/^%=]

%%

 /* delimitadores. */
[(]         {printf("(parenteses esquerda %u)\n", yylineno);}
[)]         {printf("(parenteses direita %u)\n", yylineno);}
[{]         {printf("(abre chaves esquerda %u)\n", yylineno);}
[}]         {printf("(abre chaves direita %u)\n", yylineno);}
[;]         {printf("(ponto-e-vírgula %u)\n", yylineno);}
[,]         {printf("(vírgula %u)\n", yylineno);}

 /* Operadores aritméticos */
[+]	 {printf("(op_sum %u)\n", yylineno);}
[-]	 {printf("(op_sub %u)\n", yylineno);}
[*]	 {printf("(op_mult %u)\n", yylineno);}
[//]	 {printf("(op_div %u)\n", yylineno);}
[/^]	 {printf("(op_exp %u)\n", yylineno);}
[/%]	 {printf("(op_mod %u)\n", yylineno);}


 /* Operadores de atribuição */
[=]	 {printf("(op_assing %u)\n", yylineno);}

 /* Operadores Lógicos */
	"||"	 {printf("(op_log_or %u)\n", yylineno);}
	"&&"	 {printf("(op_log_and %u)\n", yylineno);}
	">"	 {printf("(op_log_gt %u)\n", yylineno);}
	"<"	 {printf("(op_log_lt %u)\n", yylineno);}
	"<="	 {printf("(op_log_lte %u)\n", yylineno);}
	">="	 {printf("(op_log_gte %u)\n", yylineno);}
	"=="	 {printf("(op_log_equal %u)\n", yylineno);}
	"!="	 {printf("(op_log_diff %u)\n", yylineno);}

 /* Palavras reservadas */
	inteiro	 	 {printf("(key_int %u)\n", yylineno);}
	real	 	 {printf("(key_real %u)\n", yylineno);}
	caractere	 {printf("(key_caractere %u)\n", yylineno);}
	string	 	 {printf("(key_string %u)\n", yylineno);}
	senao	 	 {printf("(key_else %u)\n", yylineno);}
	enquanto	 {printf("(key_while %u)\n", yylineno);}
	programa	 {printf("(key_main %u)\n", yylineno);}
	leia	 	 {printf("(key_in %u)\n", yylineno);}
	escreva	 	 {printf("(key_out %u)\n", yylineno);}
	conjunto	 {printf("(key_set %u)\n", yylineno);}
	se	 	 {printf("(key_if %u)\n", yylineno);} 
	para	 	 {printf("(key_for %u)\n", yylineno);}
	pare	 	 {printf("(key_break %u)\n", yylineno);}
	continue	 {printf("(key_continue %u)\n", yylineno);}
	retorne		 {printf("(key_return %u)\n", yylineno);}
	

{INT}       {printf("(inteiro %s %u)\n",yytext, yylineno);}
{REAL}      {printf("(real %s %u)\n",yytext, yylineno);}
{CARACTERE} {printf("(caractere %s %u)\n",yytext, yylineno);}
{STRING}    {printf("(string %s %u)\n",yytext, yylineno);}
{ID}        {printf("(id \"%s\" %u)\n", yytext, yylineno);}


 /* Ignora comentários e espaços em branco */
#[^\n]*     {}
[ \t\r\n]   {}

<<EOF>>     {printf("(eof %u)\n", yylineno); return 0;}

. 	    {printf("(%d,ERROR,\"%s\")\n",yylineno,yytext); return 0;}

%%

int main(int argc, char* argv[]) {
  yylex() ;
  return EXIT_SUCCESS ;
}
