%language "C++"

%code requires{
	#include <map>
	#include <string>
	using namespace std;
	extern map<string, int> symbol_table;
}

%{
using namespace std;
#include <iostream>
#include <stdlib.h>
#include "grammar.tab.h"
#include <cmath>
extern int yylex(yy::parser::value_type *val);
extern FILE *yyin;


%}



%start expression_list
%token NUMBER IDENTIFIER
%left '+' '-' 
%left '*' '/'
%left '^'
%right '='
%%

// one or more expressions 
expression_list: 
	  expression_list  expression separator { std::cout << "Result: " << $2 << std::endl; }
	| expression separator  { std::cout << "Result: " << $1 << std::endl; }
	;
separator: ';' | '\n';
	
expression : 
	   expression '+' expression	{ $$ = $1 + $3;}
	 | expression '-' expression	{ $$ = $1 - $3;}
	 | expression '*' expression	{ $$ = $1 * $3;}
	 | expression '/' expression	{ $$ = $1 / $3;}
	 | expression '^' expression	{ $$ = (int)pow((double)$1,(double)($3));}
	 | IDENTIFIER '=' expression	{ $$ = $3; }
	 | IDENTIFIER 
	 | NUMBER  { $$ = $1; }	
	;


%%

int main(int argc, char **argv){
	fopen_s(&yyin, argv[1], "r");
	yy::parser parser;
	parser.parse();
	return 0;
}

void yy::parser::error(const std::string& msg){
	std::cerr << msg << std::endl;
}