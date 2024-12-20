#include "Tree.h"
#include <cstdarg>
#include <iostream>
#include <string>

int CNode::_serialCounter = 0;
CNode* root = NULL;
string g_nodeNames[] = { "EXPRESSSION_LIST", "EXPRESSION", "SEPARATOR", "NUMBER"
	, "VARIABLE", "ADDITION", "SUBTRACTION", "MULTIPLICATION", "DIVISION", "ASSIGNMENT" };

CNode::CNode(NODETYPE symbolType,int count, ...) {
	_symbolType = symbolType;	
	_serial = _serialCounter++;
	_children = new list<CNode*>();
	va_list args;
	va_start(args, count);
	CNode* child ;
	for ( int i = 0; i < count; i++) {
		child = va_arg(args, CNode*);
		_children->push_back(child);
		child->SetParent(this);				
	}
	va_end(args);
	// SymbolName = NODETYPE_SERIALNUMBER
	_symbolNameGV = g_nodeNames[_symbolType] + "_" + to_string(_serial);
}

void CNode::PrintSyntaxTree(ofstream *file) {

	if ( _parent != NULL) {
		*file << _parent->_symbolNameGV << " -> " << _symbolNameGV << endl;
	}
	(*file) << _symbolNameGV << "[label=\"" << g_nodeNames[_symbolType] << "\"]" << endl;
	
	for (list<CNode*>::iterator it = _children->begin();
		 it != _children->end();
		 it++) {
		(*it)->PrintSyntaxTree(file);
	}
}

CExpressionList::CExpressionList(CNode* expression,
	CNode* expressionList) :
CNode(EXPRESSSION_LIST,2, expression, expressionList) {
}

CExpressionList::CExpressionList(CNode* expression) :
CNode(EXPRESSSION_LIST,1, expression) {
}

CExpression::CExpression(NODETYPE symbolType) :CNode(symbolType, 0) {}


CExpression::CExpression(NODETYPE symbolType, CExpression *expression) :
CNode(symbolType,1,expression) {
}

CExpression::CExpression(NODETYPE symbolType, CExpression* expression1,
	CExpression* expression2) : CNode(symbolType, 2,expression1, expression2) {
}

CAddition::CAddition(CExpression* expression1, CExpression* expression2) :
CExpression(ADDITION, expression1, expression2) {
}

CMultiplication::CMultiplication(CExpression* expression1, CExpression* expression2) :
CExpression(MULTIPLICATION, expression1, expression2) {
}

CSubtraction::CSubtraction(CExpression* expression1, CExpression* expression2) :
CExpression(SUBTRACTION, expression1, expression2) {
}

CDivision::CDivision(CExpression* expression1, CExpression* expression2) :
CExpression(DIVISION, expression1, expression2) {
}

CAssignment::CAssignment(CExpression* expression1, CExpression* expression2) :
CExpression(ASSIGNMENT, expression1, expression2) {
}

CVARIABLE::CVARIABLE(string name) :
CExpression(VARIABLE, NULL) {
	m_name= name;
	AppendNodeName("_" + m_name);
}

CNUMBER::CNUMBER(int value) :
CExpression(NUMBER){
	m_value = value;
	AppendNodeName("_" + to_string(m_value));
}

