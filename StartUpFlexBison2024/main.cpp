#include <iostream>
#include <fstream>
#include "grammar.tab.h"
extern FILE* yyin;

int main(int argc, char** argv) {
	CNode *_root;
	ofstream *dotFile = new ofstream("graph.dot", ios::out);
	fopen_s(&yyin, argv[1], "r");
	yy::parser parser;
	parser.parse();
	_root = root;

	(*dotFile) << "digraph G{\n";
	root->PrintSyntaxTree(dotFile);
	(*dotFile) << "}\n";
	dotFile->close();
	system("dot -Tgif graph.dot -o graph.gif");
	return 0;
}