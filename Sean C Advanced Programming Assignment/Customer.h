#pragma once
#include "User.h"
#include "Orders.h"

class Customer : public User
{
public:
	string address;
	Customer(string username, string userpassword, string usertype, string address);
	void Screen(SerialTree* Tree1, vector<string> ProductList, vector<string> ConditionList, vector<string> Status, Orders* orders) override;
	void MakeOrder(vector<string> ProductList, vector<string> ConditionList, Orders* orders);
	~Customer();
};