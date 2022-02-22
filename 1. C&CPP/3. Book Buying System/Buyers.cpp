#include"Global.h"
#include"Buyers.h"
#include<iostream>
#include<algorithm>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::vector;
using namespace Liuyuan;

unsigned int Layfork::numOfRegister = 0;
unsigned int Number::numOfRegister = 0;
unsigned int Honoured_guest::numOfRegister = 0;

template<class T>
T Liuyuan::getData()
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

bool Liuyuan::isLogined()
{
	return logined;
}

void Liuyuan::logout()
{
	logined = false;
}

Buyer* Liuyuan::getLogin_accountPtr()
{
	return logined_accountPtr;
}

void Liuyuan::setLogin_accountPtr(Buyer* newPtr)
{
	logined_accountPtr = newPtr;
}

string Liuyuan::getLogin_level()
{
	return logined_level;
}

void Liuyuan::setLogin_level(string newLevel)
{
	logined_level = newLevel;
}

bool Liuyuan::judgeNoSpace(string judge)
{
	for(auto i : judge)
	{
		if(isspace(i))
		{
			return false;
		}
	}
	return true;
}

bool Liuyuan::judgeNoSlash(string judge)
{
	for(auto i : judge)
	{
		if(i == '/')
		{
			return false;
		}
	}
	return true;
}

bool greaterID(Buyer* left, Buyer* right)
{
	return (left->getID() > right->getID());
}

void Liuyuan::init()
{
	guestList.push_back(new Layfork("ZhangXiaobin", "123", "99th, Shangda Road", 200));
	guestList.push_back(new Number("LiShichun", "123", "80th, Nanchen Road", 2, 400));
	guestList.push_back(new Honoured_guest("WangSicheng", "123", "70th, Jinqiu Road", 0.7, 600));
	sort(guestList.rbegin(), guestList.rend(),greaterID);
}

void Buyer::printInfo(string userLevel, double userRate)
{
	cout << "/ User Level:\t\t" << userLevel << endl;
	cout << "/ User ID:\t\t" << this->_id << endl;
	cout << "/ User name:\t\t" << this->_name << endl;
	if (super_usr)
	{
		cout << "/ **USER password:\t" << this->_password << endl;
	}
	cout << "/ User address:\t\t" << this->_address << endl;
	cout << "/ User balance:\t\t" << this->_balance << endl;
	cout << "/ User mypay:\t\t" << this->_mypay << endl;
	cout << "/ User rate:\t\t" << userRate << endl;
}

void Liuyuan::printGuest()
{
	cout << "========== print guests info ==========" << endl;
	for (auto i : guestList)
	{
		if (dynamic_cast<Layfork*>(i)) { i->printInfo("Layfork", 1); }
		else if (dynamic_cast<Number*>(i)) { i->printInfo("Number", rate[dynamic_cast<Number*>(i)->getStar()]); }
		else { i->printInfo("Honoured", dynamic_cast<Honoured_guest*>(i)->getRate()); }
		cout << "+=====================================+" << endl;
	}
	cout << "=======================================" << endl;
}

Layfork::Layfork(string name, string password, string address, double balance, double mypay) :
	Buyer(name, password, address, balance, mypay)
{
	this->_id = 100000 + (++numOfRegister);
}

Number::Number(string name, string password, string address, unsigned short star, double balance, double mypay) :
	Buyer(name, password, address, balance, mypay)
{
	if (star > 5)
	{
		cout << "illegal star number! Construction FAIL" << endl;
		exit(-1);
	}
	this->_star = star;
	this->_id = 200000 + (++numOfRegister);
}

Honoured_guest::Honoured_guest(string name, string password, string address, double rate, double balance, double mypay) :
	Buyer(name, password, address, balance, mypay)
{
	if (rate <= 0 || rate > 1)
	{
		cout << "illegal rate, construction FAIL" << endl;
		exit(-1);
	}
	this->_rate = rate;
	this->_id = 300000 + (++numOfRegister);
}

int Liuyuan::login(string id, string password)
{
	for(auto i : password)
	{
		if(i == '/')
		{
			cout << "Canceled" << endl;
			return CANCEL;
		}
	}

	int id_int = 0;
	for(auto i : id)
	{
		if(!isdigit(i))
		{
			cout << "your ID is incorrect" << endl;
			system("pause");
			return FAIL;
		}
		id_int = id_int * 10 + i - '0';
	}

	for (auto i : guestList)
	{
		if (i->getID() == id_int)
		{
			if (i->isPassword(password))
			{
				//debug
				cout << "Logined" << endl;

				logined = true;
				logined_accountPtr = i;
				if (dynamic_cast<Layfork*>(i)) { logined_level = "Layfork"; }
				else if (dynamic_cast<Number*>(i)) { logined_level = "Number"; }
				else { logined_level = "Honoured"; }
				return SUCCESS;
			}
			else
			{
				return FAIL;
			}
		}
	}
	return FAIL;
}

void Liuyuan::searchName(string name)
{
	cout << "You input a name, searching..." << endl;

	bool found = false;
	for (auto i : guestList)
	{
		//if found the first same name, print info
		if (i->getName() == name)
		{
			found ? (cout << "") : (cout << "===== found same name as follows: =====\n");
			cout << "ID:\t" << i->getID() << "\t" << "Name:\t" << i->getName() << endl;
		}
	}
	if (!found)
	{
		cout << "you haven't registed yet, do you want to regist? (Y/N)" << endl;
		char key;
		while (cin >> key, cin.fail() || (key != 'Y' && key != 'y' && key != 'n' && key != 'N'))
		{
			cout << "illegal input, input again: ";
			cin.clear();
			cin.ignore(1024, '\n');
		}
		if (key == 'Y' || key == 'y')
		{
			regist(name);
		}
		else
		{
			return;
		}
	}
}

void Liuyuan::regist(string name)
{
	CLEAR;
	cout << "=============== REGIST ===============" << endl;
	cout << "/ 1. regist layfork" << endl;
	cout << "/ 2. regist number" << endl;
	cout << "/ 3. regist honoured" << endl;
	cout << "/ 4. exit" << endl;
	cout << "======================================" << endl;
	
	//from getChoice, but can't move this function to Global.h on Linux
	//so strange
	int choice = 0;
	cout << "input your choice: ";
	while (cin >> choice, cin.fail() || choice > 4 || choice < 1)
	{
		cout << "illegal input, input again: ";
		//Can't use Fflush either
		cin.clear();
		cin.ignore(1024, '\n');
	}

	if(choice == 4)
	{
		cout << "Cancel Regist" << endl;
		system("pause");
		return;
	}

	string password;
	string address;
	double balance = 0;
	double mypay = 0;
	short star = 0;
	double rate = 0;

	cout << "input password:";
	while(password = getData<string>(), !judgeNoSpace(password) && judgeNoSlash(password))
	{
		cout << "illegal input, input again: ";
	}
	cin.clear();
	cin.ignore(1024, '\n');
	cout << "input address: ";
	getline(cin,address);
	cin.clear();
	cout << "input balance: ";
	balance = getData<double>();
	cin.clear();
	cin.ignore(1024, '\n');

	switch(choice)
	{
	case 1:
		cout << "=============== REGIST Layfork ===============" << endl;
		guestList.push_back(new Layfork(name, password, address, balance));
		break;
	case 2:
		cout << "=============== REGIST Number ===============" << endl;
		cout << "input star of the guest: ";
		while(star = getData<short>(), star < 1 || star > 5)
		{
			cout << "out of range, please input an integer in [1,5]: ";
		}
		guestList.push_back(new Number(name, password, address, star, balance));
		break;
	case 3:
		cout << "=============== REGIST Honoured ===============" << endl;
		cout << "input rate of the guest: ";
		while(rate = getData<double>(), rate <= 0 || rate > 1)
		{
			cout << "rate out of range, please input in a legal range: ";
		}
		guestList.push_back(new Honoured_guest(name,password,address,rate,balance));
		break;
	}
	sort(guestList.rbegin(),guestList.rend(),greaterID);
}