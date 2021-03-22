#include <stdio.h>
#include <stdlib.h>
#include "tokens.h"

char token_names[124][35] = {
    "=", 
    "+=", 
    "-=", 
    "*=", 
    "/=", 
    "\\\/=", 
    "\/\\=", 
    "~",
    "||",
    "&&", 
    ">",
    "<",
    "<=", 
    ">=", 
    "==", 
    "!=", 
    "%", 
    "(", 
    ")", 
    "*", 
    "/", 
    "+", 
    "-", 
    ",", 
    ".", 
    "\/\\",
    "\\\/",  
    "booleano", 
    "caractere", 
    "conjunto",
    "vetor",
    "continue", 
    "enquanto", 
    "escreva", 
    "inteiro", 
    "leia", 
    "para", 
    "paraconj",
    "em", 
    "pare", 
    "palavra",  
    "se", 
    "senao", 
    "real", 
    "registro", 
    "retorne", 
    "void", 
    "def", 
    "deftipo", 

    "booleano_lit", 
    "inteiro_lit", 
    "real_lit", 
    "caractere_lit", 
    "palavra_lit", 
    "id",

    "[",
    "]",
    "^",
    ";",
    "{",
    "}",

    "eof",
    "empty",

    "TExpressao",
    "TExp1",
    "TTLogico",
    "TTLogico1",
    "TFLogico",
    "TExpRel",
    "TExpRel2",
    "TExpA",
    "TExpA1",
    "TTermo",
    "TTermo1",
    "TFator",
    "TFator2",
    "TExpUnaria",
    "TExpBase",
    "TExpId",
    "TInstrucoes",
    "TInstrucoes2",
    "TInstrucao",
    "TInstrucaoDeclaracaoInicializacao",
    "TInstrucaoDeclaracaoInicializacao2",
    "TInstrucaoDeclaracaoInicializacao3",
    "TInstrucaoAtribuicaoCasting",
    "TInstrucaoChamadaId",
    "TChamadaFuncaoOuAtribuicao",
    "TLvalueId",
    "TOperadoresAtribuicao",
    "TListaIdentificadores",
    "TListaIdentificadores2",
    "TListaExpressoes",
    "TListaExpressoes2",
    "TInstrucaoCondicional",
    "TInstrucaoCondicional2",
    "TInstrucaoRepeticao",
    "TLacoPara",
    "TLacoParaConjunto",
    "TLacoEnquanto",
    "TInstrucaoSaida",
    "TInstrucaoIO",
    "TBloco",
    "TDefinicaoFuncao",
    "TListaParametrosFuncao",
    "TListaParametrosFuncao2",
    "TTipoFuncao",
    "TParametroFuncao",
    "TTipo",
    "TTipoPrimitivo",
    "TTipoNumerico",
    "TTipoEstruturado",
    "TPrograma",
    "TDef",
    "TDefinicaoRegistro",
    "TListaAtributos",
    "TListaAtributos2"
    
};

void printToken(Token token) {
    for(int i = 0; i < 35; i++){
        printf("%c", token_names[token][i]);
    }
    printf(" ");
}
