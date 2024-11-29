#include "Tree.h"
#include <cstdarg>
#include <iostream>

int CNode::_serialCounter = 0;

CNode::CNode(int symbolType, ...) {
	_symbolType = symbolType;
	_parent = nullptr;
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
