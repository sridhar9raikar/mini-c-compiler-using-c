%{
#include<stdio.h>
#include<string.h>
#include "lex.yy.c"
#include "codegen.h"
#include "symbol.h"
void yyerror(const char*);
int yylex();
%}
%error-verbose
%token  ID NUMCONST if_key else_key while_key static_key int_key float_key char_key break_key Charcons MAIN INCLUDE Hfile incr decr lt gt neq deq and or not

%%
Program:{codegen_init();} Header Main {print_struct();}
|{codegen_init();} Main {print_struct();}
;
Header: INC_STMT INC_ANSTMT
;
INC_STMT:INCLUDE '"' Hfile '"'
| INCLUDE '<' Hfile '>'
;
INC_ANSTMT:INC_STMT 
|
;
Main:typeSpecifier MAIN statement 
| MAIN statement
| declarationList 
; 
declarationList:declarationList declaration 
| declaration
;  
declaration:varDeclaration 
;
varDeclaration:typeSpecifier varDeclList ';' 
; 
scopedVarDeclaration:scopedTypeSpecifier varDeclList ';'
; 
varDeclList : varDeclList ',' varDeclInitialize 
| varDeclInitialize
; 
varDeclInitialize : ID {push(lexid);} '='{push("=");} constant {add_id(lextype,lexid,lexval); codegen_assign();}
| varDeclId 
; 

varDeclId : ID      { add_id(lextype,lexid,NULL);}
| ID '[' NUMCONST ']' {add_id("array",lexid,NULL);}
; 
scopedTypeSpecifier : static_key typeSpecifier 
| typeSpecifier
;
typeSpecifier: int_key
|float_key
|char_key
;
statement : expressionStmt 
| compoundStmt 
| selectionStmt 
| iterationStmt 
| breakStmt
; 
compoundStmt : '{' localDeclarations statementList '}'
; 
localDeclarations : localDeclarations scopedVarDeclaration 
| 
;
statementList : statementList statement 
| 
;
expressionStmt : expression ';' 
| ';'
; 
selectionStmt : if_key '(' simpleExpression {codegen_if1();} ')' statement {codegen_if2();} elsestmt
;
elsestmt : else_key statement {codegen_if3();}
| 	{codegen_if4();}
;
iterationStmt : while_key {codegen_while1();} '(' simpleExpression {codegen_while2();} ')' statement {codegen_while3();}
; 
breakStmt : break_key ';'
; 
expression : mutable '=' {push("=");} expression {codegen_assign();}
| mutable  incr 	{push("=");push(lexid);push("+");push("1");codegen_exp();codegen_assign();}
| mutable  decr 	{push("=");push(lexid);push("-");push("1");codegen_exp();codegen_assign();}
| simpleExpression
; 
simpleExpression : simpleExpression or {push("||");} andExpression {codegen_exp();}
| andExpression
; 
andExpression : andExpression and  {push("&&");} unaryRelExpression {codegen_exp();}
| unaryRelExpression 
;
unaryRelExpression : not unaryRelExpression 
| relExpression 
;
relExpression : sumExpression relop sumExpression {codegen_exp();}
| sumExpression 
;
relop : lt 	{push("<=");}
| '<' 	     	{push("<");}
| '>' 		{push(">");}
| gt 		{push(">=");}
| deq 		{push("==");}
| neq		{push("!=");}
; 
sumExpression : sumExpression sumop term  {codegen_exp();}
| term    
;
sumop : '+' {push("+");} 
| '-' 		{push("-");}
;
term : term mulop unaryExpression        {codegen_exp();}
| unaryExpression 
;
mulop : '*' 	{push("*");}
| '/' 		{push("/");}
| '%'		{push("%");}
; 
unaryExpression : unaryop unaryExpression {codegen_umin();}
| factor 
;
unaryop : '-' 	{push("-");}
; 
factor : immutable 
| mutable 
;
mutable : ID {if(search(lexid)==0){printf("%s is undeclared\n",lexid);YYABORT;} push(lexid);} 	
| mutable '[' expression ']'
; 
immutable : constant
|'(' expression ')' 
| call 
;
call : ID '(' args ')' 
;
args : argList 
| 
;
argList : argList ',' expression 
| expression 
;
constant : NUMCONST {push(lexval);}
| Charcons 
;
%%
void yyerror(const char *s){
printf("%s\n ",s);

}

int main(int argc,char *argv[])
{
	/*if(argc!=0) printf("%d",argc);
	else printf("wcdbjhbhce");*/
	if( argc >=1 && strcmp(argv[1],"-o")==0)
	{
		optimize=1;
	}	
	if(!yyparse())
		printf("Valid\n");
	return 0;
}


