#include "Employee.h"

vector<int> Employee::temp;

Employee::Employee(string username, string userpassword, string usertype, string address)
{
	this->username = username;
	this->userpassword = userpassword;
	this->usertype = usertype;
}

void Employee::Screen(SerialTree* Tree1, vector<string> ProductList, vector<string> ConditionList, vector<string> Status, Orders* orders)//Gives user options for menus to interact with
{
	cout << endl << "Logged in as Employee" << endl << "Below are the menu options: " << endl;
	cout << "1. Scan new products into the system." << endl << "2. Edit existing product." << endl << "3. Open the orders list." << endl << "4. Show current stock." << endl << "5. Log Out." << endl << endl;

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
		BulkInput(Tree1, ProductList, ConditionList, Status, orders);
		break;
	
	case 2:
		EditProduct(Tree1, ProductList, ConditionList, Status, orders);
		break;
	case 3:
		OrderMenu(Tree1, ProductList, ConditionList, Status, orders);
		break;
	case 4:
		cout << "Current stock count: " << Tree1->GetStockLevel() << endl << endl;
		ShowStock(Tree1, ProductList, ConditionList, Status, orders);
		cout << endl << endl;
		Screen(Tree1, ProductList, ConditionList, Status, orders);
		break;
	case 5:
		cin.clear();
		cin.ignore(1000, '\n');
		break;
	default:
		cout << "Incorrect option, please try again." << endl << endl;
		Screen(Tree1, ProductList, ConditionList, Status, orders);
		break;
	}

	

}

void Employee::OrderMenu(SerialTree* Tree1, vector<string> ProductList, vector<string> ConditionList, vector<string> Status, Orders* orders)//Allows the employee to assign products to an order to complete it
{
	orders->ShowOrders();
	cout << endl << "What order would you like to fulfill? Enter -1 to go cancel." << endl << endl;
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

	if (choice == -1) {
		Screen(Tree1, ProductList, ConditionList, Status, orders);
	}
	else {
		orders->DisplayOrder(choice-1);
	}

	int product = stoi(orders->ordersList[choice - 1][3]);
	string quantity = orders->ordersList[choice - 1][4];

	for (int i = 0; i < stoi(quantity); i++) {
		int tempserial;
		cout << endl << "Please enter the serial of the product you would like to pick." << endl;
		cin >> tempserial;
		if (Tree1->Find(tempserial)) {

			//cout << endl << endl << ProductList[product] << endl << endl;

			if (Tree1->GetProduct(tempserial) == ProductList[product]) {
				Tree1->SetStatus("Picked", tempserial, this->username);
			}
			else {
				cout << "Incorrect Product, please restart." << endl << endl;
				Screen(Tree1, ProductList, ConditionList, Status, orders);
				break;
			}

		}
	}

	orders->CompleteOrder(choice - 1);
	cout << endl << "Order Complete!" << endl;
	orders->DisplayOrder(choice - 1);
	Screen(Tree1, ProductList, ConditionList, Status, orders);

}

void Employee::BulkInput(SerialTree* Tree1, vector<string> ProductList, vector<string> ConditionList, vector<string> Status, Orders* orders)//Lets the user input many serials to add many new products to the system. These products will all have the same data except the serial to speed up efficiency when inputting a lot of them.
{

	int product;
	int condition;

	cout << endl << "In this menu every product scanned will share the same parameters which you will set, unless you would like to change these halfway through." << endl;

	cout << "Below is a list of all the products we take: " << endl << endl;
	for (int i = 0;i < ProductList.size();i++) {
		cout << i << ". " << ProductList[i] << endl;
	}
	cout << endl << "Please select the number of the product to bulk scan: " << endl << endl;

	try {
		cin >> product;
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


	cout << endl << "Below is a list of conditions: " << endl << endl;
	for (int i = 0;i < ConditionList.size();i++) {
		cout << i << ". " << ConditionList[i] << endl;
	}
	cout << "Please select a condition: " << endl << endl;
	
	try {
		cin >> condition;
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

	while (true) {

		int serial;
		cout << endl << "Please enter serial. Type -1 to stop." << endl << endl;
		try {
			cin >> serial;
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
		if (serial == -1) {
			Screen(Tree1, ProductList, ConditionList, Status, orders);
			break;
		}

		try {
			Tree1->Find(serial);
		}
		catch (Errors& e) {
			Tree1->Insert(serial, ProductList[product], ConditionList[condition], Status[1], this->username);
			Tree1->operator+();
		}

	}

}

void Employee::EditProduct(SerialTree* Tree1, vector<string> ProductList, vector<string> ConditionList, vector<string> Status, Orders* orders)//Lets the user change any part of an object's data
{
	cout << endl << "Please enter serial: " << endl << endl;
	int serial;
	cin >> serial;
	string temp = Tree1->GetProduct(serial);
	if (temp == "") {
		Screen(Tree1, ProductList, ConditionList, Status, orders);
		return;
	}

	cout << endl << "What would you like to edit?" << endl << "1. Serial" << endl << "2. Product" << endl << "3. Condition " << endl << "4. Status" << endl << "5. Cancel." << endl << endl;
	int choice;
	cin >> choice;
	switch (choice) {
	case 1:
		cout << "Please enter the new serial: " << endl << endl;
		int newserial;
		cin >> newserial;

		Tree1->Insert(newserial, Tree1->GetProduct(serial), Tree1->GetCondition(serial), Tree1->GetStatus(serial), this->username);
		Tree1->Delete(serial);
		cout << "New item added." << endl;
		Screen(Tree1, ProductList, ConditionList, Status, orders);
		
	case 2:
		cout << endl << "Please enter the product to be changed to." << endl << endl;
		for (int i = 0; i < ProductList.size(); i++) {
			cout << i << ". " << ProductList[i] << endl;
		}
		int product;
		cin >> product;

		if (Tree1->Find(serial)) {

			Tree1->SetProduct(ProductList[product], serial, this->username);
			Screen(Tree1, ProductList, ConditionList, Status, orders);
			break;
		}
		else {
			cout << "Doesn't exist." << endl;
			EditProduct(Tree1, ProductList, ConditionList, Status, orders);
			break;
		}

		break;
	case 3:
		cout << endl << "Please enter the condition to be changed to." << endl << endl;
		for (int i = 0; i < ConditionList.size(); i++) {
			cout << i << ". " << ConditionList[i] << endl;
		}
		int condition;
		cin >> condition;

		if (Tree1->Find(serial)) {

			Tree1->SetCondition(ConditionList[condition], serial, this->username);
			Screen(Tree1, ProductList, ConditionList, Status, orders);
			break;
		}
		else {
			cout << "Doesn't exist." << endl;
			EditProduct(Tree1, ProductList, ConditionList, Status, orders);
			break;
		}
		break;
	case 4:
		cout << endl << "Please enter the status to be changed to." << endl << endl;
		for (int i = 0; i < Status.size(); i++) {
			cout << i << ". " << Status[i] << endl;
		}
		int status;
		cin >> status;

		if (Tree1->Find(serial)) {

			Tree1->SetStatus(Status[status], serial, this->username);
			Screen(Tree1, ProductList, ConditionList, Status, orders);;
			break;
		}
		else {
			cout << "Doesn't exist." << endl;
			EditProduct(Tree1, ProductList, ConditionList, Status, orders);
			break;
		}
		break;
	case 5:
		Screen(Tree1, ProductList, ConditionList, Status, orders);
		break;
	default:
		break;
	}
}

void Employee::DeleteProduct(SerialTree* Tree1)//Lets the user delete a product
{
	cout << endl << "What item would you like to delete? Please enter the serial number." << endl << endl;
	int delnum;
	cin >> delnum;
	Tree1->Delete(delnum);
}



void Employee::ShowStock(SerialTree* Tree1, vector<string> ProductList, vector<string> ConditionList, vector<string> Status, Orders* orders)//Shows all the stock in the system and has options to find a single object from its serial, list many objects filtered by their product type, or to show all the stock in order of serials.
{
	cout << endl << "Options for browsing stock: " << endl << "1. Search for serial." << endl << "2. Filter by product." << endl << "3. Display all stock" << endl << endl;
	int choice;
	cin >> choice;
	switch (choice) {
	case 1:
		cout << endl << "Please enter serial: " << endl << endl;
		int serial;
		cin >> serial;
		Tree1->Find(serial);
		cout << endl << endl;
		Screen(Tree1, ProductList, ConditionList, Status, orders);
		break;

	case 2:
		cout << endl << "Below is a list of all the product types. Please select a type." << endl << endl;
		for (int i = 0; i < ProductList.size(); i++) {
			cout << i << ". " << ProductList[i] << endl;
		}
		int choice;
		cin >> choice;
		Tree1->Find(ProductList[choice], Tree1->root, &Node::Display);
		cout << endl << endl;
		Screen(Tree1, ProductList, ConditionList, Status, orders);
		break;
	case 3:
		Tree1->DisplayInOrder(Tree1->root);
		cout << endl << endl;
		Screen(Tree1, ProductList, ConditionList, Status, orders);
		break;
	}
}

Employee::~Employee(){}
