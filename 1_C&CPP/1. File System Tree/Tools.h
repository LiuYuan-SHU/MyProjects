#ifndef _TOOL_H_
#define _TOOL_H_

#include <utility>
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace liuyuan
{
	// 将传入的字符变为大写字符
	char make_cap(const char& ch);
	// 将一个string以一个字符串进行分割
	vector<string> split_string(const string& str, const string& delimiter);	
}

#endif
