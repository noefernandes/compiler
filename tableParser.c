#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "tokens.h"
#include "tableParser.h"

Token tokStack, tokInput;

void push(Token value) {
    struct item *tmp;
    tmp = malloc(sizeof(struct item));
    tmp->data = value;

    tmp->next = top;
    top = tmp;
}

Token pop() {
    struct item *tmp;
    Token n;
    tmp = top;
    n = tmp->data;
    top = top->next;
    free(tmp);
    return n;
}

void initStack() {
    top = NULL;
}

void initTable() {
    for (int i=0; i<TOKENS_COUNT; i++) {
        for (int j=0; j<TOKENS_COUNT; j++) {
            tabela[i][j] = NULL;
        }
    }

    tabela[TExpressao][id] = list(2, TExp1, TTLogico);
    tabela[TExpressao][inteiro] = list(2, TExp1, TTLogico);
    tabela[TExpressao][real] = list(2, TExp1, TTLogico);
    tabela[TExpressao][caractere] = list(2, TExp1, TTLogico);
    tabela[TExpressao][palavra] = list(2, TExp1, TTLogico);
    tabela[TExpressao][op_sub] = list(2, TExp1, TTLogico);
    tabela[TExpressao][op_sum] = list(2, TExp1, TTLogico);
    tabela[TExpressao][op_sum] = list(2, TExp1, TTLogico);
    tabela[TExpressao][op_not] = list(2, TExp1, TTLogico);
    tabela[TExpressao][parenteses_esquerda] = list(2, TExp1, TTLogico);
    tabela[TExpressao][booleano] = list(2, TExp1, TTLogico);

    tabela[TExp1][op_or] = list(3, TExp1, TTLogico, op_or);
    tabela[TExp1][parenteses_direita] = list(1, empty);
    tabela[TExp1][colchetes_direita] = list(1, empty);
    tabela[TExp1][ponto_virgula] = list(1, empty);
    tabela[TExp1][virgula] = list(1, empty);

    tabela[TTLogico][id] = list(2, TTLogico1, TFLogico);
    tabela[TTLogico][inteiro] = list(2, TTLogico1, TFLogico);
    tabela[TTLogico][real] = list(2, TTLogico1, TFLogico);
    tabela[TTLogico][caractere] = list(2, TTLogico1, TFLogico);
    tabela[TTLogico][palavra] = list(2, TTLogico1, TFLogico);
    tabela[TTLogico][op_sub] = list(2, TTLogico1, TFLogico);
    tabela[TTLogico][op_sum] = list(2, TTLogico1, TFLogico);
    tabela[TTLogico][op_not] = list(2, TTLogico1, TFLogico);
    tabela[TTLogico][parenteses_esquerda] = list(2, TTLogico1, TFLogico);
    tabela[TTLogico][booleano] = list(2, TTLogico1, TFLogico);

    tabela[TTLogico1][op_and] = list(3, TTLogico1, TFLogico, op_and);
    tabela[TTLogico1][parenteses_direita] = list(1, empty);
    tabela[TTLogico1][colchetes_direita] = list(1, empty);
    tabela[TTLogico1][op_or] = list(1, empty);
    tabela[TTLogico1][ponto_virgula] = list(1, empty);
    tabela[TTLogico1][virgula] = list(1, empty);

    tabela[TFLogico][id] = list(1, TExpRel);
    tabela[TFLogico][inteiro] = list(1, TExpRel);
    tabela[TFLogico][real] = list(1, TExpRel);
    tabela[TFLogico][caractere] = list(1, TExpRel);
    tabela[TFLogico][palavra] = list(1, TExpRel);
    tabela[TFLogico][op_sub] = list(1, TExpRel);
    tabela[TFLogico][op_sum] = list(1, TExpRel);
    tabela[TFLogico][parenteses_esquerda] = list(1, TExpRel);
    tabela[TFLogico][booleano] = list(1, TExpRel);
    tabela[TFLogico][op_not] = list(2, TExpRel, op_not);

    tabela[TExpRel][id] = list(2, TExpRel2, TExpA);
    tabela[TExpRel][inteiro] = list(2, TExpRel2, TExpA);
    tabela[TExpRel][real] = list(2, TExpRel2, TExpA);
    tabela[TExpRel][caractere] = list(2, TExpRel2, TExpA);
    tabela[TExpRel][palavra] = list(2, TExpRel2, TExpA);
    tabela[TExpRel][op_sub] = list(2, TExpRel2, TExpA);
    tabela[TExpRel][op_sum] = list(2, TExpRel2, TExpA);
    tabela[TExpRel][parenteses_esquerda] = list(2, TExpRel2, TExpA);
    tabela[TExpRel][booleano] = list(2, TExpRel2, TExpA);

    tabela[TExpRel2][op_equal] = list(2, TExpA, op_equal);
    tabela[TExpRel2][op_diff] = list(2, TExpA, op_diff);
    tabela[TExpRel2][op_lt] = list(2, TExpA, op_lt);
    tabela[TExpRel2][op_gt] = list(2, TExpA, op_gt);
    tabela[TExpRel2][op_lte] = list(2, TExpA, op_lte);
    tabela[TExpRel2][op_gte] = list(2, TExpA, op_gte);
    tabela[TExpRel2][parenteses_direita] = list(1, empty);
    tabela[TExpRel2][colchetes_direita] = list(1, empty);
    tabela[TExpRel2][op_and] = list(1, empty);
    tabela[TExpRel2][op_or] = list(1, empty);
    tabela[TExpRel2][ponto_virgula] = list(1, empty);
    tabela[TExpRel2][virgula] = list(1, empty);

    tabela[TExpA][id] = list(2, TExpA1, TTermo);
    tabela[TExpA][inteiro] = list(2, TExpA1, TTermo);
    tabela[TExpA][real] = list(2, TExpA1, TTermo);
    tabela[TExpA][caractere] = list(2, TExpA1, TTermo);
    tabela[TExpA][palavra] = list(2, TExpA1, TTermo);
    tabela[TExpA][op_sub] = list(2, TExpA1, TTermo);
    tabela[TExpA][op_sum] = list(2, TExpA1, TTermo);
    tabela[TExpA][parenteses_esquerda] = list(2, TExpA1, TTermo);
    tabela[TExpA][booleano] = list(2, TExpA1, TTermo);

    tabela[TExpA1][op_sub] = list(3, TExpA1, TTermo, op_sub);
    tabela[TExpA1][op_sum] = list(3, TExpA1, TTermo, op_sum);
    tabela[TExpA1][set_intersection] = list(3, TExpA1, TTermo, set_intersection);
    tabela[TExpA1][set_union] = list(3, TExpA1, TTermo, set_union);
    tabela[TExpA1][parenteses_direita] = list(1, empty);
    tabela[TExpA1][colchetes_direita] = list(1, empty);
    tabela[TExpA1][op_and] = list(1, empty);
    tabela[TExpA1][op_or] = list(1, empty);
    tabela[TExpA1][ponto_virgula] = list(1, empty);
    tabela[TExpA1][virgula] = list(1, empty);
    tabela[TExpA1][op_gte] = list(1, empty);
    tabela[TExpA1][op_lte] = list(1, empty);
    tabela[TExpA1][op_lt] = list(1, empty);
    tabela[TExpA1][op_gt] = list(1, empty);
    tabela[TExpA1][op_diff] = list(1, empty);
    tabela[TExpA1][op_equal] = list(1, empty);

    tabela[TTermo][id] = list(2, TTermo1, TFator);
    tabela[TTermo][inteiro] = list(2, TTermo1, TFator);
    tabela[TTermo][real] = list(2, TTermo1, TFator);
    tabela[TTermo][caractere] = list(2, TTermo1, TFator);
    tabela[TTermo][palavra] = list(2, TTermo1, TFator);
    tabela[TTermo][op_sub] = list(2, TTermo1, TFator);
    tabela[TTermo][op_sum] = list(2, TTermo1, TFator);
    tabela[TTermo][parenteses_esquerda] = list(2, TTermo1, TFator);
    tabela[TTermo][booleano] = list(2, TTermo1, TFator);

    tabela[TTermo1][op_mult] = list(3, TTermo1, TFator, op_mult);
    tabela[TTermo1][op_div] = list(3, TTermo1, TFator, op_div);
    tabela[TTermo1][op_mod] = list(3, TTermo1, TFator, op_mod);
    tabela[TTermo1][colchetes_direita] = list(1, empty);
    tabela[TTermo1][op_and] = list(1, empty);
    tabela[TTermo1][op_or] = list(1, empty);
    tabela[TTermo1][ponto_virgula] = list(1, empty);
    tabela[TTermo1][virgula] = list(1, empty);
    tabela[TTermo1][op_gte] = list(1, empty);
    tabela[TTermo1][op_lte] = list(1, empty);
    tabela[TTermo1][op_lt] = list(1, empty);
    tabela[TTermo1][op_gt] = list(1, empty);
    tabela[TTermo1][op_diff] = list(1, empty);
    tabela[TTermo1][op_equal] = list(1, empty);
    tabela[TTermo1][op_sum] = list(1, empty);
    tabela[TTermo1][op_sub] = list(1, empty);
    tabela[TTermo1][set_intersection] = list(1, empty);
    tabela[TTermo1][set_union] = list(1, empty);

    tabela[TFator][id] = list(2, TFator2, TExpUnaria);
    tabela[TFator][inteiro] = list(2, TFator2, TExpUnaria);
    tabela[TFator][real] = list(2, TFator2, TExpUnaria);
    tabela[TFator][caractere] = list(2, TFator2, TExpUnaria);
    tabela[TFator][palavra] = list(2, TFator2, TExpUnaria);
    tabela[TFator][op_sub] = list(2, TFator2, TExpUnaria);
    tabela[TFator][op_sum] = list(2, TFator2, TExpUnaria);
    tabela[TFator][parenteses_esquerda] = list(2, TFator2, TExpUnaria);
    tabela[TFator][booleano] = list(2, TFator2, TExpUnaria);

    tabela[TFator2][circunflexo] = list(2, TFator, circunflexo);
    tabela[TFator2][op_mult] = list(1, empty);
    tabela[TFator2][op_div] = list(1, empty);
    tabela[TFator2][op_mod] = list(1, empty);
    tabela[TFator2][parenteses_direita] = list(1, empty);
    tabela[TFator2][colchetes_direita] = list(1, empty);
    tabela[TFator2][op_and] = list(1, empty);
    tabela[TFator2][op_or] = list(1, empty);
    tabela[TFator2][ponto_virgula] = list(1, empty);
    tabela[TFator2][virgula] = list(1, empty);
    tabela[TFator2][op_gte] = list(1, empty);
    tabela[TFator2][op_lte] = list(1, empty);
    tabela[TFator2][op_lt] = list(1, empty);
    tabela[TFator2][op_gt] = list(1, empty);
    tabela[TFator2][op_diff] = list(1, empty);
    tabela[TFator2][op_equal] = list(1, empty);
    tabela[TFator2][op_sum] = list(1, empty);
    tabela[TFator2][op_sub] = list(1, empty);
    tabela[TFator2][set_intersection] = list(1, empty);
    tabela[TFator2][set_union] = list(1, empty);

    tabela[TExpUnaria][id] = list(1, TExpBase);
    tabela[TExpUnaria][inteiro] = list(1, TExpBase);
    tabela[TExpUnaria][real] = list(1, TExpBase);
    tabela[TExpUnaria][caractere] = list(1, TExpBase);
    tabela[TExpUnaria][palavra] = list(1, TExpBase);
    tabela[TExpUnaria][parenteses_esquerda] = list(1, TExpBase);
    tabela[TExpUnaria][booleano] = list(1, TExpBase);
    tabela[TExpUnaria][op_sub] = list(2, TExpBase, op_sub);
    tabela[TExpUnaria][op_sum] = list(2, TExpBase, op_sum);

    tabela[TExpBase][id] = list(2, TExpId, id);
    tabela[TExpBase][inteiro] = list(1, inteiro);
    tabela[TExpBase][real] = list(1, real);
    tabela[TExpBase][caractere] = list(1, caractere);
    tabela[TExpBase][palavra] = list(1, palavra);
    tabela[TExpBase][parenteses_esquerda] = list(3, parenteses_direita, TExpressao, parenteses_esquerda);
    tabela[TExpBase][booleano] = list(1, booleano);

    tabela[TExpId][colchetes_esquerda] = list(3, colchetes_direita, TExpressao, colchetes_esquerda);
    tabela[TExpId][parenteses_esquerda] = list(3, parenteses_direita, TExpressao, parenteses_esquerda);
    tabela[TExpId][ponto] = list(2, id, ponto);
    tabela[TExpId][op_mult] = list(1, empty);
    tabela[TExpId][op_div] = list(1, empty);
    tabela[TExpId][op_mod] = list(1, empty);
    tabela[TExpId][circunflexo] = list(1, empty);
    tabela[TExpId][colchetes_direita] = list(1, empty);
    tabela[TExpId][op_and] = list(1, empty);
    tabela[TExpId][op_or] = list(1, empty);
    tabela[TExpId][ponto_virgula] = list(1, empty);
    tabela[TExpId][virgula] = list(1, empty);
    tabela[TExpId][op_gte] = list(1, empty);
    tabela[TExpId][op_lte] = list(1, empty);
    tabela[TExpId][op_lt] = list(1, empty);
    tabela[TExpId][op_gt] = list(1, empty);
    tabela[TExpId][op_diff] = list(1, empty);
    tabela[TExpId][op_equal] = list(1, empty);
    tabela[TExpId][op_sum] = list(1, empty);
    tabela[TExpId][op_sub] = list(1, empty);
    tabela[TExpId][set_intersection] = list(1, empty);
    tabela[TExpId][set_union] = list(1, empty);
    tabela[TExpId][parenteses_direita] = list(1, empty);

    tabela[TDefinicaoFuncao][key_vetor] = list(6, TBloco, parenteses_direita, TListaParametrosFuncao, parenteses_esquerda, id, TTipoFuncao);
    tabela[TDefinicaoFuncao][key_register] = list(6, TBloco, parenteses_direita, TListaParametrosFuncao, parenteses_esquerda, id, TTipoFuncao);
    tabela[TDefinicaoFuncao][key_set] = list(6, TBloco, parenteses_direita, TListaParametrosFuncao, parenteses_esquerda, id, TTipoFuncao);
    tabela[TDefinicaoFuncao][key_bool] = list(6, TBloco, parenteses_direita, TListaParametrosFuncao, parenteses_esquerda, id, TTipoFuncao);
    tabela[TDefinicaoFuncao][key_real] = list(6, TBloco, parenteses_direita, TListaParametrosFuncao, parenteses_esquerda, id, TTipoFuncao);
    tabela[TDefinicaoFuncao][key_int] = list(6, TBloco, parenteses_direita, TListaParametrosFuncao, parenteses_esquerda, id, TTipoFuncao);
    tabela[TDefinicaoFuncao][key_string] = list(6, TBloco, parenteses_direita, TListaParametrosFuncao, parenteses_esquerda, id, TTipoFuncao);
    tabela[TDefinicaoFuncao][key_caractere] = list(6, TBloco, parenteses_direita, TListaParametrosFuncao, parenteses_esquerda, id, TTipoFuncao);
    tabela[TDefinicaoFuncao][key_return_nothing] = list(6, TBloco, parenteses_direita, TListaParametrosFuncao, parenteses_esquerda, id, TTipoFuncao);

    tabela[TListaParametrosFuncao][parenteses_direita] = list(1, empty);
    tabela[TListaParametrosFuncao][key_vetor] = list(2, TListaParametrosFuncao2, TParametroFuncao);
    tabela[TListaParametrosFuncao][key_register] = list(2, TListaParametrosFuncao2, TParametroFuncao);
    tabela[TListaParametrosFuncao][key_set] = list(2, TListaParametrosFuncao2, TParametroFuncao);
    tabela[TListaParametrosFuncao][key_bool] = list(2, TListaParametrosFuncao2, TParametroFuncao);
    tabela[TListaParametrosFuncao][key_real] = list(2, TListaParametrosFuncao2, TParametroFuncao);
    tabela[TListaParametrosFuncao][key_int] = list(2, TListaParametrosFuncao2, TParametroFuncao);
    tabela[TListaParametrosFuncao][key_string] = list(2, TListaParametrosFuncao2, TParametroFuncao);
    tabela[TListaParametrosFuncao][key_caractere] = list(2, TListaParametrosFuncao2, TParametroFuncao);

    tabela[TListaParametrosFuncao2][parenteses_direita] = list(1, empty);
    tabela[TListaParametrosFuncao2][virgula] = list(2, TListaParametrosFuncao, virgula );
    
    tabela[TTipoFuncao][key_vetor] = list(1, TTipo);
    tabela[TTipoFuncao][key_register] = list(1, TTipo);
    tabela[TTipoFuncao][key_set] = list(1, TTipo);
    tabela[TTipoFuncao][key_bool] = list(1, TTipo);
    tabela[TTipoFuncao][key_real] = list(1, TTipo);
    tabela[TTipoFuncao][key_int] = list(1, TTipo);
    tabela[TTipoFuncao][key_string] = list(1, TTipo);
    tabela[TTipoFuncao][key_caractere] = list(1, TTipo);
    tabela[TTipoFuncao][key_return_nothing] = list(1, key_return_nothing);

    tabela[TParametroFuncao][key_vetor] = list(2, id, TTipo);
    tabela[TParametroFuncao][key_register] = list(2, id, TTipo);
    tabela[TParametroFuncao][key_set] = list(2, id, TTipo);
    tabela[TParametroFuncao][key_bool] = list(2, id, TTipo);
    tabela[TParametroFuncao][key_real] = list(2, id, TTipo);
    tabela[TParametroFuncao][key_int] = list(2, id, TTipo);
    tabela[TParametroFuncao][key_string] = list(2, id, TTipo);
    tabela[TParametroFuncao][key_caractere] = list(2, id, TTipo);
    
    tabela[TTipo][key_vetor] = list(1, TTipoEstruturado);
    tabela[TTipo][key_register] = list(1, TTipoEstruturado);
    tabela[TTipo][key_set] = list(1, TTipoEstruturado);
    tabela[TTipo][key_bool] = list(1, TTipoPrimitivo);
    tabela[TTipo][key_real] = list(1, TTipoPrimitivo);
    tabela[TTipo][key_int] = list(1, TTipoPrimitivo);
    tabela[TTipo][key_string] = list(1, TTipoPrimitivo);
    tabela[TTipo][key_caractere] = list(1, TTipoPrimitivo);

    tabela[TTipoPrimitivo][key_bool] = list(1, TTipoNumerico);
    tabela[TTipoPrimitivo][key_real] = list(1, TTipoNumerico);
    tabela[TTipoPrimitivo][key_int] = list(1, TTipoNumerico);
    tabela[TTipoPrimitivo][key_string] = list(1, palavra);
    tabela[TTipoPrimitivo][key_caractere] = list(1, caractere);

    tabela[TTipoNumerico][key_bool] = list(1, key_bool);
    tabela[TTipoNumerico][key_real] = list(1, key_real);
    tabela[TTipoNumerico][key_int] = list(1, key_int);

    tabela[TTipoEstruturado][key_vetor] = list(4, colchetes_direita, colchetes_esquerda, TTipo, key_vetor );
    tabela[TTipoEstruturado][key_register] = list(2, id, key_register );
    tabela[TTipoEstruturado][key_set] = list(2, TTipo, key_set);

    tabela[TBloco][chaves_esquerda] = list(3, chaves_direita, TInstrucoes, chaves_esquerda);

    tabela[TInstrucoes][id] = list(2, TInstrucoes2, TInstrucao);
    tabela[TInstrucoes][parenteses_esquerda] = list(2, TInstrucoes2, TInstrucao);
    tabela[TInstrucoes][key_write] = list(2, TInstrucoes2, TInstrucao);
    tabela[TInstrucoes][key_read] = list(2, TInstrucoes2, TInstrucao);
    tabela[TInstrucoes][key_continue] = list(2, TInstrucoes2, TInstrucao);
    tabela[TInstrucoes][key_break] = list(2, TInstrucoes2, TInstrucao);
    tabela[TInstrucoes][key_return] = list(2, TInstrucoes2, TInstrucao);
    tabela[TInstrucoes][key_while] = list(2, TInstrucoes2, TInstrucao);
    tabela[TInstrucoes][key_for_set] = list(2, TInstrucoes2, TInstrucao);
    tabela[TInstrucoes][key_for] = list(2, TInstrucoes2, TInstrucao);
    tabela[TInstrucoes][key_if] = list(2, TInstrucoes2, TInstrucao);
    tabela[TInstrucoes][chaves_esquerda] = list(2, TInstrucoes2, TInstrucao);
    tabela[TInstrucoes][key_vetor] = list(2, TInstrucoes2, TInstrucao);
    tabela[TInstrucoes][key_register] = list(2, TInstrucoes2, TInstrucao);
    tabela[TInstrucoes][key_set] = list(2, TInstrucoes2, TInstrucao);
    tabela[TInstrucoes][key_bool] = list(2, TInstrucoes2, TInstrucao);
    tabela[TInstrucoes][key_real] = list(2, TInstrucoes2, TInstrucao);
    tabela[TInstrucoes][key_int] = list(2, TInstrucoes2, TInstrucao);
    tabela[TInstrucoes][key_string] = list(2, TInstrucoes2, TInstrucao);
    tabela[TInstrucoes][key_caractere] = list(2, TInstrucoes2, TInstrucao);

    tabela[TInstrucoes2][id] = list(1, TInstrucoes);
    tabela[TInstrucoes2][parenteses_esquerda] = list(1, TInstrucoes);
    tabela[TInstrucoes2][key_write] = list(1, TInstrucoes);
    tabela[TInstrucoes2][key_read] = list(1, TInstrucoes);
    tabela[TInstrucoes2][key_continue] = list(1, TInstrucoes);
    tabela[TInstrucoes2][key_break] = list(1, TInstrucoes);
    tabela[TInstrucoes2][key_return] = list(1, TInstrucoes);
    tabela[TInstrucoes2][key_while] = list(1, TInstrucoes);
    tabela[TInstrucoes2][key_for_set] = list(1, TInstrucoes);
    tabela[TInstrucoes2][key_for] = list(1, TInstrucoes);
    tabela[TInstrucoes2][key_if] = list(1, TInstrucoes);
    tabela[TInstrucoes2][chaves_esquerda] = list(1, TInstrucoes);
    tabela[TInstrucoes2][chaves_direita] = list(1, empty);
    tabela[TInstrucoes2][key_vetor] = list(1, TInstrucoes);
    tabela[TInstrucoes2][key_register] = list(1, TInstrucoes);
    tabela[TInstrucoes2][key_set] = list(1, TInstrucoes);
    tabela[TInstrucoes2][key_bool] = list(1, TInstrucoes);
    tabela[TInstrucoes2][key_real] = list(1, TInstrucoes);
    tabela[TInstrucoes2][key_int] = list(1, TInstrucoes);
    tabela[TInstrucoes2][key_string] = list(1, TInstrucoes);
    tabela[TInstrucoes2][key_caractere] = list(1, TInstrucoes);

    tabela[TInstrucao][id] = list(2, ponto_virgula, TInstrucaoChamadaId);
    tabela[TInstrucao][parenteses_esquerda] = list(2, ponto_virgula, TInstrucaoAtribuicaoCasting);
    tabela[TInstrucao][key_write] = list(1, TInstrucaoIO);
    tabela[TInstrucao][key_read] = list(1, TInstrucaoIO);
    tabela[TInstrucao][key_continue] = list(1, TInstrucaoSaida);
    tabela[TInstrucao][key_break] = list(1, TInstrucaoSaida);
    tabela[TInstrucao][key_return] = list(1, TInstrucaoSaida);
    tabela[TInstrucao][key_while] = list(1, TInstrucaoRepeticao);
    tabela[TInstrucao][key_for_set] = list(1, TInstrucaoRepeticao);
    tabela[TInstrucao][key_for] = list(1, TInstrucaoRepeticao);
    tabela[TInstrucao][key_if] = list(1, TInstrucaoCondicional);
    tabela[TInstrucao][chaves_esquerda] = list(1, TBloco);
    tabela[TInstrucao][key_vetor] = list(1, TInstrucaoDeclaracaoInicializacao);
    tabela[TInstrucao][key_register] = list(1, TInstrucaoDeclaracaoInicializacao);
    tabela[TInstrucao][key_set] = list(1, TInstrucaoDeclaracaoInicializacao);
    tabela[TInstrucao][key_bool] = list(1, TInstrucaoDeclaracaoInicializacao);
    tabela[TInstrucao][key_real] = list(1, TInstrucaoDeclaracaoInicializacao);
    tabela[TInstrucao][key_int] = list(1, TInstrucaoDeclaracaoInicializacao);
    tabela[TInstrucao][key_string] = list(1, TInstrucaoDeclaracaoInicializacao);
    tabela[TInstrucao][key_caractere] = list(1, TInstrucaoDeclaracaoInicializacao);

    tabela[TInstrucaoDeclaracaoInicializacao][key_vetor] = list(4, ponto_virgula, TInstrucaoDeclaracaoInicializacao2, id, TTipo);
    tabela[TInstrucaoDeclaracaoInicializacao][key_register] = list(4, ponto_virgula, TInstrucaoDeclaracaoInicializacao2, id, TTipo);
    tabela[TInstrucaoDeclaracaoInicializacao][key_set] = list(4, ponto_virgula, TInstrucaoDeclaracaoInicializacao2, id, TTipo);
    tabela[TInstrucaoDeclaracaoInicializacao][key_bool] = list(4, ponto_virgula, TInstrucaoDeclaracaoInicializacao2, id, TTipo);
    tabela[TInstrucaoDeclaracaoInicializacao][key_real] = list(4, ponto_virgula, TInstrucaoDeclaracaoInicializacao2, id, TTipo);
    tabela[TInstrucaoDeclaracaoInicializacao][key_int] = list(4, ponto_virgula, TInstrucaoDeclaracaoInicializacao2, id, TTipo);
    tabela[TInstrucaoDeclaracaoInicializacao][key_string] = list(4, ponto_virgula, TInstrucaoDeclaracaoInicializacao2, id, TTipo);
    tabela[TInstrucaoDeclaracaoInicializacao][key_caractere] = list(4, ponto_virgula, TInstrucaoDeclaracaoInicializacao2, id, TTipo);

    tabela[TInstrucaoDeclaracaoInicializacao2][TAtribuicao] = list(2, TInstrucaoDeclaracaoInicializacao3, TOperadoresAtribuicao);
    tabela[TInstrucaoDeclaracaoInicializacao2][virgula] = list(2, TListaIdentificadores, virgula);
    tabela[TInstrucaoDeclaracaoInicializacao2][TAtribuicaoConj] = list(2, TInstrucaoDeclaracaoInicializacao3, TOperadoresAtribuicao);
    tabela[TInstrucaoDeclaracaoInicializacao2][TAtribuicaoDisj] = list(2, TInstrucaoDeclaracaoInicializacao3, TOperadoresAtribuicao);
    tabela[TInstrucaoDeclaracaoInicializacao2][TAtribuicaoDiv] = list(2, TInstrucaoDeclaracaoInicializacao3, TOperadoresAtribuicao);
    tabela[TInstrucaoDeclaracaoInicializacao2][TAtribuicaoMult] = list(2, TInstrucaoDeclaracaoInicializacao3, TOperadoresAtribuicao);
    tabela[TInstrucaoDeclaracaoInicializacao2][TAtribuicaoSoma] = list(2, TInstrucaoDeclaracaoInicializacao3, TOperadoresAtribuicao);
    tabela[TInstrucaoDeclaracaoInicializacao2][TAtribuicaoSub] = list(2, TInstrucaoDeclaracaoInicializacao3, TOperadoresAtribuicao);

    tabela[TInstrucaoDeclaracaoInicializacao3][id] = list(1, TListaExpressoes);
    tabela[TInstrucaoDeclaracaoInicializacao3][parenteses_esquerda] = list(1, TListaExpressoes);
    tabela[TInstrucaoDeclaracaoInicializacao3][colchetes_esquerda] = list(3, colchetes_direita, TListaExpressoes, colchetes_esquerda);
    tabela[TInstrucaoDeclaracaoInicializacao3][palavra] = list(1, TListaExpressoes);
    tabela[TInstrucaoDeclaracaoInicializacao3][booleano] = list(1, TListaExpressoes);
    tabela[TInstrucaoDeclaracaoInicializacao3][caractere] = list(1, TListaExpressoes);
    tabela[TInstrucaoDeclaracaoInicializacao3][real] = list(1, TListaExpressoes);
    tabela[TInstrucaoDeclaracaoInicializacao3][inteiro] = list(1, TListaExpressoes);
    tabela[TInstrucaoDeclaracaoInicializacao3][op_sum] = list(1, TListaExpressoes);
    tabela[TInstrucaoDeclaracaoInicializacao3][op_sub] = list(1, TListaExpressoes);
    tabela[TInstrucaoDeclaracaoInicializacao3][op_not] = list(1, TListaExpressoes);
    tabela[TInstrucaoDeclaracaoInicializacao3][ponto_virgula] = list(1, TListaExpressoes);

    tabela[TInstrucaoAtribuicaoCasting][parenteses_esquerda] = list(7, TExpressao, TOperadoresAtribuicao, TLvalueId, id, parenteses_direita, TTipoPrimitivo, parenteses_esquerda);

    tabela[TInstrucaoChamadaId][id] = list(2, TChamadaFuncaoOuAtribuicao, id);

    tabela[TChamadaFuncaoOuAtribuicao][ponto] = list(3, TExpressao, TOperadoresAtribuicao, TLvalueId);
    tabela[TChamadaFuncaoOuAtribuicao][parenteses_esquerda] = list(3, parenteses_direita, TListaExpressoes, parenteses_esquerda);
    tabela[TChamadaFuncaoOuAtribuicao][colchetes_esquerda] = list(3, TExpressao, TOperadoresAtribuicao, TLvalueId);
    tabela[TChamadaFuncaoOuAtribuicao][TAtribuicao] = list(3, TExpressao, TOperadoresAtribuicao, TLvalueId);
    tabela[TChamadaFuncaoOuAtribuicao][TAtribuicaoConj] = list(3, TExpressao, TOperadoresAtribuicao, TLvalueId);
    tabela[TChamadaFuncaoOuAtribuicao][TAtribuicaoDisj] = list(3, TExpressao, TOperadoresAtribuicao, TLvalueId);
    tabela[TChamadaFuncaoOuAtribuicao][TAtribuicaoDiv] = list(3, TExpressao, TOperadoresAtribuicao, TLvalueId);
    tabela[TChamadaFuncaoOuAtribuicao][TAtribuicaoMult] = list(3, TExpressao, TOperadoresAtribuicao, TLvalueId);
    tabela[TChamadaFuncaoOuAtribuicao][TAtribuicaoSoma] = list(3, TExpressao, TOperadoresAtribuicao, TLvalueId);
    tabela[TChamadaFuncaoOuAtribuicao][TAtribuicaoSub] = list(3, TExpressao, TOperadoresAtribuicao, TLvalueId);

    tabela[TLvalueId][ponto] = list(2, id, ponto);
    tabela[TLvalueId][colchetes_esquerda] = list(3, colchetes_direita, TExpressao, colchetes_esquerda);
    tabela[TLvalueId][TAtribuicao] = list(1, empty);
    tabela[TLvalueId][TAtribuicaoConj] = list(1, empty);
    tabela[TLvalueId][TAtribuicaoDisj] = list(1, empty);
    tabela[TLvalueId][TAtribuicaoDiv] = list(1, empty);
    tabela[TLvalueId][TAtribuicaoMult] = list(1, empty);
    tabela[TLvalueId][TAtribuicaoSoma] = list(1, empty);
    tabela[TLvalueId][TAtribuicaoSub] = list(1, empty);

    tabela[TOperadoresAtribuicao][TAtribuicao] = list(1, TAtribuicao);
    tabela[TOperadoresAtribuicao][TAtribuicaoConj] = list(1, TAtribuicaoConj);
    tabela[TOperadoresAtribuicao][TAtribuicaoDisj] = list(1, TAtribuicaoDisj);
    tabela[TOperadoresAtribuicao][TAtribuicaoDiv] = list(1, TAtribuicaoDiv);
    tabela[TOperadoresAtribuicao][TAtribuicaoMult] = list(1, TAtribuicaoMult);
    tabela[TOperadoresAtribuicao][TAtribuicaoSoma] = list(1, TAtribuicaoSoma);
    tabela[TOperadoresAtribuicao][TAtribuicaoSub] = list(1, TAtribuicaoSub);

    tabela[TListaIdentificadores][id] = list(2, TListaIdentificadores2, id);

    tabela[TListaIdentificadores2][ponto_virgula] = list(1, empty);
    tabela[TListaIdentificadores2][virgula] = list(TListaIdentificadores, virgula);

    tabela[TListaExpressoes][id] = list(2, TListaExpressoes2, TExpressao);
    tabela[TListaExpressoes][parenteses_direita] = list(1, empty);
    tabela[TListaExpressoes][parenteses_esquerda] = list(2, TListaExpressoes2, TExpressao);
    tabela[TListaExpressoes][colchetes_direita] = list(1, empty);
    tabela[TListaExpressoes][palavra] = list(2, TListaExpressoes2, TExpressao);
    tabela[TListaExpressoes][booleano] = list(2, TListaExpressoes2, TExpressao);
    tabela[TListaExpressoes][inteiro] = list(2, TListaExpressoes2, TExpressao);
    tabela[TListaExpressoes][real] = list(2, TListaExpressoes2, TExpressao);
    tabela[TListaExpressoes][caractere] = list(2, TListaExpressoes2, TExpressao);
    tabela[TListaExpressoes][op_sum] = list(2, TListaExpressoes2, TExpressao);
    tabela[TListaExpressoes][op_sub] = list(2, TListaExpressoes2, TExpressao);
    tabela[TListaExpressoes][op_not] = list(2, TListaExpressoes2, TExpressao);
    tabela[TListaExpressoes][ponto_virgula] = list(1, empty);

    tabela[TListaExpressoes2][parenteses_direita] = list(1, empty);
    tabela[TListaExpressoes2][colchetes_direita] = list(1, empty);
    tabela[TListaExpressoes2][ponto_virgula] = list(1, empty);
    tabela[TListaExpressoes2][virgula] = list(2, TListaExpressoes, virgula);

    tabela[TInstrucaoCondicional][key_if] = list(6, TInstrucaoCondicional2, TInstrucao, parenteses_direita, TExpressao, parenteses_esquerda, key_if);
    
    tabela[TInstrucaoCondicional2][ponto_virgula] = list(1, ponto_virgula);
    tabela[TInstrucaoCondicional2][key_else] = list(2, TInstrucao, key_else);

    tabela[TInstrucaoRepeticao][key_while] = list(1, TLacoEnquanto);
    tabela[TInstrucaoRepeticao][key_for_set] = list(1, TLacoParaConjunto);
    tabela[TInstrucaoRepeticao][key_for] = list(1, TLacoPara);

    tabela[TLacoPara][key_for] = list(12, TInstrucao, parenteses_direita, TInstrucaoChamadaId, ponto_virgula, TExpressao, ponto_virgula, TExpressao, TAtribuicao, id, TTipoNumerico, parenteses_esquerda, key_for);
    tabela[TLacoParaConjunto][key_for_set] = list(7, TInstrucao, parenteses_direita, TExpressao, key_in, id, parenteses_esquerda, key_for_set);
    tabela[TLacoParaConjunto][key_while] = list(5, TInstrucao, parenteses_direita, TExpressao, parenteses_esquerda, key_while);

    tabela[TInstrucaoSaida][key_continue] = list(2, ponto_virgula, key_continue);
    tabela[TInstrucaoSaida][key_continue] = list(2, ponto_virgula, key_break);
    tabela[TInstrucaoSaida][key_return] = list(3, ponto_virgula, TExpressao,key_return);

    tabela[TInstrucaoIO][key_write] = list(5, ponto_virgula, parenteses_direita,TExpressao,parenteses_esquerda, key_write);
    tabela[TInstrucaoIO][key_read] = list(5, ponto_virgula, parenteses_direita,id,parenteses_esquerda, key_read);
    
    tabela[TPrograma][eof] = list(1, eof);
    tabela[TPrograma][id] = list(2, TPrograma, TDef);
    tabela[TPrograma][parenteses_esquerda] = list(2, TPrograma, TDef);
    tabela[TPrograma][key_write] = list(2, TPrograma, TDef);
    tabela[TPrograma][key_read] = list(2, TPrograma, TDef);
    tabela[TPrograma][key_continue] = list(2, TPrograma, TDef);
    tabela[TPrograma][key_break] = list(2, TPrograma, TDef);
    tabela[TPrograma][key_return] = list(2, TPrograma, TDef);
    tabela[TPrograma][key_while] = list(2, TPrograma, TDef);
    tabela[TPrograma][key_for_set] = list(2, TPrograma, TDef);
    tabela[TPrograma][key_for] = list(2, TPrograma, TDef);
    tabela[TPrograma][key_if] = list(2, TPrograma, TDef);
    tabela[TPrograma][chaves_esquerda] = list(2, TPrograma, TDef);
    tabela[TPrograma][key_vetor] = list(2, TPrograma, TDef);
    tabela[TPrograma][key_register] = list(2, TPrograma, TDef);
    tabela[TPrograma][key_set] = list(2, TPrograma, TDef);
    tabela[TPrograma][key_bool] = list(2, TPrograma, TDef);
    tabela[TPrograma][key_real] = list(2, TPrograma, TDef);
    tabela[TPrograma][key_int] = list(2, TPrograma, TDef);
    tabela[TPrograma][key_string] = list(2, TPrograma, TDef);
    tabela[TPrograma][key_caractere] = list(2, TPrograma, TDef);
    tabela[TPrograma][key_deftipo] = list(2, TPrograma, TDef);
    tabela[TPrograma][key_def] = list(2, TPrograma, TDef);

    tabela[TDef][id] = list(1, TInstrucao);
    tabela[TDef][parenteses_esquerda] = list(1, TInstrucao);
    tabela[TDef][id] = list(1, TInstrucao);
    tabela[TDef][key_write] = list(1, TInstrucao);
    tabela[TDef][key_read] = list(1, TInstrucao);
    tabela[TDef][key_continue] = list(1, TInstrucao);
    tabela[TDef][key_break] = list(1, TInstrucao);
    tabela[TDef][key_return] = list(1, TInstrucao);
    tabela[TDef][key_while] = list(1, TInstrucao);
    tabela[TDef][key_for_set] = list(1, TInstrucao);
    tabela[TDef][key_for] = list(1, TInstrucao);
    tabela[TDef][key_if] = list(1, TInstrucao);
    tabela[TDef][chaves_esquerda] = list(1, TInstrucao);
    tabela[TDef][key_vetor] = list(1, TInstrucao);
    tabela[TDef][key_register] = list(1, TInstrucao);
    tabela[TDef][key_set] = list(1, TInstrucao);
    tabela[TDef][key_bool] = list(1, TInstrucao);
    tabela[TDef][key_real] = list(1, TInstrucao);
    tabela[TDef][key_int] = list(1, TInstrucao);
    tabela[TDef][key_string] = list(1, TInstrucao);
    tabela[TDef][key_caractere] = list(1, TInstrucao);
    tabela[TDef][key_deftipo] = list(1, TDefinicaoRegistro);
    tabela[TDef][key_def] = list(2, TDefinicaoFuncao, key_def);

    tabela[TDefinicaoRegistro][key_deftipo] = list(6, chaves_direita, TListaAtributos, chaves_esquerda, id, key_register, key_deftipo);

    tabela[TListaAtributos][key_vetor] = list(2, TListaAtributos2, TInstrucaoDeclaracaoInicializacao);
    tabela[TListaAtributos][key_register] = list(2, TListaAtributos2, TInstrucaoDeclaracaoInicializacao);
    tabela[TListaAtributos][key_set] = list(2, TListaAtributos2, TInstrucaoDeclaracaoInicializacao);
    tabela[TListaAtributos][key_bool] = list(2, TListaAtributos2, TInstrucaoDeclaracaoInicializacao);
    tabela[TListaAtributos][key_real] = list(2, TListaAtributos2, TInstrucaoDeclaracaoInicializacao);
    tabela[TListaAtributos][key_int] = list(2, TListaAtributos2, TInstrucaoDeclaracaoInicializacao);
    tabela[TListaAtributos][key_string] = list(2, TListaAtributos2, TInstrucaoDeclaracaoInicializacao);
    tabela[TListaAtributos][key_caractere] = list(2, TListaAtributos2, TInstrucaoDeclaracaoInicializacao);

    tabela[TListaAtributos2][chaves_direita] = list(1, empty);
    tabela[TListaAtributos2][key_vetor] = list(1, TListaAtributos);
    tabela[TListaAtributos2][key_register] = list(1, TListaAtributos);
    tabela[TListaAtributos2][key_set] = list(1, TListaAtributos);
    tabela[TListaAtributos2][key_bool] = list(1, TListaAtributos);
    tabela[TListaAtributos2][key_real] = list(1, TListaAtributos);
    tabela[TListaAtributos2][key_int] = list(1, TListaAtributos);
    tabela[TListaAtributos2][key_string] = list(1, TListaAtributos);
    tabela[TListaAtributos2][key_caractere] = list(1, TListaAtributos);
}   

struct item* list(int arg_count, ...) {
    va_list ap;
    va_start(ap, arg_count);
    
    struct item* begin;
    begin = malloc(sizeof(struct item));
    begin->data = va_arg(ap, Token);
    begin->next = NULL;
    
    struct item *before;
    before = begin;
    
    for (int i = 2; i <= arg_count; i++) {
        struct item *tmp;
        tmp = malloc(sizeof(struct item));
        tmp->data = va_arg(ap, Token);
        tmp->next = NULL;
        
        before->next = tmp;
        before = tmp;
    }
    
    va_end(ap);
    return begin;
}

void runTableParser() {
    push(eof);
    push(TPrograma);
    tokStack = top->data;
    tokInput = yylex();
    do {
	if (tokStack == empty) {
	    pop();
	} else if (tokStack < NONTERMINAL_BEGIN_INDEX) {
	    if (tokStack == tokInput) {
		pop();
		tokInput = yylex();
	    } else {
		printf("topo da pilha: ");
		printToken(tokStack);
		printf("\ntoken da entrada: ");
		printToken(tokInput);
		error("\nerro na aceitação de terminal \n");
		break;
	    }
	} else {
	    struct item *tmp;
	    tmp = tabela[tokStack][tokInput];
	    if (tmp != NULL) {
		pop();
		while (tmp) {
		    push(tmp->data);
		    tmp = tmp->next;
		}
	    } else {
		printf("topo da pilha: ");
		printToken(tokStack);
		printf("\ntoken da entrada: ");
		printToken(tokInput);
		error("\nerro na regra da tabela \n");
		break;
	    }
	}

    	tokStack = top->data;
    } while (tokStack != eof);
    if (tokStack == eof)
        printf("OK\n");
}

void printTable() {
    for (int i=0; i<TOKENS_COUNT; i++) {
        for (int j=0; j<TOKENS_COUNT; j++) {
            struct item *tmp;
            tmp = tabela[i][j];
	    if (tmp != NULL) {
            	printf("%d, %d: ", i, j);
                while (tmp) {
                    printf("%d ", tmp->data);
                    tmp = tmp->next;
                }
                printf("\n");
            }
        }
    }
    printf("\n");
}
