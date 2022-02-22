#include"Global.h"
#include"Buyers.h"
#include"Books.h"
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
	system("clear");
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
	system("clear");
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

void UI_logined()
{
	system("clear");
	cout << "===== Book Purchase System - Logined =====" << endl;
	cout << "/ 1. Log out                             /" << endl;
	cout << "/ 2. Print my info                       /" << endl;
	cout << "/ 3. Purchase books                      /" << endl;
	cout << "/ 4. Exit                                /" << endl;
	cout << "==========================================" << endl;

	int choice = 0;
	while(choice = getChoice(), choice < 1 || choice > 4)
	{
		cout << "illegal input, input again: ";
	}

	switch(choice)
	{
	case 1:
		logined = false;
		logined_accountPtr = nullptr;
		break;
	case 2:
		cout << "========== print guests info ==========" << endl;
		logined_accountPtr->printInfo(logined_level, logined_accountPtr->getRate());
		cout << "=======================================" << endl;
		break;
	case 3:
		break;
	case 4:
		cout << "System shutting down, thank you for use!" << endl;
		system("pause");
		exit(0);
	}
}

int main()
{
	/*
	init();
	while (true)
	{
		if(logined)
		{
			
		}
		else
		{
			UI1();
		}
		system("clear");
	}
	*/

	//debug
	printBookInfo();
}