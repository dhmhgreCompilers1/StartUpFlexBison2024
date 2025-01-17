#pragma once
#include <map>
#include <string>
#include "Tree.h"
class SymbolTable;
using namespace std;

typedef enum SymbolType {
	Integer,
	Float,
	Double,
	Char,
	Function
} SYMBOLTYPE;

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
	CSymbol(string name, SYMBOLTYPE type) {
		this->name = name;
		this->type = type;
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
};

class CFunctionSymbol : public CSymbol {
	CNode* functionBody;	
	CFunctionSymbol(string name, CNode* node, CNode* functionBody) : CSymbol(name, node) {
		this->functionBody = functionBody;		
	}


class SymbolTable {
private:	
	SymbolTable *parent;
	map<std::string, CSymbol*> *table;
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
