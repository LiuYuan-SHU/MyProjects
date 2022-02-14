#include"Node.h"
#include<stdlib.h>
#include<string.h>

struct Node *root,*pwd;

void Node_init()
{
    Node_init_root();
    Node_init_pwd();
}

void Node_init_root()
{
    root = (struct Node*)malloc(sizeof(struct Node));
    root->_type = 'D';
    strcpy(root->_name,"root");
    root->_parent = NULL;
    root->_sibling = NULL;
    root->_child = NULL;
}

void Node_init_pwd()
{
    pwd = (struct Node*)malloc(sizeof(struct Node));
    pwd->_type = 'D';
    strcpy(pwd->_name,"");
    pwd->_sibling = NULL;
    pwd->_child = NULL;
}