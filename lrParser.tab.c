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
  void yyerror (char const *);

#line 77 "lrParser.tab.c"

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
#define YYLAST   580

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  120
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  214

#define YYUNDEFTOK  2
#define YYMAXUTOK   374


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
     115,   116,   117,   118,   119
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    27,    27,    28,    31,    32,    33,    36,    39,    40,
      43,    46,    47,    48,    51,    52,    55,    58,    59,    62,
      63,    64,    67,    68,    69,    72,    73,    74,    77,    80,
      81,    84,    85,    86,    87,    88,    89,    90,    91,    94,
      95,    98,    99,   102,   103,   106,   109,   110,   113,   116,
     117,   118,   121,   122,   123,   126,   127,   130,   131,   132,
     135,   138,   141,   144,   145,   146,   149,   150,   153,   154,
     155,   156,   157,   158,   159,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   190,   191,   192,   193
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
  "key_def", "key_deftipo", "booleano", "inteiro", "real", "caractere",
  "palavra", "id", "colchetes_esquerda", "colchetes_direita",
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
  "matched_if", "$accept", "PROGRAM", "DEF", "DEFINICAO_REGISTRO",
  "LISTA_ATRIBUTOS", "DEFINICAO_FUNCAO", "LISTA_PARAMETROS_FUNCAO",
  "TIPO_FUNCAO", "PARAMETRO_FUNCAO", "TIPO", "TIPO_PRIMITIVO",
  "TIPO_NUMERICO", "TIPO_ESTRUTURADO", "BLOCO", "INSTRUCOES", "INSTRUCAO",
  "INSTRUCAO_DECLARACAO_INICIALIZACAO",
  "INSTRUCAO_DECLARACAO_INICIALIZACAO_2", "LISTA_IDENTIFICADORES",
  "INSTRUCAO_CHAMADA_ID", "CHAMADA_FUNCAO_OU_ATRIBUICAO",
  "INSTRUCAO_ATRIBUICAO_CASTING", "LVALUE", "LISTA_EXPRESSOES",
  "INSTRUCAO_CONDICIONAL", "INSTRUCAO_REPETICAO", "LACO_PARA",
  "LACO_PARA_CONJUNTO", "LACO_ENQUANTO", "INSTRUCAO_SAIDA", "INSTRUCAO_IO",
  "OPERADORES_ATRIBUICAO", "EXP", "EXP_ID", YY_NULLPTR
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
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374
};
# endif

#define YYPACT_NINF (-145)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     479,    82,  -145,  -145,   533,   533,   -47,     4,     5,  -145,
       8,    14,    18,   -34,  -145,    26,  -145,   -10,   451,   447,
       1,    16,   512,    50,   479,  -145,    20,  -145,  -145,  -145,
    -145,  -145,  -145,    -8,    17,  -145,  -145,  -145,  -145,  -145,
    -145,  -145,    58,  -145,    23,  -145,   451,   451,    44,    80,
      45,  -145,   451,  -145,   451,   451,   451,   451,  -145,  -145,
    -145,  -145,  -145,    25,    -6,  -145,  -145,    46,  -145,    48,
     451,    52,   451,  -145,   177,    41,   512,  -145,   111,   162,
      54,  -145,  -145,    65,    79,   184,   203,   103,    87,    98,
     224,   421,   243,     7,     7,   451,    88,   451,  -145,   451,
     451,   451,   451,   451,   451,   451,   451,   451,   451,   451,
     451,   451,   451,   451,   451,  -145,   135,    94,   136,   263,
    -145,   282,  -145,  -145,  -145,  -145,  -145,  -145,  -145,   451,
    -145,  -145,  -145,   101,    96,  -145,    -7,  -145,   512,   100,
     102,   156,   451,   512,  -145,   303,  -145,   332,   402,   421,
     441,   441,   441,   441,   441,   441,   112,   112,   112,     7,
       7,     7,     7,   112,   533,   533,  -145,   451,  -145,   382,
     147,  -145,   451,   115,  -145,   177,  -145,  -145,  -145,   451,
     353,   -12,  -145,  -145,   141,   161,   133,   128,   533,  -145,
     134,  -145,   451,    47,   512,   512,  -145,   142,   533,  -145,
    -145,  -145,  -145,   382,   451,  -145,  -145,  -145,  -145,   118,
     153,   190,   512,  -145
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,    24,    20,     0,     0,     0,     0,     0,    22,
       0,     0,     0,     0,    21,     0,    23,     0,     0,     0,
       0,    51,     0,     0,     3,     5,     0,    17,    19,    18,
      38,     6,    31,     0,     0,    34,    35,    57,    58,    59,
      37,    36,     0,    25,     0,    65,     0,     0,     0,     0,
       0,    64,     0,    26,     0,     0,     0,     0,    80,    76,
      77,    78,    79,   101,     0,    15,     4,     0,    14,     0,
      54,     0,     0,    45,     0,     0,    29,     1,     0,    43,
       0,    32,    33,     0,     0,     0,     0,     0,     0,     0,
       0,    84,     0,    86,    85,     0,     0,     0,    75,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    63,     0,     0,     0,    52,
      50,     0,    68,    69,    70,    71,    72,    73,    74,     0,
      28,    30,     2,     0,    54,    39,    51,    27,     0,     0,
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
    -145,   199,  -145,  -145,    42,  -145,    31,  -145,  -145,    -4,
     232,   185,  -145,    53,   175,   -20,  -144,  -145,   137,    59,
    -145,  -145,   154,   -99,  -145,  -145,  -145,  -145,  -145,  -145,
    -145,   -75,   -15,  -145
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    23,    24,    25,   187,    66,   184,    67,   185,    26,
      27,    28,    29,    30,    75,    31,    32,   173,    80,    33,
      73,    34,    74,   118,    35,    36,    37,    38,    39,    40,
      41,   129,   119,    98
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      43,    44,    76,    64,   134,    99,   100,   101,   102,   103,
     104,   105,   106,   107,    45,    68,   108,   109,   110,   111,
      71,   188,   112,   113,    46,    47,   107,    51,    48,   108,
     109,    85,    86,   195,    49,   174,    70,    90,    50,    91,
      92,    93,    94,    71,   188,    95,    52,    53,    69,   196,
      77,    72,    96,    81,   114,   115,    76,   121,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   114,   189,   108,
     109,   110,   111,   190,    72,   112,   113,    79,    82,    83,
     145,    84,   147,    97,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     192,    87,    89,   116,   130,   117,    54,   114,   204,   120,
       2,   132,     2,     3,   169,   135,    55,     9,   176,     9,
      56,    57,   136,   181,   140,    14,    16,   180,    16,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   137,   142,
     108,   109,   110,   111,   141,   146,   112,   113,    58,    59,
      60,    61,    62,    63,   172,   164,   165,   166,   170,   179,
     186,   177,   197,   178,   193,   122,   123,   124,   125,   126,
     127,   128,   114,   133,   205,   206,   191,   203,   114,   210,
     122,   123,   124,   125,   126,   127,   128,   198,   133,   209,
     199,   200,   213,   202,   186,    99,   100,   101,   102,   103,
     104,   105,   106,   107,    22,   138,   108,   109,   110,   111,
      21,   212,   112,   113,    99,   100,   101,   102,   103,   104,
     105,   106,   107,    78,   139,   108,   109,   110,   111,   208,
     201,   112,   113,    42,    88,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   114,   143,   108,   109,   110,   111,
     207,   131,   112,   113,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   114,   144,   108,   109,   110,   111,   211,
     171,   112,   113,     0,    99,   100,   101,   102,   103,   104,
     105,   106,   107,     0,   114,   108,   109,   110,   111,   167,
     175,   112,   113,    99,   100,   101,   102,   103,   104,   105,
     106,   107,     0,   114,   108,   109,   110,   111,     0,     0,
     112,   113,     0,     0,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   114,   182,   108,   109,   110,   111,     0,
       0,   112,   113,     0,     0,     0,     0,     0,     0,     0,
       0,   168,   114,    99,   100,   101,   102,   103,   104,   105,
     106,   107,     0,     0,   108,   109,   110,   111,     0,     0,
     112,   113,     0,   114,    99,   100,   101,   102,   103,   104,
     105,   106,   107,     0,   194,   108,   109,   110,   111,     0,
       0,   112,   113,     0,     0,     0,     0,     0,     0,     0,
       0,   183,   114,    99,   100,   101,   102,   103,   104,   105,
     106,   107,     0,     0,   108,   109,   110,   111,     0,     0,
     112,   113,     0,   114,   100,   101,   102,   103,   104,   105,
     106,   107,     0,     0,   108,   109,   110,   111,     0,     0,
     112,   113,     0,     0,   101,   102,   103,   104,   105,   106,
     107,     0,   114,   108,   109,   110,   111,     0,     0,   112,
     113,     0,     0,     0,    -1,    -1,    -1,    -1,    -1,    -1,
     107,    54,   114,   108,   109,   110,   111,     0,     0,   112,
     113,    55,     0,     0,     0,    56,    57,     2,     3,     4,
       5,   114,     0,     0,     9,     0,     0,     0,     0,     0,
      14,     0,     0,    16,    17,     0,    65,     0,     0,     1,
       0,   114,     0,    58,    59,    60,    61,    62,    63,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
       0,    13,    14,    15,     0,    16,    17,    18,     0,    19,
      20,     0,     1,     0,     0,     0,    21,     0,     0,     0,
       0,    22,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,     0,    13,    14,    15,     0,    16,    17,
      18,     0,     0,     2,     3,     4,     5,     0,     0,    21,
       9,     0,     0,     0,    22,     0,    14,     0,     0,    16,
      17
};

static const yytype_int16 yycheck[] =
{
       4,     5,    22,    18,    79,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    61,    19,    22,    23,    24,    25,
      27,   165,    28,    29,    20,    20,    19,    61,    20,    22,
      23,    46,    47,    45,    20,   134,    20,    52,    20,    54,
      55,    56,    57,    27,   188,    20,    20,    57,    47,    61,
       0,    58,    27,    61,    60,    61,    76,    72,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    60,   167,    22,
      23,    24,    25,   172,    58,    28,    29,    57,    61,    21,
      95,    58,    97,    58,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     175,    57,    57,    57,    63,    57,    10,    60,    61,    57,
      30,     0,    30,    31,   129,    61,    20,    37,   138,    37,
      24,    25,    57,   143,    21,    43,    46,   142,    46,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    59,    41,
      22,    23,    24,    25,    57,    57,    28,    29,    52,    53,
      54,    55,    56,    57,    58,    20,    62,    21,    57,     3,
     164,    61,    21,    61,   179,     3,     4,     5,     6,     7,
       8,     9,    60,    26,   194,   195,    61,   192,    60,    61,
       3,     4,     5,     6,     7,     8,     9,    26,    26,   204,
      57,    63,   212,    59,   198,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    62,    21,    22,    23,    24,    25,
      57,    21,    28,    29,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    24,    21,    22,    23,    24,    25,   198,
     188,    28,    29,     1,    49,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    60,    21,    22,    23,    24,    25,
     197,    76,    28,    29,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    60,    21,    22,    23,    24,    25,   210,
     133,    28,    29,    -1,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    -1,    60,    22,    23,    24,    25,    26,
     136,    28,    29,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    -1,    60,    22,    23,    24,    25,    -1,    -1,
      28,    29,    -1,    -1,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    60,    21,    22,    23,    24,    25,    -1,
      -1,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    60,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    -1,    -1,    22,    23,    24,    25,    -1,    -1,
      28,    29,    -1,    60,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    -1,    21,    22,    23,    24,    25,    -1,
      -1,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    60,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    -1,    -1,    22,    23,    24,    25,    -1,    -1,
      28,    29,    -1,    60,    12,    13,    14,    15,    16,    17,
      18,    19,    -1,    -1,    22,    23,    24,    25,    -1,    -1,
      28,    29,    -1,    -1,    13,    14,    15,    16,    17,    18,
      19,    -1,    60,    22,    23,    24,    25,    -1,    -1,    28,
      29,    -1,    -1,    -1,    13,    14,    15,    16,    17,    18,
      19,    10,    60,    22,    23,    24,    25,    -1,    -1,    28,
      29,    20,    -1,    -1,    -1,    24,    25,    30,    31,    32,
      33,    60,    -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,
      43,    -1,    -1,    46,    47,    -1,    49,    -1,    -1,    20,
      -1,    60,    -1,    52,    53,    54,    55,    56,    57,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    42,    43,    44,    -1,    46,    47,    48,    -1,    50,
      51,    -1,    20,    -1,    -1,    -1,    57,    -1,    -1,    -1,
      -1,    62,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    42,    43,    44,    -1,    46,    47,
      48,    -1,    -1,    30,    31,    32,    33,    -1,    -1,    57,
      37,    -1,    -1,    -1,    62,    -1,    43,    -1,    -1,    46,
      47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    20,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    42,    43,    44,    46,    47,    48,    50,
      51,    57,    62,   121,   122,   123,   129,   130,   131,   132,
     133,   135,   136,   139,   141,   144,   145,   146,   147,   148,
     149,   150,   130,   129,   129,    61,    20,    20,    20,    20,
      20,    61,    20,    57,    10,    20,    24,    25,    52,    53,
      54,    55,    56,    57,   152,    49,   125,   127,   129,    47,
      20,    27,    58,   140,   142,   134,   135,     0,   121,    57,
     138,    61,    61,    21,    58,   152,   152,    57,   131,    57,
     152,   152,   152,   152,   152,    20,    27,    58,   153,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    22,    23,
      24,    25,    28,    29,    60,    61,    57,    57,   143,   152,
      57,   152,     3,     4,     5,     6,     7,     8,     9,   151,
      63,   134,     0,    26,   151,    61,    57,    59,    21,    21,
      21,    57,    41,    21,    21,   152,    57,   152,   152,   152,
     152,   152,   152,   152,   152,   152,   152,   152,   152,   152,
     152,   152,   152,   152,    20,    62,    21,    26,    59,   152,
      57,   138,    58,   137,   143,   142,   135,    61,    61,     3,
     152,   135,    21,    59,   126,   128,   129,   124,   136,   143,
     143,    61,   151,   152,    21,    45,    61,    21,    26,    57,
      63,   124,    59,   152,    61,   135,   135,   133,   126,   152,
      61,   139,    21,   135
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   120,   121,   121,   122,   122,   122,   123,   124,   124,
     125,   126,   126,   126,   127,   127,   128,   129,   129,   130,
     130,   130,   131,   131,   131,   132,   132,   132,   133,   134,
     134,   135,   135,   135,   135,   135,   135,   135,   135,   136,
     136,   137,   137,   138,   138,   139,   140,   140,   141,   142,
     142,   142,   143,   143,   143,   144,   144,   145,   145,   145,
     146,   147,   148,   149,   149,   149,   150,   150,   151,   151,
     151,   151,   151,   151,   151,   152,   152,   152,   152,   152,
     152,   152,   152,   152,   152,   152,   152,   152,   152,   152,
     152,   152,   152,   152,   152,   152,   152,   152,   152,   152,
     152,   153,   153,   153,   153
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
  switch (yytype)
    {
    case 3: /* assign  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1076 "lrParser.tab.c"
        break;

    case 4: /* assign_sum  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1082 "lrParser.tab.c"
        break;

    case 5: /* assign_sub  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1088 "lrParser.tab.c"
        break;

    case 6: /* assign_mult  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1094 "lrParser.tab.c"
        break;

    case 7: /* assign_div  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1100 "lrParser.tab.c"
        break;

    case 8: /* assign_set_union  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1106 "lrParser.tab.c"
        break;

    case 9: /* assign_set_intersection  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1112 "lrParser.tab.c"
        break;

    case 10: /* op_not  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1118 "lrParser.tab.c"
        break;

    case 11: /* op_or  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1124 "lrParser.tab.c"
        break;

    case 12: /* op_and  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1130 "lrParser.tab.c"
        break;

    case 13: /* op_gt  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1136 "lrParser.tab.c"
        break;

    case 14: /* op_lt  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1142 "lrParser.tab.c"
        break;

    case 15: /* op_lte  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1148 "lrParser.tab.c"
        break;

    case 16: /* op_gte  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1154 "lrParser.tab.c"
        break;

    case 17: /* op_equal  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1160 "lrParser.tab.c"
        break;

    case 18: /* op_diff  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1166 "lrParser.tab.c"
        break;

    case 19: /* op_mod  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1172 "lrParser.tab.c"
        break;

    case 20: /* parenteses_esquerda  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1178 "lrParser.tab.c"
        break;

    case 21: /* parenteses_direita  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1184 "lrParser.tab.c"
        break;

    case 22: /* op_mult  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1190 "lrParser.tab.c"
        break;

    case 23: /* op_div  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1196 "lrParser.tab.c"
        break;

    case 24: /* op_sum  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1202 "lrParser.tab.c"
        break;

    case 25: /* op_sub  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1208 "lrParser.tab.c"
        break;

    case 26: /* virgula  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1214 "lrParser.tab.c"
        break;

    case 27: /* ponto  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1220 "lrParser.tab.c"
        break;

    case 28: /* set_intersection  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1226 "lrParser.tab.c"
        break;

    case 29: /* set_union  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1232 "lrParser.tab.c"
        break;

    case 30: /* key_bool  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1238 "lrParser.tab.c"
        break;

    case 31: /* key_caractere  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1244 "lrParser.tab.c"
        break;

    case 32: /* key_set  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1250 "lrParser.tab.c"
        break;

    case 33: /* key_vetor  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1256 "lrParser.tab.c"
        break;

    case 34: /* key_continue  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1262 "lrParser.tab.c"
        break;

    case 35: /* key_while  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1268 "lrParser.tab.c"
        break;

    case 36: /* key_write  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1274 "lrParser.tab.c"
        break;

    case 37: /* key_int  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1280 "lrParser.tab.c"
        break;

    case 38: /* key_read  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1286 "lrParser.tab.c"
        break;

    case 39: /* key_for  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1292 "lrParser.tab.c"
        break;

    case 40: /* key_for_set  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1298 "lrParser.tab.c"
        break;

    case 41: /* key_in  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1304 "lrParser.tab.c"
        break;

    case 42: /* key_break  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1310 "lrParser.tab.c"
        break;

    case 43: /* key_string  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1316 "lrParser.tab.c"
        break;

    case 44: /* key_if  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1322 "lrParser.tab.c"
        break;

    case 45: /* key_else  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1328 "lrParser.tab.c"
        break;

    case 46: /* key_real  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1334 "lrParser.tab.c"
        break;

    case 47: /* key_register  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1340 "lrParser.tab.c"
        break;

    case 48: /* key_return  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1346 "lrParser.tab.c"
        break;

    case 49: /* key_return_nothing  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1352 "lrParser.tab.c"
        break;

    case 50: /* key_def  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1358 "lrParser.tab.c"
        break;

    case 51: /* key_deftipo  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1364 "lrParser.tab.c"
        break;

    case 52: /* booleano  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1370 "lrParser.tab.c"
        break;

    case 53: /* inteiro  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1376 "lrParser.tab.c"
        break;

    case 54: /* real  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1382 "lrParser.tab.c"
        break;

    case 55: /* caractere  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1388 "lrParser.tab.c"
        break;

    case 56: /* palavra  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1394 "lrParser.tab.c"
        break;

    case 57: /* id  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1400 "lrParser.tab.c"
        break;

    case 58: /* colchetes_esquerda  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1406 "lrParser.tab.c"
        break;

    case 59: /* colchetes_direita  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1412 "lrParser.tab.c"
        break;

    case 60: /* circunflexo  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1418 "lrParser.tab.c"
        break;

    case 61: /* ponto_virgula  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1424 "lrParser.tab.c"
        break;

    case 62: /* chaves_esquerda  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1430 "lrParser.tab.c"
        break;

    case 63: /* chaves_direita  */
#line 12 "lrParser.y"
         { printToken((*yyvaluep)); }
#line 1436 "lrParser.tab.c"
        break;

      default:
        break;
    }
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

#line 2050 "lrParser.tab.c"

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
#line 195 "lrParser.y"


void yyerror(char const *s) {
  fprintf(stderr, "%s\n", s);
}
