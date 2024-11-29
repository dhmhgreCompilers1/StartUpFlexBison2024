%option noyywrap

%{
#include <iostream>
#include <stdlib.h>
#include "grammar.tab.h"
#include "Tree.h"
#define YY_DECL int yylex(yy::parser::value_type *val)
%}

%%

";" return ';';
"+" return '+';
"-" return '-';
"*" return '*';
"/" return '/';
"^" return '^';
"=" return '=';

0|[1-9][0-9]* {
	//val->node = new CNode(1);	
	return yy::parser::token::NUMBER;
}


[ \t\n\r] ;

%%


