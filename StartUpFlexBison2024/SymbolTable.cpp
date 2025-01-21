#include "SymbolTable.h"

SymbolTable* SymbolTable::ms_instance = NULL;

SymbolTable::SymbolTable(){
	m_table = new map<std::string, CSymbol*>();
}

CSymbol* SymbolTable::GetSymbol(string symbolName) {
	map<std::string,CSymbol *>::iterator it = m_table->find(symbolName);
	if (it != m_table->end()) {
		return it->second;
	}
	else {
		CSymbol* node = new CVariableSymbol(symbolName,Variable);
		m_table->insert(pair<string, CSymbol*>(symbolName, node));
		return node;
	}
}

