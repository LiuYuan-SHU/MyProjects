#ifndef TOOL_H
#define TOOL_H

#include <ctype.h>
#include<iostream>

using namespace std;

extern int priority[128];

void initTool();

bool isNegative(const char* current, const char* start);

void Fflush();

template<class T>
inline T getData()
{
	T input;
	while (cin >> input, cin.fail())
	{
		cout << "illegal input, input again: ";
		Fflush();
	}
	return input;
}

#endif
