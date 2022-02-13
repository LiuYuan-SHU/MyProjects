#ifndef COMMAND_H
#define COMMAND_H

#include<stdio.h>
#include<string.h>

const char const * root = "/root/";
char pwd[100] = "/root/";
char command[1024];
char cmd[20];
char pathname[1000];

const char* cmds[] = { "cd" , "rm" , "mkdir" , "rmdir" , "mv" ,
 "cp" , "ls" };
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
 * @description	get command from terminal,
 				split it into cmd and pathname
 ***********************************************/
void getCommand()
{
	//initialization
	strcpy(command,"");
	strcpy(cmd, "");
	strcpy(pathname, "");

	//show current work path
	printf("%s:", pwd);

	unsigned int ite = 0;			//traverse the command string
	unsigned int ite_temp = 0;		//temporary traverse argument
	
	char input;						//get char from the terminal
	char space = 0;					//jump unneccesary spaces

	//get command
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
			command[ite_temp++] = input;
			space = 1;
		}
	}	
	command[ite_temp] = '\0';
	const unsigned int command_length = ite_temp == 0 ? 0 : ite_temp;
	ite_temp = 0;

	//split the command into cmd and pathname
	//get cmd
	while( ite < command_length && command[ite] != ' ' )
	{
		cmd[ite_temp++] = command[ite++];
	} 
	cmd[ite_temp] = '\0';
	ite_temp = 0;

	//jump spaces
	while( ite < command_length && command[ite] == ' ')
	{
		ite++;
	}

	//copy
	while( ite < command_length )
	{
		//ignore needless spaces
		if( command[ite] == ' ' && (ite + 1) < command_length && command[ite + 1] == ' ')
		{
			ite++;
			continue;
		}
		pathname[ite_temp++] = command[ite++];
	}
	pathname[ite_temp] = '\0';
} 

int findCmd()
{
	for(int i = 0; i < cmds_length; i++)
	{
		if(!strcmp(cmd,cmds[i]))
		{
			return i;
		}
	}

	return -1;
}

#endif