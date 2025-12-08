#include <iostream>
#include <string>
#include <vector>

#include "Employee.h"
#include "Admin.h"
#include "Customer.h"
#include "SerialTree.h"
#include "Node.h"
#include "UserManager.h"
#include "Errors.h"

using namespace std;

/*

IDEAS:

    CLASS DIAGRAM
    CLASS DIAGRAM
    CLASS DIAGRAM
    CLASS DIAGRAM
    CLASS DIAGRAM
    CLASS DIAGRAM
    CLASS DIAGRAM

*/




/*
Layout of bulk input and database:

    Serial :: Product :: Condition (New/Used/Faulty) :: Status (Picked/Not Picked) :: Last Editor

*/

int loginAttempts = 0;
int loginType = 0;
bool loggedIn = false;
User* currentUser;
SerialTree* Tree1 = new SerialTree();
Orders* orders = new Orders();

vector<string> dummyOrder;

vector<User*> systemUsers = UserManager::getUsers();

vector<string> ProductList
{
    "Pax A920",
    "Pax A920 Pro",
    "Lenovo Think Vision T24H_20",
    "Lenovo Think Vision T24m_10",
    "Lenovo Think Vision T2223pD",
    "IOT Sim 1",
};

vector<string> ConditionList
{
    "New",
    "Used",
    "Faulty",
};

vector<string> Status
{
    "Picked",
    "Available",
};

string userTypes[3] = { "Employee", "Admin", "Customer" };

//vector<User*> SystemUsers;//make static public in a management class so admin can access to delete a user.

void Login() {
    systemUsers = UserManager::getUsers();
    while (loginAttempts < 3 && loggedIn == false) {

        string username;
        string password;

        //REMEMEBR TO ADD THE THING THAT FIXES SPACES

        cout << "Please enter username" << endl;
        cin >> username;

        cout << "Please enter password" << endl;
        cin >> password;

        for (int i = 0; i < systemUsers.size();i++) {
            if (systemUsers[i]->getUsername() == username && systemUsers[i]->getPassword() == password) {
                currentUser = systemUsers[i];
                currentUser->Screen(Tree1, ProductList, ConditionList, Status, orders);
                loggedIn = true;
                break;
            }
            else {
                loggedIn = false;
            }
        }
        loginAttempts++;

    }

    if (loginAttempts == 3) {
        exit(0);
    }
}

void InitialStockFunction(string product, string condition, string status, int minSerial, int maxSerial) {

    for (int i = minSerial; i < (maxSerial + 1); i++)
    {

        Tree1->Insert(i, product, condition, status, "Sean C");
        Tree1->operator+();

    }
}

void CreateEmployee() {

    cout << endl << "Please enter the Employee Creation Password." << endl << endl;
    string passw;
    cin >> passw;
    if (passw == "123") {
        cout << "Please enter a username. Must be unique." << endl;

        cout << systemUsers.size();

        string username;
        cin >> username;
        bool unique = true;
        for (int i = 0; i < systemUsers.size(); i++) {
            if (systemUsers[i]->getUsername() == username) {
                unique = false;
                CreateEmployee();
            }
        }
        if (unique = true) {
            cout << "Please enter a password." << endl;
            string password;
            cin >> password;
            UserManager::InitialiseUser(username, password, userTypes[0], "Ignore");
        }
    }
    else {
        cout << "Incorrect Password." << endl << endl;
    }
    

}

void CreateAdmin() {

    cout << endl << "Please enter the Admin Creation Password." << endl << endl;
    string passw;
    cin >> passw;
    if (passw == "123") {
        cout << "Please enter a username. Must be unique." << endl;
        string username;
        cin >> username;
        bool unique = true;
        for (int i = 0; i < systemUsers.size(); i++) {
            if (systemUsers[i]->getUsername() == username) {
                unique = false;
                CreateAdmin();
            }
        }
        if (unique = true) {
            cout << "Please enter a password." << endl;
            string password;
            cin >> password;
            UserManager::InitialiseUser(username, password, userTypes[1], "Ignore");
        }
    }
    else {
        cout << "Incorrect Password." << endl << endl;
    }
}

void CreateCustomer() {

    cout << endl << "Please enter a username. Must be unique." << endl << endl;
    cout << systemUsers.size() << endl;
    string username;
    cin >> username;
    bool unique = true;
    for (int i = 0; i < systemUsers.size(); i++) {
        if (systemUsers[i]->getUsername() == username) {
            unique = false;
            CreateCustomer();
        }
    }
    if (unique = true) {
        cout << "Please enter a password." << endl;
        string password;
        cin >> password;

        cout << endl << "Please enter address." << endl;
        string address;
        cin >> address;

        UserManager::InitialiseUser(username, password, userTypes[2], address);
    }
}

int CreateUser() {
    cout << endl << "Enter the account you are creating." << endl << "1. Employee." << endl << "2. Admin." << endl << "3. Customer." << endl << "4. Cancel." << endl << endl;
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
        return 0;
    }

    switch (choice) {
    case 1:
        CreateEmployee();
        return 0;
        break;

    case 2:
        CreateAdmin();
        return 0;
        break;
    case 3:
        CreateCustomer();
        return 0;
        break;
    case 4:
        return 0;
        break;
    default:
        return 0;
    }
}

void MainMenu() {
    
    cout << "Please enter an option from below: " << endl << "1. Log In." << endl << "2. Create Account." << endl << "3. Close Program." << endl << endl;
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
        return;
    }

    switch (choice) {
    case 1:
        Login();
        break;
    case 2:
        if (CreateUser() == 0) break;
    case 3:
        exit(0);
        break;
    default:
        cout << "Incorrect input. please try again." << endl;
        break;
    }
}

void DummyOrders() {

}

int main()
{

    UserManager::InitialiseUser("a", "b", userTypes[0], "Ignore");
    UserManager::InitialiseUser("b", "c", userTypes[1], "Ignore");

    UserManager::InitialiseUser("c", "d", userTypes[2], "70 Clarendon View BR5 8PF");
    UserManager::InitialiseUser("d", "e", userTypes[2], "16 North Way BR8 9BH");


    InitialStockFunction(ProductList[0], ConditionList[0], Status[1], 101, 200);
    InitialStockFunction(ProductList[2], ConditionList[0], Status[1], 1, 100);
    InitialStockFunction(ProductList[4], ConditionList[0], Status[1], 201, 300);

    systemUsers = UserManager::getUsers();

    DummyOrders();

    while (true) {
        loggedIn = false;
        loginAttempts = 0;
        MainMenu();
    }


    delete Tree1;
    Tree1 = nullptr;
}
