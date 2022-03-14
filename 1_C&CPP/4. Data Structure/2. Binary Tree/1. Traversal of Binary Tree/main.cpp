#include "Tool.h"
#include "Node.h"
#include <string>

using namespace std;

extern int priority[128];

int main()
{
	initTool();

	string input;
	getline(cin, input);
	preOrderTraversal_recursion(buildExpressionTree(input));
	cout << endl;
	preOrderTraversal_no_recursion(buildExpressionTree(input));	
}
