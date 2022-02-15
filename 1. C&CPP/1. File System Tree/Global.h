#ifndef GLOBAL_H
#define GLOBAL_H

/***********************************************
 * @author	Liuyuan
 * @date	Feb 14th, 2022
 * @description	Global variables and definitions
 ***********************************************/

#include<string.h>

#define SUCCESS 1
#define TRUE	1
#define FAIL	-1
#define FALSE	-1
#define MAX_LENGTH 64

char line[128];		//the whole command
char command[16];	//the command
char pathname[MAX_LENGTH];	//the pathname
char dirName[MAX_LENGTH];	//
char baseName[MAX_LENGTH];	//

/***********************************************
 * @author	Liuyuan
 * @date	Feb 14th, 2022
 * @return	None
 * @description	initialize all the strings
 ***********************************************/
void global_init()
{
	strcpy(line, "");
	strcpy(command, "");
	strcpy(pathname, "");
	strcpy(dirName, "");
	strcpy(baseName, "");
}

#endif // !GLOBAL_H

