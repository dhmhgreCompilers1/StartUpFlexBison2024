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
%define parse.error verbose
%locations


%start translation_unit
%token <node> NUMBER IDENTIFIER NE GE LE AND OR INT
FLOAT CHAR DOUBLE WHILE DO FOR IF ELSE RETURN BREAK CONTINUE
%nonassoc IFPREC
%right '='
%left AND 
%left OR
%left GE LE '>' '<' EQ NE
%left '+' '-' 
%left '*' '/' '%'
%left '^'
%right '!'
%nonassoc ELSE
%type <node> expression  declarations declaration function_declarations
function_declaration parameter_list parameter type_specifier statements
statement compound_statement while_statement do_while_statement
for_statement if_statement continue_statement break_statement 
return_statement  argument_list translation_unit
%%

translation_unit: declarations function_declarations statements	{ root = $$ = new CTranslationUnit(3,$1,$2,$3);}
			| declarations statements { root = $$ = new CTranslationUnit(2,$1,$2);}
			| function_declarations statements { root = $$ = new CTranslationUnit(2,$1,$2);}
			| statements { root = $$ = new CTranslationUnit(1,$1);}
			;

declarations: declarations declaration { $$ = new CDeclarations(2,$1,$2); }
			| declaration { $$ = new CDeclarations(1,$1); }
			;

declaration: type_specifier IDENTIFIER ';' 	{ $$ = new CDeclaration(2,$1,$2); }		
			;

function_declarations: function_declarations function_declaration { $$ = new CFunctionDeclarations(2,$1,$2); }
			| function_declaration { $$ = new CFunctionDeclarations(1,$1); }
			;


function_declaration: type_specifier IDENTIFIER '(' parameter_list ')' '{' declarations statements '}' { $$ = new CFunctionDeclaration(5,$1,$2,$4,$7,$8); }  
					| type_specifier IDENTIFIER '(' parameter_list ')' '{' declarations '}' { $$ = new CFunctionDeclaration(4,$1,$2,$4,$7); }
					| type_specifier IDENTIFIER '(' parameter_list ')' '{' statements '}' { $$ = new CFunctionDeclaration(4,$1,$2,$4,$7); }
					| type_specifier IDENTIFIER '(' parameter_list ')' '{' '}' { $$ = new CFunctionDeclaration(3,$1,$2,$4); }
			;
parameter_list: parameter_list ',' parameter { $$ = new CParameterList(2,$1,$3); }
			| parameter { $$ = new CParameterList(1,$1); }
			;
parameter: type_specifier IDENTIFIER { $$ = new CParameter(2,$1,$2); }
			;

type_specifier: INT  { $$ = new CTypeSpecifier(INT); }
			| FLOAT  { $$ = new CTypeSpecifier(FLOAT); } 
			| DOUBLE { $$ = new CTypeSpecifier(DOUBLE); }
			| CHAR { $$ = new CTypeSpecifier(CHAR); } 
			;

statements: statements statement { $$ = new CStatements(2,$1,$2); }
			| statement { $$ = new CStatements(1,$1); }
			;

statement : expression ';' { $$ = new CExpressionStatement(1,$1); }
		  | do_while_statement { $$ = new CDoWhileStatement(1,$1); }
		  | while_statement { $$ = new CWhileStatement(1,$1); }
		  | if_statement { $$ = new CIfStatement(1,$1); }
		  | for_statement { $$ = new CForStatement(1,$1); }
		  | return_statement { $$ = new CReturnStatement(1,$1);}		  
		  | break_statement  { $$ = new CBreakStatement(); }
		  | continue_statement { $$ = new CContinueStatement(); }
		  | ';'   { $$ = new CEmptyStatement(); }
		  | compound_statement { $$ = new CCompoundStatement(1,$1); }
		  ;

compound_statement: '{' statements '}' { $$ = new CCompoundStatement(1,$2); }
				 | '{'  '}' { $$ = new CCompoundStatement(0); }
				;

while_statement:  WHILE '(' expression ')' statement { $$ = new CWhileStatement(2,$3,$5); }
				;
do_while_statement: DO statement WHILE '(' expression ')' ';' { $$ = new CDoWhileStatement(2,$2,$5); }
				;
for_statement: FOR '(' expression ';' expression ';' expression ')' statement { $$ = new CForStatement(4,$3,$5,$7,$9); }
			 | FOR '(' expression ';' expression ';' ')' statement { $$ = new CForStatement(3,$3,$5,$8); }
			 | FOR '(' expression ';' ';' expression ')' statement { $$ = new CForStatement(3,$3,$6,$8); }
			 | FOR '(' expression ';' ';' ')' statement { $$ = new CForStatement(2,$3,$7); }
			 | FOR '(' ';' expression ';' expression ')' statement { $$ = new CForStatement(3,$4,$6,$8); }
			 | FOR '(' ';' expression ';' ')' statement { $$ = new CForStatement(2,$4,$7); }
			 | FOR '(' ';' ';' expression ')' statement { $$ = new CForStatement(2,$5,$7); }
			 | FOR '(' ';' ';' ')' statement { $$ = new CForStatement(0); }
			 ;
if_statement: IF '(' expression ')' statement  %prec IFPREC { $$= new CIfStatement(2,$3,$5); }
		| IF '(' expression ')' statement ELSE statement  { $$ = new CIfStatement(3,$3,$5,$7); }
		;

continue_statement: CONTINUE ';' { $$ = new CContinueStatement(); }
				;
break_statement: BREAK ';' { $$ = new CBreakStatement(); }
				;
return_statement: RETURN expression ';'	{ $$ = new CReturnStatement(1,$2); }
				| RETURN ';' { $$ = new CReturnStatement(0); }
				;

expression : 
    expression '+' expression	{ $$ = new CAddition(2,$1,$3); }
  | expression '-' expression	{ $$ = new CSubtraction(2,$1,$3); }
  | expression '*' expression	{ $$ = new CMultiplication(2,$1,$3); }
  | expression '/' expression	{ $$ = new CDivision(2,$1,$3); }	 
  | expression '%' expression	{ $$ = new CModulo(2,$1,$3); }	 
  | IDENTIFIER '=' expression	{ $$ = new CAssignment(2,$1,$3); }
  | '-' expression	{ $$ = new CNegation(1,$2); }
  | '+' expression	{ $$ = new CIdentity(1,$2); }
  | expression '^' expression	{ $$ = new CPower(2,$1,$3); }
  | '(' expression ')'	{ $$ = $2; }
  | expression '>' expression { $$ = new CGreaterThan(2,$1,$3); }
  | expression '<' expression { $$ = new CLessThan(2,$1,$3); }
  | expression EQ expression { $$ = new CEqual(2,$1,$3); }
  | expression NE expression { $$ = new CNotEqual(2,$1,$3); }
  | expression GE expression { $$ = new CGreaterEqual(2,$1,$3); }
  | expression LE expression { $$ = new CLessEqual(2,$1,$3); }
  | expression AND expression { $$ = new CAnd(2,$1,$3); }
  | expression OR expression { $$ = new COr(2,$1,$3); }
  | '!' expression { $$ = new CNot(1,$2); }
  | IDENTIFIER { $$=$1; }
  | IDENTIFIER '(' argument_list ')' { $$ = new CFunctionCall(2,$1,$3); }
  | NUMBER  	{ $$=$1; }
	;

argument_list: argument_list  ',' expression  { $$ = new CArgumentList(2,$1,$3);  }
	| expression				{ root= $$ = new CArgumentList(1,$1); } 
	;

%%


void yy::parser::error(const location_type& loc, const std::string& msg){
	std::cerr << msg << " at "<< loc <<  std::endl;
}