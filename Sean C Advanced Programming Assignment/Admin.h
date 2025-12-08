#pragma once
#include "User.h"
#include "Orders.h"
#include "UserManager.h"

class Admin : public User
{
public:

	Admin(string username, string userpassword, string usertype, string address);
	void Screen(SerialTree* Tree1, vector<string> ProductList, vector<string> ConditionList, vector<string> Status, Orders* orders) override;
	void DeleteCustomer(SerialTree* Tree1, vector<string> ProductList, vector<string> ConditionList, vector<string> Status, Orders* orders);
	~Admin();
};

