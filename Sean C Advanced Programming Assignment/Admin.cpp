#include "Admin.h"
#include "Orders.h"

Admin::Admin(string username, string userpassword, string usertype, string address)
{
	this->username = username;
	this->userpassword = userpassword;
	this->usertype = usertype;
}

void Admin::Screen(SerialTree* Tree1, vector<string> ProductList, vector<string> ConditionList, vector<string> Status, Orders* orders)//Gives user options for menus to interact with
{
	cout << endl << "Logged in as Admin" << endl << "Below are the menu options: " << endl << endl;
	cout << "1. Delete a Customer." << endl << "2. Log out." << endl << endl;

	int choice;
	try{ 
		cin >> choice;
		if (cin.fail()) {
			throw Errors();
		}
		

	}
	catch (Errors &e) {
		cout << e.what() << endl << endl;
		cin.clear();
		cin.ignore();
		Screen(Tree1, ProductList, ConditionList, Status, orders);
	}

	switch (choice) {
	case 1:
		DeleteCustomer(Tree1, ProductList, ConditionList, Status, orders);
		break;
	case 2:
		break;
	default:
		cout << "Incorrect option, please try again." << endl << endl;
		Screen(Tree1, ProductList, ConditionList, Status, orders);
		break;
	}
}

void Admin::DeleteCustomer(SerialTree* Tree1, vector<string> ProductList, vector<string> ConditionList, vector<string> Status, Orders* orders)//Deletes a customer that the admin has chosen to delete
{
	cout << endl << "Please enter a customer to delete." << endl << endl;
	for (int i = 0; i < UserManager::customerDetails.size(); i++) {
		UserManager::ShowCustomerDetails(i);
	}

	int delcustomer;
	try {
		cin >> delcustomer;
		if (cin.fail()) {
			throw Errors();
		}


	}
	catch (Errors& e) {
		cout << e.what() << endl << endl;
		cin.clear();
		cin.ignore();
		Screen(Tree1, ProductList, ConditionList, Status, orders);
	}
	
	for (int i = 0; i < UserManager::SystemUsers.size(); i++) {
		if (UserManager::SystemUsers[i]->getUsername() == UserManager::customerDetails[delcustomer][0]) {

			UserManager::SystemUsers.erase(UserManager::SystemUsers.begin() + i);
			UserManager::customerDetails.erase(UserManager::customerDetails.begin() + delcustomer);

		}
	}

	cout << "Deleted Customer." << endl;

	Screen(Tree1, ProductList, ConditionList, Status, orders);

}

Admin::~Admin()
{
}
