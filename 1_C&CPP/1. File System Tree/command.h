#ifndef _COMMAND_H_
#define _COMMAND_H_

#include "Node.h"
#include "directory.h"
#include <cstdlib>
#include <string>
#include <utility>
#include <memory>

using std::pair;
using std::string;
using std::shared_ptr;
using std::system;

namespace liuyuan
{
struct Command;

// 简单工厂模式
struct CommandFactory
{
	static shared_ptr<Command> create_command(const string& line);
	static shared_ptr<Command> create_command(const pair<string, string>& p);
};

struct Command
{
	string mStr_command;
	string mStr_pathname;

	Command() = default;
	// Command(const string& cmd) : Command(splitCmd(cmd)) {};
	Command(const pair<string, string>& p) : mStr_command(p.first), mStr_pathname(p.second) {};
	// Command(const Command&& tmp) : mStr_command(tmp.mStr_command), mStr_pathname(tmp.mStr_pathname) {};

	// Command& operator=(const Command&& tmp) { mStr_command = tmp.mStr_command; mStr_pathname = tmp.mStr_pathname; return *this; };

	virtual ~Command() = default;

	static pair<string, string> splitCmd(const string& cmd);

	virtual void execute(const Directory& dir, const shared_ptr<Node> root, shared_ptr<Node> pwd) {};
};

struct Clear : public Command
{
	Clear(const pair<string, string>& p) : Command(p) {}

	void execute(const Directory& dir, const shared_ptr<Node> root, shared_ptr<Node> pwd) 
	{
#if defined(_WIN32_)
		system("cls"); 
#else
		system("clear");
#endif
	}	
};

struct Exit : public Command
{
	Exit(const pair<string, string>& p) : Command(p) {}

	void execute(const Directory& dir, const shared_ptr<Node> root, shared_ptr<Node> pwd) { exit(0); }
};

struct Mkdir : public Command
{
	Mkdir(const pair<string, string>& p) : Command(p) {}	

	void execute(const Directory& dir, const shared_ptr<Node> root, shared_ptr<Node> pwd);
};

}

#endif
