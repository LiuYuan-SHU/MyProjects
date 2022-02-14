#include"Commands.h"
#include"Node.h"
#include<stdio.h>
#include<string.h>

int main()
{
	//initialization
	Node_init();

	while(1)
	{
		getCommand();	
		//printf("command: %s\n", command);
		//printf("cmd: %s\n", cmd);
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