#ifndef NODE_H
#define NODE_H

#include<string>

using std::string;

typedef struct Node
{
	string _data;
	struct Node* _parent;
	struct Node* _left;
	struct Node* _right;

	Node();
	Node(char data);
	Node(string data);
}* nodePtr;

nodePtr buildExpressionTree(string& expression);

void preOrderTraversal_recursion(nodePtr root);

void preOrderTraversal_no_recursion(nodePtr root);



#endif
