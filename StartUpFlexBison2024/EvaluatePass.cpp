

#include "Tree.h"

int CAddition::Evaluate()
{
	int op1, op2;
	list<CNode*>::iterator it = _children->begin();

	// VISIT
	op1 = (*it)->Evaluate();
	it++;
	op2 = (*it)->Evaluate();

	// POSTORDER
	return op1 + op2;
}
