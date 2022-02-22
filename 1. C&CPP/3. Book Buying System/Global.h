#ifndef GLOBAL
#define GLOBAL

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
	inline int getChoice(int lowerLimit, int upperLimit);

	inline void Fflush();

	template<class T>
	inline T getData();
}

#endif // !GLOBAL
