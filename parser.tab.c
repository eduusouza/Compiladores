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
#line 1 "parser.y"

#define YYPARSER
#include "globals.h"  

#define YYSTYPE TreeNode *

static TreeNode * savedTree;
static int yylex(void);

#line 81 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_INT = 5,                        /* INT  */
  YYSYMBOL_RETURN = 6,                     /* RETURN  */
  YYSYMBOL_VOID = 7,                       /* VOID  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_NUM = 9,                        /* NUM  */
  YYSYMBOL_ID = 10,                        /* ID  */
  YYSYMBOL_SUM = 11,                       /* SUM  */
  YYSYMBOL_SUB = 12,                       /* SUB  */
  YYSYMBOL_MULT = 13,                      /* MULT  */
  YYSYMBOL_DIV = 14,                       /* DIV  */
  YYSYMBOL_LT = 15,                        /* LT  */
  YYSYMBOL_LET = 16,                       /* LET  */
  YYSYMBOL_GT = 17,                        /* GT  */
  YYSYMBOL_GET = 18,                       /* GET  */
  YYSYMBOL_EQ = 19,                        /* EQ  */
  YYSYMBOL_NEQ = 20,                       /* NEQ  */
  YYSYMBOL_ATTR = 21,                      /* ATTR  */
  YYSYMBOL_SEMI = 22,                      /* SEMI  */
  YYSYMBOL_COMMA = 23,                     /* COMMA  */
  YYSYMBOL_OP = 24,                        /* OP  */
  YYSYMBOL_CP = 25,                        /* CP  */
  YYSYMBOL_OSB = 26,                       /* OSB  */
  YYSYMBOL_CSB = 27,                       /* CSB  */
  YYSYMBOL_OCB = 28,                       /* OCB  */
  YYSYMBOL_CCB = 29,                       /* CCB  */
  YYSYMBOL_ERROR = 30,                     /* ERROR  */
  YYSYMBOL_ENDFILE = 31,                   /* ENDFILE  */
  YYSYMBOL_YYACCEPT = 32,                  /* $accept  */
  YYSYMBOL_program = 33,                   /* program  */
  YYSYMBOL_list_declaration = 34,          /* list_declaration  */
  YYSYMBOL_declaration = 35,               /* declaration  */
  YYSYMBOL_var_declaration = 36,           /* var_declaration  */
  YYSYMBOL_fun_declaration = 37,           /* fun_declaration  */
  YYSYMBOL_params = 38,                    /* params  */
  YYSYMBOL_param_list = 39,                /* param_list  */
  YYSYMBOL_param = 40,                     /* param  */
  YYSYMBOL_compound_decl = 41,             /* compound_decl  */
  YYSYMBOL_local_declarations = 42,        /* local_declarations  */
  YYSYMBOL_statement_list = 43,            /* statement_list  */
  YYSYMBOL_statement = 44,                 /* statement  */
  YYSYMBOL_expression_decl = 45,           /* expression_decl  */
  YYSYMBOL_selection_decl = 46,            /* selection_decl  */
  YYSYMBOL_iterator_decl = 47,             /* iterator_decl  */
  YYSYMBOL_return_decl = 48,               /* return_decl  */
  YYSYMBOL_expression = 49,                /* expression  */
  YYSYMBOL_var = 50,                       /* var  */
  YYSYMBOL_simple_expression = 51,         /* simple_expression  */
  YYSYMBOL_relational = 52,                /* relational  */
  YYSYMBOL_sum_expression = 53,            /* sum_expression  */
  YYSYMBOL_sum = 54,                       /* sum  */
  YYSYMBOL_term = 55,                      /* term  */
  YYSYMBOL_mult = 56,                      /* mult  */
  YYSYMBOL_factor = 57,                    /* factor  */
  YYSYMBOL_activation = 58,                /* activation  */
  YYSYMBOL_arg_list = 59,                  /* arg_list  */
  YYSYMBOL_ident = 60,                     /* ident  */
  YYSYMBOL_num = 61                        /* num  */
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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   150

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  118

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
       0,    18,    18,    22,    33,    37,    40,    43,    47,    56,
      67,    81,    94,    97,   102,   113,   117,   126,   136,   147,
     150,   153,   157,   168,   172,   183,   187,   190,   193,   196,
     199,   203,   206,   209,   213,   218,   225,   231,   235,   240,
     246,   250,   254,   261,   266,   271,   276,   281,   286,   291,
     296,   302,   307,   311,   315,   320,   325,   329,   333,   338,
     341,   344,   347,   351,   357,   363,   374,   378,   384
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
  "\"end of file\"", "error", "\"invalid token\"", "IF", "ELSE", "INT",
  "RETURN", "VOID", "WHILE", "NUM", "ID", "SUM", "SUB", "MULT", "DIV",
  "LT", "LET", "GT", "GET", "EQ", "NEQ", "ATTR", "SEMI", "COMMA", "OP",
  "CP", "OSB", "CSB", "OCB", "CCB", "ERROR", "ENDFILE", "$accept",
  "program", "list_declaration", "declaration", "var_declaration",
  "fun_declaration", "params", "param_list", "param", "compound_decl",
  "local_declarations", "statement_list", "statement", "expression_decl",
  "selection_decl", "iterator_decl", "return_decl", "expression", "var",
  "simple_expression", "relational", "sum_expression", "sum", "term",
  "mult", "factor", "activation", "arg_list", "ident", "num", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-50)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-3)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      41,   -15,    34,    34,    49,    40,   -50,   -50,   -50,   -50,
     -50,    30,    31,   -50,   -50,   -50,    65,    66,    65,    34,
     -50,    64,    72,   -50,   -50,    71,    74,    75,    63,    99,
      87,    63,    89,     5,   -50,   -50,   -50,   -50,   -50,    92,
      93,    34,    13,    95,   -50,    29,   -50,   -50,   -50,    68,
      78,   -50,   -50,   -50,   -50,   -50,   101,   104,   -50,    46,
       6,   -50,   -50,    56,   -50,   -50,    29,     4,   -50,   105,
      29,   103,   -50,   -50,   102,   -50,   -50,   -50,    29,   -50,
     -50,   -50,   -50,   -50,   -50,   -50,   -50,    29,    29,   -50,
     -50,    29,     7,    29,   107,   -50,   108,   -50,   -50,   -50,
     -50,    82,     6,   -50,   -50,   -50,    60,   115,   112,   112,
      29,   -50,   -50,   125,   -50,   -50,   112,   -50
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     4,     5,     6,     7,
      67,     0,     0,     1,     3,     8,     0,     0,     0,     0,
      13,     0,    12,    15,    68,     0,     0,    16,     0,     0,
       0,     0,     0,     0,    10,    14,     9,    11,    17,     0,
       0,     0,     0,     0,    32,     0,    21,    23,    27,     0,
       0,    25,    26,    28,    29,    30,     0,    60,    40,    44,
      52,    56,    61,    41,    62,    33,     0,     0,    37,     0,
       0,     0,    19,    22,     0,    20,    24,    31,     0,    53,
      54,    47,    48,    49,    50,    45,    46,     0,     0,    57,
      58,     0,     0,     0,     0,    38,     0,    59,    18,    39,
      60,    43,    51,    55,    64,    66,     0,     0,     0,     0,
       0,    63,    42,    34,    36,    65,     0,    35
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -50,   -50,   -50,   130,   -31,   -50,   121,   -50,   114,   -19,
     -50,    96,   -49,   -50,   -50,   -50,   -50,   -42,    50,   -50,
     -50,    57,   -50,    58,   -50,    59,   -50,   -50,     2,   131
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,     7,     8,    21,    22,    23,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      87,    59,    88,    60,    91,    61,    62,   106,    63,    64
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      69,    76,    47,    71,    11,    12,    39,     9,    40,    34,
      41,    42,    37,    43,    24,    10,    24,    10,    73,    89,
      90,    27,    24,    10,    94,    76,    15,    44,    96,    45,
      17,    45,   104,    33,    46,    68,    99,    45,    24,    10,
      -2,     1,     1,    67,    10,     2,     2,     3,     3,    13,
     105,   107,    15,    45,    16,    18,    17,    79,    80,   113,
     114,    81,    82,    83,    84,    85,    86,   117,   115,    39,
      19,    40,    20,    41,    42,    24,    43,    24,    10,    39,
      92,    40,    93,   110,    42,   111,    43,    24,    10,    28,
      44,    33,    45,    79,    80,    29,    33,    72,    30,    31,
      44,    32,    45,    39,    19,    40,    33,    75,    42,    36,
      43,    24,    10,    39,    65,    40,    38,    66,    42,    70,
      43,    24,    10,    77,    44,    78,    45,    95,    97,   116,
      33,    98,   108,   109,    44,    14,    45,   100,   100,    26,
      33,   100,   112,    35,   101,    74,   102,     0,    25,     0,
     103
};

static const yytype_int8 yycheck[] =
{
      42,    50,    33,    45,     2,     3,     1,    22,     3,    28,
       5,     6,    31,     8,     9,    10,     9,    10,    49,    13,
      14,    19,     9,    10,    66,    74,    22,    22,    70,    24,
      26,    24,    25,    28,    29,    22,    78,    24,     9,    10,
       0,     1,     1,    41,    10,     5,     5,     7,     7,     0,
      92,    93,    22,    24,    24,    24,    26,    11,    12,   108,
     109,    15,    16,    17,    18,    19,    20,   116,   110,     1,
       5,     3,     7,     5,     6,     9,     8,     9,    10,     1,
      24,     3,    26,    23,     6,    25,     8,     9,    10,    25,
      22,    28,    24,    11,    12,    23,    28,    29,    27,    25,
      22,    26,    24,     1,     5,     3,    28,    29,     6,    22,
       8,     9,    10,     1,    22,     3,    27,    24,     6,    24,
       8,     9,    10,    22,    22,    21,    24,    22,    25,     4,
      28,    29,    25,    25,    22,     5,    24,    87,    88,    18,
      28,    91,    27,    29,    87,    49,    88,    -1,    17,    -1,
      91
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     5,     7,    33,    34,    35,    36,    37,    22,
      10,    60,    60,     0,    35,    22,    24,    26,    24,     5,
       7,    38,    39,    40,     9,    61,    38,    60,    25,    23,
      27,    25,    26,    28,    41,    40,    22,    41,    27,     1,
       3,     5,     6,     8,    22,    24,    29,    36,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    53,
      55,    57,    58,    60,    61,    22,    24,    60,    22,    49,
      24,    49,    29,    36,    43,    29,    44,    22,    21,    11,
      12,    15,    16,    17,    18,    19,    20,    52,    54,    13,
      14,    56,    24,    26,    49,    22,    49,    25,    29,    49,
      50,    53,    55,    57,    25,    49,    59,    49,    25,    25,
      23,    25,    27,    44,    44,    49,     4,    44
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    35,    36,    36,
      37,    37,    38,    38,    39,    39,    40,    40,    41,    41,
      41,    41,    42,    42,    43,    43,    44,    44,    44,    44,
      44,    45,    45,    45,    46,    46,    47,    48,    48,    49,
      49,    50,    50,    51,    51,    52,    52,    52,    52,    52,
      52,    53,    53,    54,    54,    55,    55,    56,    56,    57,
      57,    57,    57,    58,    58,    59,    59,    60,    61
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     2,     3,     6,
       6,     6,     1,     1,     3,     1,     2,     4,     4,     3,
       3,     2,     2,     1,     2,     1,     1,     1,     1,     1,
       1,     2,     1,     2,     5,     7,     5,     2,     3,     3,
       1,     1,     4,     3,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     4,     3,     3,     1,     1,     1
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
  case 2: /* program: list_declaration  */
#line 18 "parser.y"
                                         {
                            savedTree = yyvsp[0];
                        }
#line 1213 "parser.tab.c"
    break;

  case 3: /* list_declaration: list_declaration declaration  */
#line 22 "parser.y"
                                                     {
                            YYSTYPE t = yyvsp[-1];
                            if(t != NULL){
                                while(t->sibling != NULL)
                                    t = t->sibling;
                                t->sibling = yyvsp[0];
                                yyval = yyvsp[-1];
                            } else {
                                yyval = yyvsp[0];
                            }
                        }
#line 1229 "parser.tab.c"
    break;

  case 4: /* list_declaration: declaration  */
#line 33 "parser.y"
                                      {
                            yyval = yyvsp[0];
                        }
#line 1237 "parser.tab.c"
    break;

  case 5: /* declaration: var_declaration  */
#line 37 "parser.y"
                                        {
                            yyval = yyvsp[0];
                        }
#line 1245 "parser.tab.c"
    break;

  case 6: /* declaration: fun_declaration  */
#line 40 "parser.y"
                                          {
                            yyval = yyvsp[0];
                        }
#line 1253 "parser.tab.c"
    break;

  case 7: /* declaration: error SEMI  */
#line 43 "parser.y"
                                     {
                            yyerrok;
                        }
#line 1261 "parser.tab.c"
    break;

  case 8: /* var_declaration: INT ident SEMI  */
#line 47 "parser.y"
                                       {
                            yyval = newExpNode(typeK);
                            yyval->type = integerK;
                            yyval->attr.name = "integer";
                            yyval->child[0] = yyvsp[-1];
                            yyvsp[-1]->nodekind = statementK;
                            yyvsp[-1]->kind.stmt = variableK;
                            yyvsp[-1]->type = integerK;
                        }
#line 1275 "parser.tab.c"
    break;

  case 9: /* var_declaration: INT ident OSB num CSB SEMI  */
#line 56 "parser.y"
                                                     {
                            yyval = newExpNode(typeK);
                            yyval->type = integerK;
                            yyval->attr.name = "integer";
                            yyval->child[0] = yyvsp[-4];
                            yyvsp[-4]->nodekind = statementK;
                            yyvsp[-4]->kind.stmt = vectorStmtK;
                            yyvsp[-4]->type = integerK;
                            yyvsp[-4]->attr.len = yyvsp[-2]->attr.val;
                        }
#line 1290 "parser.tab.c"
    break;

  case 10: /* fun_declaration: INT ident OP params CP compound_decl  */
#line 67 "parser.y"
                                                             {
                            yyval = newExpNode(typeK);
                            yyval->type = integerK;
                            yyval->attr.name = "integer";
                            yyval->child[0] = yyvsp[-4];
                            yyvsp[-4]->child[0] = yyvsp[-2];
                            yyvsp[-4]->child[1] = yyvsp[0];
                            yyvsp[-4]->nodekind = statementK;
                            yyvsp[-4]->kind.stmt = functionK;
                            yyvsp[-4]->type = integerK;
                            yyvsp[-2]->type = integerK;
                            aggScope(yyvsp[-4]->child[0], yyvsp[-4]->attr.name);
                            aggScope(yyvsp[-4]->child[1], yyvsp[-4]->attr.name);
                        }
#line 1309 "parser.tab.c"
    break;

  case 11: /* fun_declaration: VOID ident OP params CP compound_decl  */
#line 81 "parser.y"
                                                                {
                            yyval = newExpNode(typeK);
                            yyval->type = voidK;
                            yyval->attr.name = "void";
                            yyval->child[0] = yyvsp[-4];
                            yyvsp[-4]->child[0] = yyvsp[-2];
                            yyvsp[-4]->child[1] = yyvsp[0];
                            yyvsp[-4]->nodekind = statementK;
                            yyvsp[-4]->kind.stmt = functionK;
                            aggScope(yyvsp[-4]->child[0], yyvsp[-4]->attr.name);
                            aggScope(yyvsp[-4]->child[1], yyvsp[-4]->attr.name);
                        }
#line 1326 "parser.tab.c"
    break;

  case 12: /* params: param_list  */
#line 94 "parser.y"
                                   {
                            yyval = yyvsp[0];
                        }
#line 1334 "parser.tab.c"
    break;

  case 13: /* params: VOID  */
#line 97 "parser.y"
                               {
                            yyval = newExpNode(typeK);
                            yyval->attr.name = "void";
                        }
#line 1343 "parser.tab.c"
    break;

  case 14: /* param_list: param_list COMMA param  */
#line 102 "parser.y"
                                               {
                            YYSTYPE t = yyvsp[-2];
                            if(t != NULL){
                                while(t->sibling != NULL)
                                    t = t->sibling;
                                t->sibling = yyvsp[0];
                                yyval = yyvsp[-2];
                            } else {
                                yyval = yyvsp[0];
                            }
                        }
#line 1359 "parser.tab.c"
    break;

  case 15: /* param_list: param  */
#line 113 "parser.y"
                                {
                            yyval = yyvsp[0];
                        }
#line 1367 "parser.tab.c"
    break;

  case 16: /* param: INT ident  */
#line 117 "parser.y"
                                  {
                            yyval = newExpNode(typeK);
                            yyvsp[0]->nodekind = statementK;
                            yyvsp[0]->kind.stmt = variableK;
                            yyval->type = integerK;
                            yyvsp[0]->type = integerK;
                            yyval->attr.name = "integer";
                            yyval->child[0] = yyvsp[0];
                        }
#line 1381 "parser.tab.c"
    break;

  case 17: /* param: INT ident OSB CSB  */
#line 126 "parser.y"
                                            {
                            yyval = newExpNode(typeK);
                            yyvsp[-2]->nodekind = statementK;
                            yyvsp[-2]->kind.stmt = vectorStmtK;
                            yyval->type = integerK;
                            yyval->attr.name = "integer";
                            yyval->child[0] = yyvsp[-2];
                            yyvsp[-2]->type = integerK;
                        }
#line 1395 "parser.tab.c"
    break;

  case 18: /* compound_decl: OCB local_declarations statement_list CCB  */
#line 136 "parser.y"
                                                                  {
                            YYSTYPE t = yyvsp[-2];
                            if(t != NULL){
                                while(t->sibling != NULL)
                                    t = t->sibling;
                                t->sibling = yyvsp[-1];
                                yyval = yyvsp[-2];
                            } else {
                                yyval = yyvsp[-1];
                            }
                        }
#line 1411 "parser.tab.c"
    break;

  case 19: /* compound_decl: OCB local_declarations CCB  */
#line 147 "parser.y"
                                                     {
                            yyval = yyvsp[-1];
                        }
#line 1419 "parser.tab.c"
    break;

  case 20: /* compound_decl: OCB statement_list CCB  */
#line 150 "parser.y"
                                                 {
                            yyval = yyvsp[-1];
                        }
#line 1427 "parser.tab.c"
    break;

  case 21: /* compound_decl: OCB CCB  */
#line 153 "parser.y"
                                  {

                        }
#line 1435 "parser.tab.c"
    break;

  case 22: /* local_declarations: local_declarations var_declaration  */
#line 157 "parser.y"
                                                           {
                            YYSTYPE t = yyvsp[-1];
                            if(t != NULL){
                                while(t->sibling != NULL)
                                    t = t->sibling;
                                t->sibling = yyvsp[0];
                                yyval = yyvsp[-1];
                            } else {
                                yyval = yyvsp[0];
                            }
                        }
#line 1451 "parser.tab.c"
    break;

  case 23: /* local_declarations: var_declaration  */
#line 168 "parser.y"
                                          {
                            yyval = yyvsp[0];
                        }
#line 1459 "parser.tab.c"
    break;

  case 24: /* statement_list: statement_list statement  */
#line 172 "parser.y"
                                                 {
                            YYSTYPE t = yyvsp[-1];
                            if(t != NULL){
                                while(t->sibling != NULL)
                                    t = t->sibling;
                                t->sibling = yyvsp[0];
                                yyval = yyvsp[-1];
                            } else {
                                yyval = yyvsp[0];
                            }
                        }
#line 1475 "parser.tab.c"
    break;

  case 25: /* statement_list: statement  */
#line 183 "parser.y"
                                    {
                            yyval = yyvsp[0];
                        }
#line 1483 "parser.tab.c"
    break;

  case 26: /* statement: expression_decl  */
#line 187 "parser.y"
                                        {
                            yyval = yyvsp[0];
                        }
#line 1491 "parser.tab.c"
    break;

  case 27: /* statement: compound_decl  */
#line 190 "parser.y"
                                        {
                            yyval = yyvsp[0];
                        }
#line 1499 "parser.tab.c"
    break;

  case 28: /* statement: selection_decl  */
#line 193 "parser.y"
                                         {
                            yyval = yyvsp[0];
                        }
#line 1507 "parser.tab.c"
    break;

  case 29: /* statement: iterator_decl  */
#line 196 "parser.y"
                                        {
                            yyval = yyvsp[0];
                        }
#line 1515 "parser.tab.c"
    break;

  case 30: /* statement: return_decl  */
#line 199 "parser.y"
                                      {
                            yyval = yyvsp[0];
                        }
#line 1523 "parser.tab.c"
    break;

  case 31: /* expression_decl: expression SEMI  */
#line 203 "parser.y"
                                        {
                            yyval = yyvsp[-1];
                        }
#line 1531 "parser.tab.c"
    break;

  case 32: /* expression_decl: SEMI  */
#line 206 "parser.y"
                               {

                        }
#line 1539 "parser.tab.c"
    break;

  case 33: /* expression_decl: error SEMI  */
#line 209 "parser.y"
                                     {
                            yyerrok;
                        }
#line 1547 "parser.tab.c"
    break;

  case 34: /* selection_decl: IF OP expression CP statement  */
#line 213 "parser.y"
                                                      {
                            yyval = newStmtNode(ifK);
                            yyval->child[0] = yyvsp[-2];
                            yyval->child[1] = yyvsp[0];
                        }
#line 1557 "parser.tab.c"
    break;

  case 35: /* selection_decl: IF OP expression CP statement ELSE statement  */
#line 218 "parser.y"
                                                                       {
                            yyval = newStmtNode(ifK);
                            yyval->child[0] = yyvsp[-4];
                            yyval->child[1] = yyvsp[-2];
                            yyval->child[2] = yyvsp[0];
                        }
#line 1568 "parser.tab.c"
    break;

  case 36: /* iterator_decl: WHILE OP expression CP statement  */
#line 225 "parser.y"
                                                         {
                            yyval = newStmtNode(whileK);
                            yyval->child[0] = yyvsp[-2];
                            yyval->child[1] = yyvsp[0];
                        }
#line 1578 "parser.tab.c"
    break;

  case 37: /* return_decl: RETURN SEMI  */
#line 231 "parser.y"
                                     {
                            yyval = newStmtNode(returnK);
                            yyval->type = voidK;
                        }
#line 1587 "parser.tab.c"
    break;

  case 38: /* return_decl: RETURN expression SEMI  */
#line 235 "parser.y"
                                                {
                            yyval = newStmtNode(returnK);
                            yyval->child[0] = yyvsp[-1];
                        }
#line 1596 "parser.tab.c"
    break;

  case 39: /* expression: var ATTR expression  */
#line 240 "parser.y"
                                            {
                            yyval = newStmtNode(assignK);
                            yyval->child[0] = yyvsp[-2];
                            yyval->child[1] = yyvsp[0];
                            yyval->type = integerK;
                        }
#line 1607 "parser.tab.c"
    break;

  case 40: /* expression: simple_expression  */
#line 246 "parser.y"
                                            {
                            yyval = yyvsp[0];
                        }
#line 1615 "parser.tab.c"
    break;

  case 41: /* var: ident  */
#line 250 "parser.y"
                              {
                            yyval = yyvsp[0];
                            yyval->type = integerK;
                        }
#line 1624 "parser.tab.c"
    break;

  case 42: /* var: ident OSB expression CSB  */
#line 254 "parser.y"
                                                   {
                            yyval = yyvsp[-3];
                            yyval->child[0] = yyvsp[-1];
                            yyval->kind.exp = vectorK;
                            yyval->type = integerK;
                        }
#line 1635 "parser.tab.c"
    break;

  case 43: /* simple_expression: sum_expression relational sum_expression  */
#line 261 "parser.y"
                                                                 {
                            yyval = yyvsp[-1];
                            yyval->child[0] = yyvsp[-2];
                            yyval->child[1] = yyvsp[0];
                        }
#line 1645 "parser.tab.c"
    break;

  case 44: /* simple_expression: sum_expression  */
#line 266 "parser.y"
                                         {
                            yyval = yyvsp[0];
                            yyval->type = integerK;
                        }
#line 1654 "parser.tab.c"
    break;

  case 45: /* relational: EQ  */
#line 271 "parser.y"
                           {
                            yyval = newExpNode(operationK);
                            yyval->attr.op = EQ;
                            yyval->type = booleanK;
                        }
#line 1664 "parser.tab.c"
    break;

  case 46: /* relational: NEQ  */
#line 276 "parser.y"
                              {
                            yyval = newExpNode(operationK);
                            yyval->attr.op = NEQ;
                            yyval->type = booleanK;
                        }
#line 1674 "parser.tab.c"
    break;

  case 47: /* relational: LT  */
#line 281 "parser.y"
                             {
                            yyval = newExpNode(operationK);
                            yyval->attr.op = LT;
                            yyval->type = booleanK;
                        }
#line 1684 "parser.tab.c"
    break;

  case 48: /* relational: LET  */
#line 286 "parser.y"
                              {
                            yyval = newExpNode(operationK);
                            yyval->attr.op = LET;
                            yyval->type = booleanK;
                        }
#line 1694 "parser.tab.c"
    break;

  case 49: /* relational: GT  */
#line 291 "parser.y"
                             {
                            yyval = newExpNode(operationK);
                            yyval->attr.op = GT;
                            yyval->type = booleanK;
                        }
#line 1704 "parser.tab.c"
    break;

  case 50: /* relational: GET  */
#line 296 "parser.y"
                              {
                            yyval = newExpNode(operationK);
                            yyval->attr.op = GET;
                            yyval->type = booleanK;
                        }
#line 1714 "parser.tab.c"
    break;

  case 51: /* sum_expression: sum_expression sum term  */
#line 302 "parser.y"
                                                {
                            yyval = yyvsp[-1];
                            yyval->child[0] = yyvsp[-2];
                            yyval->child[1] = yyvsp[0];
                        }
#line 1724 "parser.tab.c"
    break;

  case 52: /* sum_expression: term  */
#line 307 "parser.y"
                               {
                            yyval = yyvsp[0];
                        }
#line 1732 "parser.tab.c"
    break;

  case 53: /* sum: SUM  */
#line 311 "parser.y"
                            {
                            yyval = newExpNode(operationK);
                            yyval->attr.op = SUM;
                        }
#line 1741 "parser.tab.c"
    break;

  case 54: /* sum: SUB  */
#line 315 "parser.y"
                              {
                            yyval = newExpNode(operationK);
                            yyval->attr.op = SUB;
                        }
#line 1750 "parser.tab.c"
    break;

  case 55: /* term: term mult factor  */
#line 320 "parser.y"
                                         {
                            yyval = yyvsp[-1];
                            yyval->child[0] = yyvsp[-2];
                            yyval->child[1] = yyvsp[0];
                        }
#line 1760 "parser.tab.c"
    break;

  case 56: /* term: factor  */
#line 325 "parser.y"
                                 {
                            yyval = yyvsp[0];
                        }
#line 1768 "parser.tab.c"
    break;

  case 57: /* mult: MULT  */
#line 329 "parser.y"
                             {
                            yyval = newExpNode(operationK);
                            yyval->attr.op = MULT;
                        }
#line 1777 "parser.tab.c"
    break;

  case 58: /* mult: DIV  */
#line 333 "parser.y"
                              {
                            yyval = newExpNode(operationK);
                            yyval->attr.op = DIV;
                        }
#line 1786 "parser.tab.c"
    break;

  case 59: /* factor: OP expression CP  */
#line 338 "parser.y"
                                         {
                            yyval = yyvsp[-1];
                        }
#line 1794 "parser.tab.c"
    break;

  case 60: /* factor: var  */
#line 341 "parser.y"
                              {
                            yyval = yyvsp[0];
                        }
#line 1802 "parser.tab.c"
    break;

  case 61: /* factor: activation  */
#line 344 "parser.y"
                                     {
                            yyval = yyvsp[0];
                        }
#line 1810 "parser.tab.c"
    break;

  case 62: /* factor: num  */
#line 347 "parser.y"
                              {
                            yyval = yyvsp[0];
                        }
#line 1818 "parser.tab.c"
    break;

  case 63: /* activation: ident OP arg_list CP  */
#line 351 "parser.y"
                                             {
                            yyval = yyvsp[-3];
                            yyval->child[0] = yyvsp[-1];
                            yyval->nodekind = statementK;
                            yyval->kind.stmt = callK;
                        }
#line 1829 "parser.tab.c"
    break;

  case 64: /* activation: ident OP CP  */
#line 357 "parser.y"
                                      {
                            yyval = yyvsp[-2];
                            yyval->nodekind = statementK;
                            yyval->kind.stmt = callK;
                        }
#line 1839 "parser.tab.c"
    break;

  case 65: /* arg_list: arg_list COMMA expression  */
#line 363 "parser.y"
                                                  {
                            YYSTYPE t = yyvsp[-2];
                            if(t != NULL){
                                while(t->sibling != NULL)
                                    t = t->sibling;
                                t->sibling = yyvsp[0];
                                yyval = yyvsp[-2];
                            } else {
                                yyval = yyvsp[0];
                            }                 
                        }
#line 1855 "parser.tab.c"
    break;

  case 66: /* arg_list: expression  */
#line 374 "parser.y"
                                     {
                            yyval = yyvsp[0];
                        }
#line 1863 "parser.tab.c"
    break;

  case 67: /* ident: ID  */
#line 378 "parser.y"
                           {
                            yyval = newExpNode(idK);
                            yyval->attr.name = copyString(tokenString);
                        }
#line 1872 "parser.tab.c"
    break;

  case 68: /* num: NUM  */
#line 384 "parser.y"
                            {
                            yyval = newExpNode(constantK);
                            yyval->attr.val = atoi(tokenString);
                            yyval->type = integerK;
                        }
#line 1882 "parser.tab.c"
    break;


#line 1886 "parser.tab.c"

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

#line 390 "parser.y"


int yyerror(){
    printf("\nERRO SINTATICO: %s, LINHA: %d\n", tokenString, line_number);
    Error = TRUE;
    return 0;
}

static int yylex(void){
    return getToken();
}

TreeNode * parse(void){
    yyparse();
    return savedTree;
}
