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

 /* Delimitadores. */
[(]         {printf("(parenteses esquerda %u)\n", yylineno);}
[)]         {printf("(parenteses direita %u)\n", yylineno);}
[{]         {printf("(abre chaves esquerda %u)\n", yylineno);}
[}]         {printf("(abre chaves direita %u)\n", yylineno);}
[;]         {printf("(ponto-e-vírgula %u)\n", yylineno);}
[,]         {printf("(vírgula %u)\n", yylineno);}


 /* Tipos primitivos, operadores, palavras reservadas, etc */
{OP}        {printf("(op \"%s\" %u)\n", yytext, yylineno);}

"||"|"&&"|"<"|">"|"<="|">="|"=="|"!=" {printf("(op logica\"%s\" %u)\n", yytext, yylineno);}

inteiro|real|caractere|string|se|senao|enquanto|programa|para|leia|escreva|pare|continue|retorne|conjunto {printf("(palavra-chave %s %u)\n",yytext, yylineno);}


{INT}       {printf("(inteiro %s %u)\n",yytext, yylineno);}
{REAL}      {printf("(real %s %u)\n",yytext, yylineno);}
{CARACTERE} {printf("(caractere %s %u)\n",yytext, yylineno);}
{STRING}    {printf("(string %s %u)\n",yytext, yylineno);}
{ID}        {printf("(id \"%s\" %u)\n", yytext, yylineno);}


 /* Ignora comentários e espaços em branco */
#[^\n]*     {}
[ \t\r\n]   {}

<<EOF>>     {printf("(eof %u)\n", yylineno); return 0;}

%%

int main(int argc, char* argv[]) {
  yylex() ;
  return EXIT_SUCCESS ;
}