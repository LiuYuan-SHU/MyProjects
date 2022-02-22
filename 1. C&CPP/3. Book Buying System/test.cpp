#include"Global.h"
#include"Buyers.h"
#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

using namespace Liuyuan;

void Fflush()
	{
		cin.clear();
		cin.ignore(1024, '\n');
	}

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
	cout << "/ 2. Print all guests                    /" << endl;
	cout << "/ 3. Exit                                /" << endl;
	cout << "==========================================" << endl;
	switch (getChoice())
	{
	case 1:
		UI2();
		break;
	case 2:
		system("clear");
		printGuest();
		system("pause");
		break;
	case 3:
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
	//system("clear");
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
		cout << "input your passport(input a '/' to cancel): \n";
		cin >> password;
		Fflush();
		int result = login(name, password);
		while(result == FAIL)
		{
			cout << "your passport is wrong, please retry(input a '/' to cancel): ";
			cin >> password;
			Fflush();
			result = login(name, password);
		}
	}
	else if (isalpha(name[0]))
	{
		searchName(name);
	}
	system("pause");
}

int main()
{
	init();
	while (true)
	{
		UI1();
		system("clear");
	}

	//debug
	//printGuest();
}