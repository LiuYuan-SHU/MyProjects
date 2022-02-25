# Book Purchase System

> A project written for a course in the College of Communications

## Note

View question in [Question](./Question)

## Project Structure

```mermaid
classDiagram
class Global{
	<<Head File>>
	<<Tool>>
	#define SUCCESS
	#define CANCEL
	#define FAIL
	#define INCORRECT_ID
	#define OUT_OF_RANGE
	#define UNEXPECTED_ERROR
	#define NOT_FOUND
	#define NOT_ENOUGH
	Flush()
	getChoice(int lowerLimit, int upperLimit)
	getData()
	judgeNoSpace()
	judgeNoSlash()
}

class book{
	<<struct>>
	string id
	string name
	string author
	string category
	int unit_price
	int amount
}

class Books{
	<<Data>>
	vector : book*
	printBookInfo()
	getBookIndex()
	getBookUnitPrice()
	getBooksAddress()
	--setters()
	book_foundAndEnough(string id, short amount = 1)	
	book_findBook(string id)	return pointer
	book_idExist(string id)		return bool
	greaterID()			functor
	sortBook()
}

class Buyers_h{
	<<Head File>>
	vector : Buyer*
	initBuyers()
	printGuest()
	searchName()
	regist()
	greaterID()
	sortGuest()
	getGuestListAddress()
}

Books <|-- book : Data Structure Element
Books <|-- Global : Basic Tool Functions

class SuperUsr{
	<<Super User Status>>
	bool super_usr
	bool logined
	Buyer* logined_accountPtr
	string logined_level
	
	isSuperUsr()
	setSuperUsr(bool status)
	isLogined()
	logout()
	Buyers* getLogin_accountPtr()
	setLogin_accountPtr()
	getLogin_level()
	setLogin_level()
}

class Buyer{
	<<Base Virtual Class>>
	_id
	_password
	_name
	_address
	_balance
	_mypay
	--getterAndSetter()
	virtual calculatePay()
	virtual getRate()
	printInfo()
	isPassword()
	virtual hasEnoughBalance()
	virtual bayBook()
}

class Layfork{
	static numOfRegist
	rate
}

class Number{
	static numOfRegist
	_star
	getStar()
}

class Honoured{
	static numOfRegist
	_rate
}

Buyers_h <|-- Global : Basic Tool Functions
Buyers_h <|-- Buyer : Class
Buyers_h <|-- SuperUsr : Super User Data Status & Functions
Buyer <|-- Layfork : Derived from
Buyer <|-- Number : Derived from
Buyer <|-- Honoured : Derived from

class UI_h{
	<<Head File>>
	<<UI>>
	UI_basic()
	UI_login()
	UI_logined()
	UI_logined_superUsr()
	UI_logined_superUsr_setGuest()
	UI_logined_superUsr_changeKind(unsigned int id)
	UI_logined_superUsr_changeLayfork(Layfork* ptr)
	UI_logined_superUsr_changeNumber(Number* ptr)
	UI_logined_superUsr_changeHonoured(Honoured_guest* ptr)
	UI_logined_superUsr_setBooks()
	UI_buyBook()
}

UI_h <|-- Global : Supports
UI_h <|-- Books : Supports
UI_h <|-- Buyers_h : Supports
```

<center><b><i>Schematic Diagram of Project Structure</i></b></center>

## Running Progress

```mermaid
flowchart LR;
start(Start) --> initBuyers(initBuyers)
initBuyers --> judge{isSuperUsr /<br/> isLogined /<br/> None}
judge --isSuperUsr--> UI_logined_superUsr
judge --isLogined--> UI_logined
UI_logined --> printInfo & buyBook
judge --None--> UI_basic
UI_basic --> UI_login
UI_login --userName--> regist
UI_login --password--> UI_logined --logout--> UI_basic
UI_login --super--> UI_logined_superUsr --logout--> UI_basic
UI_login --cancel-->UI_basic
UI_logined_superUsr --> UI_logined_superUsr_changeKind & UI_logined_superUsr_setBooks
UI_logined_superUsr_changeKind --> UI_logined_superUsr_changeLayfork & UI_logined_superUsr_changeNumber & UI_logined_superUsr_changeHonoured

```

<center><b><i>Schematic Diagram of Running Progress </i></b></center>

## Learned & Used Interesting Skills

1. global `static` variables are only usable in current file
2. `greaterID()` functor
3. `static_cast<>()` & `dynamic_cast<>()`
4. *<u>undefined reference to</u>* & *<u>multiple definition of</u>*
