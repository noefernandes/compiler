/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_LRPARSER_H_INCLUDED
# define YY_YY_LRPARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    eof = 0,
    assign = 258,
    assign_sum = 259,
    assign_sub = 260,
    assign_mult = 261,
    assign_div = 262,
    assign_set_union = 263,
    assign_set_intersection = 264,
    op_not = 265,
    op_or = 266,
    op_and = 267,
    op_gt = 268,
    op_lt = 269,
    op_lte = 270,
    op_gte = 271,
    op_equal = 272,
    op_diff = 273,
    op_mod = 274,
    parenteses_esquerda = 275,
    parenteses_direita = 276,
    op_mult = 277,
    op_div = 278,
    op_sum = 279,
    op_sub = 280,
    virgula = 281,
    ponto = 282,
    set_intersection = 283,
    set_union = 284,
    key_bool = 285,
    key_caractere = 286,
    key_set = 287,
    key_vetor = 288,
    key_continue = 289,
    key_while = 290,
    key_write = 291,
    key_int = 292,
    key_read = 293,
    key_for = 294,
    key_for_set = 295,
    key_in = 296,
    key_break = 297,
    key_string = 298,
    key_if = 299,
    key_else = 300,
    key_real = 301,
    key_register = 302,
    key_return = 303,
    key_return_nothing = 304,
    key_def = 305,
    key_deftipo = 306,
    colchetes_esquerda = 307,
    colchetes_direita = 308,
    circunflexo = 309,
    ponto_virgula = 310,
    chaves_esquerda = 311,
    chaves_direita = 312,
    empty = 313,
    TExpressao = 314,
    TExp1 = 315,
    TTLogico = 316,
    TTLogico1 = 317,
    TFLogico = 318,
    TExpRel = 319,
    TExpRel2 = 320,
    TExpA = 321,
    TExpA1 = 322,
    TTermo = 323,
    TTermo1 = 324,
    TFator = 325,
    TFator2 = 326,
    TExpUnaria = 327,
    TExpBase = 328,
    TExpId = 329,
    TInstrucoes = 330,
    TInstrucoes2 = 331,
    TInstrucao = 332,
    TInstrucaoDeclaracaoInicializacao = 333,
    TInstrucaoDeclaracaoInicializacao2 = 334,
    TInstrucaoDeclaracaoInicializacao3 = 335,
    TInstrucaoAtribuicaoCasting = 336,
    TInstrucaoChamadaId = 337,
    TChamadaFuncaoOuAtribuicao = 338,
    TLvalueId = 339,
    TOperadoresAtribuicao = 340,
    TListaIdentificadores = 341,
    TListaIdentificadores2 = 342,
    TListaExpressoes = 343,
    TListaExpressoes2 = 344,
    TInstrucaoCondicional = 345,
    TInstrucaoCondicional2 = 346,
    TInstrucaoRepeticao = 347,
    TLacoPara = 348,
    TLacoParaConjunto = 349,
    TLacoEnquanto = 350,
    TInstrucaoSaida = 351,
    TInstrucaoIO = 352,
    TBloco = 353,
    TDefinicaoFuncao = 354,
    TListaParametrosFuncao = 355,
    TListaParametrosFuncao2 = 356,
    TTipoFuncao = 357,
    TParametroFuncao = 358,
    TTipo = 359,
    TTipoPrimitivo = 360,
    TTipoNumerico = 361,
    TTipoEstruturado = 362,
    TPrograma = 363,
    TDef = 364,
    TDefinicaoRegistro = 365,
    TListaAtributos = 366,
    TListaAtributos2 = 367,
    booleano = 368,
    inteiro = 369,
    real = 370,
    caractere = 371,
    palavra = 372,
    id = 373
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 27 "lrParser.y"

    int iValue;     // integer value
    char* sValue;     // string value

#line 182 "lrParser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_LRPARSER_H_INCLUDED  */
