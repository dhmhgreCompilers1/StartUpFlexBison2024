#include "SymbolTable.h"

CScopeSystem *CScopeSystem::instance =nullptr;

SymbolTable::SymbolTable(){
	m_table = new map<std::string, CSymbol*>();
	m_childScopes = new list<SymbolTable*>();

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

void SymbolTable::AddSymbol(CSymbol* symbol) {
	m_table->insert(pair<string, CSymbol*>(symbol->GetName(), symbol));
}


void CScopeSystem::PrintScope(SymbolTable* scope, int level) {
	if (scope == nullptr) return;

	// Print the current scope level
	cout << "Scope Level: " << level << endl;

	// Print all symbols in the current scope
	for (const auto& entry : *(scope->m_table)) {
		cout << "Symbol Name: " << entry.second->GetName() << ", Symbol Type: " << entry.second->type << endl;
	}

	// Recursively print child scopes
	for (SymbolTable* childScope : *(scope->m_childScopes)) {
		PrintScope(childScope, level + 1);
	}
}
