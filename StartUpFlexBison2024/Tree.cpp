#include "Tree.h"
#include <cstdarg>
#include <iostream>
#include <string>

int CNode::_serialCounter = 0;
CNode* root = NULL;
string g_nodeNames[] = {
    "TRANSLATION_UNIT",    
    "DECLARATIONS", "DECLARATION", "FUNCTION_DECLARATIONS", "FUNCTION_DECLARATION",
    "PARAMETER_LIST", "PARAMETER", "TYPE_SPECIFIER", "STATEMENTS", "STATEMENT",
    "COMPOUND_STATEMENT", "WHILE_STATEMENT", "DO_WHILE_STATEMENT", "FOR_STATEMENT",
    "IF_STATEMENT", "CONTINUE_STATEMENT", "BREAK_STATEMENT", "RETURN_STATEMENT",
    "EMPTY_STATEMENT",
    "ARGUMENT_LIST", "EXPRESSION", "SEPARATOR", "NUMBER", "VARIABLE", "ADDITION",
    "SUBTRACTION", "MULTIPLICATION", "DIVISION", "ASSIGNMENT", "EQUAL", "NOT_EQUAL",
    "NEGATION", "AND", "OR", "POWER", "MODULO", "NOT", "GREATER", "GREATER_EQUAL",
    "IDENTITY", "LESS_THAN", "LESS_EQUAL", "GREATER_THAN", "FUNCTION_CALL"
};

std::string trimCharacter(const std::string& str, char ch) {
	size_t start = str.find_first_not_of(ch); // Find the first non-ch character
	if (start == std::string::npos) {
		return ""; // String contains only the character to trim
	}

	size_t end = str.find_last_not_of(ch); // Find the last non-ch character
	return str.substr(start, end - start + 1);
}

void CNode::AppendNodeName(string str) {
	trimCharacter(_symbolNameGV, '"');
	_symbolNameGV = "\"" + _symbolNameGV + str + "\"";
} // inline function


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
	_symbolNameGV = "\""+g_nodeNames[_symbolType] + "_" + to_string(_serial) + "\"";
}

void CNode::PrintSyntaxTree(ofstream *file, CNode *parent) {

	if ( parent != NULL) {
		*file << parent->_symbolNameGV << " -> " << _symbolNameGV << endl;
	}
	//(*file) << _symbolNameGV << "[label=\"" << g_nodeNames[_symbolType] << "\"]" << endl;
	
	for (list<CNode*>::iterator it = _children->begin();
   it != _children->end();
   it++) {
		(*it)->PrintSyntaxTree(file,this);
	}
}

int CNode::Evaluate() {

	// PREORDER ACTIONS

	// VISIT CHILDREN
	for (list<CNode*>::iterator it = _children->begin();
		it != _children->end();
		it++) {
		(*it)->Evaluate();
	}

	// POSTORDER ACTIONS
	return 0;
}


CTranslationUnit::CTranslationUnit(CNode* declarations, CNode* functions, CNode* statements) :
CNode(TRANSLATION_UNIT, 3, declarations, functions, statements) {
}

CDeclarations::CDeclarations(CNode* declarations, CNode* declaration) :
CNode(DECLARATIONS, 2, declarations, declaration) {
}

CDeclaration::CDeclaration(CNode* typeSpecifier, CNode* identifier) :
CNode(DECLARATION, 2, typeSpecifier, identifier) {
}

CFunctionDeclarations::CFunctionDeclarations(CNode* functionDeclarations, CNode* functionDeclaration) :


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

int CAddition::Evaluate()
{
	int op1,op2;
	list<CNode*>::iterator it = _children->begin();

	// VISIT
	op1 =  (*it)->Evaluate();
	it++;
	op2 = (*it)->Evaluate();

	// POSTORDER
	return op1+op2;
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

CEqual::CEqual(CExpression* expression1, CExpression* expression2)
: CExpression(EQUAL, expression1, expression2) 
{
}

CNotEqual::CNotEqual(CExpression* expression1, CExpression* expression2)
	: CExpression(NOT_EQUAL, expression1, expression2)
{
}

CNegation::CNegation(CExpression* expression)
	: CExpression(NEGATION, expression)
{
}

CAnd::CAnd(CExpression* expression1, CExpression* expression2)
: CExpression(AND, expression1, expression2){
}

COr::COr(CExpression* expression1, CExpression* expression2)
	: CExpression(OR, expression1, expression2)		
{
}

CPower::CPower(CExpression* expression1, CExpression* expression2)
	: CExpression(POWER, expression1, expression2)
{
}

CModulo::CModulo(CExpression* expression1, CExpression* expression2)
	: CExpression(MODULO, expression1, expression2)

{
}

CNot::CNot(CExpression* expression)
	: CExpression(NOT, expression)
{
}

CGreater::CGreater(CExpression* expression1, CExpression* expression2)
	: CExpression(GREATER, expression1, expression2)
{
}

CGreaterEqual::CGreaterEqual(CExpression* expression1, CExpression* expression2)
	: CExpression(GREATER_EQUAL, expression1, expression2)
{
}

CIdentity::CIdentity(CExpression* expression)
	:	 CExpression(IDENTITY, expression)
{
}

CLessThan::CLessThan(CExpression* expression1, CExpression* expression2)
	: CExpression(LESS_THAN, expression1, expression2)

{
}

CLessEqual::CLessEqual(CExpression* expression1, CExpression* expression2)
	: CExpression(LESS_EQUAL, expression1, expression2)
{
}

CGreaterThan::CGreaterThan(CExpression* expression1, CExpression* expression2)
	: CExpression(GREATER_THAN, expression1, expression2)
{
}

CVARIABLE::CVARIABLE(string name) :
CExpression(VARIABLE) {
	m_name= name;
	SetNodeName("\"" + g_nodeNames[GetNodeType()]+ "_"+ to_string(GetSerial()) +"_"+ name + "\"");
}

CNUMBER::CNUMBER(int value) :
CExpression(NUMBER){
	m_value = value;
	SetNodeName("\"" + g_nodeNames[GetNodeType()] + "_" + to_string(GetSerial()) +"_" + to_string(value) + "\"");
}
