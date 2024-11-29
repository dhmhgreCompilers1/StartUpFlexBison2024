#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <list>
#include <stdlib.h>
using namespace std;

class CNode {
public :
	CNode(int symbolType, ...);


private:
	list<CNode*> *_children;
	CNode * _parent;
	int _symbolType;
	string _symbolNameGV;
	int _serial;

	static int _serialCounter;
};









#endif

