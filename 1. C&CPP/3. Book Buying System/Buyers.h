#ifndef BUYERS
#define BUYERS


#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::exit;
using std::vector;

/***********************************
 *
 *
 *
 * *********************************/

namespace Liuyuan
{
	class Buyer;

	static bool super_usr = false;
	static bool logined;
	static Buyer* logined_accountPtr;
	static string logined_level;
	
	//stores the rate for different star users
	static constexpr double rate[] = { 1, 0.95, 0.9, 0.85, 0.8, 0.75 };
	//stores all the registed guests
	static vector<Buyer*> guestList;

	//abstract class buyer
	class Buyer
	{
	protected:
		unsigned int _id;                       //store the id of the buyer
		string _password;						//store the password
		string _name;                           //store the name
		string _address;                        //store the address of the buyer
		double _balance;                        //store the balance
		double _mypay;                          //store the payment
	public:
		//construction, only set basic information, but do not increase numOfRegister
		Buyer(string name, string password, string address, double balance = 0, double mypay = 0) :
			_name(name), _password(password), _address(address), _balance(balance), _mypay(mypay) {}
		//No copy struction is provided
		//Use default destruction

//Tool function
//getter and setter
		int getID() { return this->_id; }
		string getName() { return this->_name; }

		//calculate the payment for different buyers
		virtual inline double calculatePay(unsigned unitPrice, unsigned amount) const = 0;
		//return the rate
		virtual inline double getRate() const = 0;
		//print the information of the buyer
		void printInfo(string userLevel, double userRate);
		//judge if the password is correct
		bool isPassword(string password) { return (this->_password == password); }
	};

	//Ordinary Buyer Class
	class Layfork : public Buyer
	{
	private:
		//restore the number of registers
		static unsigned int numOfRegister;		//init of this is in Buyers.cpp  

		static constexpr double rate = 1;   //the rate for all layforks are 1
	public:
		//constructor
		Layfork(string name, string password, string address, double balance = 0, double mypay = 0);

		//get rate
		double getRate() const { return Layfork::rate; }

		//calculate the payment
		double calculatePay(unsigned unitPrice, unsigned amount) const
		{
			return static_cast<double>(unitPrice) * static_cast<double>(amount);
		}
	};

	class Number : public Buyer
	{
	private:
		//restore the number of registers
		static unsigned int numOfRegister;		//init of this is in Buyers.cpp  

		unsigned short _star;   //use star to get the rate
	public:
		Number(string name, string password, string address, unsigned short star = 0, double balance = 0, double mypay = 0);

		double calculatePay(unsigned unitPrice, unsigned amount) const
		{
			return static_cast<double>(unitPrice) * static_cast<double>(amount) * rate[this->_star];
		}

		double getRate() const { return rate[this->_star]; }
		unsigned short getStar() { return this->_star; }
	};

	class Honoured_guest : public Buyer
	{
	private:
		//restore the number of registers
		static unsigned int numOfRegister;		//init of this is in Buyers.cpp  
		
		double _rate;
	public:
		Honoured_guest(string name, string password, string address, double rate = 1, double balance = 0, double mypay = 0);

		double calculatePay(unsigned unitPrice, unsigned amount) const
		{
			return static_cast<double>(unitPrice) * static_cast<double>(amount) * this->_rate;
		}

		double getRate() const { return this->_rate; }
	};

	template<class T>
	T getData();
	bool isLogined();
	void logout();
	Buyer* getLogin_accountPtr();
	void setLogin_accountPtr(Buyer* newPtr = nullptr);
	string getLogin_level();
	void setLogin_level(string newLevel = "");
	bool judgeNoSpace(string judge);
	bool judgeNoSlash(string judge);
	void init();
	void printGuest();
	int login(string id, string password);
	void searchName(string name);
	void regist(string name);
}


#endif // !BUYER