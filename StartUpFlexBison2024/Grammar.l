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
"int" return yy::parser::token::INT;
"float" return yy::parser::token::FLOAT;
"char" return yy::parser::token::CHAR;
"double" return yy::parser::token::DOUBLE;
"while" return yy::parser::token::WHILE;
"do" return yy::parser::token::DO;
"for" return yy::parser::token::FOR;
"if" return yy::parser::token::IF;
"else" return yy::parser::token::ELSE;
"return" return yy::parser::token::RETURN;
"break" return yy::parser::token::BREAK;
"continue" return yy::parser::token::CONTINUE;

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
	val->node = new CINTEGER(atoi(yytext));	
	return yy::parser::token::INTEGER;
}

[1-9][0-9]*\.[0-9]+([eE][+-]?[0-9]+)? {
	val->node = new CFLOAT(atof(yytext));
	return yy::parser::token::FLOAT;
}


[a-zA-Z][a-zA-Z0-9]* {
	val->node = new CIDENTIFIER(yytext);
	return yy::parser::token::IDENTIFIER;
}


[ \t]									{ loc->step (); }
[\r\n]									{ loc->lines(1);}
%%


