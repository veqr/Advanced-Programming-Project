#pragma once
#include "Node.h"
#include <vector>

class SerialTree
{
private:
	int stockLevel = 0;
public:
	Node* root;
	vector<Node*> TempList;

	void operator+();

	SerialTree();
	~SerialTree();
	Node* Find(int key);
	void Find(string key, Node* localRoot, void(Node::* onFind)());
	void Delete(int key);
	Node* Delete(Node* localRoot, int key);
	Node* GetData(int serialNumber);
	void DisplayInOrder(Node* localRoot);
	void Insert(int serialNumber, string product, string condition, string status, string lastEditor);
	void DisplayRoot();
	int GetStockLevel();

};

