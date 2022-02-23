#include"Books.h"
#include"Global.h"
#include<iostream>
#include<string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

void Liuyuan::printBookInfo(int style, string key)
{
	bool printed = false;	//store if printed information
	unsigned amount = 0;	//store the amout of printed books

	cout << "========== print books info ==========" << endl;
	//print books with specific style
	//print as ALL
	if (style == ALL)
	{
		for (unsigned i = 0; i < books_length; i++)
		{
			amount++;
			cout << "/ Book ID:\t\t" << books[i]->id << endl;
			cout << "/ Book name:\t\t" << books[i]->name << endl;
			cout << "/ Book author:\t\t" << books[i]->author << endl;
			cout << "/ Book category:\t" << books[i]->category << endl;
			cout << "/ Book unit price:\t" << books[i]->unit_price << endl;
			cout << "/ Book amout:\t\t" << books[i]->amout << endl;
			cout << "+====================================+" << endl;
		}
		cout << "/ found " << amount << " record intotal" << endl;
	}
	//print with specific ID
	else if (style == __ID)
	{
		for (unsigned i = 0; i < books_length; i++)
		{
			if (books[i]->id == key)
			{
				printed = true;
				amount++;
				cout << "/ Book ID:\t\t" << books[i]->id << endl;
				cout << "/ Book name:\t\t" << books[i]->name << endl;
				cout << "/ Book author:\t\t" << books[i]->author << endl;
				cout << "/ Book category:\t" << books[i]->category << endl;
				cout << "/ Book unit price:\t" << books[i]->unit_price << endl;
				cout << "/ Book amout:\t\t" << books[i]->amout << endl;
				cout << "+====================================+" << endl;
			}
		}
		if (printed) { cout << "/ found " << amount << " record in total" << endl; }
		else { cout << "/ didn't found any record, please check your key" << endl; }
	}
	//print with specific name
	else if (style == NAME)
	{
		for (unsigned i = 0; i < books_length; i++)
		{
			if (books[i]->name == key)
			{
				printed = true;
				amount++;
				cout << "/ Book ID:\t\t" << books[i]->id << endl;
				cout << "/ Book name:\t\t" << books[i]->name << endl;
				cout << "/ Book author:\t\t" << books[i]->author << endl;
				cout << "/ Book category:\t" << books[i]->category << endl;
				cout << "/ Book unit price:\t" << books[i]->unit_price << endl;
				cout << "/ Book amout:\t\t" << books[i]->amout << endl;
				cout << "+====================================+" << endl;
			}
		}
		if (printed) { cout << "/ found " << amount << " record intotal" << endl; }
		else { cout << "/ didn't found any record, please check your key" << endl; }
	}
	//print with specific author
	else if (style == AUTHOR)
	{
		for (unsigned i = 0; i < books_length; i++)
		{
			if (books[i]->author == key)
			{
				printed = true;
				amount++;
				cout << "/ Book ID:\t\t" << books[i]->id << endl;
				cout << "/ Book name:\t\t" << books[i]->name << endl;
				cout << "/ Book author:\t\t" << books[i]->author << endl;
				cout << "/ Book category:\t" << books[i]->category << endl;
				cout << "/ Book unit price:\t" << books[i]->unit_price << endl;
				cout << "/ Book amout:\t\t" << books[i]->amout << endl;
				cout << "+====================================+" << endl;
			}
		}
		if (printed) { cout << "/ found " << amount << " record intotal" << endl; }
		else { cout << "/ didn't found any record, please check your key" << endl; }
	}
	//print with specific category
	else if (style == CATEGORY)
	{
		for (unsigned i = 0; i < books_length; i++)
		{
			if (books[i]->category == key)
			{
				printed = true;
				amount++;
				cout << "/ Book ID:\t\t" << books[i]->id << endl;
				cout << "/ Book name:\t\t" << books[i]->name << endl;
				cout << "/ Book author:\t\t" << books[i]->author << endl;
				cout << "/ Book category:\t" << books[i]->category << endl;
				cout << "/ Book unit price:\t" << books[i]->unit_price << endl;
				cout << "/ Book amout:\t\t" << books[i]->amout << endl;
				cout << "+====================================+" << endl;
			}
		}
		if (printed) { cout << "/ found " << amount << " record intotal" << endl; }
		else { cout << "/ didn't found any record, please check your key" << endl; }
	}
	//if the print style is undefined
	else
	{
		cout << "/ Style is not defined" << endl;
	}
	cout << "======================================" << endl;
}

int Liuyuan::getBookIndex(string id)
{
	int index = 0;      //store the index of the book
	//find book index with id
	for (unsigned i = 0; i < books_length; i++, index++)
	{
		if (books[i]->id == id)
		{
			return index;
		}
	}
	
	return INCORRECT_ID;
}

int Liuyuan::getBookUnitPrice(int index)
{
	//protection
	if(index < 0 || index >= books_length)
	{
		cout << "illegal index, get price fail" << endl;
		return OUT_OF_RANGE;
	}

	return books[index]->unit_price;
}


short Liuyuan::book_foundAndEnough(string bookID, unsigned amount)
{
	int index = getBookIndex(bookID);

	//protection
	if(index == INCORRECT_ID)
	{
		return INCORRECT_ID;
	}

	//if the amount is enough, return the price of the book, minus amount
	//and return SUCCESS
	if (books[index]->amout >= amount)
	{
		return index;
	}
	//else, buy FAIL
	else
	{
		return OUT_OF_RANGE;
	}

	return FAIL;
}
