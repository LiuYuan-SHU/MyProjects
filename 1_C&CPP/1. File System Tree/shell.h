#ifndef _SHELL_H_
#define _SHELL_H_

#include "command.h"
#include "directory.h"
#include "Node.h"
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
	shared_ptr<Command> mCmd_cmd;	
	Directory mDir_dir;	
public:
	Shell();

	// 程序运行逻辑函数
	void printUI();
	void getCmd();
	inline void executeCmd() { mCmd_cmd->execute(this->mDir_dir); }

	inline string basename() { return mDir_dir.basename(mPtr_pwd); }
	inline string dirname() { return mDir_dir.dirname(mPtr_pwd); }

	// command
	inline string get_cmd() { return this->mCmd_cmd->mStr_command; }
	// pathname
	inline string get_pathname() { return this->mCmd_cmd->mStr_pathname; }
	// dirname
	inline string get_dirname() { return dirname(); }
	// basename
	inline string get_basename() { return basename(); }

	// 将pwd转到mDir_dir中的路径节点
	// 并且根据布尔值from_root决定是否从root开始查找
	void switch_to_node(bool from_root);
};
}

#endif
