#include "SerialTree.h"


SerialTree::SerialTree()
{
    root = 0;
    TempList;
}



Node* SerialTree::Find(int key)
{
    Node* current = root;
    while (current->serialNumber != key) {
        if (key < current->serialNumber)
            current = current->leftChild;
        else
            current = current->rightChild;
        if (current == 0)
            return 0;
    }
    current->Display();
    //return current;
}

void SerialTree::DisplayInOrder(Node* localRoot)
{
    if (localRoot != 0) {
        DisplayInOrder(localRoot->leftChild);
        localRoot->Display();
        DisplayInOrder(localRoot->rightChild);
    }
}

void SerialTree::Insert(int serialNumber, string product, string condition, string status, string lastEditor)
{
    Node* newNode = new Node(serialNumber, product, condition, status, lastEditor);
    if (root == 0) {
        root = newNode;
    }
    else {
        Node* current;
        current = root;
        Node* parent;
        while (true) {
            parent = current;
            if (serialNumber < current->serialNumber) {
                current = current->leftChild;
                if (current == 0) {
                    parent->leftChild = newNode;
                    return;
                }
            }
            else {
                current = current->rightChild;
                if (current == 0) {
                    parent->rightChild = newNode;
                    return;
                }
            }
        }
    }
}

void SerialTree::SortTree(Node* localRoot)
{

    
    if (localRoot != NULL) {
        SortTree(localRoot->leftChild);
        TempList.emplace_back(localRoot);
        //localRoot->Display();
        SortTree(localRoot->rightChild);
    }

    //cout << TempList[3]->serialNumber;
    //cout << TempList.size();

    //for (int i = 0; i < TempList.size(); i++) {
        //cout << TempList[i] << endl;
    //}

    //int median = (TempList[0]->serialNumber - TempList[TempList.size() - 1]->serialNumber) / 2;

    //cout << TempList[0]->serialNumber << endl;


    //cout << TempList[0]->serialNumber << endl << TempList[TempList.size() - 1]->serialNumber << endl << "Median: " << median << endl;
    
}

void SerialTree::DisplayRoot()
{
    cout << root->serialNumber;
}

SerialTree::~SerialTree()
{
}