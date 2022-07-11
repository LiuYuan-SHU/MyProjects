#include "command.h"
#include <cstddef>
#include <memory>
#include <stdio.h>
#include <utility>
#include <cstdio>

using namespace liuyuan;
using std::make_pair;
using std::pair;
using std::shared_ptr;

shared_ptr<Command> CommandFactory::create_command(const pair<string, string>& p)
{
	const string& cmd = p.first;

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

shared_ptr<Command> liuyuan::CommandFactory::create_command(const string &line)
{
	pair<string, string> p = Command::splitCmd(line);

	return create_command(p);
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

void liuyuan::Mkdir::execute(const Directory& dir, const shared_ptr<Node> root, shared_ptr<Node> pwd)
{
						
}
