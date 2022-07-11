#include "command.h"
#include "directory.h"
#include "tools.h"
#include "shell.h"
#include <iostream>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::shared_ptr;

using namespace liuyuan;

liuyuan::Shell::Shell() : mCmd_cmd(), mDir_dir()
{
	mPtr_root.reset(new Node("/", 'D'));
	mPtr_pwd = mPtr_root;
}

void liuyuan::Shell::printUI()
{
	printf("[root@localhost %s] # ", dirname().c_str());	
}

void liuyuan::Shell::getCmd()
{
	string tmp;
	std::getline(cin, tmp);
	std::pair<string, string> splited_cmdAndPth = liuyuan::Command::splitCmd(tmp);
	this->mCmd_cmd = CommandFactory::create_command(splited_cmdAndPth);	
	this->mDir_dir = Directory(splited_cmdAndPth.second);
}

void liuyuan::Shell::switch_to_node(bool from_root)
{
	vector<string> nodes = split_string(this->mDir_dir.mStr_dirName, "/");

	shared_ptr<Node> ite(nullptr);
	// 如果从节点开始
	if (from_root)
	{
		ite = this->mPtr_root;
	}
	// 如果从当前节点开始
	else
	{
		ite = this->mPtr_pwd;
	}

	// 将ite转换到对应的地址
	for(auto& node_name : nodes)
	{
		if (ite = ite->get_child(node_name), ite)
		{

		}
		else
		{
			throw std::invalid_argument("Error: 不存在节点 " + node_name);
		}
	}

	// 转换成功后，将pwd reset为ite
	this->mPtr_pwd.reset(ite.get());
}

