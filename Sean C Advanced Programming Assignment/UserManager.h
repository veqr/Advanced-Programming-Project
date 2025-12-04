#pragma once
#include <vector>
#include "User.h"
#include "Employee.h"
#include "Admin.h"
#include "Customer.h"

class UserManager
{
public:
	static vector<User*> SystemUsers;

	UserManager();
	static vector<User*> getUsers();
	static void InitialiseUser(string name, string password, string type);
};

