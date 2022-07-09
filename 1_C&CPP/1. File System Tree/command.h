#ifndef _COMMAND_H_
#define _COMMAND_H_

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

	static pair<string, string> splitCmd(const string& cmd);

	virtual void execute() {};
};

struct Clear : public Command
{
	Clear(const pair<string, string>& p) : Command(p) {}

	void execute() 
	{
#if defined(__linux__)
		system("clear"); 
#else
		system("cls");
#endif
	}	
};

struct Exit : public Command
{
	Exit(const pair<string, string>& p) : Command(p) {}

	void execute() { exit(0); }
};

}

#endif
