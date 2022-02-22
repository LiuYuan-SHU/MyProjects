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

unsigned int Buyer::numOfRegister = 0;
vector<Buyer*> guestList;

bool greaterID(Buyer* left, Buyer* right)
{
	return (left->getID() > right->getID());
}

void Liuyuan::init()
{
	guestList.push_back(new Layfork("ZhangXiaobin", "99th, Shangda Road", 200));
	guestList.push_back(new Number("LiShichun", "80th, Nanchen Road", 2, 400));
	guestList.push_back(new Honoured_guest("WangSicheng", "70th, Jinqiu Road", 0.7, 600));
	sort(guestList.rbegin(), guestList.rend(),greaterID);
}

void Buyer::printInfo(string userLevel, double userRate)
{
	cout << "/ User Level:\t" << userLevel << endl;
	cout << "/ User ID:\t" << this->_id << endl;
	cout << "/ User name:\t" << this->_name << endl;
	cout << "/ User address:\t" << this->_address << endl;
	cout << "/ User balance:\t" << this->_balance << endl;
	cout << "/ User mypay:\t" << this->_mypay << endl;
	cout << "/ User rate:\t" << userRate << endl;
}

void Liuyuan::printGuest()
{
	cout << "========== print guests info ==========" << endl;
	for (auto i : guestList)
	{
		if (dynamic_cast<Layfork*>(i)) { i->printInfo("Layfork", 1); }
		else if (dynamic_cast<Number*>(i)) { i->printInfo("Number", Number::rate[dynamic_cast<Number*>(i)->getStar()]); }
		else { i->printInfo("Honoured", dynamic_cast<Honoured_guest*>(i)->getRate()); }
		cout << "+=====================================+" << endl;
	}
	cout << "=======================================" << endl;
}

Layfork::Layfork(string name, string address, double balance, double mypay) :
	Buyer(name, address, balance, mypay)
{
	this->_id = 100000 + (++numOfRegister);
}

Number::Number(string name, string address, unsigned short star, double balance, double mypay) :
	Buyer(name, address, balance, mypay)
{
	if (star >= 5)
	{
		cout << "illegal star number! Construction FAIL" << endl;
		exit(-1);
	}
	this->_star = star;
	this->_id = 200000 + (++numOfRegister);
}

Honoured_guest::Honoured_guest(string name, string address, double rate, double balance, double mypay) :
	Buyer(name, address, balance, mypay)
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

