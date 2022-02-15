#ifndef TOOLS_H
#define TOOLS_H

//description
/***********************************************
 * @author	Liuyuan
 * @date	Feb 14th, 2022
 * @description	Command line opersations and sundry
 ***********************************************/

#include"Global.h"
#include<stdio.h>

 /***********************************************
  * @author	Liuyuan
  * @date	Feb 14th, 2022
  * @return	None
  * @description	print line, command and pathname
  ***********************************************/
void printInfo()
{
	printf("============Print Information==============\n");
	printf("line: \t\t%s\n", line);
	printf("command: \t%s\n", command);
	printf("pathname: \t%s\n", pathname);
	printf("===========================================\n");
}

 /***********************************************
  * @author	Liuyuan
  * @date	Feb 15th, 2022
  * @return	offset to jump spaces
  * @description	jump excess spaces
  ***********************************************/
unsigned short getNext_notSpace(char* str, unsigned short max_length)
{
	unsigned short offset = 0;
	while(offset < max_length && str[offset] == ' ')
	{
		offset++;
	}
	//return offset == 0 ? offset : (offset - 1);
	return offset;
}

/***********************************************
 * @author	Liuyuan
 * @date	Jan 15th, 2022
 * @return	The length of line
 * @description	get command line from terminal,
				split it into command and pathname
 ***********************************************/
const unsigned int getLine()
{
	//initialization
	strcpy(line, "");
	strcpy(command, "");
	strcpy(pathname, "");

	//show current work path
	printf("FileTreeSystem@cerasuslsat@gmail.com %s:", pwd->_name);

	unsigned int ite = 0;			//traverse the command line string
	unsigned int ite_temp = 0;		//temporary traverse argument

	char input;						//get char from the terminal
	char space = 0;					//jump unneccesary spaces

	//get command line
	while (input = getchar(), input != '\n')
	{
		//if read space before any legal character
		//read the next character
		if (!space && input == ' ')
		{
			continue;
		}
		//else store the character and set spcae as true
		else
		{
			line[ite_temp++] = input;
			space = 1;
		}
	}
	line[ite_temp] = '\0';
	const unsigned int line_length = ite_temp == 0 ? 0 : ite_temp;
	return line_length;
}

/***********************************************
 * @author	Liuyuan
 * @date	Feb 14th, 2022
 * @return	None
 * @description	split the line into command and
 *				pathname
 ***********************************************/
void splitLine(unsigned int line_length)
{
	//ite to traverse the whole line, ite_temp to input command and pathname
	unsigned ite = 0, ite_temp = 0;

	//split the line into command and pathname
	//get command
	while (ite < line_length && line[ite] != ' ')
	{
		command[ite_temp++] = line[ite++];
	}
	command[ite_temp] = '\0';
	ite_temp = 0;

	//jump spaces
	/*
	while (ite < line_length && line[ite] == ' ')
	{
		ite++;
	}
	*/
	ite += getNext_notSpace(&line[ite], line_length);

	//copy path name from line
	while (ite < line_length)
	{
		//ignore needless spaces
		if (line[ite] == ' ' && (ite + 1) < line_length && line[ite + 1] == ' ')
		{
			ite++;
			continue;
		}
		pathname[ite_temp++] = line[ite++];
	}
	pathname[ite_temp] = '\0';
}

/***********************************************
 * @author	Liuyuan
 * @date	Jan 15th, 2022
 * @return	int, the right index for found and
 *			FAIL(-1) for unfound
 * @description	Find command
 ***********************************************/
int findCmd()
{
	for (unsigned i = 0; i < cmds_length; i++)
	{
		if (!strcmp(command, cmds[i]))
		{
			return i;
		}
	}

	return FAIL;
}



#endif // !TOOLS_H
