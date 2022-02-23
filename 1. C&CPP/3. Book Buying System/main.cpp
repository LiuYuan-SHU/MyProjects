#include"Global.h"
#include"UI.h"
#include"Buyers.h"
#include"Books.h"
#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

using namespace Liuyuan;

int main()
{
	//init the system
	initBuyers();
	while (true)
	{
		if(isSuperUsr())
		{
			UI_logined_superUsr();
		}
		else if(isLogined())
		{
			UI_logined();
		}
		else
		{
			UI_basic();
		}
		CLEAR;
	}
}