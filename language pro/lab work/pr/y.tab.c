/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "while.y" /* yacc.c:339  */

	#include<bits/stdc++.h>
	using namespace std;
	
	void yyerror(char *str)
	{
		cout<<"\nError : \n"<<str<<endl;
	}
	int yylex();
	
	string myitoa(int n)
	{
		string str = "";
		while(n > 0)
		{
			int r = n%10;
			str += (char) r+'0';
			
			n /= 10;
		}
		
		int len = str.length();
		for(int i=0;i<len/2;i++)
			swap(str[i], str[len-i-1]);
		
		return str;
	}
	
	struct CodeHolder
	{
		string place;
		string code;
		string begin;
		string after;
		string type;
		string temp;
		map<string, string> *labelMap;
	}table[10005];
	
	
	int tableIndex = 0;
	int getFreeTableIndex()
	{
		table[tableIndex].place = "";
		table[tableIndex].code = "";
		table[tableIndex].begin = "";
		table[tableIndex].after = "";
		table[tableIndex].type = "";
		table[tableIndex].labelMap = NULL;
		return tableIndex++;
	}
	int labelIndex = 1;
	string newLabel()
	{
		string str = "L";
		str = str + myitoa(labelIndex++);
		return str;
	}
	int freeVarIndex = 1;
	string newTemp()
	{
		string str = "t";
		str = str + myitoa(freeVarIndex++);
		return str;
	}
	
	int mainTableIndex = -1;
	
	map<string, string> varType;
	bool isDeclared(string var)
	{
		if(varType.find(var)==varType.end())
			return false;
		return true;
	}
	int getVarSize(string str)
	{
		if(str[0]=='i' | str[0]=='u')
			return 32;
		if(str[0]=='b')
			return 8;
		return 0;
	}
	
	string getCombinedType(string ta, string tb)
	{
		if(ta=="int" || tb=="int")
			return "int";
		
		if(ta=="uint" || tb=="uint")
			return "uint";
		
		return "bool";
	}
	
	stack<string> blockExit;
	
	string curDataType;

#line 166 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ID = 258,
    NUM = 259,
    DATA_TYPE = 260,
    IF_KEY = 261,
    ELSE_KEY = 262,
    SWITCH_KEY = 263,
    CASE_KEY = 264,
    DEFAULT_KEY = 265,
    BREAK_KEY = 266,
    WHILE_KEY = 267,
    LOROP = 268,
    LANDOP = 269,
    BOROP = 270,
    BANDOP = 271,
    BXOROP = 272,
    EQOP = 273,
    NEQOP = 274,
    LTOP = 275,
    LTEQOP = 276,
    GTOP = 277,
    GTEQOP = 278,
    ADDEQ = 279,
    SUBEQ = 280,
    MULEQ = 281,
    DIVEQ = 282,
    EXPOP = 283,
    LNOTOP = 284,
    BNOTOP = 285,
    IFX = 286,
    SPACE = 287
  };
#endif
/* Tokens.  */
#define ID 258
#define NUM 259
#define DATA_TYPE 260
#define IF_KEY 261
#define ELSE_KEY 262
#define SWITCH_KEY 263
#define CASE_KEY 264
#define DEFAULT_KEY 265
#define BREAK_KEY 266
#define WHILE_KEY 267
#define LOROP 268
#define LANDOP 269
#define BOROP 270
#define BANDOP 271
#define BXOROP 272
#define EQOP 273
#define NEQOP 274
#define LTOP 275
#define LTEQOP 276
#define GTOP 277
#define GTEQOP 278
#define ADDEQ 279
#define SUBEQ 280
#define MULEQ 281
#define DIVEQ 282
#define EXPOP 283
#define LNOTOP 284
#define BNOTOP 285
#define IFX 286
#define SPACE 287

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 101 "while.y" /* yacc.c:355  */
	int lnum; char *lstr; 

#line 273 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 290 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   440

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  52
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  108

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      40,    41,    30,    28,     2,    29,     2,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    42,    39,
       2,    43,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    38,     2,     2,     2,     2,
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
      25,    26,    27,    32,    33,    34,    35,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   123,   123,   128,   136,   141,   146,   151,   156,   161,
     166,   171,   179,   179,   200,   200,   226,   238,   255,   265,
     270,   277,   289,   309,   335,   360,   365,   374,   394,   414,
     434,   454,   477,   485,   494,   502,   510,   519,   527,   535,
     543,   551,   559,   568,   576,   584,   592,   601,   610,   618,
     627,   632,   643
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "NUM", "DATA_TYPE", "IF_KEY",
  "ELSE_KEY", "SWITCH_KEY", "CASE_KEY", "DEFAULT_KEY", "BREAK_KEY",
  "WHILE_KEY", "LOROP", "LANDOP", "BOROP", "BANDOP", "BXOROP", "EQOP",
  "NEQOP", "LTOP", "LTEQOP", "GTOP", "GTEQOP", "ADDEQ", "SUBEQ", "MULEQ",
  "DIVEQ", "'+'", "'-'", "'*'", "'/'", "EXPOP", "LNOTOP", "BNOTOP", "IFX",
  "SPACE", "'{'", "'}'", "';'", "'('", "')'", "':'", "'='", "$accept",
  "program", "stmt", "while_stmt", "$@1", "switch_stmt", "$@2",
  "switch_body", "case_body", "break_stmt", "if_stmt", "declare_stmt",
  "opt_assign", "assign_stmt", "exp", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    43,    45,
      42,    47,   283,   284,   285,   286,   287,   123,   125,    59,
      40,    41,    58,    61
};
# endif

#define YYPACT_NINF -37

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-37)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -37,    45,   -37,   -16,     1,   -34,   -37,   -32,   -37,   -37,
     -37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,    43,    43,
      43,    43,    43,   -22,    43,   -18,   -37,   -12,    55,   -37,
     -37,    43,    43,    43,   240,   267,   294,   321,   348,    43,
      10,   124,    43,    43,   -37,   -37,   -37,   153,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    43,   -37,   -37,   -37,   -37,   -37,   375,
     -37,    67,   182,   211,   -37,   393,   393,   408,   408,   408,
     -13,   -13,   -13,   -13,   -13,   -13,    58,    58,    20,    20,
      20,    48,    22,    67,    67,   -37,   -37,   -37,    16,    43,
      23,   -37,    94,   -37,   -37,    67,    67,   -37
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     1,     0,     0,     0,    14,     0,    12,     3,
      11,     2,     9,     7,    10,     6,     4,     5,     0,     0,
       0,     0,     0,    26,     0,     0,    21,     0,     0,    51,
      52,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     8,    48,    49,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    28,    29,    30,    31,    27,    25,
      24,     0,     0,     0,    50,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    22,     0,     0,     0,    18,    13,    23,     0,     0,
       0,    15,     0,    20,    20,    17,    16,    19
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -37,    53,    -7,   -37,   -37,   -37,   -37,   -37,   -36,   -37,
     -37,   -37,   -37,   -37,   -19
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    11,    12,    27,    13,    25,    98,   105,    14,
      15,    16,    40,    17,    34
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      35,    36,    37,    38,    23,    41,    24,    26,    18,    19,
      20,    21,    45,    46,    47,    59,    60,    61,    62,    63,
      69,    39,    42,    72,    73,    99,   100,    22,    43,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,     2,    29,    30,     3,    70,
       4,     5,    63,     6,   101,    94,     7,     8,     3,    95,
       4,     5,    28,     6,    91,   103,     7,     8,   106,     0,
       3,     0,     4,     5,     0,     6,    31,    32,     7,     8,
     102,     0,     9,    33,    10,     0,    96,    97,    61,    62,
      63,     0,     9,    44,    10,     0,     0,     0,   107,   107,
       0,     0,     0,     0,     9,     0,    10,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,     0,     0,
       0,     0,    59,    60,    61,    62,    63,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   104,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,     0,     0,
       0,     0,    59,    60,    61,    62,    63,     0,     0,     0,
       0,     0,     0,     0,     0,    71,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,     0,     0,     0,
       0,    59,    60,    61,    62,    63,     0,     0,     0,     0,
       0,     0,     0,     0,    74,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,     0,     0,     0,     0,
      59,    60,    61,    62,    63,     0,     0,     0,     0,     0,
       0,     0,     0,    92,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,     0,     0,     0,     0,    59,
      60,    61,    62,    63,     0,     0,     0,     0,     0,     0,
       0,     0,    93,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,     0,     0,     0,     0,    59,    60,
      61,    62,    63,     0,     0,     0,     0,     0,     0,    64,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,     0,     0,     0,     0,    59,    60,    61,    62,    63,
       0,     0,     0,     0,     0,     0,    65,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,     0,     0,
       0,     0,    59,    60,    61,    62,    63,     0,     0,     0,
       0,     0,     0,    66,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,     0,     0,     0,     0,    59,
      60,    61,    62,    63,     0,     0,     0,     0,     0,     0,
      67,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,     0,     0,     0,     0,    59,    60,    61,    62,
      63,     0,     0,     0,     0,     0,     0,    68,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,     0,
       0,     0,     0,    59,    60,    61,    62,    63,    50,    51,
      52,    53,    54,    55,    56,    57,    58,     0,     0,     0,
       0,    59,    60,    61,    62,    63,    53,    54,    55,    56,
      57,    58,     0,     0,     0,     0,    59,    60,    61,    62,
      63
};

static const yytype_int8 yycheck[] =
{
      19,    20,    21,    22,     3,    24,    40,    39,    24,    25,
      26,    27,    31,    32,    33,    28,    29,    30,    31,    32,
      39,    43,    40,    42,    43,     9,    10,    43,    40,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,     0,     3,     4,     3,    39,
       5,     6,    32,     8,    38,     7,    11,    12,     3,    37,
       5,     6,     9,     8,    71,    42,    11,    12,   104,    -1,
       3,    -1,     5,     6,    -1,     8,    33,    34,    11,    12,
      99,    -1,    37,    40,    39,    -1,    93,    94,    30,    31,
      32,    -1,    37,    38,    39,    -1,    -1,    -1,   105,   106,
      -1,    -1,    -1,    -1,    37,    -1,    39,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    41,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    41,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    39,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    18,    19,    20,    21,
      22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    45,     0,     3,     5,     6,     8,    11,    12,    37,
      39,    46,    47,    49,    53,    54,    55,    57,    24,    25,
      26,    27,    43,     3,    40,    50,    39,    48,    45,     3,
       4,    33,    34,    40,    58,    58,    58,    58,    58,    43,
      56,    58,    40,    40,    38,    58,    58,    58,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    28,
      29,    30,    31,    32,    39,    39,    39,    39,    39,    58,
      39,    41,    58,    58,    41,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    46,    41,    41,     7,    37,    46,    46,    51,     9,
      10,    38,    58,    42,    42,    52,    52,    46
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    45,    46,    46,    46,    46,    46,    46,
      46,    46,    48,    47,    50,    49,    51,    51,    51,    52,
      52,    53,    54,    54,    55,    56,    56,    57,    57,    57,
      57,    57,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     1,     1,     1,     1,     3,     1,
       1,     1,     0,     6,     0,     8,     5,     4,     0,     2,
       0,     2,     5,     7,     4,     2,     0,     4,     4,     4,
       4,     4,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       3,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
#line 123 "while.y" /* yacc.c:1646  */
    {
									(yyval.lnum) = getFreeTableIndex();
									table[(yyval.lnum)].code = table[(yyvsp[-1].lnum)].code + table[(yyvsp[0].lnum)].code;
									mainTableIndex = (yyval.lnum);
								}
#line 1508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 128 "while.y" /* yacc.c:1646  */
    {
									(yyval.lnum) = getFreeTableIndex();
									table[(yyval.lnum)].code = "";
									mainTableIndex = (yyval.lnum);
								}
#line 1518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 136 "while.y" /* yacc.c:1646  */
    {
									(yyval.lnum) = getFreeTableIndex();
									table[(yyval.lnum)] = table[(yyvsp[0].lnum)];
									mainTableIndex = (yyval.lnum);
								}
#line 1528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 141 "while.y" /* yacc.c:1646  */
    {
									(yyval.lnum) = getFreeTableIndex();
									table[(yyval.lnum)] = table[(yyvsp[0].lnum)];
									mainTableIndex = (yyval.lnum);
								}
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 146 "while.y" /* yacc.c:1646  */
    {
									(yyval.lnum) = getFreeTableIndex();
									table[(yyval.lnum)] = table[(yyvsp[0].lnum)];
									mainTableIndex = (yyval.lnum);
								}
#line 1548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 151 "while.y" /* yacc.c:1646  */
    {
									(yyval.lnum) = getFreeTableIndex();
									table[(yyval.lnum)] = table[(yyvsp[0].lnum)];
									mainTableIndex = (yyval.lnum);
								}
#line 1558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 156 "while.y" /* yacc.c:1646  */
    {
									(yyval.lnum) =getFreeTableIndex();
									table[(yyval.lnum)] = table[(yyvsp[-1].lnum)];
									mainTableIndex = (yyval.lnum);
								}
#line 1568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 161 "while.y" /* yacc.c:1646  */
    {
									(yyval.lnum) = getFreeTableIndex();
									table[(yyval.lnum)] = table[(yyvsp[0].lnum)];
									mainTableIndex = (yyval.lnum);
								}
#line 1578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 166 "while.y" /* yacc.c:1646  */
    {
									(yyval.lnum) = getFreeTableIndex();
									table[(yyval.lnum)] = table[(yyvsp[0].lnum)];
									mainTableIndex = (yyval.lnum);
								}
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 171 "while.y" /* yacc.c:1646  */
    {
									(yyval.lnum) = getFreeTableIndex();
									table[(yyval.lnum)].code = "";
									mainTableIndex = (yyval.lnum);
								}
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 179 "while.y" /* yacc.c:1646  */
    {blockExit.push(newLabel());}
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 179 "while.y" /* yacc.c:1646  */
    {
																		(yyval.lnum) = getFreeTableIndex();
																		string startLabel = newLabel();
																		string falseLabel = blockExit.top();
																		table[(yyval.lnum)].code = startLabel + ":\n";
																		table[(yyval.lnum)].code += table[(yyvsp[-2].lnum)].code;
																		string boolCode;
																		if(table[(yyvsp[-2].lnum)].type=="bool")
																			boolCode = "if FALSE " + table[(yyvsp[-2].lnum)].place + ", goto " + falseLabel + "\n";
																		else
																			boolCode = "if " + table[(yyvsp[-2].lnum)].place + " == 0, goto " + falseLabel + "\n";
																		table[(yyval.lnum)].code += boolCode;
																		table[(yyval.lnum)].code += table[(yyvsp[0].lnum)].code;
																		table[(yyval.lnum)].code += "goto " + startLabel + "\n";
																		table[(yyval.lnum)].code += falseLabel + ":\n";
																		table[(yyval.lnum)].after = falseLabel;
																		blockExit.pop();
																		mainTableIndex = (yyval.lnum);
																	}
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 200 "while.y" /* yacc.c:1646  */
    {blockExit.push(newLabel());}
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 200 "while.y" /* yacc.c:1646  */
    {
																					(yyval.lnum) = getFreeTableIndex();
																					table[(yyval.lnum)].code = table[(yyvsp[-4].lnum)].code;
																					string startLabel = newLabel();
																					string outLabel = blockExit.top();
																					table[(yyval.lnum)].code += table[(yyvsp[-1].lnum)].temp;
																					table[(yyval.lnum)].code += "goto " + startLabel + "\n";
																					table[(yyval.lnum)].code += table[(yyvsp[-1].lnum)].code;
																					table[(yyval.lnum)].code += "goto " + outLabel + "\n";
																					table[(yyval.lnum)].code += startLabel + ":\n";
																					map<string, string> *temp = table[(yyvsp[-1].lnum)].labelMap;
																					for(map<string, string>::iterator iter = temp->begin();iter!=temp->end();iter++)
																					{
																						if((iter->first) == "default")
																							continue;
																						string expvar = table[(yyvsp[-4].lnum)].place;
																						table[(yyval.lnum)].code += "if " + iter->first + " == " + expvar + ", goto " + iter->second + "\n";
																					}
																					if((*temp)["default"].length()!=0)
																						table[(yyval.lnum)].code += "goto " + (*temp)["default"] + "\n";
																					table[(yyval.lnum)].code += outLabel + ":\n";
																					blockExit.pop();
																					mainTableIndex = (yyval.lnum);
																				}
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 226 "while.y" /* yacc.c:1646  */
    {
													(yyval.lnum) = getFreeTableIndex();
													table[(yyval.lnum)].temp = table[(yyvsp[-4].lnum)].temp + table[(yyvsp[-2].lnum)].code;
													string startLabel = newLabel();
													map<string, string> *temp = table[(yyvsp[-4].lnum)].labelMap;
													table[(yyval.lnum)].labelMap = temp;
													(*temp)[table[(yyvsp[-2].lnum)].place] = startLabel;
													table[(yyval.lnum)].code = table[(yyvsp[-4].lnum)].code;
													table[(yyval.lnum)].code += startLabel + ":\n";
													table[(yyval.lnum)].code += table[(yyvsp[0].lnum)].code;
													mainTableIndex = (yyval.lnum);
												}
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 238 "while.y" /* yacc.c:1646  */
    {
													(yyval.lnum) = getFreeTableIndex();
													table[(yyval.lnum)].temp = table[(yyvsp[-3].lnum)].temp;
													string startLabel = newLabel();
													map<string, string> *temp = table[(yyvsp[-3].lnum)].labelMap;
													table[(yyval.lnum)].labelMap = temp;
													if((*temp).find("default")!=(*temp).end())
													{
														cout<<"\nMore than 1 default statements in a switch body\n";
														exit(1);
													}
													(*temp)["default"] = startLabel;
													table[(yyval.lnum)].code = table[(yyvsp[-3].lnum)].code;
													table[(yyval.lnum)].code += startLabel + ":\n";
													table[(yyval.lnum)].code += table[(yyvsp[0].lnum)].code;
													mainTableIndex = (yyval.lnum);
												}
#line 1702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 255 "while.y" /* yacc.c:1646  */
    {
													(yyval.lnum) =getFreeTableIndex();
													map<string, string> *temp = new map<string, string>;
													table[(yyval.lnum)].labelMap = temp;
													table[(yyval.lnum)].code = "";
													table[(yyval.lnum)].temp = "";
													mainTableIndex = (yyval.lnum);
												}
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 265 "while.y" /* yacc.c:1646  */
    {
													(yyval.lnum) = getFreeTableIndex();
													table[(yyval.lnum)].code = table[(yyvsp[-1].lnum)].code + table[(yyvsp[0].lnum)].code;
													mainTableIndex = (yyval.lnum);
												}
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 270 "while.y" /* yacc.c:1646  */
    {
													(yyval.lnum) = getFreeTableIndex();
													table[(yyval.lnum)].code = "";
													mainTableIndex = (yyval.lnum);
												}
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 277 "while.y" /* yacc.c:1646  */
    {
													(yyval.lnum) = getFreeTableIndex();
													if(blockExit.empty())
													{
														cout<<"\nBreak statement written outside a valid block\n";
															exit(1);
													}
													table[(yyval.lnum)].code = "goto " + blockExit.top() + "\n";
													mainTableIndex = (yyval.lnum);
												}
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 289 "while.y" /* yacc.c:1646  */
    {
												(yyval.lnum) = getFreeTableIndex();
												string falseLabel;
												if(table[(yyvsp[0].lnum)].after.length()==0)
													falseLabel = newLabel();
												else
													falseLabel = table[(yyvsp[0].lnum)].after;
												table[(yyval.lnum)].code = table[(yyvsp[-2].lnum)].code;
												string boolCode;
												if(table[(yyvsp[-2].lnum)].type=="bool")
													boolCode = "if FALSE " + table[(yyvsp[-2].lnum)].place + ", goto " + falseLabel + "\n";
												else
													boolCode = "if " + table[(yyvsp[-2].lnum)].place + " == 0, goto " + falseLabel + "\n";
												table[(yyval.lnum)].code += boolCode + table[(yyvsp[0].lnum)].code;
												if(table[(yyvsp[0].lnum)].after.length()==0)
													table[(yyval.lnum)].code += falseLabel + ":\n";
												table[(yyvsp[0].lnum)].after = falseLabel;
												table[(yyval.lnum)].after = falseLabel;
												mainTableIndex = (yyval.lnum);
											}
#line 1775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 309 "while.y" /* yacc.c:1646  */
    {
												(yyval.lnum) = getFreeTableIndex();
												string falseLabel, outLabel;
												falseLabel = newLabel();
												if(table[(yyvsp[0].lnum)].after.length()==0)
													outLabel = newLabel();
												else
													outLabel = table[(yyvsp[0].lnum)].after;
												table[(yyval.lnum)].code = table[(yyvsp[-4].lnum)].code;
												string boolCode;
												if(table[(yyvsp[-4].lnum)].type=="bool")
													boolCode = "if FALSE " + table[(yyvsp[-4].lnum)].place + ", goto " + falseLabel + "\n";
												else
													boolCode = "if " + table[(yyvsp[-4].lnum)].place + " == 0, goto " + falseLabel + "\n";
												table[(yyval.lnum)].code += boolCode + table[(yyvsp[-2].lnum)].code;
												table[(yyval.lnum)].code += "goto " + outLabel + "\n";
												table[(yyval.lnum)].code += falseLabel + ":\n";
												table[(yyval.lnum)].code += table[(yyvsp[0].lnum)].code;
												if(table[(yyvsp[0].lnum)].after.length()==0)
													table[(yyval.lnum)].code += outLabel + ":\n";
												table[(yyvsp[0].lnum)].after = outLabel;
												table[(yyval.lnum)].after = outLabel;
												mainTableIndex = (yyval.lnum);
											}
#line 1804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 335 "while.y" /* yacc.c:1646  */
    {
									(yyval.lnum) = getFreeTableIndex();
									if(isDeclared(string((yyvsp[-2].lstr))))
									{
										cout<<"\nVariable "<<(yyvsp[-2].lstr)<<" declared more than once\n";
										exit(1);
									}
									varType[string((yyvsp[-2].lstr))] = string((yyvsp[-3].lstr));
									table[(yyval.lnum)].code = "assign " + string((yyvsp[-2].lstr)) + ", " + myitoa(getVarSize(string((yyvsp[-3].lstr)))) + "\n";
									string tempCode = string((yyvsp[-2].lstr)) + " = " + table[(yyvsp[-1].lnum)].place + "\n";
									table[(yyval.lnum)].code += table[(yyvsp[-1].lnum)].code + tempCode;
									
									string reqType = getCombinedType(varType[string((yyvsp[-2].lstr))], table[(yyvsp[-1].lnum)].type);
									if(reqType!=varType[string((yyvsp[-2].lstr))])
									{
										cout<<"\nVariable "<<(yyvsp[-2].lstr)<<"'s type doesn't match with expression type:\n";
										cout<<"Required : "<<varType[string((yyvsp[-2].lstr))];
										cout<<"\nFound : "<<reqType<<endl;
										exit(1);
									}
									mainTableIndex = (yyval.lnum);
								}
#line 1831 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 360 "while.y" /* yacc.c:1646  */
    {
									(yyval.lnum) = getFreeTableIndex();
									table[(yyval.lnum)] = table[(yyvsp[0].lnum)];
									mainTableIndex = (yyval.lnum);
								}
#line 1841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 365 "while.y" /* yacc.c:1646  */
    {
									(yyval.lnum) = getFreeTableIndex();
									table[(yyval.lnum)].place = "0";
									table[(yyval.lnum)].type = "bool";
									mainTableIndex = (yyval.lnum);
								}
#line 1852 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 374 "while.y" /* yacc.c:1646  */
    {
									if(!isDeclared(string((yyvsp[-3].lstr))))
									{
										cout<<"\nVariable "<<(yyvsp[-3].lstr)<<" not declared before use\n";
										exit(1);
									}
									(yyval.lnum) = getFreeTableIndex();
									cout<<"\nCurrent ID = "<<(yyvsp[-3].lstr)<<endl;
									string tempCode = string((yyvsp[-3].lstr)) + " = " + table[(yyvsp[-1].lnum)].place + "\n";
									table[(yyval.lnum)].code = table[(yyvsp[-1].lnum)].code + tempCode;
									string reqType = getCombinedType(varType[string((yyvsp[-3].lstr))], table[(yyvsp[-1].lnum)].type);
									if(reqType!=varType[string((yyvsp[-3].lstr))])
									{
										cout<<"\nVariable "<<(yyvsp[-3].lstr)<<"'s type doesn't match with expression type:\n";
										cout<<"Required : "<<varType[string((yyvsp[-3].lstr))];
										cout<<"\nFound : "<<reqType<<endl;
										exit(1);
									}
									mainTableIndex = (yyval.lnum);
								}
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 394 "while.y" /* yacc.c:1646  */
    {
									if(!isDeclared(string((yyvsp[-3].lstr))))
									{
										cout<<"\nVariable "<<(yyvsp[-3].lstr)<<" not declared before use\n";
										exit(1);
									}
									(yyval.lnum) = getFreeTableIndex();
									cout<<"\nCurrent ID = "<<(yyvsp[-3].lstr)<<endl;
									string tempCode = string((yyvsp[-3].lstr)) + " = " + string((yyvsp[-3].lstr)) + " + " + table[(yyvsp[-1].lnum)].place + "\n";
									table[(yyval.lnum)].code = table[(yyvsp[-1].lnum)].code + tempCode;
									string reqType = getCombinedType(varType[string((yyvsp[-3].lstr))], table[(yyvsp[-1].lnum)].type);
									if(reqType!=varType[string((yyvsp[-3].lstr))])
									{
										cout<<"\nVariable "<<(yyvsp[-3].lstr)<<"'s type doesn't match with expression type:\n";
										cout<<"Required : "<<varType[string((yyvsp[-3].lstr))];
										cout<<"\nFound : "<<reqType<<endl;
										exit(1);
									}
									mainTableIndex = (yyval.lnum);
								}
#line 1902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 414 "while.y" /* yacc.c:1646  */
    {
									if(!isDeclared(string((yyvsp[-3].lstr))))
									{
										cout<<"\nVariable "<<(yyvsp[-3].lstr)<<" not declared before use\n";
										exit(1);
									}
									(yyval.lnum) = getFreeTableIndex();
									cout<<"\nCurrent ID = "<<(yyvsp[-3].lstr)<<endl;
									string tempCode = string((yyvsp[-3].lstr)) + " = " + string((yyvsp[-3].lstr)) + " - " + table[(yyvsp[-1].lnum)].place + "\n";
									table[(yyval.lnum)].code = table[(yyvsp[-1].lnum)].code + tempCode;
									string reqType = getCombinedType(varType[string((yyvsp[-3].lstr))], table[(yyvsp[-1].lnum)].type);
									if(reqType!=varType[string((yyvsp[-3].lstr))])
									{
										cout<<"\nVariable "<<(yyvsp[-3].lstr)<<"'s type doesn't match with expression type:\n";
										cout<<"Required : "<<varType[string((yyvsp[-3].lstr))];
										cout<<"\nFound : "<<reqType<<endl;
										exit(1);
									}
									mainTableIndex = (yyval.lnum);
								}
#line 1927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 434 "while.y" /* yacc.c:1646  */
    {
									if(!isDeclared(string((yyvsp[-3].lstr))))
									{
										cout<<"\nVariable "<<(yyvsp[-3].lstr)<<" not declared before use\n";
										exit(1);
									}
									(yyval.lnum) = getFreeTableIndex();
									cout<<"\nCurrent ID = "<<(yyvsp[-3].lstr)<<endl;
									string tempCode = string((yyvsp[-3].lstr)) + " = " + string((yyvsp[-3].lstr)) + " * " + table[(yyvsp[-1].lnum)].place + "\n";
									table[(yyval.lnum)].code = table[(yyvsp[-1].lnum)].code + tempCode;
									string reqType = getCombinedType(varType[string((yyvsp[-3].lstr))], table[(yyvsp[-1].lnum)].type);
									if(reqType!=varType[string((yyvsp[-3].lstr))])
									{
										cout<<"\nVariable "<<(yyvsp[-3].lstr)<<"'s type doesn't match with expression type:\n";
										cout<<"Required : "<<varType[string((yyvsp[-3].lstr))];
										cout<<"\nFound : "<<reqType<<endl;
										exit(1);
									}
									mainTableIndex = (yyval.lnum);
								}
#line 1952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 454 "while.y" /* yacc.c:1646  */
    {
									if(!isDeclared(string((yyvsp[-3].lstr))))
									{
										cout<<"\nVariable "<<(yyvsp[-3].lstr)<<" not declared before use\n";
										exit(1);
									}
									(yyval.lnum) = getFreeTableIndex();
									cout<<"\nCurrent ID = "<<(yyvsp[-3].lstr)<<endl;
									string tempCode = string((yyvsp[-3].lstr)) + " = " + string((yyvsp[-3].lstr)) + " / " + table[(yyvsp[-1].lnum)].place + "\n";
									table[(yyval.lnum)].code = table[(yyvsp[-1].lnum)].code + tempCode;
									string reqType = getCombinedType(varType[string((yyvsp[-3].lstr))], table[(yyvsp[-1].lnum)].type);
									if(reqType!=varType[string((yyvsp[-3].lstr))])
									{
										cout<<"\nVariable "<<(yyvsp[-3].lstr)<<"'s type doesn't match with expression type:\n";
										cout<<"Required : "<<varType[string((yyvsp[-3].lstr))];
										cout<<"\nFound : "<<reqType<<endl;
										exit(1);
									}
									mainTableIndex = (yyval.lnum);
								}
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 477 "while.y" /* yacc.c:1646  */
    {
	  								(yyval.lnum) = getFreeTableIndex();
	  								table[(yyval.lnum)].place = newTemp();
	  								string tempCode = table[(yyval.lnum)].place + " = " + table[(yyvsp[-2].lnum)].place + " || " + table[(yyvsp[0].lnum)].place + "\n";
	  								table[(yyval.lnum)].code = table[(yyvsp[-2].lnum)].code + table[(yyvsp[0].lnum)].code + tempCode;
	  								table[(yyval.lnum)].type = "bool";
	  								mainTableIndex = (yyval.lnum);
	  							}
#line 1990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 485 "while.y" /* yacc.c:1646  */
    {
	  								(yyval.lnum) = getFreeTableIndex();
	  								table[(yyval.lnum)].place = newTemp();
	  								string tempCode = table[(yyval.lnum)].place + " = " + table[(yyvsp[-2].lnum)].place + " && " + table[(yyvsp[0].lnum)].place + "\n";
	  								table[(yyval.lnum)].code = table[(yyvsp[-2].lnum)].code + table[(yyvsp[0].lnum)].code + tempCode;
	  								table[(yyval.lnum)].type = "bool";
	  								mainTableIndex = (yyval.lnum);
	  							}
#line 2003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 494 "while.y" /* yacc.c:1646  */
    {
	  								(yyval.lnum) = getFreeTableIndex();
	  								table[(yyval.lnum)].place = newTemp();
	  								string tempCode = table[(yyval.lnum)].place + " = " + table[(yyvsp[-2].lnum)].place + " | " + table[(yyvsp[0].lnum)].place + "\n";
	  								table[(yyval.lnum)].code = table[(yyvsp[-2].lnum)].code + table[(yyvsp[0].lnum)].code + tempCode;
	  								table[(yyval.lnum)].type = "bool";
	  								mainTableIndex = (yyval.lnum);
	  							}
#line 2016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 502 "while.y" /* yacc.c:1646  */
    {
	  								(yyval.lnum) = getFreeTableIndex();
	  								table[(yyval.lnum)].place = newTemp();
	  								string tempCode = table[(yyval.lnum)].place + " = " + table[(yyvsp[-2].lnum)].place + " & " + table[(yyvsp[0].lnum)].place + "\n";
	  								table[(yyval.lnum)].code = table[(yyvsp[-2].lnum)].code + table[(yyvsp[0].lnum)].code + tempCode;
	  								table[(yyval.lnum)].type = "bool";
	  								mainTableIndex = (yyval.lnum);
	  							}
#line 2029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 510 "while.y" /* yacc.c:1646  */
    {
	  								(yyval.lnum) = getFreeTableIndex();
	  								table[(yyval.lnum)].place = newTemp();
	  								string tempCode = table[(yyval.lnum)].place + " = " + table[(yyvsp[-2].lnum)].place + " ^ " + table[(yyvsp[0].lnum)].place + "\n";
	  								table[(yyval.lnum)].code = table[(yyvsp[-2].lnum)].code + table[(yyvsp[0].lnum)].code + tempCode;
	  								table[(yyval.lnum)].type = "bool";
	  								mainTableIndex = (yyval.lnum);
	  							}
#line 2042 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 519 "while.y" /* yacc.c:1646  */
    {
	  								(yyval.lnum) = getFreeTableIndex();
	  								table[(yyval.lnum)].place = newTemp();
	  								string tempCode = table[(yyval.lnum)].place + " = " + table[(yyvsp[-2].lnum)].place + " == " + table[(yyvsp[0].lnum)].place + "\n";
	  								table[(yyval.lnum)].code = table[(yyvsp[-2].lnum)].code + table[(yyvsp[0].lnum)].code + tempCode;
	  								table[(yyval.lnum)].type = "bool";
	  								mainTableIndex = (yyval.lnum);
	  							}
#line 2055 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 527 "while.y" /* yacc.c:1646  */
    {
	  								(yyval.lnum) = getFreeTableIndex();
	  								table[(yyval.lnum)].place = newTemp();
	  								string tempCode = table[(yyval.lnum)].place + " = " + table[(yyvsp[-2].lnum)].place + " != " + table[(yyvsp[0].lnum)].place + "\n";
	  								table[(yyval.lnum)].code = table[(yyvsp[-2].lnum)].code + table[(yyvsp[0].lnum)].code + tempCode;
	  								table[(yyval.lnum)].type = "bool";
	  								mainTableIndex = (yyval.lnum);
	  							}
#line 2068 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 535 "while.y" /* yacc.c:1646  */
    {
	  								(yyval.lnum) = getFreeTableIndex();
	  								table[(yyval.lnum)].place = newTemp();
	  								string tempCode = table[(yyval.lnum)].place + " = " + table[(yyvsp[-2].lnum)].place + " < " + table[(yyvsp[0].lnum)].place + "\n";
	  								table[(yyval.lnum)].code = table[(yyvsp[-2].lnum)].code + table[(yyvsp[0].lnum)].code + tempCode;
	  								table[(yyval.lnum)].type = "bool";
	  								mainTableIndex = (yyval.lnum);
	  							}
#line 2081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 543 "while.y" /* yacc.c:1646  */
    {
	  								(yyval.lnum) = getFreeTableIndex();
	  								table[(yyval.lnum)].place = newTemp();
	  								string tempCode = table[(yyval.lnum)].place + " = " + table[(yyvsp[-2].lnum)].place + " <= " + table[(yyvsp[0].lnum)].place + "\n";
	  								table[(yyval.lnum)].code = table[(yyvsp[-2].lnum)].code + table[(yyvsp[0].lnum)].code + tempCode;
	  								table[(yyval.lnum)].type = "bool";
	  								mainTableIndex = (yyval.lnum);
	  							}
#line 2094 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 551 "while.y" /* yacc.c:1646  */
    {
	  								(yyval.lnum) = getFreeTableIndex();
	  								table[(yyval.lnum)].place = newTemp();
	  								string tempCode = table[(yyval.lnum)].place + " = " + table[(yyvsp[-2].lnum)].place + " > " + table[(yyvsp[0].lnum)].place + "\n";
	  								table[(yyval.lnum)].code = table[(yyvsp[-2].lnum)].code + table[(yyvsp[0].lnum)].code + tempCode;
	  								table[(yyval.lnum)].type = "bool";
	  								mainTableIndex = (yyval.lnum);
	  							}
#line 2107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 559 "while.y" /* yacc.c:1646  */
    {
	  								(yyval.lnum) = getFreeTableIndex();
	  								table[(yyval.lnum)].place = newTemp();
	  								string tempCode = table[(yyval.lnum)].place + " = " + table[(yyvsp[-2].lnum)].place + " >= " + table[(yyvsp[0].lnum)].place + "\n";
	  								table[(yyval.lnum)].code = table[(yyvsp[-2].lnum)].code + table[(yyvsp[0].lnum)].code + tempCode;
	  								table[(yyval.lnum)].type = "bool";
	  								mainTableIndex = (yyval.lnum);
	  							}
#line 2120 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 568 "while.y" /* yacc.c:1646  */
    {
	  								(yyval.lnum) = getFreeTableIndex();
	  								table[(yyval.lnum)].place = newTemp();
	  								string tempCode = table[(yyval.lnum)].place + " = " + table[(yyvsp[-2].lnum)].place + " + " + table[(yyvsp[0].lnum)].place + "\n";
	  								table[(yyval.lnum)].code = table[(yyvsp[-2].lnum)].code + table[(yyvsp[0].lnum)].code + tempCode;
	  								table[(yyval.lnum)].type = getCombinedType(table[(yyvsp[-2].lnum)].type, table[(yyvsp[0].lnum)].type);
	  								mainTableIndex = (yyval.lnum);
	  							}
#line 2133 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 576 "while.y" /* yacc.c:1646  */
    {
	  								(yyval.lnum) = getFreeTableIndex();
	  								table[(yyval.lnum)].place = newTemp();
	  								string tempCode = table[(yyval.lnum)].place + " = " + table[(yyvsp[-2].lnum)].place + " - " + table[(yyvsp[0].lnum)].place + "\n";
	  								table[(yyval.lnum)].code = table[(yyvsp[-2].lnum)].code + table[(yyvsp[0].lnum)].code + tempCode;
	  								table[(yyval.lnum)].type = getCombinedType(table[(yyvsp[-2].lnum)].type, table[(yyvsp[0].lnum)].type);
	  								mainTableIndex = (yyval.lnum);
	  							}
#line 2146 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 584 "while.y" /* yacc.c:1646  */
    {
	  								(yyval.lnum) = getFreeTableIndex();
	  								table[(yyval.lnum)].place = newTemp();
	  								string tempCode = table[(yyval.lnum)].place + " = " + table[(yyvsp[-2].lnum)].place + " * " + table[(yyvsp[0].lnum)].place + "\n";
	  								table[(yyval.lnum)].code = table[(yyvsp[-2].lnum)].code + table[(yyvsp[0].lnum)].code + tempCode;
	  								table[(yyval.lnum)].type = getCombinedType(table[(yyvsp[-2].lnum)].type, table[(yyvsp[0].lnum)].type);
	  								mainTableIndex = (yyval.lnum);
	  							}
#line 2159 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 592 "while.y" /* yacc.c:1646  */
    {
	  								(yyval.lnum) = getFreeTableIndex();
	  								table[(yyval.lnum)].place = newTemp();
	  								string tempCode = table[(yyval.lnum)].place + " = " + table[(yyvsp[-2].lnum)].place + " / " + table[(yyvsp[0].lnum)].place + "\n";
	  								table[(yyval.lnum)].code = table[(yyvsp[-2].lnum)].code + table[(yyvsp[0].lnum)].code + tempCode;
	  								table[(yyval.lnum)].type = getCombinedType(table[(yyvsp[-2].lnum)].type, table[(yyvsp[0].lnum)].type);
	  								mainTableIndex = (yyval.lnum);
	  							}
#line 2172 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 601 "while.y" /* yacc.c:1646  */
    {
	  								(yyval.lnum) = getFreeTableIndex();
	  								table[(yyval.lnum)].place = newTemp();
	  								string tempCode = table[(yyval.lnum)].place + " = " + table[(yyvsp[-2].lnum)].place + " @ " + table[(yyvsp[0].lnum)].place + "\n";
	  								table[(yyval.lnum)].code = table[(yyvsp[-2].lnum)].code + table[(yyvsp[0].lnum)].code + tempCode;
	  								table[(yyval.lnum)].type = table[(yyvsp[-2].lnum)].type;
	  								mainTableIndex = (yyval.lnum);
	  							}
#line 2185 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 610 "while.y" /* yacc.c:1646  */
    {
	  								(yyval.lnum) = getFreeTableIndex();
									table[(yyval.lnum)].place = newTemp();
	  								string tempCode = table[(yyval.lnum)].place + " = NOT " + table[(yyvsp[0].lnum)].place + "\n";
	  								table[(yyval.lnum)].code = table[(yyvsp[0].lnum)].code + tempCode;
	  								table[(yyval.lnum)].type = table[(yyvsp[0].lnum)].type;
	  								mainTableIndex = (yyval.lnum);
								}
#line 2198 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 618 "while.y" /* yacc.c:1646  */
    {
	  								(yyval.lnum) = getFreeTableIndex();
									table[(yyval.lnum)].place = newTemp();
	  								string tempCode = table[(yyval.lnum)].place + " = NOT " + table[(yyvsp[0].lnum)].place + "\n";
	  								table[(yyval.lnum)].code = table[(yyvsp[0].lnum)].code + tempCode;
	  								table[(yyval.lnum)].type = table[(yyvsp[0].lnum)].type;
	  								mainTableIndex = (yyval.lnum);
								}
#line 2211 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 627 "while.y" /* yacc.c:1646  */
    {
	  								(yyval.lnum) = getFreeTableIndex();
									table[(yyval.lnum)] = table[(yyvsp[-1].lnum)];
									mainTableIndex = (yyval.lnum);
								}
#line 2221 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 632 "while.y" /* yacc.c:1646  */
    {
	  								if(!isDeclared(string((yyvsp[0].lstr))))
	  								{
	  									cout<<"\nVariable "<<(yyvsp[0].lstr)<<" not declared before use\n";
	  									exit(1);
	  								}
	  								(yyval.lnum) = getFreeTableIndex();
									table[(yyval.lnum)].place = string((yyvsp[0].lstr));
									table[(yyval.lnum)].type = varType[string((yyvsp[0].lstr))];
									mainTableIndex = (yyval.lnum);
								}
#line 2237 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 643 "while.y" /* yacc.c:1646  */
    {
									int numval = atoi((yyvsp[0].lstr));
									(yyval.lnum) = getFreeTableIndex();
									table[(yyval.lnum)].place = newTemp();
									table[(yyval.lnum)].code = table[(yyval.lnum)].place + " = " + string((yyvsp[0].lstr)) + "\n";
									
									if(numval==0 || numval==1)
										table[(yyval.lnum)].type = "bool";
									else
										table[(yyval.lnum)].type = "uint";
									mainTableIndex = (yyval.lnum);
								}
#line 2254 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2258 "y.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 657 "while.y" /* yacc.c:1906  */


int main()
{
	yyparse();
	
	cout<<"\n\nGenerated 3-address code : \n\n";
	cout<<table[mainTableIndex].code<<endl;
	
	return 0;
}
