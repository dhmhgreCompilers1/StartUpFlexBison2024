%language "C++"

%{
#include <iostream>
#include <stdlib.h>
#include "grammar.tab.h"
extern int yylex(yy::parser::value_type *val);
extern FILE *yyin;
%}



%start expression_list
%token NUMBER PLUS
%left '+'
%%

// one or more expressions 
expression_list: 
	  expression_list  expression ';' { std::cout << "Result: " << $2 << std::endl; }
	| expression ';'  { std::cout << "Result: " << $1 << std::endl; }
	;
	
expression : 
	  expression '+' expression	{ $$ = $1 + $3;}
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