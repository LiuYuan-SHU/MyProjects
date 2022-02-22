#include"Buyers.h"
#include"Global.h"
#include"Tools.h"
#include<iostream>
#include<algorithm>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::vector;
using namespace Liuyuan;

unsigned int Buyer::numOfRegister = 0;
vector<Buyer*> guestList;

bool super_usr = false;

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
	if (star >= 5)
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

void initSystem()
{
	Layfork::setNum();
	Number::setNum();
	Honoured_guest::setNum();
}

bool Liuyuan::login(string id, string password)
{
	for (auto i : guestList)
	{
		if (i->getName() == id)
		{
			if (i->isPassword(password))
			{
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
	bool found = false;
	for (auto i : guestList)
	{
		//if found the first same name, print info
		if (i->getName() == name)
		{
			found ? (cout << "") : (cout << "===== found same name as follows: =====");
		}
		cout << "ID:\t" << i->getID() << "\t" << "Name:\t" << i->getName() << endl;
	}
	if (!found)
	{
		cout << "you haven't  registed yet, do you want to regist? (Y/N)" << endl;
		char key;
		while (cin >> key, cin.fail() || (key != 'Y' && key != 'y' && key != 'n' && key != 'N'))
		{
			cout << "illegal input, input again: ";
			cin.clear();
			cin.ignore(1024, '\n');
		}
		if (key == 'Y')
		{
			//regist(name);
		}
		else
		{
			return;
		}
	}
}