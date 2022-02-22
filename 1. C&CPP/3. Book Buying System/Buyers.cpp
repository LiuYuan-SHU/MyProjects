#include"Buyers.h"
#include<iostream>

using std::cin;
using std::cout;
using std::endl;
using namespace Liuyuan;

void Buyer::printInfo(string userLevel, double userRate)
{
    cout << "======== USER INFO ========" << endl;
    cout << "/ User Level:\t" << userLevel  << '/' << endl;
    cout << "/ User ID:\t" << this->_id << '/' << endl;
    cout << "/ User name:\t" << this->_name << '/' << endl;
    cout << "/ User address:\t" << this->_address << '/' << endl;
    cout << "/ User balance:\t" << this->_balance << '/' << endl;
    cout << "/ User mypay:\t" << this->_mypay << '/' << endl;
    cout << "/ User rate:\t" << userRate << '/' << endl;
    cout << "===========================" << endl << endl;
}

Layfork::Layfork(string name, string address,double balance, double mypay):
Buyer(name, address, balance, mypay)
{
    this->_id = 100000 +(++numOfRegister);
}

Number::Number(string name, string address, unsigned short star, double balance, double mypay):
Buyer(name, address, balance, mypay)
{
    if(star >= 5)
    {
        cout << "illegal star number! Construction FAIL" << endl;
        exit(-1);
    }
    this->_star = star;
    this->_id = 200000 +(++numOfRegister);
}

Honoured_guest::Honoured_guest(string name, string address,double rate, double balance, double mypay):
Buyer(name, address, balance, mypay)
{
    if(rate <= 0 || rate > 1)
    {
        cout << "illegal rate, construction FAIL" << endl;
        exit(-1);
    }
    this->_rate = rate;
    this->_id = 300000 +(++numOfRegister);
}

void initSystem()
{
    Layfork::setNum();
    Number::setNum();
    Honoured_guest::setNum();
}