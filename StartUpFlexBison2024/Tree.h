#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <list>
#include <fstream>
#include <stdlib.h>
#include "SymbolTable.h"
class CINTEGER;
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
	ARGUMENT_LIST, EXPRESSION, SEPARATOR, INTEGER_, FLOAT_, VARIABLE, ADDITION,
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

#define CONSTRUCTOR(type) type(int params,...);

class CTranslationUnit : public CNode {
public:
	CONSTRUCTOR(CTranslationUnit)
	// CTranslationUnit(int params, ...);
};

class CDeclarations : public CNode{
public :
	CONSTRUCTOR(CDeclarations)
};

class CDeclaration : public CNode {
public:
	CONSTRUCTOR(CDeclaration)
};

class CFunctionDeclarations : public CNode {
public:
	CONSTRUCTOR(CFunctionDeclarations)
};

class CFunctionDeclaration : public CNode {
public:
	CONSTRUCTOR(CFunctionDeclaration)
};

class CParameterList : public CNode {
public:
	CONSTRUCTOR(CParameterList)
};

class CParameter : public CNode {
public:
	CONSTRUCTOR(CParameter)
};

class CTypeSpecifier : public CNode {
public:
	CTypeSpecifier(TYPE_SPECIFIER typespecifier);
};

class CStatements : public CNode {
public:
	CONSTRUCTOR(CStatements)
};

class CStatement : public CNode {
public:
	CONSTRUCTOR(CStatement)
};

class CExpressionStatement : public CNode {
public:
	CONSTRUCTOR(CExpressionStatement)
};

class CCompoundStatement : public CNode {
public:
	CONSTRUCTOR(CCompoundStatement);
};

class CWhileStatement : public CNode {
public:
	CONSTRUCTOR(CWhileStatement)
};

class CDoWhileStatement : public CNode {
public:
	CONSTRUCTOR(CDoWhileStatement)
};

class CForStatement : public CNode {
public:
	CONSTRUCTOR(CForStatement)
};

class CIfStatement : public CNode {
public:
	CONSTRUCTOR(CIfStatement)
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
	CONSTRUCTOR(CReturnStatement)
};

class CEmptyStatement : public CNode {
public:	
	CEmptyStatement();
};

class CArgumentList : public CNode {
public:
	CONSTRUCTOR(CArgumentList)
};

class CExpression : public CNode {
public:
	CExpression(NODETYPE symbolType);	
};

class CAddition : public CExpression {
public:
	CONSTRUCTOR(CAddition)
	int virtual Evaluate() override;
};

class CMultiplication : public CExpression {
public:
	CONSTRUCTOR(CMultiplication)
};

class CSubtraction : public CExpression {
public:
	CONSTRUCTOR(CSubtraction)
};

class CDivision : public CExpression {
public:
	CONSTRUCTOR(CDivision)
};

class CAssignment : public CExpression {
public:
	CONSTRUCTOR(CAssignment)
};

class CEqual : public CExpression {
	public:
		CONSTRUCTOR(CEqual)
};

class CNotEqual : public CExpression {
public:
	CONSTRUCTOR(CNotEqual)
};

class CNegation : public CExpression {
public:
	CONSTRUCTOR(CNegation)
};

class CFunctionCall : public CExpression {
public:
	CONSTRUCTOR(CFunctionCall)
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

class CIDENTIFIER : public CExpression {
public:
	string m_name;
	CIDENTIFIER(string name);
};

/*class CNumberExpression : CExpression {
public:
	CNumberExpression(CINTEGER value);
};*/

class CINTEGER : public CExpression {
public :
	CINTEGER(int value);
	int m_value;
};

class CFLOAT : public CExpression {
public:
    CFLOAT(float value);
    float m_value;
};















#endif

