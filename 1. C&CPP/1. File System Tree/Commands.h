#ifndef COMMANDS_H
#define COMMANDS_H

/***********************************************
 * @author	Liuyuan
 * @date	Feb 14th, 2022
 * @description	All the commands of the system
 ***********************************************/

#include"Node.h"
#include"Global.h"
#include<stdio.h>
#include<string.h>

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
void (*funcs[])() = { cd , rm , mkdir , rmdir , mv , cp , ls };

#endif