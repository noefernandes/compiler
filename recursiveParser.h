#include "tokens.h"

void nextsym();
void error(const char msg[]);
void accept(Token s);

/* Nonterminals symbols */
void Expressao();
void Exp1();
void TLogico();
void TLogico1();
void FLogico();
void ExpRel();
void ExpRel2();
void ExpA();
void ExpA1();
void Termo();
void Termo1();
void Fator();
void Fator2();
void ExpUnaria();
void ExpBase();
void ExpId();

void Programa();
void Def();
void DefinicaoFuncao();
void DefinicaoRegistro();
void Instrucao();
void ListaAtributos();
void ListaAtributos2();
void InstrucaoDeclIni();
void TipoFuncao();
void ListaParamsFunc();
void Bloco();
void ParamFunc();
void ListaParamsFunc2();
void Tipo();
void TipoPrimitivo();
void TipoEstruturado();
void TipoNumerico();
