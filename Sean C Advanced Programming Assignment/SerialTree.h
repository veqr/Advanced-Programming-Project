#pragma once
#include "Node.h"
#include <vector>

class SerialTree
{
public:
	Node* root;
	vector<Node*> TempList;

	SerialTree();
	~SerialTree();
	Node* Find(int key);
	Node* Find(string key, Node* localRoot);
	Node* Successor(Node* current);
	Node* Delete(Node* localRoot, int key);
	void DisplayInOrder(Node* localRoot);
	void Insert(int serialNumber, string product, string condition, string status, string lastEditor);
	void SortTree(Node* localRoot);
	void DisplayRoot();

};

