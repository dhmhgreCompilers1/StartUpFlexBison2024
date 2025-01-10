#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <list>
#include <fstream>
#include <stdlib.h>
class CNUMBER;
class CNode;
using namespace std;

extern CNode* root;

typedef enum NodeType {
	EXPRESSSION_LIST, EXPRESSION, SEPARATOR, NUMBER
	, VARIABLE, ADDITION, SUBTRACTION, MULTIPLICATION, DIVISION, ASSIGNMENT,
	EQUAL, NOT_EQUAL, NEGATION, AND, OR, POWER, MODULO, NOT, GREATER, GREATER_EQUAL, IDENTITY, LESS_THAN, LESS_EQUAL, GREATER_THAN

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

class CExpressionList : public CNode {
public:
	CExpressionList(CNode* expression, CNode* expressionList);
	CExpressionList(CNode* expression);
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

