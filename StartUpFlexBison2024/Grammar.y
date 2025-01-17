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
extern int yylex(yy::parser::value_type *val, yy::parser::location_type* loc);
extern FILE *yyin;
%}

%union {
	CNode *node;
};

%verbose
%error-verbose
%locations


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

translation_unit: declarations function_declarations statements	
			| declarations statements
			| function_declarations statements
			| statements
			;

declarations: declarations declaration
			| declaration
			;

declaration: type_specifier IDENTIFIER ';' 			
			;

function_declarations: function_declarations function_declaration
			| function_declaration
			;


function_declaration: type_specifier IDENTIFIER '(' parameter_list ')' '{' declarations statements '}'
					| type_specifier IDENTIFIER '(' parameter_list ')' '{' declarations '}'
					| type_specifier IDENTIFIER '(' parameter_list ')' '{' statements '}'
					| type_specifier IDENTIFIER '(' parameter_list ')' '{' '}'
			;
parameter_list: parameter_list ',' parameter
			| parameter
			;
parameter: type_specifier IDENTIFIER
			;

type_specifier: INT 
			| FLOAT 
			| DOUBLE 
			| CHAR 
			;

statements: statements statement
			| statement
			;

statement : expression ';'
		  | while_statement
		  | if_statement
		  | for_statement
		  | return_statement
		  | switch_statement
		  | break_statement
		  | continue_statement
		  | ';' /* empty statement */
		  | compound_statement
		  ;

compound_statement: '{' statements '}'
				 | '{'  '}'
				;

while_statement:  WHILE '(' expression ')' statement
				| WHILE '(' expression ')' ';'
				;
do_while_statement: DO statement WHILE '(' expression ')' ';'
				;
for_statement: FOR '(' expression ';' expression ';' expression ')' statement
			 | FOR '(' expression ';' expression ';' ')' statement
			 | FOR '(' expression ';' ';' expression ')' statement
			 | FOR '(' expression ';' ';' ')' statement
			 | FOR '(' ';' expression ';' expression ')' statement
			 | FOR '(' ';' expression ';' ')' statement
			 | FOR '(' ';' ';' expression ')' statement
			 | FOR '(' ';' ';' ')' statement
			 ;
if_statement: IF '(' expression ')' statement
		| IF '(' expression ')' statement ELSE statement
		;

continue_statement: CONTINUE ';'
				;
break_statement: BREAK ';'
				;
return_statement: RETURN expression ';'
				| RETURN ';'
				;

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
  | IDENTIFIER '(' argument_list ')' { $$ = new CFunctionCall($1, $3); })
  | NUMBER  	{ $$=$1; }
	;

argument_list: argument_list  ',' expression  { root =$$ = new CExpressionList($1,$2);  }
	| expression				{ root= $$ = new CExpressionList($1); } 
	;

%%


void yy::parser::error(const location_type& loc, const std::string& msg){
	std::cerr << msg << " at "<< loc <<  std::endl;
}