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
}
