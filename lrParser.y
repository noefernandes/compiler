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
PROGRAM: EXP eof

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
