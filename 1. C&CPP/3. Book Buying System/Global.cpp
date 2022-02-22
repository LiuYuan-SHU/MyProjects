#include"Global.h"
#include<iostream>

using std::cin;
using std::cout;
using std::endl;

namespace Liuyuan
{
	inline void Fflush()
	{
		cin.clear();
		cin.ignore(1024, '\n');
	}

	inline int getChoice()
	{
		int choice = 0;
		cout << "input your choice: ";
		while (cin >> choice, cin.fail())
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
			//Can't use Fflush either
			cin.clear();
			cin.ignore(1024, '\n');
		}

		return data;
	}
}
