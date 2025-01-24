%option noyywrap

%{
#include <iostream>
#include <stdlib.h>
#include "grammar.tab.h"
#include "SymbolTable.h"
#include "Tree.h"
#define YY_DECL int yylex(yy::parser::value_type *val, yy::parser::location_type* loc)
#define YY_USER_ACTION loc->columns(yyleng);
%}

%%
 loc->step ();

";" return ';';
"+" return '+';
"-" return '-';
"*" return '*';
"/" return '/';
"^" return '^';
"=" return '=';
"(" return '(';
")" return ')';
"{" return '{';
"}" return '}';
"," return ',';
"%" return '%';
"!=" return yy::parser::token::NE;
"==" return yy::parser::token::EQ;
"<" return '<';
"<=" return yy::parser::token::LE;
">" return '>';
">=" return yy::parser::token::GE;
"&&" return yy::parser::token::AND;
"||" return yy::parser::token::OR;
"!" return '!';



0|[1-9][0-9]* {
	val->node = new CNUMBER(atoi(yytext));	
	return yy::parser::token::NUMBER;
}

[a-zA-Z][a-zA-Z0-9]* {
	//SymbolTable *symbolTable;
	//symbolTable = SymbolTable::GetSymbolTable();
	
	//val->node = symbolTable->GetSymbol(yytext)->node;
	return yy::parser::token::IDENTIFIER;
}


[ \t]									{ loc->step (); }
[\r\n]									{ loc->lines(1);}
%%


