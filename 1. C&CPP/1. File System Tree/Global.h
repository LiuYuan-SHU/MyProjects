#ifndef GLOBAL_H
#define GLOBAL_H

#include<string.h>

char line[128];		//the whole command
char command[16];	//the command
char pathname[64];	//the pathname
char dirName[64];	//
char baseName[64];	//

void global_init()
{
	strcpy(line, "");
	strcpy(command, "");
	strcpy(pathname, "");
	strcpy(dirName, "");
	strcpy(baseName, "");
}

#endif // !GLOBAL_H

