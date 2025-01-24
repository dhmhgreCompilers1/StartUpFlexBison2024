#pragma once
#include <iostream>
#include <fstream>
#include "grammar.tab.h"
#include "SymbolTable.h"
extern FILE* yyin;
class CFacade
{
private:
	CScopeSystem* m_scopeSystem;
	string m_sourceFileName;
	yy::parser parser;
	ofstream* dotFile;
	CNode* _root;

	bool b_debugTree;
	

public:
	CFacade(bool debugTree);
	void Parse(string m_sourceFileName);
	void EmitParseTree();
};
