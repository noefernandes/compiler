%{
  #include <stdio.h>
  #include "lex.yy.c"
  void yyerror (char const *);
%}

%define parse.error verbose
%defines "lrParser.h"
%verbose

%token eof 0
%token assign assign_sum assign_sub assign_mult assign_div assign_set_union assign_set_intersection op_not op_or op_and op_gt op_lt op_lte op_gte op_equal op_diff op_mod parenteses_esquerda parenteses_direita op_mult op_div op_sum op_sub virgula ponto set_intersection set_union key_bool key_caractere key_set key_vetor key_continue key_while key_write key_int key_read key_for key_for_set key_in key_break key_string key_if key_else key_real key_register key_return key_return_nothing key_def key_deftipo booleano inteiro real caractere palavra id colchetes_esquerda colchetes_direita circunflexo ponto_virgula chaves_esquerda chaves_direita empty TExpressao TExp1 TTLogico TTLogico1 TFLogico TExpRel TExpRel2 TExpA TExpA1 TTermo TTermo1 TFator TFator2 TExpUnaria TExpBase TExpId TInstrucoes TInstrucoes2 TInstrucao TInstrucaoDeclaracaoInicializacao TInstrucaoDeclaracaoInicializacao2 TInstrucaoDeclaracaoInicializacao3 TInstrucaoAtribuicaoCasting TInstrucaoChamadaId TChamadaFuncaoOuAtribuicao TLvalueId TOperadoresAtribuicao TListaIdentificadores TListaIdentificadores2 TListaExpressoes TListaExpressoes2 TInstrucaoCondicional TInstrucaoCondicional2 TInstrucaoRepeticao TLacoPara TLacoParaConjunto TLacoEnquanto TInstrucaoSaida TInstrucaoIO TBloco TDefinicaoFuncao TListaParametrosFuncao TListaParametrosFuncao2 TTipoFuncao TParametroFuncao TTipo TTipoPrimitivo TTipoNumerico TTipoEstruturado TPrograma TDef TDefinicaoRegistro TListaAtributos TListaAtributos2
%left op_or
%left op_and
%left op_not
%left op_diff op_equal op_gte op_lte op_gt op_lt
%left op_sub op_sum set_intersection set_union
%left op_mult op_div op_mod
%right circunflexo

%precedence parenteses_direita
%precedence key_else

%%
PROGRAM: DEF PROGRAM eof
| %empty
;

DEF: key_def DEFINICAO_FUNCAO
| DEFINICAO_REGISTRO
| INSTRUCAO
;

DEFINICAO_REGISTRO: key_deftipo key_register id chaves_esquerda LISTA_ATRIBUTOS chaves_direita
;

LISTA_ATRIBUTOS: INSTRUCAO_DECLARACAO
| INSTRUCAO_INICIALIZACAO
| INSTRUCAO_DECLARACAO LISTA_ATRIBUTOS
| INSTRUCAO_INICIALIZACAO LISTA_ATRIBUTOS
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

INSTRUCAO: INSTRUCAO_DECLARACAO
|  INSTRUCAO_INICIALIZACAO ponto_virgula
|  INSTRUCAO_CHAMADA_ID ponto_virgula
|  INSTRUCAO_ATRIBUICAO_CASTING ponto_virgula
|  INSTRUCAO_CONDICIONAL
|  INSTRUCAO_REPETICAO
|  INSTRUCAO_IO
|  INSTRUCAO_SAIDA
|  BLOCO 
|  EXP ponto_virgula
;

INSTRUCAO_DECLARACAO: TIPO LISTA_IDENTIFICADORES ponto_virgula
;

LISTA_IDENTIFICADORES: id
| id virgula LISTA_IDENTIFICADORES
;

INSTRUCAO_INICIALIZACAO: TIPO id assign EXP
| TIPO id assign colchetes_esquerda LISTA_EXPRESSOES colchetes_direita
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

INSTRUCAO_CONDICIONAL: key_if parenteses_esquerda EXP parenteses_direita INSTRUCAO
|  key_if parenteses_esquerda EXP parenteses_direita INSTRUCAO key_else INSTRUCAO
;

INSTRUCAO_REPETICAO: LACO_PARA 
|  LACO_PARA_CONJUNTO 
|  LACO_ENQUANTO
;

LACO_PARA:  key_for parenteses_esquerda INSTRUCAO_INICIALIZACAO ponto_virgula EXP ponto_virgula INSTRUCAO_CHAMADA_ID parenteses_direita BLOCO
| key_for parenteses_esquerda INSTRUCAO_CHAMADA_ID ponto_virgula EXP ponto_virgula INSTRUCAO_CHAMADA_ID parenteses_direita BLOCO
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

EXP: id EXP_ID
| inteiro
| real
| caractere
| palavra
| booleano
| parenteses_esquerda EXP parenteses_direita
| EXP op_or EXP
| EXP op_and EXP
| op_not EXP
| op_sub EXP
| op_sum EXP
| EXP op_sub EXP
| EXP op_sum EXP
| EXP set_intersection EXP
| EXP set_union EXP
| EXP op_mult EXP
| EXP op_div EXP
| EXP op_mod EXP
| EXP circunflexo EXP
| EXP op_diff EXP
| EXP op_equal EXP
| EXP op_gte EXP
| EXP op_lte EXP
| EXP op_gt EXP
| EXP op_lt EXP
;

EXP_ID: %empty
| ponto id
| colchetes_esquerda EXP colchetes_direita
| parenteses_esquerda EXP %prec parenteses_direita
;

%%

void yyerror(char const *s) {
  fprintf(stderr, "%s\n", s);
}
