%option noyywrap

%{
#include "grammar.tab.h"
#define YY_DECL int yylex(yy::parser::value_type *val)
%}

%%

";" return ';';
"+" return '+';

0|[1-9][0-9]* {
	*val = atoi(yytext);
	return yy::parser::token::NUMBER;
}

[ \t\r\n] ;

%%


