#ifndef BOOKS
#define BOOKS

#include"Global.h"
#include<iostream>
#include<string>
#include<vector>

#define MAX_AMOUNT	100

#define ALL			100
#define __ID    	101
#define NAME    	102
#define AUTHOR 		103
#define CATEGORY	104

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

namespace Liuyuan
{
	typedef struct
	{
		string id;			//store the id			of book
		string name;		//store the name		of book
		string author;		//store the author		of book
		string category;	//store the category	of book
		int unit_price;		//store the unit price	of book
		int amout;			//store the amount		of book
	} book;

	static vector<book> books{
		{"1001","BOOK_NAME","AUTHOR_NAME","CATEGORY_NAME",34,50},
		{"1002","BOOK_NAME","AUTHOR_NAME","CATEGORY_NAME",38,20},
		{"1003","BOOK_NAME","AUTHOR_NAME","CATEGORY_NAME",31,30},
		{"1004","BOOK_NAME","AUTHOR_NAME","CATEGORY_NAME",40,40},
		{"2001","BOOK_NAME","AUTHOR_NAME","CATEGORY_NAME",24,5},
		{"2002","BOOK_NAME","AUTHOR_NAME","CATEGORY_NAME",28,35},
		{"2003","BOOK_NAME","AUTHOR_NAME","CATEGORY_NAME",32,10},
		{"2004","BOOK_NAME","AUTHOR_NAME","CATEGORY_NAME",36,8},
		{"3001","BOOK_NAME","AUTHOR_NAME","CATEGORY_NAME",23,30},
		{"3002","BOOK_NAME","AUTHOR_NAME","CATEGORY_NAME",37,2},
		{"3003","BOOK_NAME","AUTHOR_NAME","CATEGORY_NAME",20,18},
		{"3004","BOOK_NAME","AUTHOR_NAME","CATEGORY_NAME",30,60}
	};

	// struct to store book information
	static book books_a[] = {
		{"1001","BOOK_NAME","AUTHOR_NAME","CATEGORY_NAME",34,50},
		{"1002","BOOK_NAME","AUTHOR_NAME","CATEGORY_NAME",38,20},
		{"1003","BOOK_NAME","AUTHOR_NAME","CATEGORY_NAME",31,30},
		{"1004","BOOK_NAME","AUTHOR_NAME","CATEGORY_NAME",40,40},
		{"2001","BOOK_NAME","AUTHOR_NAME","CATEGORY_NAME",24,5},
		{"2002","BOOK_NAME","AUTHOR_NAME","CATEGORY_NAME",28,35},
		{"2003","BOOK_NAME","AUTHOR_NAME","CATEGORY_NAME",32,10},
		{"2004","BOOK_NAME","AUTHOR_NAME","CATEGORY_NAME",36,8},
		{"3001","BOOK_NAME","AUTHOR_NAME","CATEGORY_NAME",23,30},
		{"3002","BOOK_NAME","AUTHOR_NAME","CATEGORY_NAME",37,2},
		{"3003","BOOK_NAME","AUTHOR_NAME","CATEGORY_NAME",20,18},
		{"3004","BOOK_NAME","AUTHOR_NAME","CATEGORY_NAME",30,60}
	};
	//store the amount of books
	unsigned static books_length = books.size();

	//print the information of books, use `style` and `key` to search
	void printBookInfo(int style = ALL, string key = "");

	//getters and setters

	//get the index of books, defaultly search with ID
	//if success, return the index of the book
	//else return FAIL
	int getBookIndex(string id);

	//get the unit price of the book
	int getBookUnitPrice(int index);

	//set the amount of 
	//WARNING: no judgement on index
	inline void setBookAmount(unsigned int index, int amount = getChoice(0, MAX_AMOUNT)) { books[index].amout = amount; }

	//buy book
	//param_containUnitPrice need a argument to store the price
	//amount is the amount of the books to buy, defaultly buy one book
	//style is the way to search the book, defaultly use ID
	short book_foundAndEnough(string bookID, unsigned amount = 1);
}

#endif