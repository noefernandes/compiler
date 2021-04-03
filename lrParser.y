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

%%
PROGRAM: DEF PROGRAM eof
| %empty
;

DEF: key_def DEFINICAO_FUNCAO
| DEFINICAO_FUNCAO
| DEFINICAO_REGISTRO
| INSTRUCAO
;

DEFINICAO_REGISTRO: key_deftipo key_register id chaves_esquerda LISTA_ATRIBUTOS chaves_direita
;

LISTA_ATRIBUTOS: INSTRUCAO_DECLARACAO_INICIALIZACAO LISTA_ATRIBUTOS_2
;

LISTA_ATRIBUTOS_2: LISTA_ATRIBUTOS
| %empty
;

DEFINICAO_FUNCAO: TIPO_FUNCAO id parenteses_esquerda LISTA_PARAMETROS_FUNCAO parenteses_direita BLOCO
;

LISTA_PARAMETROS_FUNCAO: PARAMETRO_FUNCAO LISTA_PARAMETROS_FUNCAO_2
| %empty
;

LISTA_PARAMETROS_FUNCAO_2: virgula LISTA_PARAMETROS_FUNCAO
| empty
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

INSTRUCOES: INSTRUCAO INSTRUCOES2
;

INSTRUCOES2: INSTRUCOES 
| %empty
;

INSTRUCAO: INSTRUCAO_DECLARACAO_INICIALIZACAO 
|  INSTRUCAO_ATRIBUICAO_CASTING ponto_virgula
|  INSTRUCAO_CHAMADA_ID ponto_virgula
|  INSTRUCAO_CONDICIONAL
|  INSTRUCAO_REPETICAO
|  INSTRUCAO_IO
|  INSTRUCAO_SAIDA
|  BLOCO 
;

INSTRUCAO_DECLARACAO_INICIALIZACAO: %empty
;

INSTRUCAO_ATRIBUICAO_CASTING: %empty
;

INSTRUCAO_CHAMADA_ID: %empty
;

INSTRUCAO_CONDICIONAL: key_if parenteses_esquerda EXP parenteses_direita INSTRUCAO INSTRUCAO_CONDICIONAL2 
;

INSTRUCAO_CONDICIONAL2: key_else INSTRUCAO 
|  ponto_virgula 
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

INSTRUCAO_IO: key_read parenteses_esquerda id parenteses_direita ponto_virgula 
| key_write parenteses_esquerda EXP parenteses_direita ponto_virgula
;

INSTRUCAO_SAIDA:  key_return EXP ponto_virgula 
|  key_break ponto_virgula 
|  key_continue ponto_virgula
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
| parenteses_esquerda EXP parenteses_direita
;

%%

void yyerror(char const *s) {
  fprintf(stderr, "%s\n", s);
}
