#ifndef TOOLS_H
#define TOOLS_H

//description
/***********************************************
 * @author	Liuyuan
 * @date	Feb 14th, 2022
 * @description	Command line opersations and sundry
 ***********************************************/

#include"Global.h"
#include"Node.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
	while (input = getchar(), ite_temp < MAX_LENGTH - 1 && input != '\n')
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

	setbuf(stdin, NULL);		//flush the buffer

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

char splitPath(char originPath[MAX_LENGTH], char** subPath, char** nodeName);
char findNode(char nodeName[MAX_LENGTH]);

/***********************************************
 * @author	Liuyuan
 * @date	Jan 16th, 2022
 * @return	char, SUCCESS(1) for success and
 *			FAIL(-1) for fail
 * @description	set pwd to a pathname
 ***********************************************/
char setPwdTo(char path[MAX_LENGTH])
{
	char *nodeName = (char*)malloc(MAX_LENGTH * sizeof(char));			//current level node
	char *subPath = (char*)malloc(MAX_LENGTH * sizeof(char));			//path except current level node
	//init
	memset(nodeName,MAX_LENGTH,sizeof(nodeName));
	strcpy(subPath, path);				//regard path as the longest path

	//split the subpath into a subpath and a nodename
	//loop until the subpath is empty
	while(strlen(subPath) != 0)
	{
		//debug
		/*printf("subpath: %s\n",subPath);
		printf("subpath address: %p\n", subPath);
		printf("subpath length: %ld\n", strlen(subPath));*/
		if( splitPath(subPath, &subPath, &nodeName) == FAIL )
		{
			return FAIL;
		}
		printf("Node Name: %s\n", nodeName);
		printf("subpath: %s\n", subPath);
		printf("=========LOOP END======\n");

		/*if(setPwdTo(nodeName) == FAIL)
		{
			return FAIL;
		}*/
	}

	return SUCCESS;	
}

/***********************************************
 * @author	Liuyuan
 * @date	Jan 16th, 2022
 * @return	char, SUCCESS for success and FAIL
 * 			for FAIL
 * @description	split a path into subpath and
 * 				node name
 ***********************************************/
char splitPath(char originPath[MAX_LENGTH], char** subPath, char** nodeName)
{
	unsigned short offset = 0;		//record the index of the first splash('/')
	//debug
	/*printf("origin path: %s\n", originPath);
	printf("subPath: %p\n", *subPath);
	printf("nodeName: %p\n", *nodeName);
	printf("offset add: %p\n", &offset);*/
	
	//copy chars before the first '/' into nodeName
	//if slash is at the first char, copy it into the nodeName too
	do
	{
		(*nodeName)[offset] = originPath[offset];
		offset++;
	}	while( offset < MAX_LENGTH && originPath[offset] != '/' && originPath[offset] != '\0' && offset < strlen(originPath));
	(*nodeName)[offset] = '\0';								//protection
	//debug
	//printf("offset: %u\n", offset);				

	//copy the rest of the string to subPath
	unsigned short subPath_length = 0;						//to record the length of the subPath
	while(offset < strlen(originPath))
	{
		(*subPath)[subPath_length++] = originPath[offset++];
	}
	(*subPath)[subPath_length] = '\0';
	
	//testcode
	/*{
		printf("\n===========TEST============\n");
		printf("subpath:\t %s\n",strlen(*subPath) == 0 ? "(empty)" : *subPath);
		printf("subpath length:\t %ld\n",strlen(*subPath));
		printf("subpath address: %p\n",*subPath);
		printf("nodeName:\t %s\n",*nodeName);
		printf("\n===========TEST============\n");
	}*/

	return SUCCESS;
}

char findNode(char nodeName[MAX_LENGTH])
{
	if(strlen(nodeName) == 0)
	{
		pwd = ROOT;
		return SUCCESS;
	}

	struct Node* traverse = pwd->_child;
	while(traverse != NULL && strcmp(traverse->_name, nodeName) != 0)
	{
		traverse = traverse->_sibling;
	}
	
	if(traverse)
	{
		return SUCCESS;
	}
	else
	{
		return SUCCESS;
	}
}

#endif // !TOOLS_H
