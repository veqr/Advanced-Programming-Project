#pragma once
#include <string>
#include <iostream>
#include "SerialTree.h"
#include <vector>
#include "Orders.h"
#include "Errors.h"

using namespace std;

class User
{
protected:
	string userpassword;
	string username;
	string usertype;
public:
	User();
	void setUserType(string setusertype);
	string getUserType();
	void setPassword(string setpassword);
	string getPassword();
	void setUsername(string setusername);
	string getUsername();
	virtual void Screen(SerialTree* Tree1, vector<string> ProductList, vector<string> ConditionList, vector<string> Status, Orders* orders);
	~User();

};

