%{
  #include <stdio.h>
  #include "lex.yy.c"
  void yyerror (char const *);
%}

%token NUM

%%
input: %empty
     | input line
;

line: '\n'
| exp '\n'
;

exp: NUM
| exp exp '+'
| exp exp '-'
| exp exp '*'
| exp exp '/'
| exp exp '^'
| exp 'n'
;
%%

void yyerror(char const *s) {
  fprintf(stderr, "%s\n", s);
}
