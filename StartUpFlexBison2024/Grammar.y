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
%token NUMBER IDENTIFIER
%left '+' '-' 
%left '*' '/'
%left '^'
%right '='
%%

// one or more expressions 
expression_list: 
	  expression_list  expression separator {  }
	| expression separator  {  }
	;
separator: ';';
	
expression : 
	   expression '+' expression	{ }
	 | expression '-' expression	{ }
	 | expression '*' expression	{ }
	 | expression '/' expression	{ }
	 | expression '^' expression	{ }
	 | IDENTIFIER '=' expression	{ }
	 | IDENTIFIER 
	 | NUMBER  {  }	
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