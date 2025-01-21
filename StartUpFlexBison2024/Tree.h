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
	PARAMETER_LIST, PARAMETER, TYPESPECIFIER, STATEMENTS, STATEMENT,
	COMPOUND_STATEMENT, WHILE_STATEMENT, DO_WHILE_STATEMENT, FOR_STATEMENT,
	IF_STATEMENT, CONTINUE_STATEMENT, BREAK_STATEMENT, RETURN_STATEMENT,
	EMPTY_STATEMENT, EXPRESSION_STATEMENT,
	ARGUMENT_LIST, EXPRESSION, SEPARATOR, NUMBER, VARIABLE, ADDITION,
	SUBTRACTION, MULTIPLICATION, DIVISION, ASSIGNMENT, EQUAL, NOT_EQUAL,
	NEGATION, AND, OR, POWER, MODULO, NOT, GREATER, GREATER_EQUAL,
	IDENTITY, LESS_THAN, LESS_EQUAL, GREATER_THAN, FUNCTION_CALL	
} NODETYPE;
extern string g_nodeNames[];


class CNode {
public:
	CNode(NODETYPE symbolType);
	void AppendNodeName(string str);
	void SetNodeName(string str) { _symbolNameGV = str; }
	void SetParent(CNode* parent) { _parent = parent; }
	string GetNodeName() { return _symbolNameGV; }
	NODETYPE GetNodeType() { return _symbolType; }
	int GetSerial() { return _serial; }
	void virtual PrintSyntaxTree(ofstream *file,CNode *parent);
	int virtual Evaluate();

protected:
	CNode* _parent;
	list<CNode*>* _children;
	NODETYPE _symbolType;
	string _symbolNameGV; // NODETYPE_SERIALNUMBER_SEMANTICVALUE
	int _serial;
	static int _serialCounter;
};

class CTranslationUnit : public CNode {
public:
	CTranslationUnit(int params,...);	
};

class CDeclarations : public CNode{
public :
		CDeclarations(int params,...);
};

class CDeclaration : public CNode {
public:
	CDeclaration(int params, ...);
};

class CFunctionDeclarations : public CNode {
public:
	CFunctionDeclarations(int params,...);
};

class CFunctionDeclaration : public CNode {
public:
	CFunctionDeclaration(int params, ...);
};

class CParameterList : public CNode {
public:
	CParameterList(int params, ...);
};

class CParameter : public CNode {
public:
	CParameter(int params, ...);
};

class CTypeSpecifier : public CNode {
public:
	CTypeSpecifier(TYPE_SPECIFIER symbolType);
};

class CStatements : public CNode {
public:
		CStatements(int params, ...);
};

class CStatement : public CNode {
public:
	CStatement(int params,...);
};

class CExpressionStatement : public CNode {
public:
	CExpressionStatement(int params, ...);
};

class CCompoundStatement : public CNode {
public:	
	CCompoundStatement(int params, ...);
};

class CWhileStatement : public CNode {
public:
	CWhileStatement(int params, ...);
};


class CDoWhileStatement : public CNode {
public:
	CDoWhileStatement(int params, ...);
};

class CForStatement : public CNode {
public:
	CForStatement(int params, ...);
};

class CIfStatement : public CNode {
public:	
	CIfStatement(int params, ...);
};

class CContinueStatement : public CNode {
public:
	CContinueStatement();
};

class CBreakStatement : public CNode {
public:
	CBreakStatement();
};

class CReturnStatement : public CNode {
public:
	CReturnStatement(int params, ...);
};

class CEmptyStatement : public CNode {
public:
	CEmptyStatement();
};

class CArgumentList : public CNode {
public:
	CArgumentList(int params, ...);
};

class CExpression : public CNode {
public:
	CExpression(NODETYPE symbolType);	
};

class CAddition : public CExpression {
public:
	CAddition(int params, ...);
	int virtual Evaluate() override;
};

class CMultiplication : public CExpression {
public:
	CMultiplication(int params, ...);
};

class CSubtraction : public CExpression {
public:
	CSubtraction(int params, ...);
};

class CDivision : public CExpression {
public:
	CDivision(int params, ...);
};

class CAssignment : public CExpression {
public:
	CAssignment(int params, ...);
};

class CEqual : public CExpression {
	public:
	CEqual(int params, ...);
};

class CNotEqual : public CExpression {
public:
	CNotEqual(int params, ...);
};

class CNegation : public CExpression {
public:
	CNegation(int params, ...);
};

class CFunctionCall : public CExpression {
public:
	CFunctionCall(int params, ...);
};

class CAnd : public CExpression {
public:
	CAnd(int params, ...);
};

class COr : public CExpression {
public:
	COr(int params, ...);
};

class CPower : public CExpression {
public:
	CPower(int params, ...);
};

class CModulo : public CExpression {
public:
	CModulo(int params, ...);
};

class CNot : public CExpression {
public:
	CNot(int params, ...);
};

class CGreater : public CExpression {
public:
	CGreater(int params, ...);
};

class CGreaterEqual : public CExpression {
public:
	CGreaterEqual(int params, ...);
};

class CIdentity: public CExpression {
public:
	CIdentity(int params, ...);
};

class CLessThan : public CExpression {
public:
	CLessThan(int params, ...);
};

class CLessEqual : public CExpression {
public:
	CLessEqual(int params, ...);
};

class CGreaterThan : public CExpression {
public:
	CGreaterThan(int params, ...);
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

