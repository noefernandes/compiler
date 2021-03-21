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
    tabela[TExp1][']'] = list(1, empty);
    tabela[TExp1][';'] = list(1, empty);
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
    tabela[TTLogico1][']'] = list(1, empty);
    tabela[TTLogico1][op_or] = list(1, empty);
    tabela[TTLogico1][';'] = list(1, empty);
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
    tabela[TExpRel2][']'] = list(1, empty);
    tabela[TExpRel2][op_and] = list(1, empty);
    tabela[TExpRel2][op_or] = list(1, empty);
    tabela[TExpRel2][';'] = list(1, empty);
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
    tabela[TExpA1][']'] = list(1, empty);
    tabela[TExpA1][op_and] = list(1, empty);
    tabela[TExpA1][op_or] = list(1, empty);
    tabela[TExpA1][';'] = list(1, empty);
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
    tabela[TTermo1][']'] = list(1, empty);
    tabela[TTermo1][op_and] = list(1, empty);
    tabela[TTermo1][op_or] = list(1, empty);
    tabela[TTermo1][';'] = list(1, empty);
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

    tabela[TFator2]['^'] = list(2, TFator, '^');
    tabela[TFator2][op_mult] = list(1, empty);
    tabela[TFator2][op_div] = list(1, empty);
    tabela[TFator2][op_mod] = list(1, empty);
    tabela[TFator2][parenteses_direita] = list(1, empty);
    tabela[TFator2][']'] = list(1, empty);
    tabela[TFator2][op_and] = list(1, empty);
    tabela[TFator2][op_or] = list(1, empty);
    tabela[TFator2][';'] = list(1, empty);
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

    tabela[TExpId]['['] = list(3, ']', TExpressao, '[');
    tabela[TExpId][parenteses_esquerda] = list(3, parenteses_direita, TExpressao, parenteses_esquerda);
    tabela[TExpId][ponto] = list(2, id, ponto);
    tabela[TExpId][op_mult] = list(1, empty);
    tabela[TExpId][op_div] = list(1, empty);
    tabela[TExpId][op_mod] = list(1, empty);
    tabela[TExpId]['^'] = list(1, empty);
    tabela[TExpId][']'] = list(1, empty);
    tabela[TExpId][op_and] = list(1, empty);
    tabela[TExpId][op_or] = list(1, empty);
    tabela[TExpId][';'] = list(1, empty);
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

    tabela[TInstrucaoDeclaracaoInicializacao][booleano] = list(3, TInstrucaoDeclaracaoInicializacao2, id, TTipo);
    tabela[TInstrucaoDeclaracaoInicializacao][key_vetor] = list(3, TInstrucaoDeclaracaoInicializacao2, id, TTipo);
    tabela[TInstrucaoDeclaracaoInicializacao][key_register] = list(3, TInstrucaoDeclaracaoInicializacao2, id, TTipo);
    tabela[TInstrucaoDeclaracaoInicializacao][key_set] = list(3, TInstrucaoDeclaracaoInicializacao2, id, TTipo);
    tabela[TInstrucaoDeclaracaoInicializacao][real] = list(3, TInstrucaoDeclaracaoInicializacao2, id, TTipo);
    tabela[TInstrucaoDeclaracaoInicializacao][inteiro] = list(3, TInstrucaoDeclaracaoInicializacao2, id, TTipo);
    tabela[TInstrucaoDeclaracaoInicializacao][palavra] = list(3, TInstrucaoDeclaracaoInicializacao2, id, TTipo);
    tabela[TInstrucaoDeclaracaoInicializacao][caractere] = list(3, TInstrucaoDeclaracaoInicializacao2, id, TTipo);

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
    tabela[TInstrucaoDeclaracaoInicializacao3]['['] = list(3, ']', TListaExpressoes, '[');
    tabela[TInstrucaoDeclaracaoInicializacao3][palavra] = list(1, TListaExpressoes);
    tabela[TInstrucaoDeclaracaoInicializacao3][booleano] = list(1, TListaExpressoes);
    tabela[TInstrucaoDeclaracaoInicializacao3][caractere] = list(1, TListaExpressoes);
    tabela[TInstrucaoDeclaracaoInicializacao3][real] = list(1, TListaExpressoes);
    tabela[TInstrucaoDeclaracaoInicializacao3][inteiro] = list(1, TListaExpressoes);
    tabela[TInstrucaoDeclaracaoInicializacao3][op_sum] = list(1, TListaExpressoes);
    tabela[TInstrucaoDeclaracaoInicializacao3][op_sub] = list(1, TListaExpressoes);
    tabela[TInstrucaoDeclaracaoInicializacao3][op_not] = list(1, TListaExpressoes);
    tabela[TInstrucaoDeclaracaoInicializacao3][';'] = list(1, TListaExpressoes);

    tabela[TInstrucaoAtribuicaoCasting][parenteses_esquerda] = list(7, TExpressao, TOperadoresAtribuicao, TLvalueId, id, parenteses_direita, TTipoPrimitivo, parenteses_esquerda);

    tabela[TInstrucaoChamadaId][id] = list(2, TChamadaFuncaoOuAtribuicao, id);

    tabela[TChamadaFuncaoOuAtribuicao][ponto] = list(3, TExpressao, TOperadoresAtribuicao, TLvalueId);
    tabela[TChamadaFuncaoOuAtribuicao][parenteses_esquerda] = list(3, parenteses_direita, TListaExpressoes, parenteses_esquerda);
    tabela[TChamadaFuncaoOuAtribuicao]['['] = list(3, TExpressao, TOperadoresAtribuicao, TLvalueId);
    tabela[TChamadaFuncaoOuAtribuicao][TAtribuicao] = list(3, TExpressao, TOperadoresAtribuicao, TLvalueId);
    tabela[TChamadaFuncaoOuAtribuicao][TAtribuicaoConj] = list(3, TExpressao, TOperadoresAtribuicao, TLvalueId);
    tabela[TChamadaFuncaoOuAtribuicao][TAtribuicaoDisj] = list(3, TExpressao, TOperadoresAtribuicao, TLvalueId);
    tabela[TChamadaFuncaoOuAtribuicao][TAtribuicaoDiv] = list(3, TExpressao, TOperadoresAtribuicao, TLvalueId);
    tabela[TChamadaFuncaoOuAtribuicao][TAtribuicaoMult] = list(3, TExpressao, TOperadoresAtribuicao, TLvalueId);
    tabela[TChamadaFuncaoOuAtribuicao][TAtribuicaoSoma] = list(3, TExpressao, TOperadoresAtribuicao, TLvalueId);
    tabela[TChamadaFuncaoOuAtribuicao][TAtribuicaoSub] = list(3, TExpressao, TOperadoresAtribuicao, TLvalueId);

    tabela[TLvalueId][ponto] = list(2, id, ponto);
    tabela[TLvalueId]['['] = list(3, ']', TExpressao, ']');
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

    tabela[TListaIdentificadores2][';'] = list(1, empty);
    tabela[TListaIdentificadores2][virgula] = list(TListaIdentificadores, virgula);

    tabela[TListaExpressoes][id] = list(2, TListaExpressoes2, TExpressao);
    tabela[TListaExpressoes][parenteses_direita] = list(1, empty);
    tabela[TListaExpressoes][parenteses_esquerda] = list(2, TListaExpressoes2, TExpressao);
    tabela[TListaExpressoes][']'] = list(1, empty);
    tabela[TListaExpressoes][palavra] = list(2, TListaExpressoes2, TExpressao);
    tabela[TListaExpressoes][booleano] = list(2, TListaExpressoes2, TExpressao);
    tabela[TListaExpressoes][inteiro] = list(2, TListaExpressoes2, TExpressao);
    tabela[TListaExpressoes][real] = list(2, TListaExpressoes2, TExpressao);
    tabela[TListaExpressoes][caractere] = list(2, TListaExpressoes2, TExpressao);
    tabela[TListaExpressoes][op_sum] = list(2, TListaExpressoes2, TExpressao);
    tabela[TListaExpressoes][op_sub] = list(2, TListaExpressoes2, TExpressao);
    tabela[TListaExpressoes][op_not] = list(2, TListaExpressoes2, TExpressao);
    tabela[TListaExpressoes][';'] = list(1, empty);

    tabela[TListaExpressoes2][parenteses_direita] = list(1, empty);
    tabela[TListaExpressoes2][']'] = list(1, empty);
    tabela[TListaExpressoes2][';'] = list(1, empty);
    tabela[TListaExpressoes2][virgula] = list(2, TListaExpressoes, virgula);

    tabela[TInstrucaoCondicional][key_if] = list(6, TInstrucaoCondicional2, TInstrucao, parenteses_direita, TExpressao, parenteses_esquerda, key_if);
    
    tabela[TInstrucaoCondicional2][';'] = list(1, ';');
    tabela[TInstrucaoCondicional2][key_else] = list(2, TInstrucao, key_else);

    tabela[TInstrucaoRepeticao][key_while] = list(1, TLacoEnquanto);
    tabela[TInstrucaoRepeticao][key_for_set] = list(1, TLacoParaConjunto);
    tabela[TInstrucaoRepeticao][key_for] = list(1, TLacoPara);

    tabela[TLacoPara][key_for] = list(12, TInstrucao, parenteses_direita, TInstrucaoChamadaId, ';', TExpressao, ';', TExpressao, TAtribuicao, id, TTipoNumerico, parenteses_esquerda, key_for);
    tabela[TLacoParaConjunto][key_for_set] = list(7, TInstrucao, parenteses_direita, TExpressao, key_in, id, parenteses_esquerda, key_for_set);
    tabela[TLacoParaConjunto][key_while] = list(5, TInstrucao, parenteses_direita, TExpressao, parenteses_esquerda, key_while);

    tabela[TInstrucaoSaida][key_continue] = list(2, ';', key_continue);
    tabela[TInstrucaoSaida][key_continue] = list(2, ';', key_break);
    tabela[TInstrucaoSaida][key_return] = list(3, ';', TExpressao,key_return);

    tabela[TInstrucaoIO][key_write] = list(5, ';', parenteses_direita,TExpressao,parenteses_esquerda, key_write);
    tabela[TInstrucaoIO][key_read] = list(5, ';', parenteses_direita,id,parenteses_esquerda, key_read);

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
    push(TExpressao);
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
		printf("%d %d ", tokStack, tokInput);
		error("erro na aceitação de terminal \n");
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
		printf("%d %d ", tokStack, tokInput);
		error("erro na regra da tabela \n");
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
