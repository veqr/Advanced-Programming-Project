#pragma once
#include <vector>
#include <string>
#include <iostream>


using namespace std;

class Orders
{
public:
	vector<vector<string>>ordersList;

	void ShowOrders();
	void DisplayOrder(int key);
	void AddOrder(vector<string> order);
	void CompleteOrder(int key);
	int NewOrderNumber();


	Orders();
	~Orders();
};

