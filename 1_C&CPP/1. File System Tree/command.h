#ifndef _COMMAND_H_
#define _COMMAND_H_

#include "tools.h"
#include <string>
#include <utility>

using std::pair;
using std::string;

namespace liuyuan
{
struct Command
{
	string mStr_command;
	string mStr_pathname;

	Command() = default;
	Command(const string& cmd) : Command(splitCmd(cmd)) {};
	Command(const pair<string, string>& p) : mStr_command(p.first), mStr_pathname(p.second) {};
};
}

#endif
