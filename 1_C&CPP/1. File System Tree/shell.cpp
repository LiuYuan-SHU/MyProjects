#include "shell.h"
#include <iostream>
#include <cstdio>
#include <string>

using std::cin;
using std::cout;
using std::endl;

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
	this->mCmd_cmd = CommandFactory::create_command(tmp);	
}
