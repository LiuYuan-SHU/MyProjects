#include "tools.h"
#include <vector>
#include <string>
#include <cstdio>
#include <utility>

using namespace liuyuan;
using std::string;
using std::vector;

char liuyuan::make_cap(const char& ch)
{
	if ('a' <= ch && ch <= 'z')
	{
		return ch + ('a' - 'A');
	}
	else if ('A' <= ch && ch <= 'Z')
	{
		return ch;
	}
	else
	{
		return 0;
	}
}

vector<string> liuyuan::split_string(const string &str, const string &delimiter)
{
	vector<string> result;
	// 防止字符串以'/'开头而导致加入vector的第一个字符串为空
	string s = str.at(0) == '/' ? string(str, 1) : str;
	// 用于find函数，记录delimiter的位置
	string::size_type pos = 0;

	// 查找delimiter的下标，如果查找结果是npos，就说明已经没有了
	while (pos = s.find(delimiter), pos != string::npos)
	{
		result.push_back(s.substr(0, pos));
		s = string(s, pos + delimiter.size());
	}

	// 防止最后一个字符串没有加入进去
	if (s.size() != 0) { result.push_back(s); }

	return result;
}
