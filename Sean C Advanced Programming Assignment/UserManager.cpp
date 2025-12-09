#include "UserManager.h"

vector<vector<string>> UserManager::customerDetails;

vector<User*> UserManager::SystemUsers;

void UserManager::ShowCustomerDetails(int key)//Displays all of the customers and their data
{
	cout << key << ". " << customerDetails[key][0] << " :: " << customerDetails[key][1] << endl;
}

UserManager::UserManager()
{
	
}

vector<User*> UserManager::getUsers()// returns all the users and their data
{
	return SystemUsers;
}



void UserManager::InitialiseUser(string name, string password, string type, string address)//Initialises a user and adds it to the system
{
	if (type == "Employee") {
		User* initUser = new Employee(name, password, type, address);
		SystemUsers.emplace_back(initUser);
	}
	else if (type == "Admin") {
		User* initUser = new Admin(name, password, type, address);
		SystemUsers.emplace_back(initUser);
	}
	else if (type == "Customer") {
		User* initUser = new Customer(name, password, type, address);
		SystemUsers.emplace_back(initUser);
		vector<string> temp{ name, address };
		customerDetails.emplace_back(temp);
	}
}