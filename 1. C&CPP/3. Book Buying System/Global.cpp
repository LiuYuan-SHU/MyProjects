#include"Global.h"
#include<iostream>

using std::cin;
using std::cout;
using std::endl;

void Liuyuan::Fflush()
{
	cin.clear();
	cin.ignore(1024, '\n');
}

int Liuyuan::getChoice()
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