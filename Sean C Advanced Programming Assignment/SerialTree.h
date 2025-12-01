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
	void DisplayInOrder(Node* localRoot);
	void Insert(int serialNumber, string product, string condition, string status, string lastEditor);
	void SortTree(Node* localRoot);
	void DisplayRoot();

};

