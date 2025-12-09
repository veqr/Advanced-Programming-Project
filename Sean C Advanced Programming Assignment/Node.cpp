#include "Node.h"

Node::Node(int serialNumber, string product, string condition, string status, string lastEditor)
{
    
    this->serialNumber = serialNumber;
    this->product = product;
    this->condition = condition;
    this->status = status;
    this->lastEditor = lastEditor;
    left = 0;
    right = 0;
}

Node::~Node()
{
    delete left;
    delete right;
    cout << endl << "Node children deallocated" << endl;
}

void Node::Display()//Displays the node and its data
{
    cout << "S/N: " << this->serialNumber <<  "  ::  Product: " << this->product << "  ::  Condition: " << this->condition << "  ::  Status: " << this->status <<  " :: Last Editor: " << lastEditor << endl;
}