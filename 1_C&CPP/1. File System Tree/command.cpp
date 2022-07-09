#include "command.h"
#include <cstddef>
#include <memory>
#include <stdio.h>
#include <utility>
#include <cstdio>

using namespace liuyuan;
using std::make_pair;
using std::pair;

std::shared_ptr<Command> liuyuan::CommandFactory::create_command(const string &line)
{
	pair<string, string> p = Command::splitCmd(line);
	string cmd = p.first, pathname = p.second;

	if (cmd == "clear")
	{
		return shared_ptr<Clear>(new Clear(p));
	}
	else if(cmd == "exit")
	{
		return shared_ptr<Exit>(new Exit(p));
	}
	else
	{
		return shared_ptr<Command>(new Command(p));
	}
}

pair<string, string> liuyuan::Command::splitCmd(const string &cmd)
{
	char command[1024], pathname[1024];
	if (cmd.find(" ") == string::npos)
	{
		return make_pair(cmd, "");
	}
	else
	{
		sscanf(cmd.c_str(), "%s %s", command, pathname);
	}

	return make_pair(string(command), string(pathname));
}
