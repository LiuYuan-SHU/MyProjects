#ifndef _SHELL_H_
#define _SHELL_H_

#include "command.h"
#include "directory.h"
#include "node.h"
#include <memory>
#include <string>

using std::shared_ptr;
using std::string;
using namespace liuyuan;

namespace liuyuan
{
class Shell
{
private:
	shared_ptr<Node> mPtr_root, mPtr_pwd;
	Command mCmd_cmd;	
	Directory mDir_dir;	
public:
	Shell() = default;

	typedef int EXECUTE_CODE;

	void printUI();
	void getCmd();
	bool idCmd();
	EXECUTE_CODE executeCmd();
};
}

#endif
