#include "Admin.h"

Admin::Admin(string username, string userpassword, string usertype)
{
	this->username = username;
	this->userpassword = userpassword;
	this->usertype = usertype;
}

void Admin::Screen(SerialTree* Tree1, vector<string> ProductList, vector<string> ConditionList, vector<string> Status)
{
	cout << "Admin";
}

Admin::~Admin()
{
}
