#include "Customer.h"
#include "Orders.h"

Customer::Customer(string username, string userpassword, string usertype, string address)
{
	this->username = username;
	this->userpassword = userpassword;
	this->usertype = usertype;
	this->address = address;
}

void Customer::Screen(SerialTree* Tree1, vector<string> ProductList, vector<string> ConditionList, vector<string> Status, Orders* orders)//Gives user options for menus to interact with
{
	cout << endl << "Logged in as Customer" << endl << "Below are the menu options: " << endl << endl;
	cout << "1. Make an order." << endl << "2. Log out." << endl << endl;

	int choice;
	try {
		cin >> choice;
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

	switch (choice) {
	case 1:
		MakeOrder(ProductList, ConditionList, orders);
		Screen(Tree1, ProductList, ConditionList, Status, orders);
		break;
	case 2:
		cin.clear();
		cin.ignore(1000, '\n');
		break;
	default:
		cout << "Incorrect option, please try again." << endl << endl;
		Screen(Tree1, ProductList, ConditionList, Status, orders);
		break;
	}

	
}

void Customer::MakeOrder(vector<string> ProductList, vector<string> ConditionList, Orders* orders)//Makes a new order and calls AddOrder to add it to the ordersList vector
{
	cout << endl << "Please enter product to be ordered." << endl << endl;
	for (int i = 0; i < ProductList.size(); i++) {
		cout << i << ". " << ProductList[i] << endl;
	}
	int product;
	cin >> product;

	cout << "Please enter quantity." << endl;
	int quantity;
	cin >> quantity;

	cout << "Please enter condition." << endl;
	for (int i = 0; i < ConditionList.size(); i++) {
		cout << i << ". " << ConditionList[i] << endl;
	}
	int condition;
	cin >> condition;

	string num = to_string(orders->NewOrderNumber());
	vector<string> temp{
		num, username, "Incomplete", to_string(product), to_string(quantity), to_string(condition), address
	};

	orders->AddOrder(temp);
	orders->DisplayOrder(stoi(num)-1);

}

Customer::~Customer()
{
}
