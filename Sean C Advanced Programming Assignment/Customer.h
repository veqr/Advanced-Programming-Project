#pragma once
#include "User.h"
class Customer : public User
{
public:
	Customer(string username, string userpassword, string usertype);
	void Screen(SerialTree* Tree1, vector<string> ProductList, vector<string> ConditionList, vector<string> Status) override;
	~Customer();
};