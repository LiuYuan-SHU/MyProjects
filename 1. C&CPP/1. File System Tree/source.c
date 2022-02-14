#define _CRT_SECURE_NO_WARNINGS

#include"Commands.h"
#include<stdio.h>
#include<string.h>

int main()
{
	//initialization
	global_init();

	while(1)
	{
		getLine();	
		printf("command: %s\n", command);
		//printf("command: %s\n", command);
		//printf("pathname: %s\n", pathname);
		if(findCmd() != -1)
		{
			printf("func found, pathname: %s\n",pathname);
			funcs[ findCmd() ]();
		}
		else
		{
			printf("invalid command, please input again\n");
			
		}
		//printf("find command ID: %d\n\n", findCmd());
	}
	
}