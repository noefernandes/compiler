#include <stdio.h>
#include <stdlib.h>
#include "tokens.h"
#include "recursiveParser.h"

Token tok;

void nextsym() {
    tok = yylex();
}

void error(const char msg[]) {
    printf("%s", msg);
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
        case parenteses_esquerda: Instrucao(); break;
        case '}': break;        
        default: error("esperando } \n");
    }
};

void Instrucao(){
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
        case parenteses_esquerda: InstrucaoRepeticao(); InstrucaoIO(); InstrucaoSaida(); Bloco(); break;
        default: error(
            "esperando id, se, leia, escreva, retorne, pare, continue, {, para, paraconj, caractere, palavra, conjunto, registro, vetor, real, inteiro, booleano\n"
        );
    }
};

void InstrucaoRepeticao(){
    switch(tok) {
        case key_for_set:
        case key_while:
        case key_for: LacoPara(); LacoParaConjunto(); LacoEnquanto(); break;
        default: error(
            "esperando para, paraconj, enquanto \n"
        );
    }
};
void InstrucaoIO(){
    switch(tok) {
        case key_out: 
            accept(key_out); 
            accept('('); 
            Expressao(); 
            accept(')'); 
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
            accept(op_assign); 
            Expressao(); 
            accept(';'); 
            Expressao(); 
            accept(';'); 
            InstrucaoAtribuicao(); 
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
        case '~': TLogico(); Exp1(); break;
        default: error("esperando id, inteiro, real, caractere, palavra, -, + ou ~\n");
    }
}

void Exp1() {
    switch(tok) {
        case op_log_or: accept(op_log_or); TLogico(); Exp1(); break;
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
        case '~': FLogico(); TLogico1(); break;
        default: error("esperando id, inteiro, real, caractere, palavra, -, + ou ~\n");
    }
}

void TLogico1() {
    switch(tok) {
        case op_log_and: accept(op_log_and); FLogico(); TLogico1(); break;
        case parenteses_direita: break;
        case ']': break;
        case op_log_or: break;
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
        case '~': accept('~'); ExpRel(); break;
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
        case op_log_equal: accept(op_log_equal); ExpA(); break;
        case op_log_diff: accept(op_log_diff); ExpA(); break;
        case '<': accept('<'); ExpA(); break;
        case '>': accept('>'); ExpA(); break;
        case op_log_lte: accept(op_log_lte); ExpA(); break;
        case op_log_gte: accept(op_log_gte); ExpA(); break;
        case parenteses_direita: break;
        case ']': break;
        case op_log_and: break;
        case op_log_or: break;
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
        case op_conj_intersection: accept(op_conj_intersection); Termo(); ExpA1(); break;
        case op_conj_union: accept(op_conj_union); Termo(); ExpA1(); break;
        case parenteses_direita: break;
        case ']': break;
        case op_log_gte: break;
        case op_log_lte: break;
        case '<': break;
        case '>': break;
        case op_log_diff: break;
        case op_log_equal: break;
        case op_log_and: break;
        case op_log_or: break;
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
        case op_conj_intersection: break;
        case op_conj_union: break;
        case op_log_gte: break;
        case op_log_lte: break;
        case '<': break;
        case '>': break;
        case op_log_diff: break;
        case op_log_equal: break;
        case op_log_and: break;
        case op_log_or: break;
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
        case op_conj_intersection: break;
        case op_conj_union: break;
        case op_log_gte: break;
        case op_log_lte: break;
        case '<': break;
        case '>': break;
        case op_log_diff: break;
        case op_log_equal: break;
        case op_log_and: break;
        case op_log_or: break;
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
        case key_def: accept(key_def); DefinicaoFuncao(); break;
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
        default: error("esperando def, deftipo, vazio, caractere, palavra, conjunto, registro, vetor, inteiro, real ou booleano\n");
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
        case key_bool: InstrucaoDeclIni(); ListaAtributos2(); break;
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
