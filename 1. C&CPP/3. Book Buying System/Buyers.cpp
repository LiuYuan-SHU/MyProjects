#include"Global.h"
#include"Global.cpp"
#include"Buyers.h"
#include"Books.h"
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

//functor for sort()
bool greaterID(Buyer* left, Buyer* right)
{
	return (left->getID() > right->getID());
}

void Liuyuan::initBuyers()
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

bool Liuyuan::Buyer::hasEnoughBalance(int unitPrice, unsigned amount) const
{
	//protection
	if(unitPrice == OUT_OF_RANGE)
	{
		return false;
	}
	return this->_balance >= this->calculatePay(unitPrice, amount); 
}

void Liuyuan::printGuest()
{
	cout << "========== print guests info ==========" << endl;
	//'i' is a pointer of kind Buyers*
	//use dynamic_cast to check which derived class it points
	//if it is a pointer points the derived class object in "()", it returns a pointer
	//otherwise returns nullptr
	for (auto i : guestList)
	{
		if (dynamic_cast<Layfork*>(i)) { i->printInfo("Layfork", 1); }
		else if (dynamic_cast<Number*>(i)) { i->printInfo("Number", rate[dynamic_cast<Number*>(i)->getStar()]); }
		else { i->printInfo("Honoured", dynamic_cast<Honoured_guest*>(i)->getRate()); }
		cout << "+=====================================+" << endl;
	}
	cout << "=======================================" << endl;
}

//constructor of layfork
Layfork::Layfork(string name, string password, string address, double balance, double mypay) :
	Buyer(name, password, address, balance, mypay)
{
	this->_id = 100000 + (++numOfRegister);
}

//constructor of number
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

//constructor of honoured
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

//login the system
int Liuyuan::login(string id, string password)
{
	//if password contains '/', cancel login with this account
	for(auto i : password)
	{
		if(i == '/')
		{
			cout << "Canceled" << endl;
			return CANCEL;
		}
	}

	//transform the string into int
	int id_int = 0;		//store the result
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

	//find the user account with same ID
	for (auto i : guestList)
	{
		//if find ID
		if (i->getID() == id_int)
		{
			//if the password is correct
			if (i->isPassword(password))
			{
				//print info
				cout << "Logined" << endl;

				//set login status
				logined = true;
				logined_accountPtr = i;
				if (dynamic_cast<Layfork*>(i)) { logined_level = "Layfork"; }
				else if (dynamic_cast<Number*>(i)) { logined_level = "Number"; }
				else { logined_level = "Honoured"; }

				return SUCCESS;
			}
			//if the password is not correct
			else
			{
				return FAIL;
			}
		}
	}
	//if not find
	return FAIL;
}

//search the account with same name in the vector
void Liuyuan::searchName(string name)
{
	cout << "You input a name, searching..." << endl;

	bool found = false;			//restore if find account(s) that have(has) the same name
	for (auto i : guestList)
	{
		//if found the first same name, print info
		if (i->getName() == name)
		{
			found ? (cout << "") : (cout << "===== found same name as follows: =====\n");
			cout << "ID:\t" << i->getID() << "\t" << "Name:\t" << i->getName() << endl;
		}
	}
	//if there is no one with same name
	if (!found)
	{
		cout << "you haven't registed yet, do you want to regist? (Y/N)" << endl;
		char key = getData<char>();;	//whether to regist or not

		if (key == 'Y' || key == 'y')
		{
			regist(name);
		}
		else
		{
			cout << "Give up registing, return" << endl;
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
	
	int choice = getChoice(1, 4);

	if(choice == 4)
	{
		cout << "Cancel Regist" << endl;
		system("pause");
		return;
	}

	//arguments to store datas which are to contruct new user account
	string password;
	string address;
	double balance = 0;
	double mypay = 0;
	short star = 0;
	double rate = 0;

	//get password
	cout << "input password:";
	while(password = getData<string>(), !judgeNoSpace(password) && judgeNoSlash(password))
	{
		cout << "illegal input, input again: ";
	}
	Fflush();
	
	//get address
	cout << "input address: ";
	getline(cin,address);
	cin.clear();

	//get balance
	cout << "input balance: ";
	balance = getData<double>();
	Fflush();

	//construct account depending on choice
	switch(choice)
	{
		//construct layfork
	case 1:
		cout << "=============== REGIST Layfork ===============" << endl;
		guestList.push_back(new Layfork(name, password, address, balance));
		break;
		//construct number
	case 2:
		cout << "=============== REGIST Number ===============" << endl;
		cout << "input star of the guest: ";
		while(star = getData<short>(), star < 1 || star > 5)
		{
			cout << "out of range, please input an integer in [1,5]: ";
		}
		guestList.push_back(new Number(name, password, address, star, balance));
		break;
		//construct honoured
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
	//sort the guest list by ID
	sort(guestList.rbegin(),guestList.rend(),greaterID);
}

int Liuyuan::Buyer::buyBook()
{
	//get book id and amount
	cout << "Input book id: ";
	string bookID = getData<string>();
	Fflush();
	cout << "input amount you want to buy: ";
	unsigned int bookAmount = getData<unsigned int>();
	Fflush();

	int bookIndex;
	//judge if the book exists and amount is enough
	switch (bookIndex = book_foundAndEnough(bookID, bookAmount))
	{
	case FAIL:
		cout << "log: function book_foundAndEnough quit with code FAIL" << endl;
		cout << "Please check function" << endl;
		cout << "------------------------------" << endl;
		return FAIL;
	case INCORRECT_ID:
	case NOT_FOUND:
		cout << "Books with your ID: " << bookID << " is not found, please check your ID" << endl;
		return INCORRECT_ID;
	case OUT_OF_RANGE:
		cout << "the index of book is out of range" << endl;
		return OUT_OF_RANGE;
	case NOT_ENOUGH:
		cout << "The amount of book is not enough, please check the amount in book information" << endl;
		return NOT_ENOUGH;
	default:
		cout << "Book FOUND and amount is ENOUGH" << endl;		
	}

	//get unit price of the book
	unsigned int unitPrice = getBookUnitPrice(bookIndex);

	//judge if the user has enough balance
	//if doesn't
	if(!logined_accountPtr->hasEnoughBalance(getBookUnitPrice(bookIndex),bookAmount))
	{
		cout << "Your balance is not enough, please recharge" << endl;
		return CANCEL;
	}
	//if does
	else
	{
		//decrease book amount
		books[bookIndex].amout -= bookAmount;
		//decrease user balance
		Buyer* account = getLogin_accountPtr();
		double payment = account->calculatePay(unitPrice,bookAmount);
		account->setBalance(account->getBalance() - payment);
		//increase user mypay
		account->raisePayment(payment);
		return SUCCESS;
	}
	return UNEXPECTED_ERROR;
}