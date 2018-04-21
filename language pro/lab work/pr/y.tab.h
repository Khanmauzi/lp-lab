/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 101 "while.y" /* yacc.c:1909  */
	int lnum; char *lstr; 

#line 121 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
