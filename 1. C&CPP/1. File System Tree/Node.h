#ifndef NODE_H
#define NODE_H

struct Node
{
    char _type;             //D for directory and F for file
    char _name[128];        //name of the node
    struct Node* _parent;   //the parent node of the current node
    struct Node* _sibling;  //the sibling node of the current node
    struct Node* _child;    //the child node of the current node
};

#endif // !NODE_H