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
	switch (getChoice(1,3))
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

	//super user login
	if(name == "super")
	{
		CLEAR;
		cout << "========================================" << endl;
		cout << "/         Welcome! SUPER USER          /" << endl;
		cout << "========================================" << endl;
		setSuperUsr(true);
		system("pause");
		return;
	}

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

	switch (getChoice(1, 4))
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

void Liuyuan::UI_logined_superUsr()
{	
	CLEAR;
	cout << "===== Book Purchase System - Super User =====" << endl;
	cout << "/ 1. Log out                                /" << endl;
	cout << "/ 2. Print Guest Info                       /" << endl;
	cout << "/ 3. Edit Guests                            /" << endl;
	cout << "/ 4. Edit Books                             /" << endl;
	cout << "/ 5. Exit                                   /" << endl;
	cout << "=============================================" << endl;

	switch (getChoice(1,5))
	{
	case 1:
		cout << "Super User logout" << endl;
		setSuperUsr(false);
		break;
	case 2:
		cout << "========== print guests info ==========" << endl;
		getLogin_accountPtr()->printInfo(logined_level, getLogin_accountPtr()->getRate());
		cout << "=======================================" << endl;
		break;
	case 3:
		UI_logined_superUsr_setGuest();
		break;
	case 4:
		UI_logined_superUsr_setBooks();
		break;
	case 5:
		cout << "System shutting down, thank you for use" << endl;
		break;
	default:
		break;
	}
	system("pause");
}

void Liuyuan::UI_logined_superUsr_setGuest()
{
	CLEAR;
	cout << "===== Book Purchase System - Set Guest =====" << endl;
	cout << "/ 1. Set Guest Kind                        /" << endl;
	cout << "/ 2. Set Guest Name                        /" << endl;
	cout << "/ 3. Set Guest Password                    /" << endl;
	cout << "/ 4. Set Guest Address                     /" << endl;
	cout << "/ 5. Set Guest Balance                     /" << endl;
	cout << "/ 6. Cancel                                /" << endl;
	cout << "============================================" << endl;

	int choice = getChoice(1,6);
	if(choice == 6)
	{
		cout << "Cancel" << endl;
		system("pause");
		return;
	}

	Buyer* account = getLogin_accountPtr();
	string value;
	double value_double;
	cout << "input user id: ";
	unsigned int id = getData<unsigned int>();
	Fflush();
	switch(choice)
	{
	case 1:
		UI_logined_superUsr_changeKind();
		break;
	case 2:
		cout << "input new name: ";
		getline(cin,value);
		cin.clear();
		account->setName(value);
		break;
	case 3:
		cout << "input new password: ";
		while(value = getData<string>(), judgeNoSlash(value))
		{
			cout << "your password contains '/', please retry: ";
		}
		account->setPassword(value);
		break;
	case 4:
		cout << "input new address: ";
		getline(cin,value);
		cin.clear();
		account->setAddress(value);
		break;
	case 5:
		cout << "input new balance: ";
		while(value_double = getData<double>(), value_double < 0)
		{
			cout <<"illegal value, please input again: ";
		}
		account->setBalance(value_double);
		break;
	}
	system("pause");
}

void Liuyuan::UI_logined_superUsr_changeKind()
{
	CLEAR;
	cout << "========================================" << endl;
	cout << "Please input the ID of the guest: ";
	unsigned int id = getData<unsigned int>();
	Fflush();
	Buyer* account = findId(id)；
	if(!account)
	{
		cout << "incorrect ID, change FAIL" << endl;
		system("pause");
		return;
	}
	else
	{
		cout << endl << "============ Account found =============" << endl;
		if(Layfork* ptr = dynamic_cast<Layfork*>(account))
		{
			UI_logined_superUsr_changeLayfork(ptr);
		}
		else if(Number* ptr = dynamic_cast<Number*>(account))
		{
			UI_logined_superUsr_changeNumber(ptr);
		}
		else
		{
			UI_logined_superUsr_changeHonoured(dynamic_cast<Honoured_guest*>(account));
		}
	}
}

void Liuyuan::UI_logined_superUsr_changeLayfork(Layfork* ptr)
{
	CLEAR;
	cout << "============ Change Layfork ============" << endl;
	cout << "/ 1. Change to Number                  /" << endl;
	cout << "/ 2. Change to Honoured                /" << endl;
	cout << "/ 3. Cancel                            /" << endl;
	cout << "========================================" << endl;
	
	int choice = getChoice(1,3);

	if(choice == 3)
	{
		cout << "Cancle" << endl;
		system("pause");
		CLEAR;
		return;
	}

	unsigned int star;
	double rate;
	switch(choice)
	{
	case 1:
		cout <<"=========== Set to Number =============" << endl;
		cout << "input the star of the guest: " << endl;
		cout << "From 1 to 5, ";
		star = getChoice(1,5);
		break;
	}
}

void Liuyuan::UI_logined_superUsr_changeNumber(Number* ptr)
{

}

void Liuyuan::UI_logined_superUsr_changeHonoured(Honoured_guest* ptr)
{

}

void Liuyuan::UI_logined_superUsr_setBooks()
{

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

	switch (getChoice(1, 5))
	{
	case 1:
		UI_printBook();
		break;
	case 2:
		cout << "buy book" << endl;
		getLogin_accountPtr()->buyBook();
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

	string key;
	switch (getChoice(1, 6))
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