#pragma once
#include <map>
#include <string>
#include "Tree.h"
using namespace std;

class SymbolTable {
private:
	map<std::string, CNode*> *table;
	static SymbolTable *_instance;
	SymbolTable();
public:		
	CNode* GetSymbol(string symbolName);

	static SymbolTable *GetSymbolTable()	{
		if (_instance == NULL) {
			_instance = new SymbolTable();
		}
		return _instance;
		
	}

};
