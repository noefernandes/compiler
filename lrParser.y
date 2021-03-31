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
%left "||"
%left "&&"
%left '~'
%left "!=" "==" ">=" "<=" '>' '<'
%left '-' op_sum "/\\" "\\/"
%left '*' '/' '%'
%right '^'

%%
PROGRAM: EXP eof

EXP: id EXP_ID
| inteiro
| real
| caractere
| palavra
| booleano
| '(' EXP ')'
| EXP "||" EXP
| EXP "&&" EXP
| '~' EXP
| '-' EXP
| op_sum EXP
| EXP '-' EXP
| EXP op_sum EXP
| EXP "/\\" EXP
| EXP "\\/" EXP
| EXP '*' EXP
| EXP '/' EXP
| EXP '%' EXP
| EXP '^' EXP
| EXP "!=" EXP
| EXP "==" EXP
| EXP ">=" EXP
| EXP "<=" EXP
| EXP '>' EXP
| EXP '<' EXP
;

EXP_ID: %empty
| '.' id
| '[' EXP ']'
| '(' EXP ')'
;

%%

void yyerror(char const *s) {
  fprintf(stderr, "%s\n", s);
}
