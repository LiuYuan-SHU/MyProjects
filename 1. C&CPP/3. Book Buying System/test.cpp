#include"Global.h"
#include"Buyers.h"
#include"Tools.h"
#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

using namespace Liuyuan;

int getChoice()
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

void UI2();

void UI1()
{
	cout << "========== Book Purchase System ==========" << endl;
	cout << "/ 1. Log in                              /" << endl;
	cout << "/ 2. Exit                                /" << endl;
	cout << "==========================================" << endl;
	switch (getChoice())
	{
	case 1:
		UI2();
		break;
	case 2:
		cout << "Exit System, thank you for using" << endl;
		system("pause");
		exit(0);
	default:
		cout << "illegal choice, input again: ";
		system("pause");
		system("clear");
		break;
	}
}

void UI2()
{
	string name;
	string password;
	cout << "==============================================================================================" << endl;
	cout << "/NOTE: if you don't have an account yet or you forget your id, please input your name        /" << endl;
	cout << "/We will deal it for you.                                                                    /" << endl;
	cout << "===========================================WARNING============================================" << endl;
	cout << "/Your name should not start with number, and include no space                                /" << endl;
	cout << "/If necessary, use '_'                                                                       /" << endl;
	cout << "==============================================================================================" << endl;

	cout << "input your id: ";
	cin >> name;
	Fflush();
	if (isdigit(name[0]))
	{
		cout << "input your passport: ";
		cin >> password;
		Fflush();
		login(name, password);
	}
	else if (isalpha(name[0]))
	{
		cout << "You input a name, searching..." << endl;
		//searchName(name);
	}
}

int main()
{
	init();
	/*while (true)
	{
		UI1();
	}*/

	//debug
	printGuest();
}