#include "tools.h"
#include <cstdio>
#include <utility>

using std::sscanf;
using namespace liuyuan;

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
