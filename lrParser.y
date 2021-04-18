%{
  #include <stdio.h>
  #include "lex.yy.c"
  #include "tokens.h"
  #include <string.h>
  #include <stdarg.h>

  char* concat(int arg_count, ...);
  void print_code(char subject[]);
  void append(char subject[], const char insert[], int pos);
  char* updateFunctionName(char* functionName);
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

PROGRAM: DEF PROGRAM eof                         { print_code($1);}//printf(">%s %s", $2, $1); }
| %empty { $$ = ""; }
;

DEF: key_def DEFINICAO_FUNCAO { $$ = $2; }
| DEFINICAO_REGISTRO { $$ = $1; }
| INSTRUCAO { $$ = $1; }
;

DEFINICAO_REGISTRO: key_deftipo key_register id chaves_esquerda LISTA_ATRIBUTOS chaves_direita { $$ = concat(5, "struct ", $3, "{", $5, "}"); }
;

LISTA_ATRIBUTOS: INSTRUCAO_DECLARACAO_INICIALIZACAO { $$ = $1; }
| INSTRUCAO_DECLARACAO_INICIALIZACAO LISTA_ATRIBUTOS { $$ = concat(2, $1, $2); }
;

DEFINICAO_FUNCAO: TIPO_FUNCAO id parenteses_esquerda LISTA_PARAMETROS_FUNCAO parenteses_direita BLOCO { $$ = concat(6, $1, updateFunctionName($2), "(", $4, ")", $6); }
;

LISTA_PARAMETROS_FUNCAO: PARAMETRO_FUNCAO { $$ = $1; }
| PARAMETRO_FUNCAO virgula LISTA_PARAMETROS_FUNCAO { $$ = concat(3, $1, ",", $3); }
| %empty { $$ = ""; }
;

TIPO_FUNCAO: TIPO { $$ = $1; }
| key_return_nothing { $$ = "void"; }
;

PARAMETRO_FUNCAO: TIPO id { $$ = concat(2, $1, $2); }
;

TIPO: TIPO_PRIMITIVO { $$ = $1; }
| TIPO_ESTRUTURADO { $$ = $1; }
;

TIPO_PRIMITIVO: TIPO_NUMERICO { $$ = $1; }
| key_caractere { $$ = "char"; }
| key_string { $$ = "char*"; }
;

TIPO_NUMERICO: key_int { $$ = "int"; }
| key_real { $$ = "float"; }
| key_bool { $$ = "int"; }
;

TIPO_ESTRUTURADO: key_set TIPO { $$ = $2; }
| key_register id { $$ = concat(2, "struct ", $2); }
| key_vetor TIPO colchetes_esquerda colchetes_direita { $$ = concat(2, $1, "[]"); }
;

BLOCO: chaves_esquerda INSTRUCOES chaves_direita { $$ = concat(3, "{", $2, "}"); }
;

INSTRUCOES: INSTRUCAO { $$ = concat(1, $1); }
| INSTRUCAO INSTRUCOES { $$ = concat(2, $1, $2); }
;

INSTRUCAO: INSTRUCAO_DECLARACAO_INICIALIZACAO { $$ = $1; }
|  INSTRUCAO_CHAMADA_ID ponto_virgula { $$ = concat(2, $1, ";"); }
|  INSTRUCAO_ATRIBUICAO_CASTING ponto_virgula { $$ = concat(2, $1, ";"); }
|  INSTRUCAO_CONDICIONAL { $$ = $1; }
|  INSTRUCAO_REPETICAO { $$ = $1; }
|  INSTRUCAO_IO { $$ = $1; }
|  INSTRUCAO_SAIDA { $$ = $1; }
|  BLOCO { $$ = $1; }
;

INSTRUCAO_DECLARACAO_INICIALIZACAO: TIPO LISTA_IDENTIFICADORES ponto_virgula { $$ = concat(3, $1, $2, ";"); }
| TIPO id OPERADORES_ATRIBUICAO INSTRUCAO_DECLARACAO_INICIALIZACAO_2 ponto_virgula { $$ = concat(5, $1, $2, $3, $4, ";"); }
;

INSTRUCAO_DECLARACAO_INICIALIZACAO_2: LISTA_EXPRESSOES { $$ = $1; }
| colchetes_esquerda LISTA_EXPRESSOES colchetes_direita { $$ = concat(3, "[", $2, "]"); }
;

LISTA_IDENTIFICADORES: id { $$ = $1; }
| id virgula LISTA_IDENTIFICADORES { $$ = concat(3, $1, ",", $3); }
;

INSTRUCAO_CHAMADA_ID: id CHAMADA_FUNCAO_OU_ATRIBUICAO { $$ = concat(2, $1, $2); }
;

CHAMADA_FUNCAO_OU_ATRIBUICAO: parenteses_esquerda LISTA_EXPRESSOES parenteses_direita { $$ = concat(3, "(", $2, ")"); }
| LVALUE OPERADORES_ATRIBUICAO EXP { $$ = concat(3, $1, $2, $3); }
;

INSTRUCAO_ATRIBUICAO_CASTING: parenteses_esquerda TIPO_PRIMITIVO parenteses_direita id LVALUE OPERADORES_ATRIBUICAO EXP { $$ = concat(7, "(", $2, ")", $4, $5, $6, $7); }
;

LVALUE: colchetes_esquerda EXP colchetes_direita { $$ = concat(3, "(", $2, ")"); }
| ponto id { $$ = concat(2, $1, $2); }
| %empty { $$ = ""; }
;

LISTA_EXPRESSOES: EXP { $$ = $1; }
| EXP virgula LISTA_EXPRESSOES { $$ = concat(3, $1, ",", $3); }
| %empty { $$ = ""; }
;

INSTRUCAO_CONDICIONAL: key_if parenteses_esquerda EXP parenteses_direita INSTRUCAO ponto_virgula { $$ = concat(5, "if (", $3, ")", $5, ";"); }
| key_if parenteses_esquerda EXP parenteses_direita INSTRUCAO key_else INSTRUCAO { $$ = concat(7, "if (", $3, ") ", $5, " else" , $7, ";"); }
;

INSTRUCAO_REPETICAO: LACO_PARA { $$ = $1; }
|  LACO_PARA_CONJUNTO { $$ = $1; }
|  LACO_ENQUANTO { $$ = $1; }
;

LACO_PARA: key_for parenteses_esquerda TIPO_NUMERICO id assign EXP ponto_virgula EXP ponto_virgula INSTRUCAO_CHAMADA_ID parenteses_direita INSTRUCAO { $$ = concat(11, "for (", $3, $4, $5, $6, ";", $8, ";", $10, ")", $12); }
;

LACO_PARA_CONJUNTO: key_for_set parenteses_esquerda id key_in EXP parenteses_direita INSTRUCAO { $$ = "problema"; }
;

LACO_ENQUANTO: key_while parenteses_esquerda EXP parenteses_direita INSTRUCAO { $$ = concat(4, "while (", $3, ")", $5); }
;

INSTRUCAO_SAIDA: key_return EXP ponto_virgula { $$ = concat(3, "return ", $2, ";"); }
| key_break ponto_virgula { $$ = "break;"; }
| key_continue ponto_virgula { $$ = "continue;"; }
;

INSTRUCAO_IO: key_read parenteses_esquerda id parenteses_direita ponto_virgula { $$ = "problema"; }
| key_write parenteses_esquerda EXP parenteses_direita ponto_virgula { $$ = "problema"; }
;

OPERADORES_ATRIBUICAO: assign { $$ = "="; }
|  assign_sum { $$ = "+="; }
|  assign_sub { $$ = "-="; }
|  assign_mult { $$ = "*="; }
|  assign_div { $$ = "/="; }
|  assign_set_union { $$ = "problema"; }
|  assign_set_intersection { $$ = "problema"; }
;

EXP: id EXP_ID                                  { $$ = concat(2, $1, $2); }
| inteiro                                  		  { $$ = $1; }
| real                                          { $$ = $1; }
| caractere                                     { $$ = $1; }
| palavra	                                      { $$ = $1; }
| booleano                                      { $$ = $1; }
| parenteses_esquerda EXP parenteses_direita    { $$ = concat(3, "(", $2, ")"); }
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
| EXP circunflexo EXP                           { $$ = concat(5, "pow(", $1, ",", $3, ")"); }
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

char* updateFunctionName(char* functionName){
  if(strcmp(functionName,"programa") == 0){
    return "main";
  }

  return functionName;
}

void append(char subject[], const char insert[], int pos) {
    char buf[500] = {}; 
    strncpy(buf, subject, pos); 
    int len = strlen(buf);
    strcpy(buf+len, insert); 
    len += strlen(insert);  
    strcpy(buf+len, subject+pos); 
    strcpy(subject, buf);  
}

void print_code(char code[]) {
    char * pch;
    pch=strchr(code,'{');
    while (pch!=NULL)
    {
      append(code, "\n", pch-code+1);
      pch=strchr(pch+1,'{');
    }

    char * pchx;
    pchx=strchr(code,';');
    while (pchx!=NULL)
    {
      append(code, "\n", pchx-code+1);
      pchx=strchr(pchx+1,';');
    }
   printf("%s\n", code);
}

char* concat(int arg_count, ...){
	  va_list ap, ap_count;
    va_start(ap, arg_count);
    va_copy(ap_count, ap);

    char* start;
    start = va_arg(ap_count, char*);
    int size = strlen(start);
    for (int i = 2; i <= arg_count; i++) {
      char* tmp;
      tmp = va_arg(ap_count, char*);
      size += strlen(tmp);
    }
    va_end(ap_count);
    
    int real_size = sizeof(char)*size*2;
    
    char* result;
    result = (char*) malloc(real_size);
    result[0]='\0';
    char* begin;
    begin = va_arg(ap, char*);
    strcat(result, " ");
    strcat(result, begin);

    for (int i = 2; i <= arg_count; i++) {
        char tmp [real_size];
        strcpy(tmp, va_arg(ap, char*));

        strcat(result, " ");
        strcat(result, tmp);
    }

    va_end(ap);
    return result;
}

void yyerror(char const *s) {
  fprintf(stderr, "%s", s);
}
