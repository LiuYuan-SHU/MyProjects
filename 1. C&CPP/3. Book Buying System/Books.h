#ifndef BOOKS
#define BOOKS

#include"Global.h"
#include<iostream>
#include<string>

#define __ID      100
#define NAME    101

using std::string;
using std::cin;
using std::cout;
using std::endl;

namespace Liuyuan
{
	typedef struct
	{
		string id;
		string name;
		string author;
		string category;
		int unit_price;
		int amout;
	} book;

	// struct to store book information
	book books[] = {
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
		{"3004","BOOK_NAME","AUTHOR_NAME","CATEGORY_NAME",30,60},
	};
	//store the amount of books
	unsigned books_length = sizeof(books) / sizeof(*books);

	//get the index of books, defaultly search with ID
	//if success, return the index of the book
	//else return FAIL
	int getBookIndex(string value, int style = __ID)
	{
		int index = 0;      //store the index of the book
		//find book index with id
		if (style == __ID)
		{
			for (int i = 0; i < books_length; i++, index++)
			{
				if (books[i].id == value)
				{
					return index;
				}
			}
		}
		//find book index with name
		else if (style == NAME)
		{
			for (int i = 0; i < books_length; i++, index++)
			{
				if (books[i].name == value)
				{
					return index;
				}
			}
		}
		//if the style is wrong
		else
		{
			cout << "---------------" << endl;
			cout << "illegal style" << endl;
			cout << "SEARCH FAIL" << endl;
			cout << "---------------" << endl;
		}
		return FAIL;
	}

	//buy book
	//param_containUnitPrice need a argument to store the price
	//amount is the amount of the books to buy, defaultly buy one book
	//style is the way to search the book, defaultly use ID
	int buyBook(string bookName, unsigned& param_containUnitPrice, unsigned amount = 1, int style = __ID)
	{
		int index = getBookIndex(bookName, style);
		//if the amount is enough, return the price of the book, minus amout
		//and return SUCCESS
		if (books[index].amout - amount > 0)
		{
			param_containUnitPrice = books[index].unit_price;
			books[index].amout -= amount;
			return SUCCESS;
		}
		//else, buy FAIL
		else
		{
			cout << "amout is out of range, buy fail" << endl;
			param_containUnitPrice = 0;
			return FAIL;
		}

		return FAIL;
	}
}

#endif