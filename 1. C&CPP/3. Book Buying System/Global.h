#ifndef GLOBAL
#define GLOBAL

#include<string>

using std::string;

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

namespace Liuyuan
{
	//clear cin stream
	inline void Fflush();

	//get an integer in range [lowLimit, upperLimit]
	inline int getChoice(int lowerLimit, int upperLimit);

	//get data with specific type
	template<class T>
	inline T getData();

	//judge the string with the condition 
	inline bool judgeNoSpace(string judge);
	inline bool judgeNoSlash(string judge);
}

#endif // !GLOBAL
