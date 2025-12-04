#include "SerialTree.h"
//include my own exception class. single header file.
//miussing and alreayd exists


SerialTree::SerialTree()
{
    root = 0;
    TempList;
}

void SerialTree::operator+() {
    stockLevel ++;
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
    return current;
}

void SerialTree::Find(string key, Node* localRoot, void (Node::*onFind)())//function pointer BOOM https://www.geeksforgeeks.org/cpp/function-pointer-to-member-function-in-cpp/
{
    if (localRoot != 0) {
        Find(key, localRoot->leftChild, onFind);
        if(localRoot->product == key) (localRoot->*onFind)();
        Find(key, localRoot->rightChild, onFind);
    }
}

void SerialTree::Delete(int key)
{
    root = Delete(root, key);
}

Node* SerialTree::Delete(Node* localRoot, int key)
{
    cout << 1 << " " << key << " " << localRoot->serialNumber << endl;

    if (localRoot == NULL) {
        cout << 2 << endl;
        return localRoot;
    }

    if (localRoot->serialNumber > key) {
        cout << 3 << endl;
        localRoot->leftChild = Delete(localRoot->leftChild, key);
    }
    else if (localRoot->serialNumber < key) {
        cout << 4 << endl;
        localRoot->rightChild = Delete(localRoot->rightChild, key);
    }
    else {

        cout << 10 << endl;

        // if both are null, delete local and return null

        if (localRoot->leftChild == NULL && localRoot->rightChild == NULL) {
            delete localRoot;
            return NULL;
        }

        // if one is null, delete local, return other

        if (localRoot->leftChild == NULL) {
            Node* temp = localRoot->rightChild;
            localRoot->rightChild = NULL;
            delete localRoot;
            return temp;
        }

        if (localRoot->rightChild == NULL) {
            Node* temp = localRoot->leftChild;
            localRoot->leftChild = NULL;
            delete localRoot;
            return temp;
        }

        // if both are nonnull, delete local, return left, add right to right most node of left child

        Node* temp = localRoot->leftChild;


        while (temp->rightChild) {
            temp = temp->rightChild;
        }
        
        temp->rightChild = localRoot->rightChild;
        localRoot->rightChild = NULL;

        temp = localRoot->leftChild;
        localRoot->leftChild = NULL;

        delete localRoot;
        return temp;


    }
    return localRoot;
}

Node* SerialTree::GetData(int serialNumber)
{
    Node* temp = Find(serialNumber);
    return temp;
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
            //if keys same throw error
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

void SerialTree::DisplayRoot()
{
    cout << root->serialNumber;
}

int SerialTree::GetStockLevel()
{
    return stockLevel;
}

SerialTree::~SerialTree()
{
    delete root;
    cout << endl << "Binary tree root deallocated" << endl;
}