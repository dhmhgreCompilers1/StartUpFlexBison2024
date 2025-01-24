#include "Facade.h"
#include "grammar.tab.h"

int main(int argc, char** argv) {
	CFacade* facade = CFacade::GetInstance(true);
	facade->Parse(argv[1]);
	return 0;
}