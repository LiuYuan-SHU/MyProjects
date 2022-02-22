#include"UI.h"
#include"Global.h"
#include"Global.cpp"
#include"Buyers.h"
#include"Books.h"
#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void Liuyuan::UI_basic()
{
	CLEAR;
	cout << "========== Book Purchase System ==========" << endl;
	cout << "/ 1. Log in                              /" << endl;
	cout << "/ 2. Print all guests                    /" << endl;
	cout << "/ 3. Exit                                /" << endl;
	cout << "==========================================" << endl;
	switch (getChoice())
	{
	case 1:
		UI_login();
		break;
	case 2:
		CLEAR;
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
		CLEAR;
		break;
	}
}

void Liuyuan::UI_login()
{
	string name;
	string password;
	CLEAR;
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
		while (result == FAIL)
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

void Liuyuan::UI_logined()
{
	CLEAR;
	cout << "===== Book Purchase System - Logined =====" << endl;
	cout << "/ 1. Log out                             /" << endl;
	cout << "/ 2. Print my info                       /" << endl;
	cout << "/ 3. Purchase books                      /" << endl;
	cout << "/ 4. Exit                                /" << endl;
	cout << "==========================================" << endl;

	int choice = 0;
	while (choice = getChoice(), choice < 1 || choice > 4)
	{
		cout << "illegal input, input again: ";
	}

	switch (choice)
	{
	case 1:
		logout();
		setLogin_accountPtr();
		setLogin_level();
		break;
	case 2:
		cout << "========== print guests info ==========" << endl;
		getLogin_accountPtr()->printInfo(logined_level, getLogin_accountPtr()->getRate());
		cout << "=======================================" << endl;
		system("pause");
		break;
	case 3:
		UI_buyBook();
		system("pause");
		break;
	case 4:
		cout << "System shutting down, thank you for use!" << endl;
		system("pause");
		exit(0);
	}
}

void Liuyuan::UI_buyBook()
{
	CLEAR;
	cout << "===== Book Purchase System - Purchase =====" << endl;
	cout << "/ 1. Print book info                      /" << endl;
	cout << "/ 2. Purchase book                        /" << endl;
	cout << "/ 3. Cancel                               /" << endl;
	cout << "/ 4. Log out                              /" << endl;
	cout << "/ 5. Exit                                 /" << endl;
	cout << "===========================================" << endl;

	int choice = 0;
	while (choice = getChoice(), choice < 1 || choice > 5)
	{
		cout << "illegal input, input again: ";
	}

	switch (choice)
	{
	case 1:
		UI_printBook();
		break;
	case 2:
		cout << "buy book" << endl;
		//buyBook();
		break;
	case 3:
		return;
	case 4:
		cout << "Log out" << endl;
		logout();
		setLogin_accountPtr();
		setLogin_level();
		break;
	case 5:
		cout << "System shutting down, thank you for use!" << endl;
		system("pause");
		exit(0);
	default:
		break;
	}
}

void Liuyuan::UI_printBook()
{
	CLEAR;
	cout << "===== Book Purchase System - Pirnt Book =====" << endl;
	cout << "/ 1. Print All                              /" << endl;
	cout << "/ 2. Search with ID                         /" << endl;
	cout << "/ 3. Search with name                       /" << endl;
	cout << "/ 4. Search with author                     /" << endl;
	cout << "/ 5. Search with category                   /" << endl;
	cout << "/ 6. Cancel                                 /" << endl;
	cout << "=============================================" << endl;

	int choice = 0;
	while (choice = getChoice(), choice < 1 || choice > 6)
	{
		cout << "illegal input, input again: ";
	}

	string key;
	switch (choice)
	{
	case 1:
		printBookInfo();
		break;
	case 2:
		cout << "input book's ID: ";
		cin >> key;
		Fflush();
		printBookInfo(__ID, key);
		break;
	case 3:
		cout << "input book's name: ";
		getline(cin, key);
		Fflush();
		printBookInfo(NAME, key);
		break;
	case 4:
		cout << "input book's author: ";
		getline(cin, key);
		Fflush();
		printBookInfo(AUTHOR, key);
		break;
	case 5:
		cout << "input book's category: ";
		getline(cin, key);
		Fflush();
		printBookInfo(CATEGORY, key);
		break;
	case 6:
		cout << "Canceled" << endl;
		system("pause");
		return;
	default:
		cout << "illegal choice code" << endl;
	}
}