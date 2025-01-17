#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <list>
#include <fstream>
#include <stdlib.h>
#include "SymbolTable.h"
class CNUMBER;
class CNode;
using namespace std;

extern CNode* root;

typedef enum NodeType {
	TRANSLATION_UNIT,
	DECLARATIONS, DECLARATION, FUNCTION_DECLARATIONS, FUNCTION_DECLARATION,
	PARAMETER_LIST, PARAMETER, TYPE_SPECIFIER, STATEMENTS, STATEMENT,
	COMPOUND_STATEMENT, WHILE_STATEMENT, DO_WHILE_STATEMENT, FOR_STATEMENT,
	IF_STATEMENT, CONTINUE_STATEMENT, BREAK_STATEMENT, RETURN_STATEMENT,
	EMPTY_STATEMENT,
	ARGUMENT_LIST, EXPRESSION, SEPARATOR, NUMBER, VARIABLE, ADDITION,
	SUBTRACTION, MULTIPLICATION, DIVISION, ASSIGNMENT, EQUAL, NOT_EQUAL,
	NEGATION, AND, OR, POWER, MODULO, NOT, GREATER, GREATER_EQUAL,
	IDENTITY, LESS_THAN, LESS_EQUAL, GREATER_THAN, FUNCTION_CALL	
} NODETYPE;
extern string g_nodeNames[];


class CNode {
public:
	CNode(NODETYPE symbolType,int count, ...);
	void AppendNodeName(string str);
	void SetNodeName(string str) { _symbolNameGV = str; }
	void SetParent(CNode* parent) { _parent = parent; }
	string GetNodeName() { return _symbolNameGV; }
	NODETYPE GetNodeType() { return _symbolType; }
	int GetSerial() { return _serial; }
	void virtual PrintSyntaxTree(ofstream *file,CNode *parent);
	int virtual Evaluate();

public:
	CNode* _parent;
	list<CNode*>* _children;
	NODETYPE _symbolType;
	string _symbolNameGV; // NODETYPE_SERIALNUMBER_SEMANTICVALUE
	int _serial;
	static int _serialCounter;
};

class CTranslationUnit : public CNode {
public:
	CTranslationUnit(CNode* declarations, CNode* functions, CNode* statements);	
};

class CDeclarations : public CNode{
public :
		CDeclarations(CNode* declarations, CNode* declaration);
		CDeclarations(CNode* declaration);
};

class CDeclaration : public CNode {
public:
	CDeclaration(CNode* typeSpecifier, CNode* identifier);
};

class CFunctionDeclarations : public CNode {
public:
	CFunctionDeclarations(CNode* functionDeclarations, CNode* functionDeclaration);
	CFunctionDeclarations(CNode* functionDeclaration);
};

class CFunctionDeclaration : public CNode {
public:
	CFunctionDeclaration(CNode* typeSpecifier, CNode* identifier, CNode* parameterList, CNode* declarations, CNode* statements);
	CFunctionDeclaration(CNode* typeSpecifier, CNode* identifier, CNode* parameterList, CNode* declarations);
	CFunctionDeclaration(CNode* typeSpecifier, CNode* identifier, CNode* parameterList, CNode* statements);
	CFunctionDeclaration(CNode* typeSpecifier, CNode* identifier, CNode* parameterList);
};

class CParameterList : public CNode {
public:
	CParameterList(CNode* parameterList, CNode* parameter);
	CParameterList(CNode* parameter);
};

class CParameter : public CNode {
public:
	CParameter(CNode* typeSpecifier, CNode* identifier);
};

class CTypeSpecifier : public CNode {
public:
	CTypeSpecifier(SYMBOLTYPE symbolType);
};

class CStatements : public CNode {
public:
		CStatements(CNode* statements, CNode* statement);
	

};

class CStatement : public CNode {
public:
	CStatement(CNode* expression);	
};

class CCompoundStatement : public CNode {
public:	
	CCompoundStatement(CNode* statements);	
};

class CWhileStatement : public CNode {
public:
	CWhileStatement(CNode* expression, CNode* statement);	
};


class CDoWhileStatement : public CNode {
public:
	CDoWhileStatement(CNode* expression, CNode* statement);
};

class CForStatement : public CNode {
public:
	CForStatement(CNode* expression1, CNode* expression2, CNode* expression3, CNode* statement);
};

class CIfStatement : public CNode {
public:	
	CIfStatement(CNode* expression, CNode* statement1, CNode* statement2);
};

class CContinueStatement : public CNode {
public:
};

class CBreakStatement : public CNode {
public:
};

class CReturnStatement : public CNode {
public:
	CReturnStatement(CNode* expression);
};

class CArgumentList : public CNode {
public:
	CArgumentList(CNode* argumentList, CNode* expression);
};

class CExpression : public CNode {
public:
	CExpression(NODETYPE symbolType);
	CExpression(NODETYPE symbolType, CExpression *expr1);
	CExpression(NODETYPE symbolType, CExpression* expr1,CExpression *expr2);
};

class CAddition : public CExpression {
public:
	CAddition(CExpression* expression1, CExpression* expression2);
	int virtual Evaluate() override;
};

class CMultiplication : public CExpression {
public:
	CMultiplication(CExpression* expression1, CExpression* expression2);
};

class CSubtraction : public CExpression {
public:
	CSubtraction(CExpression* expression1, CExpression* expression2);
};

class CDivision : public CExpression {
public:
	CDivision(CExpression* expression1, CExpression* expression2);
};

class CAssignment : public CExpression {
public:
	CAssignment(CExpression* expression1, CExpression* expression2);
};

class CEqual : public CExpression {
	public:
	CEqual(CExpression* expression1, CExpression* expression2);
};

class CNotEqual : public CExpression {
public:
	CNotEqual(CExpression* expression1, CExpression* expression2);
};

class CNegation : public CExpression {
public:
	CNegation(CExpression* expression);
};

class CAnd : public CExpression {
public:
	CAnd(CExpression* expression1, CExpression* expression2);
};

class COr : public CExpression {
public:
	COr(CExpression* expression1, CExpression* expression2);
};

class CPower : public CExpression {
public:
	CPower(CExpression* expression1, CExpression* expression2);
};

class CModulo : public CExpression {
public:
	CModulo(CExpression* expression1, CExpression* expression2);
};

class CNot : public CExpression {
public:
	CNot(CExpression* expression);
};

class CGreater : public CExpression {
public:
	CGreater(CExpression* expression1, CExpression* expression2);
};

class CGreaterEqual : public CExpression {
public:
	CGreaterEqual(CExpression* expression1, CExpression* expression2);
};

class CIdentity: public CExpression {
public:
	CIdentity(CExpression* expression);
};

class CLessThan : public CExpression {
public:
	CLessThan(CExpression* expression1, CExpression* expression2);
};

class CLessEqual : public CExpression {
public:
	CLessEqual(CExpression* expression1, CExpression* expression2);
};

class CGreaterThan : public CExpression {
public:
	CGreaterThan(CExpression* expression1, CExpression* expression2);
};

class CVARIABLE : public CExpression {
public:
	string m_name;
	CVARIABLE(string name);
};

/*class CNumberExpression : CExpression {
public:
	CNumberExpression(CNUMBER value);
};*/

class CNUMBER : public CExpression {
public :
	CNUMBER(int value);
	int m_value;
};















#endif

