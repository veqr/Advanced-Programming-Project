#pragma once
#include <string>
#include <iostream>

using namespace std;

class Node
{
public:
    Node* leftChild;
    Node* rightChild;

    int serialNumber;
    string product;
    string condition;
    string status;
    string lastEditor;

    Node(int serialNumber, string product, string condition, string status, string lastEditor);
    ~Node();
    void Display();

};

