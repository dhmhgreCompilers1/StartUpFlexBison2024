%language "C++"

%code requires{
	#include <map>
	#include <string>
	#include "Tree.h"
	using namespace std;
	extern map<string, int> symbol_table;
}

%{
using namespace std;
#include <iostream>
#include <stdlib.h>
#include "Tree.h"
#include "grammar.tab.h"
#include <cmath>
extern int yylex(yy::parser::value_type *val);
extern FILE *yyin;
%}

%union {
	CNode *node;
};

%verbose
%error-verbose


%start expression_list
%token <node> NUMBER IDENTIFIER NE GE LE AND OR
%right '='
%left AND 
%left OR
%left GE LE '>' '<' EQ NE
%left '+' '-' 
%left '*' '/' '%'
%left '^'
%right '!'
%type <node> expression expression_list 
%%

// one or more expressions 
expression_list: 
   expression_list  expression separator { root =$$ = new CExpressionList($1,$2);  }
	| expression separator  { root= $$ = new CExpressionList($1); } 
	;
separator: ';';
	
expression : 
    expression '+' expression	{ $$ = new CAddition((CExpression *)$1,(CExpression *)$3); }
  | expression '-' expression	{ $$ = new CSubtraction((CExpression *)$1,(CExpression *)$3); }
  | expression '*' expression	{ $$ = new CMultiplication((CExpression *)$1,(CExpression *)$3); }
  | expression '/' expression	{ $$ = new CDivision((CExpression *)$1,(CExpression *)$3); }	 
  | expression '%' expression	{ $$ = new CModulo((CExpression *)$1,(CExpression *)$3); }	 
  | IDENTIFIER '=' expression	{ $$ = new CAssignment((CExpression *)$1,(CExpression *)$3); }
  | '-' expression	{ $$ = new CNegation((CExpression *)$2); }
  | '+' expression	{ $$ = new CIdentity((CExpression *)$2); }
  | expression '^' expression	{ $$ = new CPower((CExpression *)$1,(CExpression *)$3); }
  | '(' expression ')'	{ $$ = $2; }
  | expression '>' expression { $$ = new CGreaterThan((CExpression *)$1,(CExpression *)$3); }
  | expression '<' expression { $$ = new CLessThan((CExpression *)$1,(CExpression *)$3); }
  | expression EQ expression { $$ = new CEqual((CExpression *)$1,(CExpression *)$3); }
  | expression NE expression { $$ = new CNotEqual((CExpression *)$1,(CExpression *)$3); }
  | expression GE expression { $$ = new CGreaterEqual((CExpression *)$1,(CExpression *)$3); }
  | expression LE expression { $$ = new CLessEqual((CExpression *)$1,(CExpression *)$3); }
  | expression AND expression { $$ = new CAnd((CExpression *)$1,(CExpression *)$3); }
  | expression OR expression { $$ = new COr((CExpression *)$1,(CExpression *)$3); }
  | '!' expression { $$ = new CNot((CExpression *)$2); }
  | IDENTIFIER { $$=$1; }
  | NUMBER  	{ $$=$1; }
	;


%%


void yy::parser::error(const std::string& msg){
	std::cerr << msg << std::endl;
}