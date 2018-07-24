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
    NUMCONST = 259,
    if_key = 260,
    else_key = 261,
    while_key = 262,
    static_key = 263,
    int_key = 264,
    float_key = 265,
    char_key = 266,
    break_key = 267,
    Charcons = 268,
    MAIN = 269,
    INCLUDE = 270,
    Hfile = 271,
    incr = 272,
    decr = 273,
    lt = 274,
    gt = 275,
    neq = 276,
    deq = 277,
    and = 278,
    or = 279,
    not = 280
  };
#endif
/* Tokens.  */
#define ID 258
#define NUMCONST 259
#define if_key 260
#define else_key 261
#define while_key 262
#define static_key 263
#define int_key 264
#define float_key 265
#define char_key 266
#define break_key 267
#define Charcons 268
#define MAIN 269
#define INCLUDE 270
#define Hfile 271
#define incr 272
#define decr 273
#define lt 274
#define gt 275
#define neq 276
#define deq 277
#define and 278
#define or 279
#define not 280

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
