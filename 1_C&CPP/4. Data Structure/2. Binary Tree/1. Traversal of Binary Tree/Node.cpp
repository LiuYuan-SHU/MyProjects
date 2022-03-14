#include"Node.h"
#include"Tool.h"
#include <ctype.h>
#include<stack>

using std::cin;
using std::cout;
using std::endl;
using std::stack;

extern int priority[128];

Node::Node()
{
	this->_data = "";
	this->_parent = nullptr;
	this->_left = nullptr;
	this->_right = nullptr;
}

Node::Node(char data)
{
	this->_data = string(1,data);
	this->_parent = nullptr;
	this->_left = nullptr;
	this->_right = nullptr;
}

Node::Node(string data)
{
	this->_data = data;
	this->_parent = nullptr;
	this->_left = nullptr;
	this->_right = nullptr;
}

nodePtr buildExpressionTree(string& expression)
{
	//stack to hold nodes
	stack<nodePtr> stack_node;
	//stack to hold operators
	stack<char> stack_operator;
	//nodePtr to store the parent, left, right node
	nodePtr nodePtr_parent, nodePtr_left, nodePtr_right;

	for (int i = 0; i < expression.length(); i++)
	{
		//if current operator is '(', push it into the stack
		if (expression[i] == '(')
		{
			stack_operator.push('(');
		}
		//push the operands into the stack
		else if (
			isalpha(expression[i]) || isdigit(expression[i]) ||
			(
				expression[i] == '-' && isNegative(&expression[i], expression.c_str())
				)
			)
		{
			bool negatve = expression[i] == '-' ? true : false;
			string operand = negatve ? "(" : "";

			do
			{
				operand += operand + expression[i++];
			} while (isalpha(expression[i]) || isdigit(expression[i]));
			i--;

			if (negatve)
			{
				operand += ')';
			}

			nodePtr_parent = new Node(operand);
			stack_node.push(nodePtr_parent);
		}
		//if read an operator
		else if (priority[expression[i]] > 0)
		{
			//If an operator with lower or the same priority appears
			while (
				!stack_operator.empty() && stack_operator.top() != '(' &&
				(
					(expression[i] != '^' && priority[stack_operator.top()] >= priority[expression[i]]) ||
					(expression[i] == '^' && priority[stack_operator.top()] > priority[expression[i]])
				)
				)
			{
				//Get and remove the top element from the operator stack
				nodePtr_parent = new Node(stack_operator.top());
				stack_operator.pop();

				//Get and remote the top element from the operand stack
				nodePtr_right = stack_node.top();
				stack_node.pop();

				//Get and remote the top element from the operand stack
				nodePtr_left = stack_node.top();
				stack_node.pop();

				//update the tree
				nodePtr_parent->_left = nodePtr_left;
				nodePtr_parent->_right = nodePtr_right;

				//push the node to the node tree
				stack_node.push(nodePtr_parent);
			}

			//push the curent operator into the stack
			stack_operator.push(expression[i]);
		}
		else if (expression[i] == ')')
		{
			//Link all the nodes until '('
			while (!stack_operator.empty() && stack_operator.top() != '(')
			{
				nodePtr_parent = new Node(stack_operator.top());
				stack_operator.pop();
				nodePtr_right = stack_node.top();
				stack_node.pop();
				nodePtr_left = stack_node.top();
				stack_node.pop();

				//update the tree
				nodePtr_parent->_left = nodePtr_left;
				nodePtr_parent->_right = nodePtr_right;

				//push the node to the node tree
				stack_node.push(nodePtr_parent);
			}
			stack_operator.pop();
		}
	}
	return stack_node.top();
}

void preOrderTraversal_recursion(nodePtr root)
{
	if (root != nullptr)
	{
		cout << root->_data;
		preOrderTraversal_recursion(root->_left);
		preOrderTraversal_recursion(root->_right);
	}
}

void preOrderTraversal_no_recursion(nodePtr root)
{
	stack<struct Node*> stack_node;
	struct Node* pNode_temp = root;

	//while there still are nodes not traversed
	while (pNode_temp != nullptr || !stack_node.empty())
	{
		//if current node is not nullptr
		//access
		if (pNode_temp != nullptr)
		{
			cout << pNode_temp->_data << endl;
			stack_node.push(pNode_temp);
			pNode_temp = pNode_temp->_left;
		}
		//if current node is nullptr but the stack is not empty
		else
		{
			pNode_temp = stack_node.top()->_right;
			stack_node.pop();
		}
	}
}
