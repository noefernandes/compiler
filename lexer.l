%{
#include <stdio.h>
#include <stdlib.h>
int yycolumn = 1;

typedef enum {
    assign, 
    assign_sum, 
    assign_sub, 
    assign_mult, 
    assign_div, 
    assign_union, 
    assign_intersection, 
    or, 
    and, 
    lte, 
    gte, 
    equal, 
    diff, 
    intersection, 
    union, 
    booleano, 
    inteiro, 
    real, 
    caractere, 
    palavra, 
    id, 
    key_bool, 
    key_caractere, 
    set, 
    continue, 
    key_while, 
    out, 
    key_int, 
    read, 
    key_for, 
    key_for_set,
    in, 
    key_break, 
    key_string, 
    main, 
    if, 
    else, 
    key_real, 
    register, 
    return, 
    return_nothing
} Token;

/* LL(1) parser */
Token tok;
void nextsym() { tok = yylex(); }
void error(const char msg[]) { printf(msg); }
void accept(Token s) { if (tok == s) nextsym(); else error("accept: unexpected token\n"); }

/* Nonterminals symbols */

void Instrucoes();
void Instrucoes2();

void Instrucao();
void InstrucaoRepeticao();
void InstrucaoIO();
void InstrucaoSaida();
void Bloco();

void LacoPara();
void LacoParaConjunto();
void LacoEnquanto();

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
"+="	 {return assign_sum;}
"-="	 {return assign_sub;}
"*="	 {return assign_mult;}
"/="	 {return assign_div;}
"\/\\="	 {return assign_union;}
"\\\/="	 {return assign_intersection;}

 /* Operadores Lógicos */
"~"	 {return '~';}
"||" {return or;}
"&&" {return and;}
">"	 {return '>';}
"<"	 {return '<';}
"<=" {return lte;}
">=" {return gte;}
"==" {return equal;}
"!=" {return diff;}

 /* Operadores de conjuntos */

	"\/\\"   {return intersection;}
	"\\\/"	 {return union;}

 /* Palavras reservadas */  

	booleano 	 {return key_bool;}
	caractere	 {return key_caractere;}
	conjunto	 {return set;}
	continue	 {return continue;}
	enquanto	 {return key_while;}
	escreva	 	 {return out;}
	inteiro	 	 {return key_int;}
	leia	 	 {return read;}
	para	 	 {return key_for;}
    paraconj     {return key_for_set;}
	em	 	     {return in;}
	pare	 	 {return key_break;}
	palavra		 {return key_string;}
	programa	 {return main;}
	se	 	     {return if;}
	senao	 	 {return else;}
	real	 	 {return key_real;}
	registro	 {return register;}
	retorne		 {return return;}
	vazio		 {return return_nothing;}

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

void Instrucoes(){
    Instrucao(); Instrucoes2();
}
void Instrucoes2(){
    Instrucoes();
}

void Instrucao(){
    InstrucaoRepeticao(); InstrucaoIO(); InstrucaoSaida(); Bloco();
}
void InstrucaoRepeticao(){
    LacoPara(); LacoParaConjunto(); LacoEnquanto();
}
void InstrucaoIO(){
    switch(tok) {
        case read: accept(read); accept('('); accept(id); accept(')'); accept(';'); break;
        case out: accept(out); accept('('); Expressao(); accept(')'); accept(';'); break;
    }
}
void InstrucaoSaida(){
    switch(tok) {
        case return: accept(return); Expressao(); accept(';'); break;
        case key_break: accept(key_break); accept(';'); break;
        case continue: accept(continue); accept(';'); break;
    }
}
void Bloco(){
    switch(tok) {
        case '{': accept('{'); Instrucoes(); accept('}'); break;
    }
}

void LacoPara(){
    switch(tok) {
        case key_for: 
            accept(key_for); 
            accept('('); 
            TipoNumerico(); 
            accept(id); 
            accept(assign); 
            Expressao(); 
            accept(';'); 
            Expressao(); 
            accept(';'); 
            InstrucaoAtribuicao(); 
            accept(')'); 
            Instrucao();
            break;
    }
}
void LacoParaConjunto(){
    switch(tok) {
        case key_for_set: 
            accept(key_for_set); 
            accept('('); 
            accept(id); 
            accept(in); 
            Expressao(); 
            accept(')'); 
            Instrucao();
            break;
    }
}
void LacoEnquanto(){
    switch(tok) {
        case key_while: 
            accept(key_while); 
            accept('('); 
            Expressao(); 
            accept(')'); 
            Instrucao();
            break;
    }
}

void Expressao() {
    TLogico(); Exp1();
}

void Exp1() {
    switch(tok) {
        case or: accept(or); TLogico(); Exp1(); break;
    }
}

void TLogico() {
    FLogico(); TLogico1();
}

void TLogico1() {
    switch(tok) {
        case and: accept(and); FLogico(); TLogico1(); break;
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
        case equal: accept(equal); ExpA(); break;
        case diff: accept(diff); ExpA(); break;
        case '<': accept('<'); ExpA(); break;
        case '>': accept('>'); ExpA(); break;
        case lte: accept(lte); ExpA(); break;
        case gte: accept(gte); ExpA(); break;
    }
}

void ExpA() {
    Termo(); ExpA1();
}

void ExpA1() {
    switch(tok) {
        case '-': accept('-'); Termo(); ExpA1(); break;
        case '+': accept('+'); Termo(); ExpA1(); break;
        case intersection: accept(intersection); Termo(); ExpA1(); break;
        case union: accept(union); Termo(); ExpA1(); break;
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
