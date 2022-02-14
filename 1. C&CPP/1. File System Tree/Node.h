#ifndef NODE_H
#define NODE_H

#include <stddef.h>

struct Node
{
	char _type;             //D for directory and F for file
	char _name[128];        //oath of the node
	struct Node* _parent;   //the parent node of the current node
	struct Node* _sibling;  //the sibling node of the current node
	struct Node* _child;    //the child node of the current node
} root = { 'D',"/root",NULL,NULL,NULL };

struct Node* pwd;

void Node_init();
#endif // !NODE_H