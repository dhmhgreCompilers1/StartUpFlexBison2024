#pragma once
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

class CScopeSystem
{
	map<string, SymbolTable*> *scopes;
	SymbolTable * currentScope;

public:
	CScopeSystem() {
		scopes = new map<string, SymbolTable*>();
		currentScope = nullptr;
	}
};


class CSymbol{
	public:
	string name;	
	SYMBOLTYPE type;
	CNode* node;
	CSymbol(string name, SYMBOLTYPE type) {
		this->name = name;
		this->type = type;
		node = nullptr;
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
	CVariableSymbol(string name, SYMBOLTYPE type) :
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


class SymbolTable {
private:	
	SymbolTable *m_parent;
	list<SymbolTable*>* m_childScopes;
	int m_level;
	map<std::string, CSymbol*> *m_table;	
	static SymbolTable *ms_instance;
	SymbolTable();
public:
	CSymbol* GetSymbol(string symbolName);

	static SymbolTable *GetSymbolTable()	{
		if (ms_instance == NULL) {
			ms_instance = new SymbolTable();
		}
		return ms_instance;
		
	}

};
