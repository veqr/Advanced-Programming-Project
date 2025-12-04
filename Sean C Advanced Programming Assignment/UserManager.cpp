#include "UserManager.h"

vector<User*> UserManager::SystemUsers;

UserManager::UserManager()
{
}

vector<User*> UserManager::getUsers()
{
	return SystemUsers;
}

void UserManager::InitialiseUser(string name, string password, string type)
{
	if (type == "Employee") {
		User* initUser = new Employee(name, password, type);
		SystemUsers.emplace_back(initUser);
	}
	else if (type == "Admin") {
		User* initUser = new Admin(name, password, type);
		SystemUsers.emplace_back(initUser);
	}
	else if (type == "Customer") {
		User* initUser = new Customer(name, password, type);
		SystemUsers.emplace_back(initUser);
	}
}