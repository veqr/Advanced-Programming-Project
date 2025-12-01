/*
class Node {
public:
    Node* leftChild;
    Node* rightChild;
    int data;
    Node(int data) {
        this->data = data;
        leftChild = 0;
        rightChild = 0;
    }

    void Display() {
        cout << this->data << endl;
    }
};

class Tree {
public:
    Node* root;
    Tree() {
        root = 0;
    }

    Node* Find(int key) {
        Node* current = root;
        while (current->data != key) {
            if (key < current->data)
                current = current->leftChild;
            else
                current = current->rightChild;
            if (current == 0)
                return 0;
        }
        return current;
    }

    void DisplayInOrder(Node* localRoot) {
        if (localRoot != 0) {
            DisplayInOrder(localRoot->leftChild);
            localRoot->Display();
            DisplayInOrder(localRoot->rightChild);
        }
    }

    void Insert(int data) {
        Node* newNode = new Node(data);
        if (root == 0) {
            root = newNode;
        }
        else {
            Node* current;
            current = root;
            Node* parent;
            while (true) {
                parent = current;
                if (data < current->data) {
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
};
*/