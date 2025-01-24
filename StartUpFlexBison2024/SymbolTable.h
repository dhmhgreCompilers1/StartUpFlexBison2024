#pragma once
#include <iostream>
#include <list>
#include <map>
#include <string>
class SymbolTable;
class CNode;
using namespace std;

typedef enum SymbolType {
	Variable,
	Function
} SYMBOLTYPE;

typedef enum TypeSpecifier {
	INT,
	DOUBLE,
	FLOAT,
	CHAR,
} TYPE_SPECIFIER;


class CSymbol {
public:
	string name;
	SYMBOLTYPE type;
	CNode* node;
	CSymbol(string name, SYMBOLTYPE type) {
		this->name = name;
		this->type = type;
		node = nullptr;
	}

	string GetName() {
		return name;
	}
};

class CVariableSymbol : public CSymbol {
	union vValue {
		int intValue;
		float floatValue;
		char charValue;
		double doubleValue;
	} value;

	union vValue GetValue() {
		return value;
	}
public:
	CVariableSymbol(string name) :
		CSymbol(name, Variable) {
	}
};

class CFunctionSymbol : public CSymbol {
	CNode* functionBody;
	CFunctionSymbol(string name, CNode* node, CNode* functionBody) :
		CSymbol(name, Function) {
		this->functionBody = functionBody;
	}
};

/*int i=0;				Global Scope
{
	int i=1;			Local Scope Level 1
	// leve1_i
	{
	int i;			    Local Scope Level 2
		i = 2;
	}
	i +=2;
	// i = 3
}
{
	int i;			Local Scope Level 1
		i = 3;
}*/


class SymbolTable {
	friend class CScopeSystem;
private:
	SymbolTable* m_parent;
	list<SymbolTable*>* m_childScopes;
	int m_level;
	map<std::string, CSymbol*>* m_table;

public:
	SymbolTable();
	CSymbol* GetSymbol(string symbolName);
	void AddSymbol(CSymbol* symbol);
};

class CScopeSystem {

	map<string, SymbolTable*>* scopes;
	SymbolTable* currentScope;
	SymbolTable* rootScope;
	static CScopeSystem* instance;

	// Private constructor to prevent instantiation
	CScopeSystem() {
		scopes = new map<string, SymbolTable*>();
		currentScope = rootScope = new SymbolTable();
	}

	// Delete copy constructor and assignment operator
	CScopeSystem(const CScopeSystem&) = delete;
	CScopeSystem& operator=(const CScopeSystem&) = delete;

public:
	// Static method to get the single instance of the class
	static CScopeSystem* GetInstance() {
		if (instance == nullptr) {
			instance = new CScopeSystem();
		}
		return instance;
	}

	void AddSymbol(string symbolName, CSymbol* symbol) {
		currentScope->AddSymbol(symbol);
	}

	CSymbol* GetSymbol(string symbolName) {
		return currentScope->GetSymbol(symbolName);
	}

	void Debug_ScopeSystem() {
		// Debugging function to print the symbol tables
		PrintScope(rootScope, 0);
	}

private:
	void PrintScope(SymbolTable* scope, int level);

	SymbolTable* GetCurrentScope() {
		return currentScope;
	}

	void EnterScope() {
		// Implementation for entering a new scope
	}

	void LeaveScope() {
		// Implementation for leaving the current scope
	}
};
