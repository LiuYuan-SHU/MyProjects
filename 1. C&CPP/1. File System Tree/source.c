#define _CRT_SECURE_NO_WARNINGS

#include"Commands.h"
#include"Tools.h"
#include<stdio.h>
#include<string.h>

int main()
{
	//initialization
	global_init();

	//definitions
	unsigned line_length = 0;

	while (TRUE)
	{
		line_length = getLine();
		splitLine(line_length);

		//print infomation
		printInfo();

		if (findCmd() != -1)
		{
			printf("\n=====FUNC FOUND=====\n");
			printf("=====FUNC EXECUTE=====\n");
			//printf("func found, pathname: %s\n", pathname);
			funcs[findCmd()]();
		}
		else
		{
			printf("invalid command, please input again\n");

		}
		//printf("find command ID: %d\n\n", findCmd());
	}

}