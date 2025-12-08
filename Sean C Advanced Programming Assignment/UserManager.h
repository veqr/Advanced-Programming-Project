#pragma once
#include <vector>
#include "User.h"
#include "Employee.h"
#include "Admin.h"
#include "Customer.h"

class UserManager
{
private:
	static vector<vector<string>> customerDetails;
	static void ShowCustomerDetails(int key);
public:
	friend class Admin;
	
	static vector<User*> SystemUsers;

	UserManager();
	static vector<User*> getUsers();
	static void InitialiseUser(string name, string password, string type, string address);
};

