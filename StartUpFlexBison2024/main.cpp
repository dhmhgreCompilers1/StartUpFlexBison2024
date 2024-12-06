

#include "grammar.tab.h"
extern FILE* yyin;

int main(int argc, char** argv) {
	CNode *_root;
	fopen_s(&yyin, argv[1], "r");
	yy::parser parser;
	parser.parse();
	_root = root;
	return 0;
}