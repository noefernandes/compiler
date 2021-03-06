%{
#include <stdio.h>
#include <stdlib.h>
#include "tokens.h"
int yycolumn = 1;
int line, column;

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
STRING      \"(?:[^"\\]|\\.)*\"
OP          [-+*/^%=]
BOOL 	    verdadeiro|falso
 
%%
   /* Any indented text before the first rule goes at the top of the lexer.  */
   int start_line, start_column;
   int prev_yylineno = yylineno;

 /* Delimitadores. */
"("		{return parenteses_esquerda;}
")"		{return parenteses_direita;}
"["		{return colchetes_esquerda;}
"]"		{return colchetes_direita;}
"{"		{return chaves_esquerda;}
"}"		{return chaves_direita;}
";"		{return ponto_virgula;}
","		{return virgula;}
"."		{return ponto;}

 /* Operadores aritméticos */
[+]		{return op_sum;}
[-]	 	{return op_sub;}
[*]	 	{return op_mult;}
"/"	 	{return op_div;}
[/^]	 	{return circunflexo;}
[/%] 		{return op_mod;}


 /* Operadores de atribuição */
[=]		{return assign;}
"+="		{return assign_sum;}
"-="		{return assign_sub;}
"*="		{return assign_mult;}
"/="		{return assign_div;}
"\/\\="		{return assign_set_union;}
"\\\/="		{return assign_set_intersection;}

 /* Operadores Lógicos */
"~"	 	{return op_not;}
"||"		{return op_or;}
"&&"		{return op_and;}
">"	 	{return op_gt;}
"<"	 	{return op_lt;}
"<="		{return op_lte;}
">="	 	{return op_gte;}
"=="		{return op_equal;}
"!="	 	{return op_diff;}

 /* Operadores de conjuntos */
"\/\\"   {return set_intersection;}
"\\\/"	 {return set_union;}

 /* Palavras reservadas */
booleano		{return key_bool;}
caractere		{return key_caractere;}
conjunto		{return key_set;}	
continue		{return key_continue;}
enquanto		{return key_while;}
escreva			{return key_write;}
inteiro	 	 	{return key_int;}
leia	 	 	{return key_read;}
para	 	 	{return key_for;}
em	 	 	{return key_in;}
pare	 	 	{return key_break;}
palavra		 	{return key_string;}
se	 	 	{return key_if;} 
senao	 	 	{return key_else;}
real	 	 	{return key_real;}
registro	 	{return key_register;}
retorne		 	{return key_return;}
vazio		 	{return key_return_nothing;}
def			{return key_def;}
deftipo			{return key_deftipo;}
vetor       		{return key_vetor;}
paraconj   		{return key_for_set;}

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

<<EOF>>     {return eof;}

. 	    {printf("(ERROR,%s %u %u)\n",yytext, start_line, start_column); return 0;}

%%
