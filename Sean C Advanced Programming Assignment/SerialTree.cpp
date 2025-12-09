#include "SerialTree.h"
#include "Errors.h"


SerialTree::SerialTree()
{
    root = 0;
}

int SerialTree::GetSerial(int key)//Finding the product, displaying its info, and returning the serial
{
    Node* temp = Find(key);

    return temp->serialNumber;
}

string SerialTree::GetProduct(int key)//Finds a product from a serial number
{
    Node* temp;
    try {
        temp = Find(key);
        
    }
    catch (Errors& e) {
        cout << e.delwhat() << endl << endl;
        cin.clear();
        cin.ignore();
        return "";
    }
    return temp->product;
}

string SerialTree::GetCondition(int key)//Finds a condition from a serial number
{
    Node* temp = Find(key);

    return temp->condition;
}

string SerialTree::GetStatus(int key)//Finds a status from a serial number
{
    Node* temp = Find(key);

    return temp->status;
}

string SerialTree::GetEditor(int key)//Finds last editor from a serial number
{
    Node* temp = Find(key);

    return temp->lastEditor;
}

void SerialTree::SetProduct(string product, int key, string username)//Changes the product of an object
{
    Node* temp = Find(key);
    temp->product = product;
    temp->lastEditor = username;
}

void SerialTree::SetCondition(string condition, int key, string username)//Changes the condition of an object
{
    Node* temp = Find(key);
    temp->condition = condition;
    temp->lastEditor = username;
}

void SerialTree::SetStatus(string status, int key, string username)//Changes the status of an object
{
    Node* temp = Find(key);
    temp->status = status;
    temp->lastEditor = username;
}

void SerialTree::operator+() {//Increases stock level
    stockLevel ++;
}

Node* SerialTree::Find(int key)//Finds an object and displays all of its data from a serial number
{
    Node* current = root;//Sets the current Node to the first value of the Tree
    while (current->serialNumber != key) {//Loops until the serial number is a key
        if (key < current->serialNumber)//If the key is less than the serial number of the current Node then
            current = current->left;//Switches the current Node to the left Node
        else//Otherwise
            current = current->right;//switches the current Node to the right Node
        if (current == nullptr)//If the serial cannot be found then
            throw Errors();//Throws an error so crashes can be prevented
    }
    current->Display();//Displays the current object
    return current;//Return the Node
}

void SerialTree::Find(string key, Node* localRoot, void (Node::*onFind)())
{
    if (localRoot != 0) {//If the local root isnt 0
        Find(key, localRoot->left, onFind);//Check the left Node of the local root
        if(localRoot->product == key) (localRoot->*onFind)();//If the product of the local root Node matches the key then the functional pointer is called
        Find(key, localRoot->right, onFind);//Checks the right Node of the local root
    }
}

void SerialTree::Delete(int key)//Deletes a Node
{
        root = Delete(root, key); 
}

Node* SerialTree::Delete(Node* localRoot, int key)//Deletes a node with a root
{
    cout << 1 << " " << key << " " << localRoot->serialNumber << endl;

    if (localRoot == NULL) {
        return localRoot;
    }

    if (localRoot->serialNumber > key) {
        localRoot->left = Delete(localRoot->left, key);
    }
    else if (localRoot->serialNumber < key) {
        localRoot->right = Delete(localRoot->right, key);
    }
    else {

        // if both are null, delete local and return null

        if (localRoot->left == NULL && localRoot->right == NULL) {
            delete localRoot;
            return NULL;
        }

        // if one is null, delete local, return other

        if (localRoot->left == NULL) {
            Node* temp = localRoot->right;
            localRoot->right = NULL;
            delete localRoot;
            return temp;
        }

        if (localRoot->right == NULL) {
            Node* temp = localRoot->left;
            localRoot->left = NULL;
            delete localRoot;
            return temp;
        }

        // if both are nonnull, delete local, return left, add right to right most node of left child

        Node* temp = localRoot->left;

        //finding right most node
        while (temp->right) {
            temp = temp->right;
        }
        
        temp->right = localRoot->right;
        localRoot->right = NULL;

        temp = localRoot->left;
        localRoot->left = NULL;

        delete localRoot;
        return temp;


    }
    return localRoot;
}

Node* SerialTree::GetData(int serialNumber)//Returns the data of an object from its serial
{
    Node* temp = Find(serialNumber);
    return temp;
}

void SerialTree::DisplayInOrder(Node* localRoot)//Displays all objects and their data in order
{
    if (localRoot != 0) {
        DisplayInOrder(localRoot->left);
        localRoot->Display();
        DisplayInOrder(localRoot->right);
    }
}

void SerialTree::Insert(int serialNumber, string product, string condition, string status, string lastEditor)//Inserts a new object into the tree
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
                current = current->left;
                if (current == 0) {

                    parent->left = newNode;
                    return;
                }
            }
            else {
                current = current->right;
                if (current == 0) {

                    parent->right = newNode;
                    return;
                }
            }
        }
    }
}

void SerialTree::DisplayRoot()//Displays root, used for debugging
{
    cout << root->serialNumber;
}

int SerialTree::GetStockLevel()//Returns stock level
{
    return stockLevel;
}

SerialTree::~SerialTree()
{
    delete root;
    cout << endl << "Binary tree root deallocated" << endl;
}