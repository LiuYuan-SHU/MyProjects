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

namespace Liuyuan
{
	class Buyer;
	
	//stores the rate for different star users
	static constexpr double rate[] = { 1, 0.95, 0.9, 0.85, 0.8, 0.75 };

	//abstract class buyer
	class Buyer
	{
	protected:
		//store the id of the buyer
		unsigned int _id;
		//store the password
		string _password;					
		//store the name
		string _name;                     
		//store the address of the buyer
		string _address;                       
		//store the balance
		double _balance;                        
		//store the payment
		double _mypay;                          
	public:
		//construction, only set basic information, but do not increase numOfRegister
		Buyer(string name, string password, string address, double balance = 0, double mypay = 0) :
			_name(name), _password(password), _address(address), _balance(balance), _mypay(mypay) {}
		//No copy struction is provided
		//Use default destruction

		//Tool function
		//getter and setter
		inline int getID() { return this->_id; }
		//password getter/setter
		inline string getPassword() { return this->_password; }
		inline void setPassword(string newPassword) { this->_password = newPassword; }
		//name getter/setter
		inline string getName() { return this->_name; }
		inline void setName(string newName) { this->_name = newName; }
		//address getter/setter
		inline string getAddress() { return this->_address; }
		inline void setAddress(string newAddress) { this->_address = newAddress; }
		//balance getter/setter
		inline double getBalance() { return this->_balance; } 
		inline void setBalance(double newBalance) { this->_balance = newBalance; }
		//mypay getter/setter
		inline double getMypay() { return this->_mypay; }
		inline void setMypay(double newMypay) { this->_mypay = newMypay; }
		//add increase to mypay
		inline void raisePayment(unsigned int increase) { this->_mypay += increase; }

		//calculate the payment for different buyers
		virtual inline double calculatePay(unsigned unitPrice, unsigned amount) const = 0;
		//return the rate
		virtual inline double getRate() const = 0;
		//print the information of the buyer
		void printInfo(string userLevel, double userRate);
		//judge if the password is correct
		inline bool isPassword(string password) const { return (this->_password == password); }
		//judge if the usr has enough balance
		virtual bool hasEnoughBalance(int unitPrice, unsigned amount) const;
		//buy book
		virtual int buyBook();
	};

	//Ordinary Buyer Class
	class Layfork : public Buyer
	{
	private:
		//store the number of registers
		//init of this is in Buyers.cpp
		static unsigned int numOfRegister;	

		//the rate for all layforks are 1
		static constexpr double rate = 1;   
	public:
		//constructor
		Layfork(string name, string password, string address, double balance = 0, double mypay = 0);

		//get rate
		inline double getRate() const { return Layfork::rate; }

		//calculate the payment
		inline double calculatePay(unsigned unitPrice, unsigned amount) const
		{
			return static_cast<double>(unitPrice) * static_cast<double>(amount);
		}
	};

	class Number : public Buyer
	{
	private:
		//store the number of registers
		//init of this is in Buyers.cpp
		static unsigned int numOfRegister;		  

		//use star to get the rate
		unsigned short _star;   
	public:
		//constructor
		Number(string name, string password, string address, unsigned short star = 0, double balance = 0, double mypay = 0);

		//calculate the payment
		double calculatePay(unsigned unitPrice, unsigned amount) const
		{
			return static_cast<double>(unitPrice) * static_cast<double>(amount) * rate[this->_star];
		}

		inline double getRate() const { return rate[this->_star]; }
		inline unsigned short getStar() const { return this->_star; }
	};

	class Honoured_guest : public Buyer
	{
	private:
		//store the number of registers
		//init of this is in Buyers.cpp  
		static unsigned int numOfRegister;		
		
		//store the rate of honoured guest
		double _rate;
	public:
		//constructor
		Honoured_guest(string name, string password, string address, double rate = 1, double balance = 0, double mypay = 0);

		//calculate the payment
		inline double calculatePay(unsigned unitPrice, unsigned amount) const
		{
			return static_cast<double>(unitPrice) * static_cast<double>(amount) * this->_rate;
		}

		inline double getRate() const { return this->_rate; }
	};

	//login/logout functions
	//return if superUsr
	bool isSuperUsr();
	//set superUsr
	void setSuperUsr(bool status);
	//return logined
	bool isLogined();
	//set logined as false
	void logout();
	//return account pointer
	Buyer* getLogin_accountPtr();
	//set account pointer as nullptr
	void setLogin_accountPtr(Buyer* newPtr = nullptr);
	//return the level of the user
	string getLogin_level();
	//set the level of the user as ""
	void setLogin_level(string newLevel = "");

	//Buyers operation functions
	//add three existing users to vector
	void initBuyers();				
	//print off the guest in the vector
	void printGuest();
	//find id
	Buyer* findId(unsigned int id);
	//login system
	int login(string id, string password);		
	//search if there has an account with same name in the vector
	void searchName(string name);			
	//regist a new account
	void regist(string name);	
	//sort guestList
	void sortGuest();
	//return guest list
	vector<Buyer*>* getGuestListAddress();
}


#endif // !BUYER