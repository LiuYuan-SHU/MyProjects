#ifndef COMMANDS_H
#define COMMANDS_H

#include"Node.h"
#include"Global.h"
#include<stdio.h>
#include<string.h>

#define SUCCESS 1
#define FAIL	-1

//const char const * root = "/root/";
//char pwd[100] = "/root/";
//char command[1024];
//char cmd[20];
//char pathname[1000];

const char* cmds[] = { "cd" , "rm" , "mkdir" , "rmdir" , "mv" , "cp" , "ls" };
const unsigned int cmds_length = sizeof(cmds) / sizeof(*cmds);

void invalidCmd() { printf("invalid command, input again\n"); }
void invalidPath() { printf("invalid pathname, input again\n"); }
void cd() { printf("cd\n"); }
void rm() { printf("rm\n"); }
void mkdir() { printf("mkdir\n"); }
void rmdir() { printf("rmdir\n"); }
void mv() { printf("mv\n"); }
void cp() { printf("cp\n"); }
void ls() { printf("ls\n"); }
void (*funcs[])() = { cd , rm , mkdir , rmdir , mv , 
cp , ls };

/***********************************************
 * @author	Liuyuan
 * @date	Jan 15th, 2022
 * @description	get command line from terminal,
 				split it into command and pathname
 ***********************************************/
void getLine()
{
	//initialization
	strcpy(line,"");
	strcpy(command, "");
	strcpy(pathname, "");

	//show current work path
	printf("%s:", pwd->_name);

	unsigned int ite = 0;			//traverse the command line string
	unsigned int ite_temp = 0;		//temporary traverse argument
	
	char input;						//get char from the terminal
	char space = 0;					//jump unneccesary spaces

	//get command line
	while( input = getchar(), input != '\n')
	{
		//if read space before any legal character
		//read the next character
		if( !space && input == ' ')
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
	ite_temp = 0;

	//split the line into command and pathname
	//get command
	while( ite < line_length && line[ite] != ' ' )
	{
		command[ite_temp++] = line[ite++];
	} 
	command[ite_temp] = '\0';
	ite_temp = 0;

	//jump spaces
	while( ite < line_length && line[ite] == ' ')
	{
		ite++;
	}

	//copy
	while( ite < line_length )
	{
		//ignore needless spaces
		if( line[ite] == ' ' && (ite + 1) < line_length && line[ite + 1] == ' ')
		{
			ite++;
			continue;
		}
		pathname[ite_temp++] = line[ite++];
	}
	pathname[ite_temp] = '\0';
} 

int findCmd()
{
	for(unsigned i = 0; i < cmds_length; i++)
	{
		if(!strcmp(command,cmds[i]))
		{
			return i;
		}
	}

	return FAIL;
}

#endif