#include"Global.h"
#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

namespace Liuyuan
{
	inline void Fflush()
	{
		cin.clear();
		cin.ignore(1024, '\n');
	}

	inline int getChoice(int lowerLimit, int upperLimit)
	{
		int choice = 0;
		cout << "input your choice: ";
		while (cin >> choice, cin.fail() || choice < lowerLimit || choice > upperLimit)
		{
			cout << "illegal input, input again: ";
			Fflush();
		}
		return choice;
	}

	template<class T>
	inline T getData()
	{
		T data;
		while (cin >> data, cin.fail())
		{
			cout << "illegal input, input again: ";
			Fflush();
		}

		return data;
	}

	bool judgeNoSpace(string judge)
	{
		for (auto i : judge)
		{
			if (isspace(i))
			{
				return false;
			}
		}
		return true;
	}

	bool judgeNoSlash(string judge)
	{
		for (auto i : judge)
		{
			if (i == '/')
			{
				return false;
			}
		}
		return true;
	}
}
