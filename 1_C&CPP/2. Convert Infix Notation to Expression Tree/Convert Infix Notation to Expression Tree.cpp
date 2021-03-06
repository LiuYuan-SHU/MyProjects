#include<cstdlib>
#include<iostream>
#include<string>
#include<stack>

//If compile with G++, an error will occur: [Error] 'nullptr' has not been declared
//So I solved it with a not very perfect way
//If you have a better solution, please tell me
#if __GLIBCXX__
#define nullptr NULL 
#endif

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stack;

//Prioritising the operators
//I thought it supposed to be something like key-value structure
//But I can't manage it with smaller memory
unsigned priority[128] = { 0 };

//Function to initialize priority
void initPriority()
{
	priority['+'] = priority['-'] = 1;
	priority['/'] = priority['*'] = 2;
	priority['^'] = 3;
	priority[')'] = 0;
}

//Binary Tree Node
typedef struct Node
{
	string data;
	struct Node *left,*right;
} *nodePtr;

//Function to create new node
template<class T>
nodePtr newNode(T newData)
{
	nodePtr newNode = new Node;
	newNode->data = newData;
	newNode->left = newNode->right = nullptr;
	return newNode;
}

//Function to judge if '-' is a negative char
//current stores the addresss of '-'
//start stores the start of expression
bool isNegative(const char* current, const char* start)
{
	do
	{
		--current;
		//if found a operator
		if (priority[*current] > 0) { return true; }
		//if found a operand
		else if(isdigit(*current) || isalpha(*current)) { return false; }
	}while(current >= start);
	
	//if reach the start of the expression
	return true;
}

//Function to build Expression Tree
nodePtr buildTree(string& expression)
{
	//Stack to hold nodes
	stack<nodePtr> stack_node;
	//Stack to hold strings
	stack<char> stack_operator;
	nodePtr nodePtr_parent,nodePtr_left,nodePtr_right;
	
	//Analyze the expression
	for (int i = 0; i < expression.size(); i++)
	{
		if (expression[i] == '(')
		{
			//Push '(' in operator stack
			stack_operator.push(expression[i]);
		}
		
		//Push the operands in node stack
		else if (
			isalpha(expression[i]) || isdigit(expression[i]) || 
			(
				expression[i] == '-' && isNegative(&expression[i], expression.c_str()) 
			)
		)
		{
			bool negative = expression[i] == '-' ? true : false;
			string operand = negative ? "(" : "";

			do
			{
				operand = operand + expression[i++];
			}while (isalpha(expression[i]) || isdigit(expression[i]));
			//after do-while loop, expression[i] references the next char which is not operand
			//when the outer loop goes next round, i++, the char will be skipped, so i need to be decreased  
			i--;

			if(negative)
			{
				operand += ')';
			}
			
			nodePtr_parent = newNode<string>(operand);
			stack_node.push(nodePtr_parent);
		}
		
		//If read a operator and it's priority is bigger than 0
		else if (priority[expression[i]] > 0)
		{
			//If an operator with lower or same associativity 
			//as the operator at the top of the stack appears
			
			//judgement condition: 1 must be satisfied and satisfy one of 2.* is enough
			//1.	the operator stack is not empty AND the top operator is not '('
			//2.1	the current operator is not '^' 	AND the priority of the top operator is highed or the same as the current operator
			//2.2	the current operator is 	   '^'	AND the priority of the top operator is higher 			 than the current operator
			while (
				!stack_operator.empty() && stack_operator.top() != '(' &&
				(
					(expression[i] != '^' && priority[stack_operator.top()] >= priority[expression[i]]) ||
					(expression[i] == '^' && priority[stack_operator.top()] >  priority[expression[i]])
				)
			)
			{
				//Get and remove the top element from the operator stack
				nodePtr_parent = newNode<char>(stack_operator.top());
				stack_operator.pop();
				
				//Get and remove the top element from the node stack
				nodePtr_right = stack_node.top();
				stack_node.pop();
				
				//Get adn remove the current top element from the node stack
				nodePtr_left = stack_node.top();
				stack_node.pop();
				
				//Update the tree
				nodePtr_parent->left = nodePtr_left;
				nodePtr_parent->right = nodePtr_right;
				
				//Push the node to the node stack
				stack_node.push(nodePtr_parent);	
			} 
			
			//Push expression[i] to operator stack
			stack_operator.push(expression[i]);
		}
		else if (expression[i] == ')')
		{
			//Link all the node until '('
			while (!stack_operator.empty() && stack_operator.top() != '(')
			{
				//Get and remove the top element from the operator stack
				nodePtr_parent = newNode<char>(stack_operator.top());
				stack_operator.pop();
				
				//Get and remove the top element from the node stack
				nodePtr_right = stack_node.top();
				stack_node.pop();
				
				//Get adn remove the current top element from the node stack
				nodePtr_left = stack_node.top();
				stack_node.pop();
				
				//Update the tree
				nodePtr_parent->left = nodePtr_left;
				nodePtr_parent->right = nodePtr_right;
				
				//Push the node to the node stack
				stack_node.push(nodePtr_parent);
			}
			//delete '('
			stack_operator.pop();
		}
	}
	nodePtr_parent = stack_node.top();
	return nodePtr_parent;
}

//Function to print the tree in post order
void postOrder(nodePtr root)
{
	if (root)
	{
		postOrder(root->left);
		postOrder(root->right);
		cout << root->data;
	}
}

//test code
void test()
{
	string input;
	cout << "input the infix notation:";
	getline(cin, input);
	nodePtr root = buildTree(input);
	
	postOrder(root);
	cout << endl;
}

int main()
{
	initPriority();
	while(true)
	{
		test();
	}
	
	system("pause");
	
	return 0;
}
