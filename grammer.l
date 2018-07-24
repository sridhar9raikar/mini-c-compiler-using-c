id [a-zA-Z]+
num [0-9]+
%{
//#include "abstract_tree.h"
//#define YYSTYPE node*
#include "y.tab.h"
#include "symbol.h"
void yyerror(const char*);
%}

%%
"//"(.*[\t]*.*)*[\n]+ 				; 
"/*"[^*]*"*/"|"/*"[^/]*"*/" 			;
[\t]|[\n]|" "					;
{id}"."{id}					{addtoken("header",yytext);return Hfile;}
"\".*\""					{addtoken("string",yytext);strcpy(lexval,yytext);return Charcons;}
"#include"					{addtoken("keyword",yytext);return INCLUDE;}
"main()"					{addtoken("fun call",yytext);return MAIN;}
"if"						{addtoken("keyword",yytext);return if_key;}
"else"						{addtoken("keyword",yytext);return else_key;}
"while"						{addtoken("keyword",yytext);return while_key;}
"int"						{addtoken("keyword",yytext);strcpy(lextype,yytext);return int_key;}
"float"						{addtoken("keyword",yytext);strcpy(lextype,yytext);return float_key;}
"char"						{addtoken("keyword",yytext);strcpy(lextype,yytext);return char_key;} 
"break"						{addtoken("keyword",yytext);return break_key;}
"&&"						{addtoken("operator",yytext);return and;}
"||"						{addtoken("operator",yytext);return or;}
"++"						{addtoken("operator",yytext);return incr;}
"--"						{addtoken("operator",yytext);return decr;}
"!"						{addtoken("operator",yytext);return not;}
"<="						{addtoken("operator",yytext);return lt;}
">="						{addtoken("operator",yytext);return gt;}
"=="						{addtoken("operator",yytext);return deq;}
"!="						{addtoken("operator",yytext);return neq;}
[a-zA-Z][a-zA-Z0-9]*				{addtoken("identifier",yytext);strcpy(lexid,yytext);return ID;}
[0-9][0-9]*					{addtoken("number",yytext);strcpy(lexval,yytext);return NUMCONST;}
{num}"."{num}					{addtoken("number",yytext);strcpy(lexval,yytext);return NUMCONST;}
.						{addtoken("spc_char",yytext);return *yytext;}
%%
