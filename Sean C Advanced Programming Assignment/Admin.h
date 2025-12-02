#pragma once
#include "User.h"
class Admin : public User
{
public:
	Admin(string username, string userpassword, string usertype);
	void Screen(SerialTree* Tree1, vector<string> ProductList, vector<string> ConditionList, vector<string> Status) override;
	~Admin();
};

