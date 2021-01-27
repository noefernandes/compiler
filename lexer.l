%{
#include <stdio.h>
#include <stdlib.h>
int yycolumn = 1;

/*executed before every action*/
#define YY_USER_ACTION
	start-line = prev_yylineno; start_column = column;
	if(yylineno == prev_yylineno) yycolumn += yyleng;
	else{
		for(yycolumn = 1; yytext[yyleng - yycolumn] != '\n'; ++yycolumn){}
		prev_yylineno = yylineno;
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

%%

int start_line, start_column;
int prev_yylineno = yylineno;

 /* Delimitadores. */
[(]         {printf("(parenteses esquerda %u)\n", start_line, start_column);}
[)]         {printf("(parenteses direita %u)\n", start_line, start_column);}
[{]         {printf("(abre chaves esquerda %u)\n", start_line, start_column);}
[}]         {printf("(abre chaves direita %u)\n", start_line, start_column);}
[;]         {printf("(ponto-e-vírgula %u)\n", start_line, start_column);}
[,]         {printf("(vírgula %u)\n", start_line, start_column);}


 /* Tipos primitivos, operadores, palavras reservadas, etc */
{OP}        {printf("(op \"%s\" %u)\n", yytext, start_line, start_column);}

"||"|"&&"|"<"|">"|"<="|">="|"=="|"!=" {printf("(op logica\"%s\" %u)\n", yytext, start_line, start_column);}

inteiro|real|caractere|string|se|senao|enquanto|programa|para|leia|escreva|pare|continue|retorne|conjunto {printf("(palavra-chave %s %u)\n",yytext, start_line, start_column);}


{INT}       {printf("(inteiro %s %u)\n",yytext, start_line, start_column);}
{REAL}      {printf("(real %s %u)\n",yytext, start_line, start_column);}
{CARACTERE} {printf("(caractere %s %u)\n",yytext, start_line, start_column);}
{STRING}    {printf("(string %s %u)\n",yytext, start_line, start_column);}
{ID}        {printf("(id \"%s\" %u)\n", yytext, start_line, start_column);}


 /* Ignora comentários e espaços em branco */
#[^\n]*     {}
[ \t\r\n]   {}

<<EOF>>     {printf("(eof %u)\n", yylineno); return 0;}

%%

void report(const char* t, int l, int c){
	printf("Encountered %s \"%.*s\" at % %d:%d\n", t, (int)yyleng, yytext, l, c);
}

int main(int argc, char* argv[]) {
  yylex() ;
  return EXIT_SUCCESS ;
}
