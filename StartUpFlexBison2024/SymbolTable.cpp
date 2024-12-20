#include "SymbolTable.h"

SymbolTable* SymbolTable::_instance = NULL;

SymbolTable::SymbolTable(){
	table = new map<std::string, CNode*>();
}

CNode* SymbolTable::GetSymbol(string symbolName) {
	map<std::string,CNode *>::iterator it = table->find(symbolName);
	if (it != table->end()) {
		return it->second;
	}
	else {
		CNode* node = new CVARIABLE(symbolName);
		table->insert(pair<string, CNode*>(symbolName, node));
		return node;
	}
}

