#ifndef GLOBAL
#define GLOBAL

#include<iostream>

using std::cin;
using std::cout;
using std::endl;

#define SUCCESS     1
#define CANCEL      0
#define FAIL        -1
#define NOT_FOUND   -2

//use different system command depending on different OS
#ifdef __unix__
#define CLEAR ststem("clear")
#elif defined(_WIN32) | defined(WIN32)
#define CLEAR system("cls")
#endif // __unix__

#endif // !GLOBAL
