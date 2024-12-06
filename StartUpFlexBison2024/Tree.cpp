#include "Tree.h"
#include <cstdarg>
#include <iostream>

int CNode::_serialCounter = 0;
CNode* root = NULL;

CNode::CNode(NODETYPE symbolType, ...) {
	_symbolType = symbolType;	
	_serial = _serialCounter++;
	_children = new list<CNode*>();
	va_list args;
	va_start(args, symbolType);
	CNode* child = va_arg(args, CNode*);
	while (child != NULL) {
		_children->push_back(child);
		child = va_arg(args, CNode*);
	}
	va_end(args);
}

CExpressionList::CExpressionList(CNode* expression,
	CNode* expressionList) :
CNode(EXPRESSSION_LIST, expression, expressionList) {
}

CExpressionList::CExpressionList(CNode* expression) :
CNode(EXPRESSSION_LIST, expression) {
}


CExpression::CExpression(NODETYPE symbolType, CExpression *expression) :
CNode(symbolType,expression) {
}

CExpression::CExpression(NODETYPE symbolType, CExpression* expression1,
	CExpression* expression2) : CNode(symbolType, expression1, expression2) {
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
}

CNUMBER::CNUMBER(int value) :
CExpression(NUMBER, NULL) {
	m_value = value;
}

