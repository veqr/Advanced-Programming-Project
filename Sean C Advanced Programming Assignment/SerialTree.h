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

	int GetSerial(int key);
	string GetProduct(int key);
	string GetCondition(int key);
	string GetStatus(int key);
	string GetEditor(int key);
	
	void SetProduct(string product, int key, string username);
	void SetCondition(string condition, int key, string username);
	void SetStatus(string status, int key, string username);
	
	void DisplayInOrder(Node* localRoot);
	void Insert(int serialNumber, string product, string condition, string status, string lastEditor);
	void DisplayRoot();
	int GetStockLevel();

};

