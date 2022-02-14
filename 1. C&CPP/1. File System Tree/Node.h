#ifndef NODE_H
#define NODE_H

#include <stddef.h>

struct Node
{
	char _type;								//D for directory and F for file
	char _name[128];						//path of the node
	struct Node* _parent;					//the parent node of the current node
	struct Node* _sibling;					//the sibling node of the current node
	struct Node* _child;					//the child node of the current node
} root = { 'D',"/root",NULL,NULL,NULL };	//define root node

struct Node* pwd = &root;

#endif // !NODE_H