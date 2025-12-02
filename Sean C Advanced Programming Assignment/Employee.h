#pragma once
#include "User.h"
class Employee : public User
{
public:
	Employee(string username, string userpassword, string usertype);
	void Screen(SerialTree* Tree1, vector<string> ProductList, vector<string> ConditionList, vector<string> Status) override;
	void BulkInput(SerialTree* Tree1, vector<string> ProductList, vector<string> ConditionList, vector<string> Status);
	void EditProduct(SerialTree* Tree1, vector<string> ProductList, vector<string> ConditionList, vector<string> Status);
	void ShowStock(SerialTree* Tree1, vector<string> ProductList, vector<string> ConditionList, vector<string> Status);
	~Employee();
};

