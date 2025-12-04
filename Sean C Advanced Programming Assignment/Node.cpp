#include "Node.h"

Node::Node(int serialNumber, string product, string condition, string status, string lastEditor)
{
    
    this->serialNumber = serialNumber;
    this->product = product;
    this->condition = condition;
    this->status = status;
    this->lastEditor = lastEditor;
    leftChild = 0;
    rightChild = 0;
}

Node::~Node()
{
    delete leftChild;
    delete rightChild;
    cout << endl << "Node children deallocated" << endl;
}

void Node::Display()
{
    cout << "S/N: " << this->serialNumber <<  "  ::  Product: " << this->product << "  ::  Condition: " << this->condition << "  ::  Status: " << this->status <<  " :: Last Editor: " << lastEditor << endl;
}