#include <iostream>
#include <string>
#include <vector>

#include "Employee.h"
#include "Admin.h"
#include "Customer.h"
#include "SerialTree.h"
#include "Node.h"
#include "UserManager.h"

using namespace std;

/*

IDEAS:

    make way to change existing items. deleting too.

    maybe add a way to take orders like work using serial numbers. should be able to bulk add serials too. must only add the items and serials if they are the correct type.

    add customer accounts so that they can order items from stock and should be able to see how many of each item is in stock and their condition.

    sign out so orders can be made and employees can complete orders for demonstration.

    need friendship

    error handling ez with serial for example

    static members? WOOOOOOO MANAGEMENT CLASS

    create account

    CLASS DIAGRAM
    CLASS DIAGRAM
    CLASS DIAGRAM
    CLASS DIAGRAM
    CLASS DIAGRAM
    CLASS DIAGRAM
    CLASS DIAGRAM



COMMANDMENTS:

    REMEMBER TO DO EXCEPTION CLASS. FIND OUT HOW THAT APPLIES HERE.

*/




/*
Layout of bulk input and database:

    Serial :: Product :: Condition (New/Used/Faulty) :: Date Added :: Status (Picked/Not Picked) :: Last Editor

*/

int loginAttempts = 0;
int loginType = 0;
bool loggedIn = false;
User* currentUser;
SerialTree* Tree1 = new SerialTree();

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
                currentUser->Screen(Tree1, ProductList, ConditionList, Status);
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
        //make program close
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

    cout << "Please enter the Employee Creation Password." << endl;
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
            UserManager::InitialiseUser(username, password, userTypes[0]);
        }
    }
    

}

void CreateAdmin() {

    cout << "Please enter the Admin Creation Password." << endl;
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
            UserManager::InitialiseUser(username, password, userTypes[1]);
        }
    }
}

void CreateCustomer() {

    cout << "Please enter a username. Must be unique." << endl;
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
        UserManager::InitialiseUser(username, password, userTypes[2]);
    }
}

int CreateUser() {
    cout << endl << "Enter the account you are creating." << endl << "1. Employee." << endl << "2. Admin." << endl << "3. Customer." << endl << "4. Cancel." << endl;
    int choice;
    cin >> choice;
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
    
    cout << "Please enter an option from below: " << endl << "1. Log In." << endl << "Create Account." << endl << "3. Close Program." << endl;
    int choice;
    cin >> choice;
    switch (choice) {
    case 1:
        Login();
        break;
    case 2:
        if(CreateUser()==0) MainMenu();
        break;
    case 3:
        exit(0);
        break;
    default:
        cout << "Incorrect input. please try again." << endl;
        MainMenu();
        break;
    }
}

int main()
{

    UserManager::InitialiseUser("a", "b", userTypes[0]);
    UserManager::InitialiseUser("b", "c", userTypes[1]);
    UserManager::InitialiseUser("c", "d", userTypes[2]);


    InitialStockFunction(ProductList[0], ConditionList[1], Status[0], 101, 200);
    InitialStockFunction(ProductList[2], ConditionList[0], Status[0], 1, 100);
    InitialStockFunction(ProductList[4], ConditionList[0], Status[0], 201, 300);

    systemUsers = UserManager::getUsers();

    MainMenu();


    //Tree1->Delete(2);
    //Tree1->Delete(300);
    //Tree1->Delete(1);
    //Tree1->Delete(150);
    //Tree1->Delete(250);
    //Tree1->DisplayInOrder(Tree1->root);

    //Tree1->Find(55);
    //Tree1->Find(ProductList[4], Tree1->root);

    //Tree1->DisplayRoot();

    //Tree1->SortTree(Tree1->root);

    //delete Tree1;
}
