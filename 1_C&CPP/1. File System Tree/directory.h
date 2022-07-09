#ifndef _DIRECTORY_H_
#define _DIRECTORY_H_

#include "Node.h"
#include <string>
#include <memory>

using std::string;
using std::shared_ptr;

namespace liuyuan
{
struct Directory
{
	string mStr_dirName, mStr_baseName;

	Directory() = default;
	Directory(const string& dirName, const string& baseName) : mStr_dirName(dirName), mStr_baseName(baseName) {} 

	static string basename(shared_ptr<Node> currentNode);
	static string dirname(shared_ptr<Node> currentNode);
};
}

#endif
