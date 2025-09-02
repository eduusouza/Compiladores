/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parse.y"


#define YYPARSER /* distinguishes Yacc output from other arquivoIntermediario files */

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"

#define YYSTYPE TreeNode *
static char * savedName; /* for use in assignments */
static int savedLineNo;  /* ditto */
static TreeNode * savedTree; /* stores syntax tree for later return */

void yyerror(char* message);
static int yylex(void);
TreeNode * parse(void);


#line 91 "parse.tab.c"

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

#include "parse.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ELSE = 3,                       /* ELSE  */
  YYSYMBOL_IF = 4,                         /* IF  */
  YYSYMBOL_INT = 5,                        /* INT  */
  YYSYMBOL_RETURN = 6,                     /* RETURN  */
  YYSYMBOL_VOID = 7,                       /* VOID  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_ID = 9,                         /* ID  */
  YYSYMBOL_NUM = 10,                       /* NUM  */
  YYSYMBOL_ADD = 11,                       /* ADD  */
  YYSYMBOL_SUB = 12,                       /* SUB  */
  YYSYMBOL_MULT = 13,                      /* MULT  */
  YYSYMBOL_DIV = 14,                       /* DIV  */
  YYSYMBOL_MENOR = 15,                     /* MENOR  */
  YYSYMBOL_MENORIG = 16,                   /* MENORIG  */
  YYSYMBOL_MAIOR = 17,                     /* MAIOR  */
  YYSYMBOL_MAIORIG = 18,                   /* MAIORIG  */
  YYSYMBOL_COMP = 19,                      /* COMP  */
  YYSYMBOL_IGUAL = 20,                     /* IGUAL  */
  YYSYMBOL_DIF = 21,                       /* DIF  */
  YYSYMBOL_SEMI = 22,                      /* SEMI  */
  YYSYMBOL_VIRG = 23,                      /* VIRG  */
  YYSYMBOL_ESQPARENT = 24,                 /* ESQPARENT  */
  YYSYMBOL_DIRPARENT = 25,                 /* DIRPARENT  */
  YYSYMBOL_ESQCOL = 26,                    /* ESQCOL  */
  YYSYMBOL_DIRCOL = 27,                    /* DIRCOL  */
  YYSYMBOL_ESQCHAV = 28,                   /* ESQCHAV  */
  YYSYMBOL_DIRCHAV = 29,                   /* DIRCHAV  */
  YYSYMBOL_ERROR = 30,                     /* ERROR  */
  YYSYMBOL_FIM = 31,                       /* FIM  */
  YYSYMBOL_YYACCEPT = 32,                  /* $accept  */
  YYSYMBOL_programa = 33,                  /* programa  */
  YYSYMBOL_declaracao_lista = 34,          /* declaracao_lista  */
  YYSYMBOL_declaracao = 35,                /* declaracao  */
  YYSYMBOL_var_declaracao = 36,            /* var_declaracao  */
  YYSYMBOL_tipo_especificador = 37,        /* tipo_especificador  */
  YYSYMBOL_fun_declaracao = 38,            /* fun_declaracao  */
  YYSYMBOL_params = 39,                    /* params  */
  YYSYMBOL_param_lista = 40,               /* param_lista  */
  YYSYMBOL_param = 41,                     /* param  */
  YYSYMBOL_composto_decl = 42,             /* composto_decl  */
  YYSYMBOL_local_declaracoes = 43,         /* local_declaracoes  */
  YYSYMBOL_statement_lista = 44,           /* statement_lista  */
  YYSYMBOL_statement = 45,                 /* statement  */
  YYSYMBOL_expressao_decl = 46,            /* expressao_decl  */
  YYSYMBOL_selecao_decl = 47,              /* selecao_decl  */
  YYSYMBOL_iteracao_decl = 48,             /* iteracao_decl  */
  YYSYMBOL_retorno_decl = 49,              /* retorno_decl  */
  YYSYMBOL_expressao = 50,                 /* expressao  */
  YYSYMBOL_var = 51,                       /* var  */
  YYSYMBOL_simples_expressao = 52,         /* simples_expressao  */
  YYSYMBOL_relacional = 53,                /* relacional  */
  YYSYMBOL_soma_expressao = 54,            /* soma_expressao  */
  YYSYMBOL_soma = 55,                      /* soma  */
  YYSYMBOL_termo = 56,                     /* termo  */
  YYSYMBOL_mult = 57,                      /* mult  */
  YYSYMBOL_fator = 58,                     /* fator  */
  YYSYMBOL_ativacao = 59,                  /* ativacao  */
  YYSYMBOL_arg_lista = 60,                 /* arg_lista  */
  YYSYMBOL_ident = 61,                     /* ident  */
  YYSYMBOL_num = 62                        /* num  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_int8 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   137

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  110

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   286


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    32,    32,    37,    50,    55,    58,    63,    70,    80,
      85,    92,   103,   106,   111,   124,   129,   136,   146,   159,
     162,   165,   170,   183,   188,   201,   206,   209,   212,   215,
     218,   223,   226,   231,   236,   244,   251,   254,   260,   265,
     270,   273,   280,   285,   290,   294,   298,   302,   306,   310,
     316,   321,   326,   330,   336,   341,   346,   350,   356,   359,
     362,   365,   370,   376,   383,   395,   400,   406
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ELSE", "IF", "INT",
  "RETURN", "VOID", "WHILE", "ID", "NUM", "ADD", "SUB", "MULT", "DIV",
  "MENOR", "MENORIG", "MAIOR", "MAIORIG", "COMP", "IGUAL", "DIF", "SEMI",
  "VIRG", "ESQPARENT", "DIRPARENT", "ESQCOL", "DIRCOL", "ESQCHAV",
  "DIRCHAV", "ERROR", "FIM", "$accept", "programa", "declaracao_lista",
  "declaracao", "var_declaracao", "tipo_especificador", "fun_declaracao",
  "params", "param_lista", "param", "composto_decl", "local_declaracoes",
  "statement_lista", "statement", "expressao_decl", "selecao_decl",
  "iteracao_decl", "retorno_decl", "expressao", "var", "simples_expressao",
  "relacional", "soma_expressao", "soma", "termo", "mult", "fator",
  "ativacao", "arg_lista", "ident", "num", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-42)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-14)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       5,   -42,   -42,    16,     5,   -42,   -42,    21,   -42,   -42,
       5,   -42,     7,   -42,    12,    25,    31,    21,    39,    43,
     -42,   -42,    49,    32,    50,     5,    58,    69,    33,   -42,
     -42,   -42,   -42,    74,     4,    75,   -42,    -2,   -42,   -42,
      21,   -42,    65,    73,   -42,   -42,   -42,   -42,   -42,    78,
      94,   -42,   101,    71,   -42,   -42,    28,   -42,    -2,   -42,
      93,    -2,   100,    27,   -42,   -42,    82,   -42,   -42,   -42,
      -2,   -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,    -2,
      -2,   -42,   -42,    -2,    -4,    -2,   103,   -42,   104,   -42,
     -42,   -42,   -42,    35,    71,   -42,   -42,   -42,    40,    97,
      99,    99,    -2,   -42,   -42,   123,   -42,   -42,    99,   -42
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     9,    10,     0,     2,     4,     5,     0,     6,     1,
       3,    66,     0,     7,     0,     0,    10,     0,     0,    12,
      15,    67,     0,    16,     0,     0,     0,     0,     0,    11,
      14,     8,    17,     0,     0,     0,    32,     0,    21,    23,
       0,    27,     0,     0,    25,    26,    28,    29,    30,     0,
      59,    39,    43,    51,    55,    60,    40,    61,     0,    36,
       0,     0,     0,     0,    19,    22,     0,    20,    24,    31,
       0,    52,    53,    46,    44,    45,    47,    48,    49,     0,
       0,    56,    57,     0,     0,     0,     0,    37,     0,    58,
      18,    38,    59,    42,    50,    54,    63,    65,     0,     0,
       0,     0,     0,    62,    41,    33,    35,    64,     0,    34
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -42,   -42,   130,   -42,   -19,   -10,   -42,   -42,   -42,   106,
     108,   -42,    91,   -41,   -42,   -42,   -42,   -42,   -34,   -35,
     -42,   -42,    55,   -42,    56,   -42,    52,   -42,   -42,    -6,
     122
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,    10,     5,     6,     7,     8,    18,    19,    20,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    79,    52,    80,    53,    83,    54,    55,    98,    56,
      57
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      60,    12,    68,    62,    17,    11,    21,    11,    21,    39,
       1,    23,     2,    11,    21,    17,     9,     1,    40,    16,
      37,    96,    37,    65,    86,    68,    59,    88,    37,    13,
      11,    14,    40,    15,    63,    21,    91,    33,     1,    34,
       2,    35,    11,    21,    92,    92,    71,    72,    92,    13,
      97,    99,    84,    15,    85,    36,   -13,    37,    27,   105,
     106,    28,    38,   102,    24,   103,    25,   109,   107,    33,
       1,    34,     2,    35,    11,    21,    26,    33,    28,    34,
      31,    35,    11,    21,    81,    82,    33,    36,    34,    37,
      35,    11,    21,    28,    64,    36,    32,    37,    58,    61,
      69,    28,    67,    33,    36,    34,    37,    35,    11,    21,
      28,    90,    71,    72,    70,    87,    73,    74,    75,    76,
      77,    36,    78,    37,   104,    89,   108,    28,   100,   101,
       4,    30,    29,    66,    93,    95,    94,    22
};

static const yytype_int8 yycheck[] =
{
      34,     7,    43,    37,    14,     9,    10,     9,    10,    28,
       5,    17,     7,     9,    10,    25,     0,     5,    28,     7,
      24,    25,    24,    42,    58,    66,    22,    61,    24,    22,
       9,    24,    42,    26,    40,    10,    70,     4,     5,     6,
       7,     8,     9,    10,    79,    80,    11,    12,    83,    22,
      84,    85,    24,    26,    26,    22,    25,    24,    26,   100,
     101,    28,    29,    23,    25,    25,    23,   108,   102,     4,
       5,     6,     7,     8,     9,    10,    27,     4,    28,     6,
      22,     8,     9,    10,    13,    14,     4,    22,     6,    24,
       8,     9,    10,    28,    29,    22,    27,    24,    24,    24,
      22,    28,    29,     4,    22,     6,    24,     8,     9,    10,
      28,    29,    11,    12,    20,    22,    15,    16,    17,    18,
      19,    22,    21,    24,    27,    25,     3,    28,    25,    25,
       0,    25,    24,    42,    79,    83,    80,    15
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     7,    33,    34,    35,    36,    37,    38,     0,
      34,     9,    61,    22,    24,    26,     7,    37,    39,    40,
      41,    10,    62,    61,    25,    23,    27,    26,    28,    42,
      41,    22,    27,     4,     6,     8,    22,    24,    29,    36,
      37,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    54,    56,    58,    59,    61,    62,    24,    22,
      50,    24,    50,    61,    29,    36,    44,    29,    45,    22,
      20,    11,    12,    15,    16,    17,    18,    19,    21,    53,
      55,    13,    14,    57,    24,    26,    50,    22,    50,    25,
      29,    50,    51,    54,    56,    58,    25,    50,    60,    50,
      25,    25,    23,    25,    27,    45,    45,    50,     3,    45
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    36,    36,    37,
      37,    38,    39,    39,    40,    40,    41,    41,    42,    42,
      42,    42,    43,    43,    44,    44,    45,    45,    45,    45,
      45,    46,    46,    47,    47,    48,    49,    49,    50,    50,
      51,    51,    52,    52,    53,    53,    53,    53,    53,    53,
      54,    54,    55,    55,    56,    56,    57,    57,    58,    58,
      58,    58,    59,    59,    60,    60,    61,    62
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     6,     1,
       1,     6,     1,     1,     3,     1,     2,     4,     4,     3,
       3,     2,     2,     1,     2,     1,     1,     1,     1,     1,
       1,     2,     1,     5,     7,     5,     2,     3,     3,     1,
       1,     4,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     3,     1,
       1,     1,     4,     3,     3,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* programa: declaracao_lista  */
#line 32 "parse.y"
                         {
		savedTree = yyvsp[0];
	}
#line 1220 "parse.tab.c"
    break;

  case 3: /* declaracao_lista: declaracao_lista declaracao_lista  */
#line 37 "parse.y"
                                          { 
		YYSTYPE t = yyvsp[-1];
           	if (t != NULL){
           		while (t->sibling != NULL) {
           			t = t->sibling;
           		}
             		t->sibling = yyvsp[0];
             		yyval = yyvsp[-1]; 
             	}
             	else { 
             		yyval = yyvsp[0];
             	}
         }
#line 1238 "parse.tab.c"
    break;

  case 4: /* declaracao_lista: declaracao  */
#line 50 "parse.y"
                      { 
         	yyval = yyvsp[0]; 
         }
#line 1246 "parse.tab.c"
    break;

  case 5: /* declaracao: var_declaracao  */
#line 55 "parse.y"
                       {
		yyval = yyvsp[0];
	}
#line 1254 "parse.tab.c"
    break;

  case 6: /* declaracao: fun_declaracao  */
#line 58 "parse.y"
                         {
		yyval = yyvsp[0];
	}
#line 1262 "parse.tab.c"
    break;

  case 7: /* var_declaracao: tipo_especificador ident SEMI  */
#line 63 "parse.y"
                                      {
		yyval = yyvsp[-2];
		yyval->child[0] = yyvsp[-1];
		yyvsp[-1]->nodekind = Declaracao_NodeK;
		yyvsp[-1]->kind.stmt = Variavel_StmtK;
		yyvsp[-1]->type = yyvsp[-2]->type;
	}
#line 1274 "parse.tab.c"
    break;

  case 8: /* var_declaracao: tipo_especificador ident ESQCOL num DIRCOL SEMI  */
#line 70 "parse.y"
                                                          {
		yyval = yyvsp[-5];
		yyval->child[0] = yyvsp[-4];
		yyvsp[-4]->nodekind = Declaracao_NodeK;
		yyvsp[-4]->kind.stmt = Vetor_StmtK;
		yyvsp[-4]->attr.len = yyvsp[-2]->attr.val;
		yyvsp[-4]->type = yyvsp[-5]->type;
	}
#line 1287 "parse.tab.c"
    break;

  case 9: /* tipo_especificador: INT  */
#line 80 "parse.y"
            {
		yyval = newExpNode(Tipo_ExpK);
		yyval->type = Integer_ExpT;
		yyval->attr.name = "Integer";
	}
#line 1297 "parse.tab.c"
    break;

  case 10: /* tipo_especificador: VOID  */
#line 85 "parse.y"
               {
		yyval = newExpNode(Tipo_ExpK);
		yyval->type = Void_ExpT;
		yyval->attr.name = "Void";
	}
#line 1307 "parse.tab.c"
    break;

  case 11: /* fun_declaracao: tipo_especificador ident ESQPARENT params DIRPARENT composto_decl  */
#line 92 "parse.y"
                                                                          {
		yyval = yyvsp[-5];
		yyval->child[0] = yyvsp[-4];
		yyvsp[-4]->child[0] = yyvsp[-2];
		yyvsp[-4]->child[1] = yyvsp[0];
		yyvsp[-4]->nodekind = Declaracao_NodeK;
		yyvsp[-4]->kind.stmt = Funcao_StmtK;
		yyvsp[-4]->type = yyvsp[-5]->type;
	}
#line 1321 "parse.tab.c"
    break;

  case 12: /* params: param_lista  */
#line 103 "parse.y"
                   {
		yyval = yyvsp[0];
	}
#line 1329 "parse.tab.c"
    break;

  case 13: /* params: VOID  */
#line 106 "parse.y"
               {
		//Região vazia
	}
#line 1337 "parse.tab.c"
    break;

  case 14: /* param_lista: param_lista VIRG param  */
#line 111 "parse.y"
                               {
		YYSTYPE t = yyvsp[-2];
		if (t != NULL) {
			while (t->sibling != NULL) {
				t = t->sibling;
			}
			t->sibling = yyvsp[0];
			yyval = yyvsp[-2];
		}
		else {
			yyval = yyvsp[-2]; //&3
		}	
	}
#line 1355 "parse.tab.c"
    break;

  case 15: /* param_lista: param  */
#line 124 "parse.y"
                {
		yyval = yyvsp[0];
	}
#line 1363 "parse.tab.c"
    break;

  case 16: /* param: tipo_especificador ident  */
#line 129 "parse.y"
                                 {
		yyval = yyvsp[-1];
		yyval->child[0] = yyvsp[0];
		yyvsp[0]->nodekind = Declaracao_NodeK;
		yyvsp[0]->kind.stmt = Parametro_StmtK;
		yyvsp[0]->type = yyvsp[-1]->type;
	}
#line 1375 "parse.tab.c"
    break;

  case 17: /* param: tipo_especificador ident ESQCOL DIRCOL  */
#line 136 "parse.y"
                                                 {
		yyval = yyvsp[-3];
		yyval->child[0] = yyvsp[-2];
		yyvsp[-2]->kind.exp = Vetor_ExpK;
		yyvsp[-2]->nodekind = Declaracao_NodeK;
		yyvsp[-2]->kind.stmt = Parametro_StmtK;
		yyvsp[-2]->type = yyvsp[-3]->type;
	}
#line 1388 "parse.tab.c"
    break;

  case 18: /* composto_decl: ESQCHAV local_declaracoes statement_lista DIRCHAV  */
#line 146 "parse.y"
                                                          {
		YYSTYPE t = yyvsp[-2];
		if (t != NULL) {
			while (t->sibling != NULL) {
				t = t->sibling;
			}
			t->sibling = yyvsp[-1];
			yyval = yyvsp[-2];
		}
		else {
			yyval = yyvsp[-1];
		}
	}
#line 1406 "parse.tab.c"
    break;

  case 19: /* composto_decl: ESQCHAV local_declaracoes DIRCHAV  */
#line 159 "parse.y"
                                            {
		yyval = yyvsp[-1];
	}
#line 1414 "parse.tab.c"
    break;

  case 20: /* composto_decl: ESQCHAV statement_lista DIRCHAV  */
#line 162 "parse.y"
                                          {
		yyval = yyvsp[-1];
	}
#line 1422 "parse.tab.c"
    break;

  case 21: /* composto_decl: ESQCHAV DIRCHAV  */
#line 165 "parse.y"
                          {
	    	//Região vazia
	}
#line 1430 "parse.tab.c"
    break;

  case 22: /* local_declaracoes: local_declaracoes var_declaracao  */
#line 170 "parse.y"
                                         {
		YYSTYPE t = yyvsp[-1];
		if (t != NULL) {
			while (t->sibling != NULL) {
				t = t->sibling;
			}
			t->sibling = yyvsp[0];
			yyval = yyvsp[-1];
		}
		else {
			yyval = yyvsp[0];
		}		
	}
#line 1448 "parse.tab.c"
    break;

  case 23: /* local_declaracoes: var_declaracao  */
#line 183 "parse.y"
                         {
		yyval = yyvsp[0];
	}
#line 1456 "parse.tab.c"
    break;

  case 24: /* statement_lista: statement_lista statement  */
#line 188 "parse.y"
                                  {
    		YYSTYPE t = yyvsp[-1];
		if (t != NULL) {
			while (t->sibling != NULL) {
				t = t->sibling;
			}
			t->sibling = yyvsp[0];
			yyval = yyvsp[-1];
		}
		else {
			yyval = yyvsp[0];
		}
    	}
#line 1474 "parse.tab.c"
    break;

  case 25: /* statement_lista: statement  */
#line 201 "parse.y"
                    {
		yyval = yyvsp[0];
	}
#line 1482 "parse.tab.c"
    break;

  case 26: /* statement: expressao_decl  */
#line 206 "parse.y"
                       {
    		yyval = yyvsp[0];
    	}
#line 1490 "parse.tab.c"
    break;

  case 27: /* statement: composto_decl  */
#line 209 "parse.y"
                        {
    		yyval = yyvsp[0];
    	}
#line 1498 "parse.tab.c"
    break;

  case 28: /* statement: selecao_decl  */
#line 212 "parse.y"
                       {
    		yyval = yyvsp[0];
    	}
#line 1506 "parse.tab.c"
    break;

  case 29: /* statement: iteracao_decl  */
#line 215 "parse.y"
                        {
    		yyval = yyvsp[0];
    	}
#line 1514 "parse.tab.c"
    break;

  case 30: /* statement: retorno_decl  */
#line 218 "parse.y"
                       {
    		yyval = yyvsp[0];
    	}
#line 1522 "parse.tab.c"
    break;

  case 31: /* expressao_decl: expressao SEMI  */
#line 223 "parse.y"
                       {
    		yyval = yyvsp[-1];
    	}
#line 1530 "parse.tab.c"
    break;

  case 32: /* expressao_decl: SEMI  */
#line 226 "parse.y"
               {
    		//Região vazia
    	}
#line 1538 "parse.tab.c"
    break;

  case 33: /* selecao_decl: IF ESQPARENT expressao DIRPARENT statement  */
#line 231 "parse.y"
                                                   {
    		yyval = newStmtNode(If_StmtK);
    		yyval->child[0] = yyvsp[-2];
    		yyval->child[1] = yyvsp[0];
    	}
#line 1548 "parse.tab.c"
    break;

  case 34: /* selecao_decl: IF ESQPARENT expressao DIRPARENT statement ELSE statement  */
#line 236 "parse.y"
                                                                    {
    		yyval = newStmtNode(If_StmtK);
    		yyval->child[0] = yyvsp[-4];
    		yyval->child[1] = yyvsp[-2];
    		yyval->child[2] = yyvsp[0];
    	}
#line 1559 "parse.tab.c"
    break;

  case 35: /* iteracao_decl: WHILE ESQPARENT expressao DIRPARENT statement  */
#line 244 "parse.y"
                                                      {
    		yyval = newStmtNode(While_StmtK);
    		yyval->child[0] = yyvsp[-2];
    		yyval->child[1] = yyvsp[0];
    	}
#line 1569 "parse.tab.c"
    break;

  case 36: /* retorno_decl: RETURN SEMI  */
#line 251 "parse.y"
                    {
    		yyval = newStmtNode(Return_StmtK);
    	}
#line 1577 "parse.tab.c"
    break;

  case 37: /* retorno_decl: RETURN expressao SEMI  */
#line 254 "parse.y"
                                {
    		yyval = newStmtNode(Return_StmtK);
    		yyval->child[0] = yyvsp[-1];
    	}
#line 1586 "parse.tab.c"
    break;

  case 38: /* expressao: var IGUAL expressao  */
#line 260 "parse.y"
                            {
    		yyval = newStmtNode(Igual_StmtK);
    		yyval->child[0] = yyvsp[-2];
    		yyval->child[1] = yyvsp[0];
    	}
#line 1596 "parse.tab.c"
    break;

  case 39: /* expressao: simples_expressao  */
#line 265 "parse.y"
                            {
    		yyval = yyvsp[0];
    	}
#line 1604 "parse.tab.c"
    break;

  case 40: /* var: ident  */
#line 270 "parse.y"
              {
		yyval = yyvsp[0];
	}
#line 1612 "parse.tab.c"
    break;

  case 41: /* var: ident ESQCOL expressao DIRCOL  */
#line 273 "parse.y"
                                        {
		yyval = yyvsp[-3];
		yyval->child[0] = yyvsp[-1];
		yyval->kind.exp = Vetor_ExpK;
	}
#line 1622 "parse.tab.c"
    break;

  case 42: /* simples_expressao: soma_expressao relacional soma_expressao  */
#line 280 "parse.y"
                                                 {
		yyval = yyvsp[-1];
		yyval->child[0] = yyvsp[-2];
		yyval->child[1] = yyvsp[0];
	}
#line 1632 "parse.tab.c"
    break;

  case 43: /* simples_expressao: soma_expressao  */
#line 285 "parse.y"
                         {
		yyval = yyvsp[0];
	}
#line 1640 "parse.tab.c"
    break;

  case 44: /* relacional: MENORIG  */
#line 290 "parse.y"
                {
		yyval = newExpNode(Operacao_ExpK);
		yyval->attr.op = MENORIG;
	}
#line 1649 "parse.tab.c"
    break;

  case 45: /* relacional: MAIOR  */
#line 294 "parse.y"
                {
		yyval = newExpNode(Operacao_ExpK);
		yyval->attr.op = MAIOR;
	}
#line 1658 "parse.tab.c"
    break;

  case 46: /* relacional: MENOR  */
#line 298 "parse.y"
                {
		yyval = newExpNode(Operacao_ExpK);
		yyval->attr.op = MENOR;
	}
#line 1667 "parse.tab.c"
    break;

  case 47: /* relacional: MAIORIG  */
#line 302 "parse.y"
                  {
		yyval = newExpNode(Operacao_ExpK);
		yyval->attr.op = MAIORIG;
	}
#line 1676 "parse.tab.c"
    break;

  case 48: /* relacional: COMP  */
#line 306 "parse.y"
               {
		yyval = newExpNode(Operacao_ExpK);
		yyval->attr.op = COMP;
	}
#line 1685 "parse.tab.c"
    break;

  case 49: /* relacional: DIF  */
#line 310 "parse.y"
              {
		yyval = newExpNode(Operacao_ExpK);
		yyval->attr.op = DIF;
	}
#line 1694 "parse.tab.c"
    break;

  case 50: /* soma_expressao: soma_expressao soma termo  */
#line 316 "parse.y"
                                  {
    		yyval = yyvsp[-1];
    		yyval->child[0] = yyvsp[-2];
    		yyval->child[1] = yyvsp[0];
    	}
#line 1704 "parse.tab.c"
    break;

  case 51: /* soma_expressao: termo  */
#line 321 "parse.y"
                {
    		yyval = yyvsp[0];
    	}
#line 1712 "parse.tab.c"
    break;

  case 52: /* soma: ADD  */
#line 326 "parse.y"
            {
    		yyval = newExpNode(Operacao_ExpK);
    		yyval->attr.op = ADD;
    	}
#line 1721 "parse.tab.c"
    break;

  case 53: /* soma: SUB  */
#line 330 "parse.y"
              {
    		yyval = newExpNode(Operacao_ExpK);
    		yyval->attr.op = SUB;
    	}
#line 1730 "parse.tab.c"
    break;

  case 54: /* termo: termo mult fator  */
#line 336 "parse.y"
                         {
    		yyval = yyvsp[-1];
    		yyval->child[0] = yyvsp[-2];
    		yyval->child[1] = yyvsp[0];
    	}
#line 1740 "parse.tab.c"
    break;

  case 55: /* termo: fator  */
#line 341 "parse.y"
                {
    		yyval = yyvsp[0];
    	}
#line 1748 "parse.tab.c"
    break;

  case 56: /* mult: MULT  */
#line 346 "parse.y"
             {
    		yyval = newExpNode(Operacao_ExpK);
    		yyval->attr.op = MULT;
    	}
#line 1757 "parse.tab.c"
    break;

  case 57: /* mult: DIV  */
#line 350 "parse.y"
              {
    		yyval = newExpNode(Operacao_ExpK);
    		yyval->attr.op = DIV;
    	}
#line 1766 "parse.tab.c"
    break;

  case 58: /* fator: ESQPARENT expressao DIRPARENT  */
#line 356 "parse.y"
                                      {
		yyval = yyvsp[-1];
	}
#line 1774 "parse.tab.c"
    break;

  case 59: /* fator: var  */
#line 359 "parse.y"
              {
		yyval = yyvsp[0];
	}
#line 1782 "parse.tab.c"
    break;

  case 60: /* fator: ativacao  */
#line 362 "parse.y"
                   {
		yyval = yyvsp[0];
	}
#line 1790 "parse.tab.c"
    break;

  case 61: /* fator: num  */
#line 365 "parse.y"
              {
		yyval = yyvsp[0];
	}
#line 1798 "parse.tab.c"
    break;

  case 62: /* ativacao: ident ESQPARENT arg_lista DIRPARENT  */
#line 370 "parse.y"
                                            {
	    	yyval = yyvsp[-3];
	    	yyval->child[0] = yyvsp[-1];
	    	yyval->nodekind = Declaracao_NodeK;
	    	yyval->kind.stmt = Call_StmtK;
    	}
#line 1809 "parse.tab.c"
    break;

  case 63: /* ativacao: ident ESQPARENT DIRPARENT  */
#line 376 "parse.y"
                                    {
		yyval = yyvsp[-2];
		yyval->nodekind = Declaracao_NodeK;
		yyval->kind.stmt = Call_StmtK;
	}
#line 1819 "parse.tab.c"
    break;

  case 64: /* arg_lista: arg_lista VIRG expressao  */
#line 383 "parse.y"
                                 {
	 	YYSTYPE t = yyvsp[-2];
		if (t != NULL) {
			while (t->sibling != NULL){
				t = t->sibling;
			}
			t->sibling = yyvsp[0];
			yyval = yyvsp[-2];
		}
		else 
			yyval = yyvsp[0];	
	}
#line 1836 "parse.tab.c"
    break;

  case 65: /* arg_lista: expressao  */
#line 395 "parse.y"
                    {
		yyval = yyvsp[0];
	}
#line 1844 "parse.tab.c"
    break;

  case 66: /* ident: ID  */
#line 400 "parse.y"
           {
		yyval = newExpNode(ID_ExpK);
		yyval->attr.name = copyString(tokenString);
	}
#line 1853 "parse.tab.c"
    break;

  case 67: /* num: NUM  */
#line 406 "parse.y"
            {
		yyval = newExpNode(Constante_ExpK);
		yyval->attr.val = atoi(tokenString);
	}
#line 1862 "parse.tab.c"
    break;


#line 1866 "parse.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 412 "parse.y"


void yyerror(char* message) {
    if(yychar != FIM && !Error){	
	    	printf("ERRO SINTÁTICO: \"%s\"  LINHA: %d\n", tokenString,lineno);
	    	Error = TRUE;
	}
}

/* yylex calls getToken to make Yacc/Bison output
 * compatible with ealier versions of the TINY scanner
 */
static int yylex(void) { 
	return getToken(); 
}

TreeNode * parse(void) {
	yyparse();
  	return savedTree;
}

