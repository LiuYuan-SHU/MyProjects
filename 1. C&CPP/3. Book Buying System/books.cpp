#include"Books.h"

void Liuyuan::printBookInfo(int style, string key)
{
	bool printed = false;
	unsigned amount = 0;

	cout << "========== print books info ==========" << endl;
	if (style == ALL)
	{
		for (unsigned i = 0; i < books_length; i++)
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
	else if (style == __ID)
	{
		for (unsigned i = 0; i < books_length; i++)
		{
			if (books[i].id == key)
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
		if (printed) { cout << "/ found " << amount << " record intotal" << endl; }
		else { cout << "/ didn't found any record, please check your key" << endl; }
	}
	else if (style == NAME)
	{
		for (unsigned i = 0; i < books_length; i++)
		{
			if (books[i].name == key)
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
		if (printed) { cout << "/ found " << amount << " record intotal" << endl; }
		else { cout << "/ didn't found any record, please check your key" << endl; }
	}
	else if (style == AUTHOR)
	{
		for (unsigned i = 0; i < books_length; i++)
		{
			if (books[i].author == key)
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
		if (printed) { cout << "/ found " << amount << " record intotal" << endl; }
		else { cout << "/ didn't found any record, please check your key" << endl; }
	}
	else if (style == CATEGORY)
	{
		for (unsigned i = 0; i < books_length; i++)
		{
			if (books[i].category == key)
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
		if (printed) { cout << "/ found " << amount << " record intotal" << endl; }
		else { cout << "/ didn't found any record, please check your key" << endl; }
	}
	else
	{
		cout << "/ Style is not defined" << endl;
	}
	cout << "======================================" << endl;
}

int Liuyuan::getBookIndex(string value, int style)
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


int Liuyuan::buyBook(string bookName, unsigned& param_containUnitPrice, unsigned amount, int style)
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
