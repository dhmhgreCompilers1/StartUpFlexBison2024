#pragma once
#include <iostream>
#include <fstream>
#include "grammar.tab.h"
#include "SymbolTable.h"
extern FILE* yyin;

class CFacade
{
private:
    static CFacade* instance;
    CScopeSystem* m_scopeSystem;
    string m_sourceFileName;
    yy::parser parser;
    ofstream* dotFile;
    CNode* _root;

    bool b_debugTree;

    // Private constructor to prevent instantiation
    CFacade(bool debugTree);

public:
    // Delete copy constructor and assignment operator
    CFacade(const CFacade&) = delete;
    CFacade& operator=(const CFacade&) = delete;

    static CFacade* GetInstance(bool debugTree = false);
	CScopeSystem* GetScopeSystem() { return m_scopeSystem; }
    void Parse(string m_sourceFileName);
    void EmitParseTree();
};
