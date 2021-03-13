%{
#include <stdio.h>
#include <stdlib.h>
#include "tokens.h"
#include "recursiveParser.h"
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
	def          {printf("(key_def %u %u)\n", start_line, start_column);}
	deftipo      {printf("(key_deftipo %u %u)\n", start_line, start_column);}
	paraconj 	 {printf("(key_for_set %u %u)\n", start_line, start_column);}
	vetor   	 {printf("(key_vetor %u %u)\n", start_line, start_column);}


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

int main(int argc, char** argv) {
    nextsym();
    Expressao();
    return 0;
}
