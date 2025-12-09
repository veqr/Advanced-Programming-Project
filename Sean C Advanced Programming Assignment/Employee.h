#pragma once
#include "User.h"
#include "Orders.h"

using namespace std;

class Employee : public User
{
public:
	static vector<int> temp;

	Employee(string username, string userpassword, string usertype, string address);
	void Screen(SerialTree* Tree1, vector<string> ProductList, vector<string> ConditionList, vector<string> Status, Orders* orders) override;
	void OrderMenu(SerialTree* Tree1, vector<string> ProductList, vector<string> ConditionList, vector<string> Status, Orders* orders);
	void BulkInput(SerialTree* Tree1, vector<string> ProductList, vector<string> ConditionList, vector<string> Status, Orders* orders);
	void EditProduct(SerialTree* Tree1, vector<string> ProductList, vector<string> ConditionList, vector<string> Status, Orders* orders);
	void DeleteProduct(SerialTree* Tree1);
	void ShowStock(SerialTree* Tree1, vector<string> ProductList, vector<string> ConditionList, vector<string> Status, Orders* orders);
	~Employee();
};

