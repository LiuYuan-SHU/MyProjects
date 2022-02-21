#ifndef GLOBAL_H
#define GLOBAL_H

/***********************************************
 * @author	Liuyuan
 * @date	Feb 14th, 2022
 * @description	Global variables and definitions
 ***********************************************/

#include<string.h>

#define SUCCESS				1
#define TRUE				1
#define FAIL				-1
#define FALSE				-1
#define MAX_LINE_LENGTH		128
#define MAX_COMMAND_LENGTH	16
#define MAX_LENGTH			MAX_LINE_LENGTH-MAX_COMMAND_LENGTH

char line[128];		//the whole command
char command[16];	//the command
char pathname[MAX_LENGTH];	//the pathname
//GNU explanation:
//Output each NAME with its last non-slash component and trailing slashes removed; 
//if NAME contains no /'s, output '.' (meaning the current directory).
char dirName[MAX_LENGTH];
char baseName[MAX_LENGTH];	//the currnet node name

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

