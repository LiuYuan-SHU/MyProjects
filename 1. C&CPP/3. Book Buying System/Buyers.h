#ifndef BUYERS
#define BUYERS


#include<iostream>
#include<string>
#include<cstdlib>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::exit;

/***********************************
 *
 *
 *
 * *********************************/

namespace Liuyuan
{
	//abstract class buyer
	class Buyer
	{
	protected:
		//restore the number of registers
		static unsigned int numOfRegister;		//init of this is in Buyers.cpp  

		unsigned int _id;                       //restore the id of the buyer
		string _name;                           //restore the name
		string _address;                        //restore the address of the buyer
		double _balance;                        //restore the balance
		double _mypay;                          //restore the payment
	public:
		//construction, only set basic information, but do not increase numOfRegister
		Buyer(string name, string address, double balance = 0, double mypay = 0) :
			_name(name), _address(address), _balance(balance), _mypay(mypay) {}
		//No copy struction is provided
		//Use default destruction

//Tool function
//getter and setter
		static void setNum(unsigned int newNum = 0) { numOfRegister = newNum; }
		static unsigned int getNum() { return numOfRegister; }
		int getID() { return this->_id; }

		//calculate the payment for different buyers
		virtual inline double calculatePay(unsigned unitPrice, unsigned amount) const = 0;
		//print the information of the buyer
		void printInfo(string userLevel, double userRate);
	};

	//Ordinary Buyer Class
	class Layfork : public Buyer
	{
	private:
		static constexpr double rate = 1;   //the rate for all layforks are 1
	public:
		//constructor
		Layfork(string name, string address, double balance = 0, double mypay = 0);

		//calculate the payment
		double calculatePay(unsigned unitPrice, unsigned amount) const
		{
			return static_cast<double>(unitPrice) * static_cast<double>(amount);
		}
	};

	class Number : public Buyer
	{
	private:
		unsigned short _star;   //use star to get the rate
	public:
		//stores the rate for different star users
		static constexpr double rate[] = { 1, 0.95, 0.9, 0.85, 0.8, 0.75 };

		Number(string name, string address, unsigned short star = 0, double balance = 0, double mypay = 0);

		double calculatePay(unsigned unitPrice, unsigned amount) const
		{
			return static_cast<double>(unitPrice) * static_cast<double>(amount) * Number::rate[this->_star];
		}

		unsigned short getStar() { return this->_star; }
	};

	class Honoured_guest : public Buyer
	{
	private:
		double _rate;
	public:
		Honoured_guest(string name, string address, double rate = 1, double balance = 0, double mypay = 0);

		double calculatePay(unsigned unitPrice, unsigned amount) const
		{
			return static_cast<double>(unitPrice) * static_cast<double>(amount) * this->_rate;
		}

		double getRate() { return this->_rate; }
	};

	void init();
	void printGuest();
	bool login();
}


#endif // !BUYER