#ifndef _DIRECTORY_H_
#define _DIRECTORY_H_

#include <string>

using std::string;

namespace liuyuan
{
struct Directory
{
	string mStr_dirName, mStr_baseName;

	Directory() = default;
	Directory(const string& dirName, const string& baseName) : mStr_dirName(dirName), mStr_baseName(baseName) {} 
};
}

#endif
