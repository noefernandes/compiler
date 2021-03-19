#include <stdio.h>
#include <stdlib.h>
#include "tokens.h"
#include "recursiveParser.h"

Token tok;

void nextsym() {
    tok = yylex();
}

void accept(Token s) {
    if (tok == s) nextsym();
    else error("token inesperado\n");
}

void Instrucoes(){
    switch(tok) {
        case id:
        case key_if:
        case key_read:
        case key_out:
        case key_return:
        case key_break:
        case key_continue:
        case '{':
        case key_for:
        case key_for_set:
        case key_while:
        case key_caractere:
        case key_string:
        case key_set:
        case key_register:
        case key_vetor:
        case key_real:
        case key_int:
        case key_bool:
        case parenteses_esquerda: Instrucao(); Instrucoes2(); break;
        default: error(
            "esperando id, se, leia, escreva, retorne, pare, continue, {, para, paraconj, caractere, palavra, conjunto, registro, vetor, real, inteiro, booleano \n"
        );
    }
}
void Instrucoes2(){
    switch(tok) {
        case id:
        case key_if:
        case key_read:
        case key_out:
        case key_return:
        case key_break:
        case key_continue:
        case '{':
        case key_for:
        case key_for_set:
        case key_while:
        case key_caractere:
        case key_string:
        case key_set:
        case key_register:
        case key_vetor:
        case key_real:
        case key_int:
        case key_bool:
        case parenteses_esquerda: Instrucoes(); break;
        case '}': break;        
        default: error("esperando } \n");
    }
};

void Instrucao(){
    switch(tok) {
        case id: InstrucaoChamadaId(); break;
        case key_if: InstrucaoCondicional(); break;
        case key_read: InstrucaoIO(); break;
        case key_out: InstrucaoIO(); break;
        case key_return: InstrucaoSaida(); break;
        case key_break: InstrucaoSaida(); break;
        case key_continue: InstrucaoSaida();break;
        case '{': Bloco(); break;
        case key_for: InstrucaoRepeticao(); break;
        case key_for_set: InstrucaoRepeticao(); break;
        case key_while: InstrucaoRepeticao(); break;
        case key_caractere: InstrucaoDeclaracaoInicializacao(); break;
        case key_string: InstrucaoDeclaracaoInicializacao(); break;
        case key_set: InstrucaoDeclaracaoInicializacao(); break;
        case key_register: InstrucaoDeclaracaoInicializacao(); break;
        case key_vetor: InstrucaoDeclaracaoInicializacao(); break;
        case key_real: InstrucaoDeclaracaoInicializacao(); break;
        case key_int: InstrucaoDeclaracaoInicializacao(); break;
        case key_bool: InstrucaoDeclaracaoInicializacao(); break;
        case parenteses_esquerda:  InstrucaoAtribuicaoCasting();  break;
        default: error(
            "esperando id, se, leia, escreva, retorne, pare, continue, {, para, paraconj, caractere, palavra, conjunto, registro, vetor, real, inteiro, booleano\n"
        );
    }
};

void InstrucaoRepeticao(){
    switch(tok) {
        case key_for_set: LacoParaConjunto(); break;
        case key_while: LacoEnquanto(); break;
        case key_for: LacoPara(); break;
        default: error(
            "esperando para, paraconj, enquanto \n"
        );
    }
};
void InstrucaoIO(){
    switch(tok) {
        case key_out: 
            accept(key_out); 
            accept(parenteses_esquerda); 
            Expressao(); 
            accept(parenteses_direita); 
            accept(';'); 
            break;
        case key_read: 
            accept(key_read); 
            accept(parenteses_esquerda); 
            accept(id); 
            accept(parenteses_direita); 
            accept(';'); 
            break;
        default: error(
            "esperando leia, escreva\n"
        );
    }
};
void InstrucaoSaida(){
    switch(tok) {
        case key_return: accept(key_return); Expressao(); accept(';'); break;
        case key_break: accept(key_break); accept(';'); break;
        case key_continue: accept(key_continue); accept(';'); break;
        default: error(
            "esperando retorne, pare, continue \n"
        );
    }
};

void InstrucaoDeclaracaoInicializacao(){
    Tipo();
    switch(tok) {
        case id: accept(id); InstrucaoDeclaracaoInicializacao2(); break;
        default: error(
            "esperando id\n"
        );
    }
}

void InstrucaoDeclaracaoInicializacao2(){
    switch(tok){
        case virgula: accept(virgula);  ListaIdentificadores(); accept(';'); break;
        case assign:          
        case assign_sum: 
        case assign_sub: 
        case assign_mult: 
        case assign_div:
        case assign_set_intersection: 
        case assign_set_union: OperadoresAtribuicao(); InstrucaoDeclaracaoInicializacao3(); break;
        case ';': accept(';'); break;
        default: error(
            "esperando ',', =, +=, -=, *=, /=, /\\=, \\/=, ;\n"
        );
    }
}

void InstrucaoDeclaracaoInicializacao3(){
    switch(tok){
        case op_not: 
        case op_sub: 
        case op_sum: 
        case id: 
        case inteiro: 
        case real: 
        case caractere: 
        case palavra: 
        case parenteses_esquerda: Expressao(); accept(';'); break;
        
        case '[': accept('['); ListaExpressoes(); accept(']'); accept(';'); break;
        default: error(
            "esperando [, ~, -, +, id, inteiro, real, caractere, palavra, (\n"
        );
    }
}

void  ListaIdentificadores(){
    switch(tok){
        case id: ListaIdentificadores2(); break;
        default: error(
            "esperando id\n"
        );
    }
}

void ListaIdentificadores2(){
    switch(tok){
        case virgula: ListaIdentificadores(); break;
        default: error(
            "esperando ,\n"
        );
    }
}

void ListaExpressoes(){
    switch(tok){
        case op_not: 
        case op_sub: 
        case op_sum: 
        case id: 
        case inteiro: 
        case real: 
        case caractere: 
        case palavra: 
        case parenteses_esquerda: Expressao(); ListaExpressoes2(); break;
        default: error(
            "esperando [, ~, -, +, id, inteiro, real, caractere, palavra, (\n"
        );
    }
}

void ListaExpressoes2(){
    switch(tok){
        case virgula: accept(virgula);  ListaExpressoes(); break;
        default: error(
            "esperando ,\n"
        );
    }
}

void InstrucaoAtribuicaoCasting(){
    switch(tok){
        case parenteses_esquerda:
            accept(parenteses_esquerda); 
            TipoPrimitivo(); 
            accept(parenteses_direita);
            accept(id);
            LvalueId();
            OperadoresAtribuicao();
            Expressao();
        default: error(
            "esperando (\n"
        );
    }
}

void OperadoresAtribuicao(){
    switch(tok){
        case assign: accept(assign); break;            
        case assign_sum: accept(assign_sum); break;
        case assign_sub: accept(assign_sub); break;
        case assign_mult: accept(assign_mult); break;
        case assign_div: accept(assign_div); break;
        case assign_set_intersection: accept(assign_set_intersection); break;
        case assign_set_union: accept(assign_set_union); break;
        default: error(
            "esperando =, +=, -=, *=, /=, /\\=, \\/=, ;\n"
        );
    }
}

void LvalueId(){
    switch(tok){
        case '[': accept('['); Expressao(); accept(']'); break;
        case ponto: accept(ponto); accept(id); break;
        default: error(
            "esperando [, .\n"
        );
    }
}

void InstrucaoChamadaId(){
        switch(tok){
        case id: accept(id); ChamadaFuncaoOuAtribuicao(); break;
        default: error(
            "esperando id\n"
        );
    }
}

void ChamadaFuncaoOuAtribuicao(){
    switch(tok){
        case parenteses_esquerda: accept(parenteses_esquerda); ListaExpressoes(); accept(parenteses_direita); accept(';'); break;
        case '[': LvalueId(); OperadoresAtribuicao(); Expressao(); accept(';'); break; 
        default: error(
            "esperando (, [\n"
        );
    }
}

void InstrucaoCondicional(){
        switch(tok){
        case key_if:  
            accept(key_if); 
            accept(parenteses_esquerda);
            Expressao();
            accept(parenteses_direita);
            Instrucao();
            InstrucaoCondicional2();
            break;
        default: error(
            "esperando se\n"
        );
    }
 }

 void InstrucaoCondicional2(){
    switch(tok){
        case key_else: accept(key_else); Instrucao(); break;
        case ';': accept(';'); break;
        default: error(
            "esperando senao\n"
        );
    }
 }

void Bloco(){
    switch(tok) {
        case '{': accept('{'); Instrucoes(); accept('}'); break;
        default: error(
            "esperando { \n"
        );
    }
};

void LacoPara(){
    switch(tok) {
        case key_for: 
            accept(key_for); 
            accept(parenteses_esquerda); 
            TipoNumerico(); 
            accept(id); 
            accept(assign); 
            Expressao(); 
            accept(';'); 
            Expressao(); 
            accept(';'); 
            InstrucaoAtribuicaoCasting(); 
            accept(parenteses_direita); 
            Instrucao();
            break;
        default: error(
            "esperando para \n"
        );
    }
};
void LacoParaConjunto(){
    switch(tok) {
       case key_for_set: 
            accept(key_for_set); 
            accept(parenteses_esquerda); 
            accept(id); 
            accept(key_in); 
            Expressao(); 
            accept(parenteses_direita); 
            Instrucao();
            break;
        default: error(
            "esperando paraconj \n"
        );
    }
};
void LacoEnquanto(){
    switch(tok) {
        case key_while: 
            accept(key_while); 
            accept(parenteses_esquerda); 
            Expressao(); 
            accept(parenteses_direita); 
            Instrucao();
            break;
        default: error(
            "esperando enquanto \n"
        );
    }
};

void Expressao() {
    switch(tok) {
        case id:
        case inteiro:
        case real:
        case caractere:
        case palavra:
        case op_sub:
        case op_sum:
        case parenteses_esquerda:
        case op_not: TLogico(); Exp1(); break;
        default: error("esperando id, inteiro, real, caractere, palavra, -, +, ( ou ~\n");
    }
}

void Exp1() {
    switch(tok) {
        case op_or: accept(op_or); TLogico(); Exp1(); break;
        case parenteses_direita: break;
        case ']': break;
        case ';': break;
        case virgula: break;
        default: error("esperando ||, ), ], ;, ou ,\n");
    }
}

void TLogico() {
    switch(tok) {
        case id:
        case inteiro:
        case real:
        case caractere:
        case palavra:
        case op_sub:
        case op_sum:
        case op_not: FLogico(); TLogico1(); break;
        default: error("esperando id, inteiro, real, caractere, palavra, -, + ou ~\n");
    }
}

void TLogico1() {
    switch(tok) {
        case op_and: accept(op_and); FLogico(); TLogico1(); break;
        case parenteses_direita: break;
        case ']': break;
        case op_or: break;
        case ';': break;
        case virgula: break;
        default: error("esperando &&, ), ], ||, ;, ou ,\n");
    }
}

void FLogico() {
    switch(tok) {
        case id:
        case inteiro:
        case real:
        case caractere:
        case palavra:
        case op_sub:
        case op_sum: ExpRel(); break;
        case op_not: accept(op_not); ExpRel(); break;
        default: error("esperando id, inteiro, real, caractere, palavra, -, + ou ~\n");
    }
}

void ExpRel() {
    switch(tok) {
        case id:
        case inteiro:
        case real:
        case caractere:
        case palavra:
        case op_sub:
        case op_sum: ExpA(); ExpRel2(); break;
        default: error("esperando id, inteiro, real, caractere, palavra, -, ou +\n");
    }
}

void ExpRel2() {
    switch(tok) {
        case op_equal: accept(op_equal); ExpA(); break;
        case op_diff: accept(op_diff); ExpA(); break;
        case op_lt: accept(op_lt); ExpA(); break;
        case op_gt: accept(op_gt); ExpA(); break;
        case op_lte: accept(op_lte); ExpA(); break;
        case op_gte: accept(op_gte); ExpA(); break;
        case parenteses_direita: break;
        case ']': break;
        case op_and: break;
        case op_or: break;
        case ';': break;
        case virgula: break;
        default: error("ExpRel2\n");
    }
}

void ExpA() {
    switch(tok) {
        case id:
        case inteiro:
        case real:
        case caractere:
        case palavra:
        case op_sub:
        case op_sum: Termo(); ExpA1(); break;
        default: error("esperando (id, inteiro, real, caractere, palavra, -, ou +\n");
    }
}

void ExpA1() {
    switch(tok) {
        case op_sub: accept(op_sub); Termo(); ExpA1(); break;
        case op_sum: accept(op_sum); Termo(); ExpA1(); break;
        case set_intersection: accept(set_intersection); Termo(); ExpA1(); break;
        case set_union: accept(set_union); Termo(); ExpA1(); break;
        case parenteses_direita: break;
        case ']': break;
        case op_gte: break;
        case op_lte: break;
        case op_lt: break;
        case op_gt: break;
        case op_diff: break;
        case op_equal: break;
        case op_and: break;
        case op_or: break;
        case ';': break;
        case virgula: break;
        default: error("ExpA1\n");
    }
}

void Termo() {
    switch(tok) {
        case id:
        case inteiro:
        case real:
        case caractere:
        case palavra:
        case op_sub:
        case op_sum: Fator(); Termo1(); break;
        default: error("esperando (id, inteiro, real, caractere, palavra, -, ou +\n");
    }
}

void Termo1() {
    switch(tok) {
        case op_mult: accept(op_mult); Fator(); Termo1(); break;
        case op_div: accept(op_div); Fator(); Termo1(); break;
        case op_mod: accept(op_mod); Fator(); Termo1(); break;
        case parenteses_direita: break;
        case ']': break;
        case op_sub: break;
        case op_sum: break;
        case set_intersection: break;
        case set_union: break;
        case op_gte: break;
        case op_lte: break;
        case op_lt: break;
        case op_gt: break;
        case op_diff: break;
        case op_equal: break;
        case op_and: break;
        case op_or: break;
        case ';': break;
        case virgula: break;
        default: error("Termo1\n");
    }
}

void Fator() {
    switch(tok) {
        case id:
        case inteiro:
        case real:
        case caractere:
        case palavra:
        case op_sub:
        case op_sum: ExpUnaria(); Fator2(); break;
        default: error("esperando (id, inteiro, real, caractere, palavra, -, ou +\n");
    }
}

void Fator2() {
    switch(tok) {
        case '^': accept('^'); Fator(); break;
        case parenteses_direita: break;
        case ']': break;
        case op_sub: break;
        case op_sum: break;
        case op_mod: break;
        case op_div: break;
        case op_mult: break;
        case set_intersection: break;
        case set_union: break;
        case op_gte: break;
        case op_lte: break;
        case op_lt: break;
        case op_gt: break;
        case op_diff: break;
        case op_equal: break;
        case op_and: break;
        case op_or: break;
        case ';': break;
        case virgula: break;
        default: error("Fator2\n");
    }
}

void ExpUnaria() {
    switch(tok) {
        case op_sub: accept(op_sub); ExpBase(); break;
        case op_sum: accept(op_sum); ExpBase(); break;
        case id:
        case inteiro:
        case real:
        case caractere:
        case palavra: ExpBase(); break;
        default: error("esperando -, +, id, inteiro, real, caractere ou palavra\n");
    }
}

void ExpBase() {
    switch(tok) {
        case parenteses_esquerda: accept(parenteses_esquerda); Expressao(); accept(parenteses_direita); break;
        case id: accept(id); ExpId(); break;
        case inteiro: accept(inteiro); break;
        case real: accept(real); break;
        case caractere: accept(caractere); break;
        case palavra: accept(palavra); break;
        default: error("esperando (, id, inteiro, real, caractere ou palavra\n");
    }
}



void ExpId() {
    switch(tok) {
        case '^':
        case op_mult:
        case op_div:
        case op_mod:
        case op_sub:
        case op_sum:
        case set_union:
        case set_intersection:
        case op_equal:
        case op_diff:
        case op_lt:
        case op_gt:
        case op_lte:
        case op_gte:
        case op_and:
        case op_or:
        case virgula:
        case ';': 
        case ']':
        case parenteses_direita: break;
        case '[': accept('['); Expressao(); accept(']'); break;
        case parenteses_esquerda: accept(parenteses_esquerda); Expressao(); accept(parenteses_direita); break;
        case ponto: accept(ponto); accept(id); break;
        default: error("esperando [, ( ou .\n");
    }
}

void Programa() {
    switch(tok) {
	    case eof: break;
        case key_def:
        case key_deftipo:
        case parenteses_esquerda:
        case id:
        case key_if:
        case key_read:
        case key_out:
        case key_return:
        case key_break:
        case key_continue:
        case '{':
        case key_for:
        case key_for_set:
        case key_while:
        case key_caractere:
        case key_string:
        case key_set:
        case key_register:
        case key_vetor:
        case key_int:
        case key_real:
        case key_bool: Def(); Programa(); break;
        default: error("esperando def, deftipo, (, id, se, leia, escreva, retorne, pare, continue, {, para, paraconj, enquanto, caractere, palavra, conjunto, registro, vetor, inteiro, real, booleano\n");
    }
}

void Def() {
    switch(tok) {
        case key_def: accept(key_def); DefinicaoFuncao(); printf("------------------------\n"); break;
        case key_deftipo: DefinicaoRegistro(); break;
        case key_return_nothing:
        case key_caractere:
        case key_string:
        case key_set:
        case key_register:
        case key_vetor:
        case key_int:
        case key_real:
        case key_bool: Instrucao(); break;
        default: error("-->esperando def, deftipo, vazio, caractere, palavra, conjunto, registro, vetor, inteiro, real ou booleano\n");
    }
}

void DefinicaoRegistro() {
    switch(tok) {
        case key_deftipo: accept(key_deftipo); accept(key_register); accept(id); accept('{'); ListaAtributos(); accept('}'); break;
        default: error("esperando deftipo\n");
    }
}

void ListaAtributos() {
    switch(tok) {
        case key_caractere:
        case key_string:
        case key_set:
        case key_register:
        case key_vetor:
        case key_int:
        case key_real:
        case key_bool: InstrucaoDeclaracaoInicializacao(); ListaAtributos2(); break;
        default: error("esperando caractere, palavra, conjunto, registro, vetor, inteiro, real ou booleano\n"); 
    }
}

void ListaAtributos2() {
    switch(tok) {
        case key_caractere:
        case key_string:
        case key_set:
        case key_register:
        case key_vetor:
        case key_int:
        case key_real:
        case key_bool: ListaAtributos(); break;
        case '}': break;
        default: error("esperando caractere, palavra, conjunto, registro, vetor, inteiro, real ou booleano\n"); 
    }
} 


void DefinicaoFuncao() {
    switch(tok) {
        case key_return_nothing:
        case key_caractere:
        case key_string:
        case key_set:
        case key_register:
        case key_vetor:
        case key_int:
        case key_real:
        case key_bool: TipoFuncao(); accept(id); accept(parenteses_esquerda); ListaParamsFunc(); accept(parenteses_direita); Bloco(); break;
        default: error("esperando vazio, caractere, palavra, conjunto, registro, vetor, inteiro, real ou booleano\n");
    }
}

void ListaParamsFunc() {
    switch(tok) {
        case key_caractere:
        case key_string:
        case key_set:
        case key_register:
        case key_vetor:
        case key_int:
        case key_real:
        case key_bool: ParamFunc(); ListaParamsFunc2(); break;
        case parenteses_direita: break;
        default: error("esperando caractere, palavra, conjunto, registro, vetor, inteiro, real, booleano ou )\n");   
    }
}

void ParamFunc() {
    switch(tok) {
        case key_caractere:
        case key_string:
        case key_set:
        case key_register:
        case key_vetor:
        case key_int:
        case key_real:
        case key_bool: Tipo(); accept(id); break;
        default: error("esperando caractere, palavra, conjunto, registro, vetor, inteiro, real ou booleano\n");
    }
}

void ListaParamsFunc2() {
    switch(tok) {
        case virgula: accept(virgula); ParamFunc(); break;
        case parenteses_direita: break;
        default: error("esperando virgula ou )\n");
    }
}

void TipoFuncao() {
    switch(tok) {
        case key_return_nothing: accept(key_return_nothing); break;
        case key_caractere:
        case key_string:
        case key_set:
        case key_register:
        case key_vetor:
        case key_int:
        case key_real:
        case key_bool: Tipo(); break;
        default: error("esperando vazio, caractere, palavra, conjunto, registro, vetor, inteiro, real ou booleano\n");
    }
}

void Tipo() {
    switch(tok) {
        case key_caractere:
        case key_string:
        case key_int:
        case key_real:
        case key_bool: TipoPrimitivo(); break;
        case key_set:
        case key_register:
        case key_vetor: TipoEstruturado(); break;
        default: error("esperando caractere, palavra, conjunto, registro, vetor, inteiro, real ou booleano\n");   
    }
}

void TipoPrimitivo() {
    switch(tok) {
        case key_int:
        case key_real:
        case key_bool: TipoNumerico(); break;
        case key_caractere: accept(key_caractere); break;
        case key_string: accept(key_string); break;
        default: error("esperando inteiro, real, booleano, caractere ou palavra\n");
    }
}

void TipoNumerico() {
    switch(tok) {
        case key_int: accept(key_int); break;
        case key_real: accept(key_real); break;
        case key_bool: accept(key_bool); break;
        default: error("esperando inteiro, real ou booleano\n");
    }
}

void TipoEstruturado() {
    switch(tok) {
        case key_set: accept(key_set); Tipo(); break;
        case key_register: accept(key_register); accept(id); break;
        case key_vetor: accept(key_vetor); Tipo(); accept('['); accept(']'); break;
        default: error("esperando conjunto, registro ou vetor\n");
    }
}


