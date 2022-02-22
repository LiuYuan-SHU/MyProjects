#ifndef BOOKS
#define BOOKS

#include"Global.h"
#include<iostream>
#include<string>

#define ALL			100
#define __ID    	101
#define NAME    	102
#define AUTHOR 		103
#define CATEGORY	104

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

	//print the information of books, use `style` and `key` to search
	void printBookInfo(int style = ALL, string key = "")
	{
		bool printed = false;
		unsigned amount = 0;

		cout << "========== print books info ==========" << endl;
		if(style == ALL)
		{
			for(unsigned i = 0; i < books_length; i++)
			{
				amount++;
				cout << "/ Book ID:\t\t" << books[i].id << endl;
				cout << "/ Book name:\t\t" << books[i].name << endl;
				cout << "/ Book author:\t\t" << books[i].author << endl;
				cout << "/ Book category:\t" << books[i].category << endl;
				cout << "/ Book unit price:\t" << books[i].unit_price << endl;
				cout << "/ Book amout:\t\t" << books[i].amout << endl;
				cout << "+====================================+" << endl;
			}
			cout << "/ found " << amount << " record intotal" << endl;
		}
		else if(style == __ID)
		{
			for(unsigned i = 0; i < books_length; i++)
			{
				if(books[i].id == key)
				{
					printed = true;
					amount++;
					cout << "/ Book ID:\t\t" << books[i].id << endl;
					cout << "/ Book name:\t\t" << books[i].name << endl;
					cout << "/ Book author:\t\t" << books[i].author << endl;
					cout << "/ Book category:\t" << books[i].category << endl;
					cout << "/ Book unit price:\t" << books[i].unit_price << endl;
					cout << "/ Book amout:\t\t" << books[i].amout << endl;
					cout << "+====================================+" << endl;
				}
			}
			if(printed) { cout << "/ found " << amount << " record intotal" << endl; }
			else { cout << "/ didn't found any record, please check your key" << endl; }
		}
		else if(style == NAME)
		{
			for(unsigned i = 0; i < books_length; i++)
			{
				if(books[i].name == key)
				{
					printed = true;
					amount++;
					cout << "/ Book ID:\t\t" << books[i].id << endl;
					cout << "/ Book name:\t\t" << books[i].name << endl;
					cout << "/ Book author:\t\t" << books[i].author << endl;
					cout << "/ Book category:\t" << books[i].category << endl;
					cout << "/ Book unit price:\t" << books[i].unit_price << endl;
					cout << "/ Book amout:\t\t" << books[i].amout << endl;
					cout << "+====================================+" << endl;
				}
			}
			if(printed) { cout << "/ found " << amount << " record intotal" << endl; }
			else { cout << "/ didn't found any record, please check your key" << endl; }
		}
		else if(style == AUTHOR)
		{
			for(unsigned i = 0; i < books_length; i++)
			{
				if(books[i].author == key)
				{
					printed = true;
					amount++;
					cout << "/ Book ID:\t\t" << books[i].id << endl;
					cout << "/ Book name:\t\t" << books[i].name << endl;
					cout << "/ Book author:\t\t" << books[i].author << endl;
					cout << "/ Book category:\t" << books[i].category << endl;
					cout << "/ Book unit price:\t" << books[i].unit_price << endl;
					cout << "/ Book amout:\t\t" << books[i].amout << endl;
					cout << "+====================================+" << endl;
				}
			}
			if(printed) { cout << "/ found " << amount << " record intotal" << endl; }
			else { cout << "/ didn't found any record, please check your key" << endl; }
		}
		else if(style == CATEGORY)
		{
			for(unsigned i = 0; i < books_length; i++)
			{
				if(books[i].category == key)
				{
					printed = true;
					amount++;
					cout << "/ Book ID:\t\t" << books[i].id << endl;
					cout << "/ Book name:\t\t" << books[i].name << endl;
					cout << "/ Book author:\t\t" << books[i].author << endl;
					cout << "/ Book category:\t" << books[i].category << endl;
					cout << "/ Book unit price:\t" << books[i].unit_price << endl;
					cout << "/ Book amout:\t\t" << books[i].amout << endl;
					cout << "+====================================+" << endl;
				}
			}
			if(printed) { cout << "/ found " << amount << " record intotal" << endl; }
			else { cout << "/ didn't found any record, please check your key" << endl; }
		}
		else
		{
			cout << "/ Style is not defined" << endl;
		}
		cout << "======================================" << endl;
	}

	//get the index of books, defaultly search with ID
	//if success, return the index of the book
	//else return FAIL
	int getBookIndex(string value, int style = __ID)
	{
		int index = 0;      //store the index of the book
		//find book index with id
		if (style == __ID)
		{
			for (unsigned i = 0; i < books_length; i++, index++)
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
			for (unsigned i = 0; i < books_length; i++, index++)
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