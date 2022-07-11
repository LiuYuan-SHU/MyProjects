#include "test.h"
#include "tools.h"
#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;
using namespace liuyuan;
using namespace test;

void test::test_tools_split_string()
{
	string testStr;
	cin >> testStr;
	vector<string> split_result = split_string(testStr, "/");
	copy(split_result.cbegin(), split_result.cend(), ostream_iterator<string>(cout, "\n"));
}
