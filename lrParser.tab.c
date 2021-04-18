/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "lrParser.y"

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

#line 84 "lrParser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
#line 15 "lrParser.y"

    int iValue;     // integer value
    char* sValue;     // string value

#line 261 "lrParser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_LRPARSER_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  77
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   599

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  119
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  214

#define YYUNDEFTOK  2
#define YYMAXUTOK   373


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    42,    42,    43,    46,    47,    48,    51,    54,    55,
      58,    61,    62,    63,    66,    67,    70,    73,    74,    77,
      78,    79,    82,    83,    84,    87,    88,    89,    92,    95,
      96,    99,   100,   101,   102,   103,   104,   105,   106,   109,
     110,   113,   114,   117,   118,   121,   124,   125,   128,   131,
     132,   133,   136,   137,   138,   141,   142,   145,   146,   147,
     150,   153,   156,   159,   160,   161,   164,   165,   168,   169,
     170,   171,   172,   173,   174,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   205,   206,   207,   208
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "eof", "error", "$undefined", "assign", "assign_sum", "assign_sub",
  "assign_mult", "assign_div", "assign_set_union",
  "assign_set_intersection", "op_not", "op_or", "op_and", "op_gt", "op_lt",
  "op_lte", "op_gte", "op_equal", "op_diff", "op_mod",
  "parenteses_esquerda", "parenteses_direita", "op_mult", "op_div",
  "op_sum", "op_sub", "virgula", "ponto", "set_intersection", "set_union",
  "key_bool", "key_caractere", "key_set", "key_vetor", "key_continue",
  "key_while", "key_write", "key_int", "key_read", "key_for",
  "key_for_set", "key_in", "key_break", "key_string", "key_if", "key_else",
  "key_real", "key_register", "key_return", "key_return_nothing",
  "key_def", "key_deftipo", "colchetes_esquerda", "colchetes_direita",
  "circunflexo", "ponto_virgula", "chaves_esquerda", "chaves_direita",
  "empty", "TExpressao", "TExp1", "TTLogico", "TTLogico1", "TFLogico",
  "TExpRel", "TExpRel2", "TExpA", "TExpA1", "TTermo", "TTermo1", "TFator",
  "TFator2", "TExpUnaria", "TExpBase", "TExpId", "TInstrucoes",
  "TInstrucoes2", "TInstrucao", "TInstrucaoDeclaracaoInicializacao",
  "TInstrucaoDeclaracaoInicializacao2",
  "TInstrucaoDeclaracaoInicializacao3", "TInstrucaoAtribuicaoCasting",
  "TInstrucaoChamadaId", "TChamadaFuncaoOuAtribuicao", "TLvalueId",
  "TOperadoresAtribuicao", "TListaIdentificadores",
  "TListaIdentificadores2", "TListaExpressoes", "TListaExpressoes2",
  "TInstrucaoCondicional", "TInstrucaoCondicional2", "TInstrucaoRepeticao",
  "TLacoPara", "TLacoParaConjunto", "TLacoEnquanto", "TInstrucaoSaida",
  "TInstrucaoIO", "TBloco", "TDefinicaoFuncao", "TListaParametrosFuncao",
  "TListaParametrosFuncao2", "TTipoFuncao", "TParametroFuncao", "TTipo",
  "TTipoPrimitivo", "TTipoNumerico", "TTipoEstruturado", "TPrograma",
  "TDef", "TDefinicaoRegistro", "TListaAtributos", "TListaAtributos2",
  "booleano", "inteiro", "real", "caractere", "palavra", "id", "$accept",
  "PROGRAM", "DEF", "DEFINICAO_FUNCAO", "DEFINICAO_REGISTRO", "INSTRUCAO",
  "LISTA_ATRIBUTOS", "INSTRUCAO_DECLARACAO_INICIALIZACAO", "TIPO_FUNCAO",
  "LISTA_PARAMETROS_FUNCAO", "BLOCO", "PARAMETRO_FUNCAO", "TIPO",
  "TIPO_PRIMITIVO", "TIPO_ESTRUTURADO", "TIPO_NUMERICO", "INSTRUCOES",
  "INSTRUCAO_CHAMADA_ID", "INSTRUCAO_ATRIBUICAO_CASTING",
  "INSTRUCAO_CONDICIONAL", "INSTRUCAO_REPETICAO", "INSTRUCAO_IO",
  "INSTRUCAO_SAIDA", "LISTA_IDENTIFICADORES", "OPERADORES_ATRIBUICAO",
  "INSTRUCAO_DECLARACAO_INICIALIZACAO_2", "LISTA_EXPRESSOES",
  "CHAMADA_FUNCAO_OU_ATRIBUICAO", "LVALUE", "EXP", "LACO_PARA",
  "LACO_PARA_CONJUNTO", "LACO_ENQUANTO", "EXP_ID", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373
};
# endif

#define YYPACT_NINF (-159)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     115,    83,  -159,  -159,   546,   546,   -47,   -10,    -8,  -159,
       3,     4,     5,   -28,  -159,     8,  -159,   -83,    23,   137,
     -11,   165,   -14,    45,   115,  -159,  -159,  -159,  -159,   -68,
    -159,  -159,  -159,     0,     1,  -159,  -159,  -159,  -159,  -159,
    -159,  -159,    32,  -159,     6,  -159,    23,    23,   -61,    85,
     -49,  -159,    23,  -159,    23,    23,    23,    23,  -159,  -159,
    -159,  -159,  -159,     2,    49,  -159,  -159,   -48,  -159,   -43,
     165,    19,    23,   -39,    23,  -159,   211,  -159,    81,   270,
      28,  -159,  -159,   -16,    47,   276,   295,    84,   -12,    76,
     322,   521,   341,    -2,    -2,    23,     7,    23,  -159,    23,
      23,    23,    23,    23,    23,    23,    23,    23,    23,    23,
      23,    23,    23,    23,    23,  -159,    98,    65,  -159,  -159,
     102,   368,  -159,   387,  -159,  -159,  -159,  -159,  -159,  -159,
    -159,    23,  -159,    10,    -6,  -159,   -18,  -159,   165,    75,
      77,   130,    23,   165,  -159,   414,  -159,   433,   503,   521,
     545,   545,   545,   545,   545,   545,    80,    80,    80,    -2,
      -2,    -2,    -2,    80,   546,   546,  -159,    23,  -159,   479,
     116,  -159,    23,    88,  -159,   211,  -159,  -159,  -159,    23,
     460,   -29,  -159,  -159,   123,   146,    38,   121,   546,  -159,
     120,  -159,    23,   212,   165,   165,  -159,   125,   546,  -159,
    -159,  -159,  -159,   479,    23,  -159,  -159,  -159,  -159,   231,
      61,   161,   165,  -159
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,    24,    20,     0,     0,     0,     0,     0,    22,
       0,     0,     0,     0,    21,     0,    23,     0,     0,     0,
       0,     0,    51,     0,     3,     5,     6,    31,    38,     0,
      17,    18,    19,     0,     0,    34,    35,    36,    37,    57,
      58,    59,     0,    25,     0,    65,     0,     0,     0,     0,
       0,    64,     0,    26,     0,     0,     0,     0,    80,    76,
      77,    78,    79,   101,     0,    15,     4,     0,    14,     0,
      29,     0,    54,     0,     0,    45,     0,     1,     0,    43,
       0,    32,    33,     0,     0,     0,     0,     0,     0,     0,
       0,    84,     0,    86,    85,     0,     0,     0,    75,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    63,     0,     0,    30,    28,
       0,    52,    50,     0,    68,    69,    70,    71,    72,    73,
      74,     0,     2,     0,    54,    39,    51,    27,     0,     0,
       0,     0,     0,     0,    81,     0,   102,     0,    82,    83,
      99,   100,    98,    97,    96,    95,    93,    91,    92,    88,
      87,    89,    90,    94,    13,     0,    46,    54,    49,    47,
      43,    44,    54,     0,    41,     0,    62,    67,    66,     0,
       0,     0,   104,   103,     0,    11,     0,     0,     8,    53,
       0,    40,     0,     0,     0,     0,    55,     0,    13,    16,
       7,     9,    42,    48,     0,    61,    56,    10,    12,     0,
       0,     0,     0,    60
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -159,   163,  -159,  -159,  -159,   -19,    18,  -158,  -159,    -7,
      -9,  -159,    -4,   189,  -159,   143,   140,    12,  -159,  -159,
    -159,  -159,  -159,    99,   -74,  -159,  -123,  -159,   103,   -15,
    -159,  -159,  -159,  -159
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    23,    24,    66,    25,    26,   187,    27,    67,   184,
      28,   185,    29,    30,    31,    32,    71,    33,    34,    35,
      36,    37,    38,    80,   131,   173,   120,    75,    76,   121,
      39,    40,    41,    98
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      43,    44,    70,    64,    54,   134,    72,   188,    45,    73,
      46,   174,    47,    73,    55,    68,   195,   107,    56,    57,
     108,   109,    95,    48,    49,    50,   196,    51,    52,    96,
     188,    85,    86,    54,    74,    53,    69,    90,    74,    91,
      92,    93,    94,    55,   189,    77,   172,    56,    57,   190,
      79,    70,   114,    83,    97,    81,    82,    87,    84,   123,
      99,   100,   101,   102,   103,   104,   105,   106,   107,    89,
     116,   108,   109,   110,   111,   117,   119,   112,   113,   122,
     145,   132,   147,   135,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     137,   192,   136,   114,   115,   140,   141,    58,    59,    60,
      61,    62,    63,     2,     3,     2,   169,   142,   164,   176,
       9,   165,     9,   166,   181,   146,    14,   180,   170,    16,
     177,    16,   178,   179,   114,     1,    58,    59,    60,    61,
      62,    63,   133,   191,   197,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,   199,    13,    14,    15,
     186,    16,    17,    18,   193,    19,    20,     2,     3,     4,
       5,    21,   198,   202,     9,   205,   206,   203,   200,    22,
      14,    21,   212,    16,    17,     1,    65,    78,   207,   209,
      42,   208,    88,   213,   186,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,   201,    13,    14,    15,
     118,    16,    17,    18,   124,   125,   126,   127,   128,   129,
     130,    21,   211,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   171,    22,   108,   109,   110,   111,     0,   175,
     112,   113,    99,   100,   101,   102,   103,   104,   105,   106,
     107,     0,     0,   108,   109,   110,   111,     0,     0,   112,
     113,     0,     0,     0,     0,     0,   114,   204,     0,     0,
       0,     0,     0,   124,   125,   126,   127,   128,   129,   130,
       0,     0,     0,    22,     0,   114,   210,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   133,   138,   108,   109,
     110,   111,     0,     0,   112,   113,    99,   100,   101,   102,
     103,   104,   105,   106,   107,     0,   139,   108,   109,   110,
     111,     0,     0,   112,   113,     0,     0,     0,     0,     0,
     114,     0,     0,    99,   100,   101,   102,   103,   104,   105,
     106,   107,     0,   143,   108,   109,   110,   111,     0,   114,
     112,   113,    99,   100,   101,   102,   103,   104,   105,   106,
     107,     0,   144,   108,   109,   110,   111,     0,     0,   112,
     113,     0,     0,     0,     0,     0,   114,     0,     0,    99,
     100,   101,   102,   103,   104,   105,   106,   107,     0,     0,
     108,   109,   110,   111,   167,   114,   112,   113,    99,   100,
     101,   102,   103,   104,   105,   106,   107,     0,     0,   108,
     109,   110,   111,     0,     0,   112,   113,     0,     0,     0,
       0,     0,   114,     0,     0,    99,   100,   101,   102,   103,
     104,   105,   106,   107,     0,   182,   108,   109,   110,   111,
     168,   114,   112,   113,    99,   100,   101,   102,   103,   104,
     105,   106,   107,     0,     0,   108,   109,   110,   111,     0,
       0,   112,   113,     0,     0,     0,     0,     0,   114,     0,
       0,    99,   100,   101,   102,   103,   104,   105,   106,   107,
       0,   194,   108,   109,   110,   111,   183,   114,   112,   113,
      99,   100,   101,   102,   103,   104,   105,   106,   107,     0,
       0,   108,   109,   110,   111,     0,     0,   112,   113,     0,
       0,     0,     0,     0,   114,   100,   101,   102,   103,   104,
     105,   106,   107,     0,     0,   108,   109,   110,   111,     0,
       0,   112,   113,   114,   101,   102,   103,   104,   105,   106,
     107,     0,     0,   108,   109,   110,   111,     0,     0,   112,
     113,     0,     0,     0,     0,     0,     0,   114,    -1,    -1,
      -1,    -1,    -1,    -1,   107,     0,     0,   108,   109,   110,
     111,     0,     0,   112,   113,   114,     2,     3,     4,     5,
       0,     0,     0,     9,     0,     0,     0,     0,     0,    14,
       0,     0,    16,    17,     0,     0,     0,     0,     0,   114
};

static const yytype_int16 yycheck[] =
{
       4,     5,    21,    18,    10,    79,    20,   165,    55,    27,
      20,   134,    20,    27,    20,    19,    45,    19,    24,    25,
      22,    23,    20,    20,    20,    20,    55,    55,    20,    27,
     188,    46,    47,    10,    52,   118,    47,    52,    52,    54,
      55,    56,    57,    20,   167,     0,    52,    24,    25,   172,
     118,    70,    54,    21,    52,    55,    55,   118,    52,    74,
      11,    12,    13,    14,    15,    16,    17,    18,    19,   118,
     118,    22,    23,    24,    25,   118,    57,    28,    29,   118,
      95,     0,    97,    55,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
      53,   175,   118,    54,    55,    21,   118,   113,   114,   115,
     116,   117,   118,    30,    31,    30,   131,    41,    20,   138,
      37,    56,    37,    21,   143,   118,    43,   142,   118,    46,
      55,    46,    55,     3,    54,    20,   113,   114,   115,   116,
     117,   118,    26,    55,    21,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,   118,    42,    43,    44,
     164,    46,    47,    48,   179,    50,    51,    30,    31,    32,
      33,    56,    26,    53,    37,   194,   195,   192,    57,   118,
      43,    56,    21,    46,    47,    20,    49,    24,   197,   204,
       1,   198,    49,   212,   198,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,   188,    42,    43,    44,
      70,    46,    47,    48,     3,     4,     5,     6,     7,     8,
       9,    56,   210,    11,    12,    13,    14,    15,    16,    17,
      18,    19,   133,   118,    22,    23,    24,    25,    -1,   136,
      28,    29,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    -1,    -1,    22,    23,    24,    25,    -1,    -1,    28,
      29,    -1,    -1,    -1,    -1,    -1,    54,    55,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    -1,   118,    -1,    54,    55,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    26,    21,    22,    23,
      24,    25,    -1,    -1,    28,    29,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    -1,    21,    22,    23,    24,
      25,    -1,    -1,    28,    29,    -1,    -1,    -1,    -1,    -1,
      54,    -1,    -1,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    -1,    21,    22,    23,    24,    25,    -1,    54,
      28,    29,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    -1,    21,    22,    23,    24,    25,    -1,    -1,    28,
      29,    -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    -1,    -1,
      22,    23,    24,    25,    26,    54,    28,    29,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    -1,    -1,    22,
      23,    24,    25,    -1,    -1,    28,    29,    -1,    -1,    -1,
      -1,    -1,    54,    -1,    -1,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    -1,    21,    22,    23,    24,    25,
      53,    54,    28,    29,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    -1,    -1,    22,    23,    24,    25,    -1,
      -1,    28,    29,    -1,    -1,    -1,    -1,    -1,    54,    -1,
      -1,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      -1,    21,    22,    23,    24,    25,    53,    54,    28,    29,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    -1,
      -1,    22,    23,    24,    25,    -1,    -1,    28,    29,    -1,
      -1,    -1,    -1,    -1,    54,    12,    13,    14,    15,    16,
      17,    18,    19,    -1,    -1,    22,    23,    24,    25,    -1,
      -1,    28,    29,    54,    13,    14,    15,    16,    17,    18,
      19,    -1,    -1,    22,    23,    24,    25,    -1,    -1,    28,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    54,    13,    14,
      15,    16,    17,    18,    19,    -1,    -1,    22,    23,    24,
      25,    -1,    -1,    28,    29,    54,    30,    31,    32,    33,
      -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,    43,
      -1,    -1,    46,    47,    -1,    -1,    -1,    -1,    -1,    54
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    20,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    42,    43,    44,    46,    47,    48,    50,
      51,    56,   118,   120,   121,   123,   124,   126,   129,   131,
     132,   133,   134,   136,   137,   138,   139,   140,   141,   149,
     150,   151,   132,   131,   131,    55,    20,    20,    20,    20,
      20,    55,    20,   118,    10,    20,    24,    25,   113,   114,
     115,   116,   117,   118,   148,    49,   122,   127,   131,    47,
     124,   135,    20,    27,    52,   146,   147,     0,   120,   118,
     142,    55,    55,    21,    52,   148,   148,   118,   134,   118,
     148,   148,   148,   148,   148,    20,    27,    52,   152,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    22,    23,
      24,    25,    28,    29,    54,    55,   118,   118,   135,    57,
     145,   148,   118,   148,     3,     4,     5,     6,     7,     8,
       9,   143,     0,    26,   143,    55,   118,    53,    21,    21,
      21,   118,    41,    21,    21,   148,   118,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,    20,    56,    21,    26,    53,   148,
     118,   142,    52,   144,   145,   147,   124,    55,    55,     3,
     148,   124,    21,    53,   128,   130,   131,   125,   126,   145,
     145,    55,   143,   148,    21,    45,    55,    21,    26,   118,
      57,   125,    53,   148,    55,   124,   124,   129,   128,   148,
      55,   136,    21,   124
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   119,   120,   120,   121,   121,   121,   123,   125,   125,
     122,   128,   128,   128,   127,   127,   130,   131,   131,   132,
     132,   132,   134,   134,   134,   133,   133,   133,   129,   135,
     135,   124,   124,   124,   124,   124,   124,   124,   124,   126,
     126,   144,   144,   142,   142,   136,   146,   146,   137,   147,
     147,   147,   145,   145,   145,   138,   138,   139,   139,   139,
     149,   150,   151,   141,   141,   141,   140,   140,   143,   143,
     143,   143,   143,   143,   143,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   152,   152,   152,   152
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     0,     2,     1,     1,     6,     1,     2,
       6,     1,     3,     0,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     4,     3,     1,
       2,     1,     2,     2,     1,     1,     1,     1,     1,     3,
       5,     1,     3,     1,     3,     2,     3,     3,     7,     3,
       2,     0,     1,     3,     0,     6,     7,     1,     1,     1,
      12,     7,     5,     3,     2,     2,     5,     5,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     3,     3,     3,     2,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     0,     2,     3,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 42 "lrParser.y"
                                                 { print_code((yyvsp[-2].sValue));}
#line 1699 "lrParser.tab.c"
    break;

  case 3:
#line 43 "lrParser.y"
         { (yyval.sValue) = ""; }
#line 1705 "lrParser.tab.c"
    break;

  case 4:
#line 46 "lrParser.y"
                              { (yyval.sValue) = (yyvsp[0].sValue); }
#line 1711 "lrParser.tab.c"
    break;

  case 5:
#line 47 "lrParser.y"
                     { (yyval.sValue) = (yyvsp[0].sValue); }
#line 1717 "lrParser.tab.c"
    break;

  case 6:
#line 48 "lrParser.y"
            { (yyval.sValue) = (yyvsp[0].sValue); }
#line 1723 "lrParser.tab.c"
    break;

  case 7:
#line 51 "lrParser.y"
                                                                                               { (yyval.sValue) = concat(5, "struct ", (yyvsp[-3].sValue), "{", (yyvsp[-1].sValue), "}"); }
#line 1729 "lrParser.tab.c"
    break;

  case 8:
#line 54 "lrParser.y"
                                                    { (yyval.sValue) = (yyvsp[0].sValue); }
#line 1735 "lrParser.tab.c"
    break;

  case 9:
#line 55 "lrParser.y"
                                                     { (yyval.sValue) = concat(2, (yyvsp[-1].sValue), (yyvsp[0].sValue)); }
#line 1741 "lrParser.tab.c"
    break;

  case 10:
#line 58 "lrParser.y"
                                                                                                      { (yyval.sValue) = concat(6, (yyvsp[-5].sValue), updateFunctionName((yyvsp[-4].sValue)), "(", (yyvsp[-2].sValue), ")", (yyvsp[0].sValue)); }
#line 1747 "lrParser.tab.c"
    break;

  case 11:
#line 61 "lrParser.y"
                                          { (yyval.sValue) = (yyvsp[0].sValue); }
#line 1753 "lrParser.tab.c"
    break;

  case 12:
#line 62 "lrParser.y"
                                                   { (yyval.sValue) = concat(3, (yyvsp[-2].sValue), ",", (yyvsp[0].sValue)); }
#line 1759 "lrParser.tab.c"
    break;

  case 13:
#line 63 "lrParser.y"
         { (yyval.sValue) = ""; }
#line 1765 "lrParser.tab.c"
    break;

  case 14:
#line 66 "lrParser.y"
                  { (yyval.sValue) = (yyvsp[0].sValue); }
#line 1771 "lrParser.tab.c"
    break;

  case 15:
#line 67 "lrParser.y"
                     { (yyval.sValue) = "void"; }
#line 1777 "lrParser.tab.c"
    break;

  case 16:
#line 70 "lrParser.y"
                          { (yyval.sValue) = concat(2, (yyvsp[-1].sValue), (yyvsp[0].sValue)); }
#line 1783 "lrParser.tab.c"
    break;

  case 17:
#line 73 "lrParser.y"
                     { (yyval.sValue) = (yyvsp[0].sValue); }
#line 1789 "lrParser.tab.c"
    break;

  case 18:
#line 74 "lrParser.y"
                   { (yyval.sValue) = (yyvsp[0].sValue); }
#line 1795 "lrParser.tab.c"
    break;

  case 19:
#line 77 "lrParser.y"
                              { (yyval.sValue) = (yyvsp[0].sValue); }
#line 1801 "lrParser.tab.c"
    break;

  case 20:
#line 78 "lrParser.y"
                { (yyval.sValue) = "char"; }
#line 1807 "lrParser.tab.c"
    break;

  case 21:
#line 79 "lrParser.y"
             { (yyval.sValue) = "char*"; }
#line 1813 "lrParser.tab.c"
    break;

  case 22:
#line 82 "lrParser.y"
                       { (yyval.sValue) = "int"; }
#line 1819 "lrParser.tab.c"
    break;

  case 23:
#line 83 "lrParser.y"
           { (yyval.sValue) = "float"; }
#line 1825 "lrParser.tab.c"
    break;

  case 24:
#line 84 "lrParser.y"
           { (yyval.sValue) = "int"; }
#line 1831 "lrParser.tab.c"
    break;

  case 25:
#line 87 "lrParser.y"
                               { (yyval.sValue) = (yyvsp[0].sValue); }
#line 1837 "lrParser.tab.c"
    break;

  case 26:
#line 88 "lrParser.y"
                  { (yyval.sValue) = concat(2, "struct ", (yyvsp[0].sValue)); }
#line 1843 "lrParser.tab.c"
    break;

  case 27:
#line 89 "lrParser.y"
                                                      { (yyval.sValue) = concat(2, (yyvsp[-3].iValue), "[]"); }
#line 1849 "lrParser.tab.c"
    break;

  case 28:
#line 92 "lrParser.y"
                                                 { (yyval.sValue) = concat(3, "{", (yyvsp[-1].sValue), "}"); }
#line 1855 "lrParser.tab.c"
    break;

  case 29:
#line 95 "lrParser.y"
                      { (yyval.sValue) = concat(1, (yyvsp[0].sValue)); }
#line 1861 "lrParser.tab.c"
    break;

  case 30:
#line 96 "lrParser.y"
                       { (yyval.sValue) = concat(2, (yyvsp[-1].sValue), (yyvsp[0].sValue)); }
#line 1867 "lrParser.tab.c"
    break;

  case 31:
#line 99 "lrParser.y"
                                              { (yyval.sValue) = (yyvsp[0].sValue); }
#line 1873 "lrParser.tab.c"
    break;

  case 32:
#line 100 "lrParser.y"
                                      { (yyval.sValue) = concat(2, (yyvsp[-1].sValue), ";"); }
#line 1879 "lrParser.tab.c"
    break;

  case 33:
#line 101 "lrParser.y"
                                              { (yyval.sValue) = concat(2, (yyvsp[-1].sValue), ";"); }
#line 1885 "lrParser.tab.c"
    break;

  case 34:
#line 102 "lrParser.y"
                         { (yyval.sValue) = (yyvsp[0].sValue); }
#line 1891 "lrParser.tab.c"
    break;

  case 35:
#line 103 "lrParser.y"
                       { (yyval.sValue) = (yyvsp[0].sValue); }
#line 1897 "lrParser.tab.c"
    break;

  case 36:
#line 104 "lrParser.y"
                { (yyval.sValue) = (yyvsp[0].sValue); }
#line 1903 "lrParser.tab.c"
    break;

  case 37:
#line 105 "lrParser.y"
                   { (yyval.sValue) = (yyvsp[0].sValue); }
#line 1909 "lrParser.tab.c"
    break;

  case 38:
#line 106 "lrParser.y"
         { (yyval.sValue) = (yyvsp[0].sValue); }
#line 1915 "lrParser.tab.c"
    break;

  case 39:
#line 109 "lrParser.y"
                                                                             { (yyval.sValue) = concat(3, (yyvsp[-2].sValue), (yyvsp[-1].sValue), ";"); }
#line 1921 "lrParser.tab.c"
    break;

  case 40:
#line 110 "lrParser.y"
                                                                                   { (yyval.sValue) = concat(5, (yyvsp[-4].sValue), (yyvsp[-3].sValue), (yyvsp[-2].sValue), (yyvsp[-1].sValue), ";"); }
#line 1927 "lrParser.tab.c"
    break;

  case 41:
#line 113 "lrParser.y"
                                                       { (yyval.sValue) = (yyvsp[0].sValue); }
#line 1933 "lrParser.tab.c"
    break;

  case 42:
#line 114 "lrParser.y"
                                                        { (yyval.sValue) = concat(3, "[", (yyvsp[-1].sValue), "]"); }
#line 1939 "lrParser.tab.c"
    break;

  case 43:
#line 117 "lrParser.y"
                          { (yyval.sValue) = (yyvsp[0].sValue); }
#line 1945 "lrParser.tab.c"
    break;

  case 44:
#line 118 "lrParser.y"
                                   { (yyval.sValue) = concat(3, (yyvsp[-2].sValue), ",", (yyvsp[0].sValue)); }
#line 1951 "lrParser.tab.c"
    break;

  case 45:
#line 121 "lrParser.y"
                                                      { (yyval.sValue) = concat(2, (yyvsp[-1].sValue), (yyvsp[0].sValue)); }
#line 1957 "lrParser.tab.c"
    break;

  case 46:
#line 124 "lrParser.y"
                                                                                      { (yyval.sValue) = concat(3, "(", (yyvsp[-1].sValue), ")"); }
#line 1963 "lrParser.tab.c"
    break;

  case 47:
#line 125 "lrParser.y"
                                   { (yyval.sValue) = concat(3, (yyvsp[-2].sValue), (yyvsp[-1].sValue), (yyvsp[0].sValue)); }
#line 1969 "lrParser.tab.c"
    break;

  case 48:
#line 128 "lrParser.y"
                                                                                                                        { (yyval.sValue) = concat(7, "(", (yyvsp[-5].sValue), ")", (yyvsp[-3].sValue), (yyvsp[-2].sValue), (yyvsp[-1].sValue), (yyvsp[0].sValue)); }
#line 1975 "lrParser.tab.c"
    break;

  case 49:
#line 131 "lrParser.y"
                                                 { (yyval.sValue) = concat(3, "(", (yyvsp[-1].sValue), ")"); }
#line 1981 "lrParser.tab.c"
    break;

  case 50:
#line 132 "lrParser.y"
           { (yyval.sValue) = concat(2, (yyvsp[-1].iValue), (yyvsp[0].sValue)); }
#line 1987 "lrParser.tab.c"
    break;

  case 51:
#line 133 "lrParser.y"
         { (yyval.sValue) = ""; }
#line 1993 "lrParser.tab.c"
    break;

  case 52:
#line 136 "lrParser.y"
                      { (yyval.sValue) = (yyvsp[0].sValue); }
#line 1999 "lrParser.tab.c"
    break;

  case 53:
#line 137 "lrParser.y"
                               { (yyval.sValue) = concat(3, (yyvsp[-2].sValue), ",", (yyvsp[0].sValue)); }
#line 2005 "lrParser.tab.c"
    break;

  case 54:
#line 138 "lrParser.y"
         { (yyval.sValue) = ""; }
#line 2011 "lrParser.tab.c"
    break;

  case 55:
#line 141 "lrParser.y"
                                                                                                 { (yyval.sValue) = concat(5, "if (", (yyvsp[-3].sValue), ")", (yyvsp[-1].sValue), ";"); }
#line 2017 "lrParser.tab.c"
    break;

  case 56:
#line 142 "lrParser.y"
                                                                                 { (yyval.sValue) = concat(7, "if (", (yyvsp[-4].sValue), ") ", (yyvsp[-2].sValue), " else" , (yyvsp[0].sValue), ";"); }
#line 2023 "lrParser.tab.c"
    break;

  case 57:
#line 145 "lrParser.y"
                               { (yyval.sValue) = (yyvsp[0].sValue); }
#line 2029 "lrParser.tab.c"
    break;

  case 58:
#line 146 "lrParser.y"
                      { (yyval.sValue) = (yyvsp[0].sValue); }
#line 2035 "lrParser.tab.c"
    break;

  case 59:
#line 147 "lrParser.y"
                 { (yyval.sValue) = (yyvsp[0].sValue); }
#line 2041 "lrParser.tab.c"
    break;

  case 60:
#line 150 "lrParser.y"
                                                                                                                                                     { (yyval.sValue) = concat(11, "for (", (yyvsp[-9].sValue), (yyvsp[-8].sValue), (yyvsp[-7].iValue), (yyvsp[-6].sValue), ";", (yyvsp[-4].sValue), ";", (yyvsp[-2].sValue), ")", (yyvsp[0].sValue)); }
#line 2047 "lrParser.tab.c"
    break;

  case 61:
#line 153 "lrParser.y"
                                                                                               { (yyval.sValue) = "problema"; }
#line 2053 "lrParser.tab.c"
    break;

  case 62:
#line 156 "lrParser.y"
                                                                              { (yyval.sValue) = concat(4, "while (", (yyvsp[-2].sValue), ")", (yyvsp[0].sValue)); }
#line 2059 "lrParser.tab.c"
    break;

  case 63:
#line 159 "lrParser.y"
                                              { (yyval.sValue) = concat(3, "return ", (yyvsp[-1].sValue), ";"); }
#line 2065 "lrParser.tab.c"
    break;

  case 64:
#line 160 "lrParser.y"
                          { (yyval.sValue) = "break;"; }
#line 2071 "lrParser.tab.c"
    break;

  case 65:
#line 161 "lrParser.y"
                             { (yyval.sValue) = "continue;"; }
#line 2077 "lrParser.tab.c"
    break;

  case 66:
#line 164 "lrParser.y"
                                                                               { (yyval.sValue) = "problema"; }
#line 2083 "lrParser.tab.c"
    break;

  case 67:
#line 165 "lrParser.y"
                                                                     { (yyval.sValue) = "problema"; }
#line 2089 "lrParser.tab.c"
    break;

  case 68:
#line 168 "lrParser.y"
                              { (yyval.sValue) = "="; }
#line 2095 "lrParser.tab.c"
    break;

  case 69:
#line 169 "lrParser.y"
              { (yyval.sValue) = "+="; }
#line 2101 "lrParser.tab.c"
    break;

  case 70:
#line 170 "lrParser.y"
              { (yyval.sValue) = "-="; }
#line 2107 "lrParser.tab.c"
    break;

  case 71:
#line 171 "lrParser.y"
               { (yyval.sValue) = "*="; }
#line 2113 "lrParser.tab.c"
    break;

  case 72:
#line 172 "lrParser.y"
              { (yyval.sValue) = "/="; }
#line 2119 "lrParser.tab.c"
    break;

  case 73:
#line 173 "lrParser.y"
                    { (yyval.sValue) = "problema"; }
#line 2125 "lrParser.tab.c"
    break;

  case 74:
#line 174 "lrParser.y"
                           { (yyval.sValue) = "problema"; }
#line 2131 "lrParser.tab.c"
    break;

  case 75:
#line 177 "lrParser.y"
                                                { (yyval.sValue) = concat(2, (yyvsp[-1].sValue), (yyvsp[0].sValue)); }
#line 2137 "lrParser.tab.c"
    break;

  case 76:
#line 178 "lrParser.y"
                                                          { (yyval.sValue) = (yyvsp[0].sValue); }
#line 2143 "lrParser.tab.c"
    break;

  case 77:
#line 179 "lrParser.y"
                                                { (yyval.sValue) = (yyvsp[0].sValue); }
#line 2149 "lrParser.tab.c"
    break;

  case 78:
#line 180 "lrParser.y"
                                                { (yyval.sValue) = (yyvsp[0].sValue); }
#line 2155 "lrParser.tab.c"
    break;

  case 79:
#line 181 "lrParser.y"
                                                      { (yyval.sValue) = (yyvsp[0].sValue); }
#line 2161 "lrParser.tab.c"
    break;

  case 80:
#line 182 "lrParser.y"
                                                { (yyval.sValue) = (yyvsp[0].sValue); }
#line 2167 "lrParser.tab.c"
    break;

  case 81:
#line 183 "lrParser.y"
                                                { (yyval.sValue) = concat(3, "(", (yyvsp[-1].sValue), ")"); }
#line 2173 "lrParser.tab.c"
    break;

  case 82:
#line 184 "lrParser.y"
                                                { (yyval.sValue) = concat(3, (yyvsp[-2].sValue), "||", (yyvsp[0].sValue)); }
#line 2179 "lrParser.tab.c"
    break;

  case 83:
#line 185 "lrParser.y"
                                                { (yyval.sValue) = concat(3, (yyvsp[-2].sValue), "&&", (yyvsp[0].sValue)); }
#line 2185 "lrParser.tab.c"
    break;

  case 84:
#line 186 "lrParser.y"
                                                { (yyval.sValue) = concat(2, "!", (yyvsp[0].sValue)); }
#line 2191 "lrParser.tab.c"
    break;

  case 85:
#line 187 "lrParser.y"
                                                { (yyval.sValue) = concat(2, "-", (yyvsp[0].sValue)); }
#line 2197 "lrParser.tab.c"
    break;

  case 86:
#line 188 "lrParser.y"
                                                { (yyval.sValue) = concat(2, "+", (yyvsp[0].sValue)); }
#line 2203 "lrParser.tab.c"
    break;

  case 87:
#line 189 "lrParser.y"
                                                { (yyval.sValue) = concat(3, (yyvsp[-2].sValue), "-", (yyvsp[0].sValue)); }
#line 2209 "lrParser.tab.c"
    break;

  case 88:
#line 190 "lrParser.y"
                                                { (yyval.sValue) = concat(3, (yyvsp[-2].sValue), "+", (yyvsp[0].sValue)); }
#line 2215 "lrParser.tab.c"
    break;

  case 89:
#line 191 "lrParser.y"
                                                { (yyval.sValue) = concat(3, (yyvsp[-2].sValue), "problema", (yyvsp[0].sValue)); }
#line 2221 "lrParser.tab.c"
    break;

  case 90:
#line 192 "lrParser.y"
                                                { (yyval.sValue) = concat(3, (yyvsp[-2].sValue), "problema", (yyvsp[0].sValue)); }
#line 2227 "lrParser.tab.c"
    break;

  case 91:
#line 193 "lrParser.y"
                                                { (yyval.sValue) = concat(3, (yyvsp[-2].sValue), "*", (yyvsp[0].sValue)); }
#line 2233 "lrParser.tab.c"
    break;

  case 92:
#line 194 "lrParser.y"
                                                { (yyval.sValue) = concat(3, (yyvsp[-2].sValue), "/", (yyvsp[0].sValue)); }
#line 2239 "lrParser.tab.c"
    break;

  case 93:
#line 195 "lrParser.y"
                                                { (yyval.sValue) = concat(3, (yyvsp[-2].sValue), "%", (yyvsp[0].sValue)); }
#line 2245 "lrParser.tab.c"
    break;

  case 94:
#line 196 "lrParser.y"
                                                { (yyval.sValue) = concat(5, "pow(", (yyvsp[-2].sValue), ",", (yyvsp[0].sValue), ")"); }
#line 2251 "lrParser.tab.c"
    break;

  case 95:
#line 197 "lrParser.y"
                                                { (yyval.sValue) = concat(3, (yyvsp[-2].sValue), "!=", (yyvsp[0].sValue)); }
#line 2257 "lrParser.tab.c"
    break;

  case 96:
#line 198 "lrParser.y"
                                                { (yyval.sValue) = concat(3, (yyvsp[-2].sValue), "==", (yyvsp[0].sValue)); }
#line 2263 "lrParser.tab.c"
    break;

  case 97:
#line 199 "lrParser.y"
                                                { (yyval.sValue) = concat(3, (yyvsp[-2].sValue), ">=", (yyvsp[0].sValue)); }
#line 2269 "lrParser.tab.c"
    break;

  case 98:
#line 200 "lrParser.y"
                                                { (yyval.sValue) = concat(3, (yyvsp[-2].sValue), "<=", (yyvsp[0].sValue)); }
#line 2275 "lrParser.tab.c"
    break;

  case 99:
#line 201 "lrParser.y"
                                                { (yyval.sValue) = concat(3, (yyvsp[-2].sValue), ">", (yyvsp[0].sValue)); }
#line 2281 "lrParser.tab.c"
    break;

  case 100:
#line 202 "lrParser.y"
                                                { (yyval.sValue) = concat(3, (yyvsp[-2].sValue), "<", (yyvsp[0].sValue)); }
#line 2287 "lrParser.tab.c"
    break;

  case 101:
#line 205 "lrParser.y"
                                                { (yyval.sValue) = ""; }
#line 2293 "lrParser.tab.c"
    break;

  case 102:
#line 206 "lrParser.y"
                                                { (yyval.sValue) = concat(2, ".", (yyvsp[0].sValue)); }
#line 2299 "lrParser.tab.c"
    break;

  case 103:
#line 207 "lrParser.y"
                                                { (yyval.sValue) = concat(3, "[", (yyvsp[-1].sValue), "]"); }
#line 2305 "lrParser.tab.c"
    break;

  case 104:
#line 208 "lrParser.y"
                                                { (yyval.sValue) = concat(3, "(", (yyvsp[-1].sValue), ")"); }
#line 2311 "lrParser.tab.c"
    break;


#line 2315 "lrParser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 210 "lrParser.y"


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
