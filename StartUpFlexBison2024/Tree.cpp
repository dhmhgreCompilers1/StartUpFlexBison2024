#include "Tree.h"
#include <cstdarg>
#include <iostream>
#include <string>

#include "grammar.tab.h"

int CNode::_serialCounter = 0;
CNode* root = NULL;
string g_nodeNames[] = {
    "TRANSLATION_UNIT",    
    "DECLARATIONS", "DECLARATION", "FUNCTION_DECLARATIONS", "FUNCTION_DECLARATION",
    "PARAMETER_LIST", "PARAMETER", "TYPE_SPECIFIER", "STATEMENTS", "STATEMENT",
    "COMPOUND_STATEMENT", "WHILE_STATEMENT", "DO_WHILE_STATEMENT", "FOR_STATEMENT",
    "IF_STATEMENT", "CONTINUE_STATEMENT", "BREAK_STATEMENT", "RETURN_STATEMENT",
	"EMPTY_STATEMENT", "EXPRESSION_STATEMENT",
    "ARGUMENT_LIST", "EXPRESSION", "SEPARATOR", "INTEGER", "FLOAT", "VARIABLE", "ADDITION",
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


CNode::CNode(NODETYPE symbolType) {
	_symbolType = symbolType;	
	_serial = _serialCounter++;
	_children = new list<CNode*>();	
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

#define GETARGS(count_param) va_list args; \
va_start(args, count_param); \
CNode* child; \
for (int i = 0; i < count_param; i++) { \
	child = va_arg(args, CNode*); \
	_children->push_back(child); \
	child->SetParent(this); \
} \
va_end(args);

CTranslationUnit::CTranslationUnit(int params,...) :
CNode(TRANSLATION_UNIT) {
	GETARGS(params)
	// va_list args;
	// va_start(args, params);
	// CNode* child;
	// for (int i = 0; i < params; i++) {
	// 	child = va_arg(args, CNode*);
	// 	_children->push_back(child);
	// 	child->SetParent(this);
	//
	// va_end(args);
}

CDeclarations::CDeclarations(int params,...) :
CNode(DECLARATIONS) {
	GETARGS(params)
}

CDeclaration::CDeclaration(int params,...) :
CNode(DECLARATION) {
	GETARGS(params)
}

CFunctionDeclaration::CFunctionDeclaration(int params,...)
	: CNode(FUNCTION_DECLARATION) {
	GETARGS(params)
}

CParameterList::CParameterList(int params, ...) :
	CNode(PARAMETER_LIST) {
	GETARGS(params)
}

CParameter::CParameter(int params, ...) :
	CNode(PARAMETER) {
	GETARGS(params)
}

CTypeSpecifier::CTypeSpecifier(TYPE_SPECIFIER typespecifier) :
	CNode(TYPESPECIFIER) {	
}

CStatements::CStatements(int params, ...) :
	CNode(STATEMENTS) {
	GETARGS(params)
}

CStatement::CStatement(int params,...) :
CNode(STATEMENT) {
	GETARGS(params)
}

CExpressionStatement::CExpressionStatement(int params, ...) :
CNode(EXPRESSION_STATEMENT) {
	GETARGS(params)
}

CCompoundStatement::CCompoundStatement(int params, ...) :
CNode(COMPOUND_STATEMENT) {
	GETARGS(params)
}

CWhileStatement::CWhileStatement(int params, ...) :
	CNode(WHILE_STATEMENT) {
	GETARGS(params)
}

CDoWhileStatement::CDoWhileStatement(int params, ...) :
	CNode(DO_WHILE_STATEMENT) {
	GETARGS(params)
}

CForStatement::CForStatement(int params, ...) :
	CNode(FOR_STATEMENT) {
	GETARGS(params)
}

CIfStatement::CIfStatement(int params, ...) :
	CNode(IF_STATEMENT) {
	GETARGS(params)
}

CContinueStatement::CContinueStatement() :
	CNode(CONTINUE_STATEMENT) {
}

CBreakStatement::CBreakStatement() :
	CNode(BREAK_STATEMENT) {
}

CReturnStatement::CReturnStatement(int params, ...) :
	CNode(RETURN_STATEMENT) {
	GETARGS(params)
}

CEmptyStatement::CEmptyStatement() :
	CNode(EMPTY_STATEMENT) {
}

CArgumentList::CArgumentList(int params, ...) :
	CNode(ARGUMENT_LIST) {
	GETARGS(params)
}

CAddition::CAddition(int params, ...) :
	CExpression(ADDITION) {
	GETARGS(params)
}

CFunctionDeclarations::CFunctionDeclarations(int params, ...) :
CNode(FUNCTION_DECLARATIONS) {
	GETARGS(params)
}

CExpression::CExpression(NODETYPE symbolType) :
CNode(symbolType) {}



CMultiplication::CMultiplication(int params,...) :
CExpression(MULTIPLICATION) {
	GETARGS(params)
}

CSubtraction::CSubtraction(int params,...) :
CExpression(SUBTRACTION) {
	GETARGS(params)
}

CDivision::CDivision(int params,...) :
CExpression(DIVISION) {
	GETARGS(params)
}

CAssignment::CAssignment(int params,...) :
CExpression(ASSIGNMENT) {
	GETARGS(params)
}

CEqual::CEqual(int params,...)
: CExpression(EQUAL){
	GETARGS(params)
}

CNotEqual::CNotEqual(int params,...)
: CExpression(NOT_EQUAL){
	GETARGS(params)
}

CNegation::CNegation(int params,...)
: CExpression(NEGATION){
	GETARGS(params)
}

CAnd::CAnd(int params,...)
: CExpression(AND){
	GETARGS(params)
}

COr::COr(int params,...)
: CExpression(OR){
	GETARGS(params)
}

CPower::CPower(int params,...)
: CExpression(POWER){
	GETARGS(params)
}

CModulo::CModulo(int params,...)
: CExpression(MODULO) {
	GETARGS(params)
}

CNot::CNot(int params,...)
: CExpression(NOT){
	GETARGS(params)
}

CGreater::CGreater(int params,...)
: CExpression(GREATER){
	GETARGS(params)
}

CGreaterEqual::CGreaterEqual(int params,...)
	: CExpression(GREATER_EQUAL){
	GETARGS(params)
}

CIdentity::CIdentity(int params,...)
:	 CExpression(IDENTITY){
	GETARGS(params)
}

CLessThan::CLessThan(int params,...)
	: CExpression(LESS_THAN) {
	GETARGS(params)
}


CLessEqual::CLessEqual(int params, ...)
	: CExpression(LESS_EQUAL){
	GETARGS(params)
}

CGreaterThan::CGreaterThan(int params, ...)
	: CExpression(GREATER_THAN){
	GETARGS(params)
}

CFunctionCall::CFunctionCall(int params, ...)
	: CExpression(FUNCTION_CALL) {
	GETARGS(params)
}

CIDENTIFIER::CIDENTIFIER(string name) :
CExpression(VARIABLE) {
	m_name= name;
	SetNodeName("\"" + g_nodeNames[GetNodeType()]+ "_"+ to_string(GetSerial()) +"_"+ name + "\"");
}

CINTEGER::CINTEGER(int value) :
CExpression(INTEGER_){
	m_value = value;
	SetNodeName("\"" + g_nodeNames[GetNodeType()] + "_" + to_string(GetSerial()) +"_" + to_string(value) + "\"");
}

CFLOAT::CFLOAT(float value)
:CExpression(FLOAT_) 
{
	m_value = value;
	SetNodeName("\"" + g_nodeNames[GetNodeType()] + "_" + to_string(GetSerial()) + "_" + to_string(value) + "\"");
}

