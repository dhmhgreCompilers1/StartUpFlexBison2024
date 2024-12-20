%option noyywrap

%{
#include <iostream>
#include <stdlib.h>
#include "grammar.tab.h"
#include "SymbolTable.h"
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
	val->node = new CNUMBER(atoi(yytext));	
	return yy::parser::token::NUMBER;
}

[a-zA-Z][a-zA-Z0-9]* {
	SymbolTable *symbolTable;
	symbolTable = SymbolTable::GetSymbolTable();
	
	val->node = symbolTable->GetSymbol(yytext);
	return yy::parser::token::IDENTIFIER;
}


[ \t\n\r] ;

%%


