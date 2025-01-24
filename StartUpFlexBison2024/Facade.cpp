#include "Facade.h"


CFacade::CFacade(bool debugTree) {
	m_scopeSystem = new CScopeSystem();
	b_debugTree = debugTree;
}

void CFacade::Parse(string sourceFileName) {
	m_sourceFileName = sourceFileName;
	fopen_s(&yyin, m_sourceFileName.c_str(), "r");
	parser.parse();
	_root = root;

	if (b_debugTree) {
		EmitParseTree();
	}
}


void CFacade::EmitParseTree()
{
	(*dotFile) << "digraph G{\n";
	root->PrintSyntaxTree(dotFile, NULL);
	(*dotFile) << "}\n";
	dotFile->close();
	system("dot -Tgif graph.dot -o graph.gif");
}
