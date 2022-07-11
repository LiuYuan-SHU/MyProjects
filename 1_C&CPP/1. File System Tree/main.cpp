#include "shell.h"
#include "test.h"
#include <iostream>

using namespace liuyuan;
using namespace std;

int main()
{
#if defined (TEST)
	using namespace test;
	test_tools_split_string();
#else
	Shell shell;

	while(true)
	{
		shell.printUI();
		shell.getCmd();
		shell.executeCmd();
		cout << "cmd: " << shell.get_cmd() << endl;
		cout << "pathname: "  << shell.get_pathname() << endl;
	}
#endif
}
