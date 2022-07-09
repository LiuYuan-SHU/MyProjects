#include "shell.h"
#include <iostream>

using namespace liuyuan;
using namespace std;

int main()
{
	Shell shell;

	while(true)
	{
		shell.printUI();
		shell.getCmd();
		shell.executeCmd();
		cout << "cmd: " << shell.get_cmd() << endl;
		cout << "pathname: "  << shell.get_pathname() << endl;
	}
}
