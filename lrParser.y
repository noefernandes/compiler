%{
  #include <stdio.h>
  #include "lex.yy.c"
  #include "tokens.h"
  #include <string.h>
  #include <stdarg.h>

  char* concat(int arg_count, ...);
  void yyerror (char const *);
%}

%union{
    int iValue;     // integer value
    char* sValue;     // string value
}

%define parse.error verbose
%defines "lrParser.h"
%verbose
%define parse.trace

%token <iValue> eof 0
%token <iValue> assign assign_sum assign_sub assign_mult assign_div assign_set_union assign_set_intersection op_not op_or op_and op_gt op_lt op_lte op_gte op_equal op_diff op_mod parenteses_esquerda parenteses_direita op_mult op_div op_sum op_sub virgula ponto set_intersection set_union key_bool key_caractere key_set key_vetor key_continue key_while key_write key_int key_read key_for key_for_set key_in key_break key_string key_if key_else key_real key_register key_return key_return_nothing key_def key_deftipo colchetes_esquerda colchetes_direita circunflexo ponto_virgula chaves_esquerda chaves_direita empty TExpressao TExp1 TTLogico TTLogico1 TFLogico TExpRel TExpRel2 TExpA TExpA1 TTermo TTermo1 TFator TFator2 TExpUnaria TExpBase TExpId TInstrucoes TInstrucoes2 TInstrucao TInstrucaoDeclaracaoInicializacao TInstrucaoDeclaracaoInicializacao2 TInstrucaoDeclaracaoInicializacao3 TInstrucaoAtribuicaoCasting TInstrucaoChamadaId TChamadaFuncaoOuAtribuicao TLvalueId TOperadoresAtribuicao TListaIdentificadores TListaIdentificadores2 TListaExpressoes TListaExpressoes2 TInstrucaoCondicional TInstrucaoCondicional2 TInstrucaoRepeticao TLacoPara TLacoParaConjunto TLacoEnquanto TInstrucaoSaida TInstrucaoIO TBloco TDefinicaoFuncao TListaParametrosFuncao TListaParametrosFuncao2 TTipoFuncao TParametroFuncao TTipo TTipoPrimitivo TTipoNumerico TTipoEstruturado TPrograma TDef TDefinicaoRegistro TListaAtributos TListaAtributos2

%token <sValue> booleano inteiro real caractere palavra id

%left op_or
%left op_and
%left op_not
%nonassoc op_diff op_equal op_gte op_lte op_gt op_lt
%left op_sub op_sum set_intersection set_union
%left op_mult op_div op_mod
%right circunflexo

%nterm <sValue> PROGRAM DEF DEFINICAO_FUNCAO DEFINICAO_REGISTRO INSTRUCAO LISTA_ATRIBUTOS INSTRUCAO_DECLARACAO_INICIALIZACAO TIPO_FUNCAO LISTA_PARAMETROS_FUNCAO BLOCO PARAMETRO_FUNCAO TIPO TIPO_PRIMITIVO TIPO_ESTRUTURADO TIPO_NUMERICO INSTRUCOES INSTRUCAO_CHAMADA_ID INSTRUCAO_ATRIBUICAO_CASTING INSTRUCAO_CONDICIONAL INSTRUCAO_REPETICAO INSTRUCAO_IO INSTRUCAO_SAIDA LISTA_IDENTIFICADORES OPERADORES_ATRIBUICAO INSTRUCAO_DECLARACAO_INICIALIZACAO_2 LISTA_EXPRESSOES CHAMADA_FUNCAO_OU_ATRIBUICAO LVALUE EXP LACO_PARA LACO_PARA_CONJUNTO LACO_ENQUANTO EXP_ID

%%

PROGRAM: DEF PROGRAM eof                         { $$ = concat($1, $2); printf("%s", $$); }
| %empty
;

DEF: key_def DEFINICAO_FUNCAO
| DEFINICAO_REGISTRO
| INSTRUCAO
;

DEFINICAO_REGISTRO: key_deftipo key_register id chaves_esquerda LISTA_ATRIBUTOS chaves_direita
;

LISTA_ATRIBUTOS: INSTRUCAO_DECLARACAO_INICIALIZACAO
| INSTRUCAO_DECLARACAO_INICIALIZACAO LISTA_ATRIBUTOS
;

DEFINICAO_FUNCAO: TIPO_FUNCAO id parenteses_esquerda LISTA_PARAMETROS_FUNCAO parenteses_direita BLOCO
;

LISTA_PARAMETROS_FUNCAO: PARAMETRO_FUNCAO 
| PARAMETRO_FUNCAO virgula LISTA_PARAMETROS_FUNCAO
| %empty
;

TIPO_FUNCAO: TIPO
| key_return_nothing
;

PARAMETRO_FUNCAO: TIPO id
;

TIPO: TIPO_PRIMITIVO
| TIPO_ESTRUTURADO
;

TIPO_PRIMITIVO: TIPO_NUMERICO
| key_caractere
| key_string
;

TIPO_NUMERICO: key_int
| key_real
| key_bool
;

TIPO_ESTRUTURADO: key_set TIPO
| key_register id
| key_vetor TIPO colchetes_esquerda colchetes_direita
;

BLOCO: chaves_esquerda INSTRUCOES chaves_direita 
;

INSTRUCOES: INSTRUCAO 
| INSTRUCAO INSTRUCOES
;

INSTRUCAO: INSTRUCAO_DECLARACAO_INICIALIZACAO
|  INSTRUCAO_CHAMADA_ID ponto_virgula
|  INSTRUCAO_ATRIBUICAO_CASTING ponto_virgula
|  INSTRUCAO_CONDICIONAL
|  INSTRUCAO_REPETICAO
|  INSTRUCAO_IO
|  INSTRUCAO_SAIDA
|  BLOCO
;

INSTRUCAO_DECLARACAO_INICIALIZACAO: TIPO LISTA_IDENTIFICADORES ponto_virgula
| TIPO id OPERADORES_ATRIBUICAO INSTRUCAO_DECLARACAO_INICIALIZACAO_2 ponto_virgula
;

INSTRUCAO_DECLARACAO_INICIALIZACAO_2: LISTA_EXPRESSOES
| colchetes_esquerda LISTA_EXPRESSOES colchetes_direita
;

LISTA_IDENTIFICADORES: id
| id virgula LISTA_IDENTIFICADORES
;

INSTRUCAO_CHAMADA_ID: id CHAMADA_FUNCAO_OU_ATRIBUICAO
;

CHAMADA_FUNCAO_OU_ATRIBUICAO: parenteses_esquerda LISTA_EXPRESSOES parenteses_direita
| LVALUE OPERADORES_ATRIBUICAO EXP
;

INSTRUCAO_ATRIBUICAO_CASTING: parenteses_esquerda TIPO_PRIMITIVO parenteses_direita id LVALUE OPERADORES_ATRIBUICAO EXP
;

LVALUE: colchetes_esquerda EXP colchetes_direita
| ponto id
| %empty
;

LISTA_EXPRESSOES: EXP
| EXP virgula LISTA_EXPRESSOES 
| %empty
;

INSTRUCAO_CONDICIONAL: key_if parenteses_esquerda EXP parenteses_direita INSTRUCAO ponto_virgula
|  key_if parenteses_esquerda EXP parenteses_direita INSTRUCAO key_else INSTRUCAO
;

INSTRUCAO_REPETICAO: LACO_PARA 
|  LACO_PARA_CONJUNTO 
|  LACO_ENQUANTO
;

LACO_PARA:  key_for parenteses_esquerda TIPO_NUMERICO id assign EXP ponto_virgula EXP ponto_virgula INSTRUCAO_CHAMADA_ID parenteses_direita INSTRUCAO
;

LACO_PARA_CONJUNTO:  key_for_set parenteses_esquerda id key_in EXP parenteses_direita INSTRUCAO
;

LACO_ENQUANTO:  key_while parenteses_esquerda EXP parenteses_direita INSTRUCAO 
;

INSTRUCAO_SAIDA:  key_return EXP ponto_virgula 
|  key_break ponto_virgula 
|  key_continue ponto_virgula
;

INSTRUCAO_IO: key_read parenteses_esquerda id parenteses_direita ponto_virgula 
| key_write parenteses_esquerda EXP parenteses_direita ponto_virgula
;

OPERADORES_ATRIBUICAO: assign 
|  assign_sum 
|  assign_sub 
|  assign_mult 
|  assign_div 
|  assign_set_union 
|  assign_set_intersection
;

EXP: id EXP_ID                                  { $$ = concat(2, $1, $2); }
| inteiro                                  		{ $$ = $1; }
| key_real                                      { $$ = $1; }
| caractere                                     { $$ = $1; }
| palavra	                                    { $$ = $1; }
| booleano                                      { $$ = $1; }
| parenteses_esquerda EXP parenteses_direita    { $$ = concat(3, "{", $2, "}"); }
| EXP op_or EXP                                 { $$ = concat(3, $1, "||", $3); }
| EXP op_and EXP                                { $$ = concat(3, $1, "&&", $3); }
| op_not EXP                                    { $$ = concat(2, "!", $2); }
| op_sub EXP                                    { $$ = concat(2, "-", $2); }
| op_sum EXP                                    { $$ = concat(2, "+", $2); }
| EXP op_sub EXP                                { $$ = concat(3, $1, "-", $3); }
| EXP op_sum EXP                                { $$ = concat(3, $1, "+", $3); }
| EXP set_intersection EXP                      { $$ = concat(3, $1, "problema", $3); }
| EXP set_union EXP                             { $$ = concat(3, $1, "problema", $3); }
| EXP op_mult EXP                               { $$ = concat(3, $1, "*", $3); }
| EXP op_div EXP                                { $$ = concat(3, $1, "/", $3); }
| EXP op_mod EXP                                { $$ = concat(3, $1, "%", $3); }
| EXP circunflexo EXP                           { $$ = concat(3, "pow(", $1, ",", $3, ")"); }
| EXP op_diff EXP                               { $$ = concat(3, $1, "!=", $3); }
| EXP op_equal EXP                              { $$ = concat(3, $1, "==", $3); }
| EXP op_gte EXP                                { $$ = concat(3, $1, ">=", $3); }
| EXP op_lte EXP                                { $$ = concat(3, $1, "<=", $3); }
| EXP op_gt EXP                                 { $$ = concat(3, $1, ">", $3); }
| EXP op_lt EXP                                 { $$ = concat(3, $1, "<", $3); }
;

EXP_ID: %empty                                  { $$ = ""; }
| ponto id                                      { $$ = concat(2, ".", $2); }
| colchetes_esquerda EXP colchetes_direita      { $$ = concat(3, "[", $2, "]"); }
| parenteses_esquerda EXP parenteses_direita    { $$ = concat(3, "(", $2, ")"); }

%%

char* concat(int arg_count, ...){
	  va_list ap;
    va_start(ap, arg_count);
    
    char* begin = va_arg(ap, char*);
    
    for (int i = 2; i <= arg_count; i++) {
        char* tmp;
        tmp = va_arg(ap, char*);
        strcat(begin, tmp);
    }
    
    va_end(ap);
    return begin;
}

void yyerror(char const *s) {
  fprintf(stderr, "%s\n", s);
}
