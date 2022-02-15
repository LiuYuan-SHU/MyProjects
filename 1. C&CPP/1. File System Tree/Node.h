#ifndef NODE_H
#define NODE_H

//description
/***********************************************
 * @author	Liuyuan
 * @date	Feb 14th, 2022
 * @description	NODE struct, the data structure 
 *				part of the project
 ***********************************************/

#include <stddef.h>

struct Node
{
	char _type;								//D for directory and F for file
	char _name[128];						//path of the node
	struct Node* _parent;					//the parent node of the current node
	struct Node* _sibling;					//the sibling node of the current node
	struct Node* _child;					//the child node of the current node
};

struct Node root = {'D',"/root",NULL,NULL,NULL};
const struct Node* pwd = &root;

void Node_init()
{
    root._parent = &root;
}

#endif // !NODE_H