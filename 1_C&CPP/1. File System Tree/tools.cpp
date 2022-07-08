#include "tools.h"
#include <cstdio>
#include <utility>

using std::sscanf;
using namespace liuyuan;

pair<string, string> liuyuan::splitCmd(const string &cmd)
{
	char command[1024], pathname[1024];
	sscanf(cmd.c_str(), "%s %s", command, pathname);

	return std::make_pair(string(command), string(pathname));
}
