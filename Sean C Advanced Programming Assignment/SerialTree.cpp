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
}

Node* SerialTree::Find(string key, Node* localRoot)
{
    if (localRoot != 0) {
        Find(key, localRoot->leftChild);
        if(localRoot->product == key) localRoot->Display();
        Find(key, localRoot->rightChild);
    }
    return 0;
}

Node* SerialTree::Successor(Node* current)
{
    cout << 7 << endl;
    current = current->rightChild;
    while (current != nullptr && current->leftChild != nullptr) {
        current = current->leftChild;
        cout << 8 << endl;
    }
    return current;
}

Node* SerialTree::Delete(Node* localRoot, int key)
{
    cout << 1 << endl;

    if (localRoot == NULL) {
        cout << 2 << endl;
        return localRoot;
    }

    if (localRoot->serialNumber > key) {
        cout << 3 << endl;
        localRoot->leftChild = Delete(localRoot->leftChild, key);
    }
    else if (root->serialNumber < key) {
        cout << 4 << endl;
        localRoot->rightChild = Delete(localRoot->rightChild, key);
    }
    else {
        if (localRoot->leftChild == nullptr) {
            cout << 5 << endl;
            Node* temp = localRoot;
            delete localRoot;
            return temp;
            cout << "Deleted?" << endl;
        }
        if (localRoot->rightChild == nullptr) {
            cout << 6 << endl;
            Node* temp = localRoot;
            delete localRoot;
            return temp;
            cout << "Deleted?" << endl;
        }

        Node* successorTemp = Successor(localRoot);
        localRoot = successorTemp;
        localRoot->rightChild = Delete(localRoot->rightChild, successorTemp->serialNumber);
    }
    return localRoot;
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
    delete root;
    cout << endl << "Binary tree root deallocated" << endl;
}