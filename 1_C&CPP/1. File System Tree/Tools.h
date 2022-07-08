#ifndef _TOOL_H_
#define _TOOL_H_

#include <utility>
#include <string>

using std::pair;
using std::string;

namespace liuyuan
{
	// 命令分割
	pair<string, string> splitCmd(const string& cmd);
}

#endif
