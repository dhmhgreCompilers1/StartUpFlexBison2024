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


%start expression_list
%token <node> NUMBER IDENTIFIER 
%right '='
%left '+' '-' 
%left '*' '/'
%left '^'
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
  | IDENTIFIER '=' expression	{ $$ = new CAssignment((CExpression *)$1,(CExpression *)$3); }
  | IDENTIFIER { $$=$1; }
  | NUMBER  	{ $$=$1; }
	;


%%


void yy::parser::error(const std::string& msg){
	std::cerr << msg << std::endl;
}