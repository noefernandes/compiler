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
    booleano = 307,
    inteiro = 308,
    real = 309,
    caractere = 310,
    palavra = 311,
    id = 312,
    colchetes_esquerda = 313,
    colchetes_direita = 314,
    circunflexo = 315,
    ponto_virgula = 316,
    chaves_esquerda = 317,
    chaves_direita = 318,
    empty = 319,
    TExpressao = 320,
    TExp1 = 321,
    TTLogico = 322,
    TTLogico1 = 323,
    TFLogico = 324,
    TExpRel = 325,
    TExpRel2 = 326,
    TExpA = 327,
    TExpA1 = 328,
    TTermo = 329,
    TTermo1 = 330,
    TFator = 331,
    TFator2 = 332,
    TExpUnaria = 333,
    TExpBase = 334,
    TExpId = 335,
    TInstrucoes = 336,
    TInstrucoes2 = 337,
    TInstrucao = 338,
    TInstrucaoDeclaracaoInicializacao = 339,
    TInstrucaoDeclaracaoInicializacao2 = 340,
    TInstrucaoDeclaracaoInicializacao3 = 341,
    TInstrucaoAtribuicaoCasting = 342,
    TInstrucaoChamadaId = 343,
    TChamadaFuncaoOuAtribuicao = 344,
    TLvalueId = 345,
    TOperadoresAtribuicao = 346,
    TListaIdentificadores = 347,
    TListaIdentificadores2 = 348,
    TListaExpressoes = 349,
    TListaExpressoes2 = 350,
    TInstrucaoCondicional = 351,
    TInstrucaoCondicional2 = 352,
    TInstrucaoRepeticao = 353,
    TLacoPara = 354,
    TLacoParaConjunto = 355,
    TLacoEnquanto = 356,
    TInstrucaoSaida = 357,
    TInstrucaoIO = 358,
    TBloco = 359,
    TDefinicaoFuncao = 360,
    TListaParametrosFuncao = 361,
    TListaParametrosFuncao2 = 362,
    TTipoFuncao = 363,
    TParametroFuncao = 364,
    TTipo = 365,
    TTipoPrimitivo = 366,
    TTipoNumerico = 367,
    TTipoEstruturado = 368,
    TPrograma = 369,
    TDef = 370,
    TDefinicaoRegistro = 371,
    TListaAtributos = 372,
    TListaAtributos2 = 373,
    matched_if = 374
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_LRPARSER_H_INCLUDED  */
