#include "Tool.h"

int priority[128] = { 0 };

void initTool()
{
	priority['+'] = priority['-'] = 1;
	priority['*'] = priority['/'] = 2;
	priority['^'] = 3;
}

bool isNegative(const char *current, const char *start)
{
	do
	{
		--current;
		//if found an operator 
		if (priority[*current] > 0) { return true; }
		//if found an operand
		if (isdigit(*current) || isalpha(*current)) { return false; }
	}while(current >= start);
	//if reach the start of the expression
	return true;
}

void Fflush()
{
	cin.ignore(1024, '\n');
	cin.clear();
}
