#include "directory.h"
#include <string>
#include <stdexcept>

using std::string;
using std::invalid_argument;
using namespace liuyuan;

// 将字符串path分割成dirname和pathname
liuyuan::Directory::Directory(const string& path)
{
	// 使用逆向搜索搜索第一个'/'的位置
	string::size_type lastSlash = path.rfind("/");	
	// 如果没有找到，那么就是只有basename，没有dirname
	if ( lastSlash == string::npos )
	{
		this->mStr_baseName = path;
		this->mStr_dirName = "";
	}
	// 如果找到了'/'，那么就做字符串分割
	else
	{
		// 首先需要避免下标超出范围，也就是：a/ 的情况
		if (lastSlash + 1 > path.length())
		{
			throw invalid_argument("输入了错误的path： " + path);
		}
		// 如果没有这样的情况，那么正常处理
		else
		{
			this->mStr_dirName = string(path, 0, lastSlash);
			this->mStr_baseName = string(path, lastSlash + 1);
		}
	}
}

string liuyuan::Directory::dirname(shared_ptr<Node> currentNode)
{
	switch (currentNode->get_type())
	{
	case 'D':
		return currentNode->get_name() == "/" ? "~" : currentNode->get_name();
		break;
	case 'F':
		return (currentNode->get_parent().lock()->get_name());
	default:
		throw invalid_argument("Wrong Node Type");
		break;
	}
}

string liuyuan::Directory::basename(shared_ptr<Node> currentNode)
{
	return currentNode->get_name();	
}
