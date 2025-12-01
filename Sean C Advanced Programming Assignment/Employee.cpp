#include "Employee.h"

Employee::Employee(string username, string userpassword, string usertype)
{
	this->username = username;
	this->userpassword = userpassword;
	this->usertype = usertype;
}

void Employee::Screen(SerialTree* Tree1, vector<string> ProductList, vector<string> ConditionList, vector<string> Status)
{
	cout << "Logged in as Employee" << endl << "Below are the menu options: " << endl;
	cout << "1. Scan new products into the system." << endl << "2. Edit existing product." << endl << "3. Open the orders list." << endl << "4. Create new product." << endl << "5. Show current stock." << endl;

	int choice;
	cin >> choice; //maybe add some exception handling here
	switch (choice) {
	case 1:
		BulkInput(Tree1, ProductList, ConditionList, Status);
		break;
	
	case 2:
		//EditProduct();
		break;
	case 3:
		//OrderList();
		break;
	case 4:
		//CreateProduct();
		break;
	case 5:
		//ShowStock();
		break;
	default:
		cout << "Incorrect option, please try again." << endl;
		Screen(Tree1, ProductList, ConditionList, Status);
		break;
	}

	

}

void Employee::BulkInput(SerialTree* Tree1, vector<string> ProductList, vector<string> ConditionList, vector<string> Status)
{

	int product;
	int condition;

	cout << "In this menu every product scanned will share the same parameters which you will set, unless you would like to change these halfway through." << endl;
	//Tree1->DisplayInOrder(Tree1->root);

	cout << "Below is a list of all the products we take: " << endl;
	for (int i = 0;i < ProductList.size();i++) {
		cout << i << ". " << ProductList[i] << endl;
	}
	cout << "Please select the number of the product to bulk scan: " << endl;
	cin >> product;


	cout << "Below is a list of conditions: " << endl;
	for (int i = 0;i < ConditionList.size();i++) {
		cout << i << ". " << ConditionList[i] << endl;
	}
	cout << "Please select a condition: " << endl;
	cin >> condition;

	while (true) {

		int serial;
		cout << endl << "Please enter serial. Type -1 to stop." << endl;
		cin >> serial; //maybe exception here?
		if (serial == -1) {
			Screen(Tree1, ProductList, ConditionList, Status);
			break;
		}
		if (!Tree1->Find(serial)) {
			Tree1->Insert(serial, ProductList[product], ConditionList[condition], Status[1], this->username);
		}
		else {
			cout << "This serial number already exists." << endl;
		}

	}


}

Employee::~Employee(){}
