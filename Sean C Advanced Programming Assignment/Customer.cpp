#include "Customer.h"

Customer::Customer(string username, string userpassword, string usertype)
{
	this->username = username;
	this->userpassword = userpassword;
	this->usertype = usertype;
}

void Customer::Screen(SerialTree* Tree1, vector<string> ProductList, vector<string> ConditionList, vector<string> Status)
{
	cout << "Customer";
}

Customer::~Customer()
{
}
