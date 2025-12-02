#include <iostream>
#include <string>
#include <vector>

#include "Employee.h"
#include "Admin.h"
#include "Customer.h"
#include "SerialTree.h"
#include "Node.h"

using namespace std;

/*

IDEAS:

    make way to add new items to database

    make way to change existing items

    not sure if deleting will be added, depends if it gives more marks

    maybe add a way to take orders like work using serial numbers. should be able to bulk add serials too. must only add the items and serials if they are the correct type.

    add customer accounts so that they can order items from stock and should be able to see how many of each item is in stock and their condition.
    might need some sort of formula to make searching for stock easier. can retrieve values of what each product contributes to decode the serial if needed. 

    sign out so orders can be made and employees can complete orders for demonstration.


    need linked lists. maybe with orders? order numbers? to track


    need friendship

    error handling ez with serial for example

    overloading ez

    static members = stock levels??

    functional pointers hard to do ask at some point// callback maybe? notification.
    memory management is destructors especially with deleting object so delete linked list from memory
    
    polymorphism ez

    operator overloading = hope

    GITHUB





COMMANDMENTS:

    3.	Friendship

    4.	Static Members

    7.	Functional Pointers

    10.	 Operator Overloading

    REMEMBER TO DO EXCEPTION CLASS. FIND OUT HOW THAT APPLIES HERE.

    MAYBE MAKE LINKED LISTS TO CONTRIBUTE TO CLASSES? MAYBE STAY AWAY FROM VECTORS


*/




/*
Layout of bulk input and database:

    Serial :: Product :: Condition (New/Used/Faulty) :: Date Added :: Status (Picked/Not Picked)

*/

int loginAttempts = 0;
int loginType = 0;
bool loggedIn = false;
User* currentUser;
SerialTree* Tree1 = new SerialTree();
User* Employee1 = new Employee("a", "b", "Employee");
User* Admin1 = new Admin("b", "c", "Admin");
User* Customer1 = new Customer("c", "d", "Customer");

const int initialStockCount = 100;

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

vector<User*> SystemUsers;

void Login() {
    while (loginAttempts < 4 && loggedIn == false) {

        string username;
        string password;

        //REMEMEBR TO ADD THE THING THAT FIXES SPACES

        cout << "Please enter username" << endl;
        cin >> username;

        cout << "Please enter password" << endl;
        cin >> password;

        for (int i = 0; i < SystemUsers.size();i++) {
            if (SystemUsers[i]->getUsername() == username && SystemUsers[i]->getPassword() == password) {
                currentUser = SystemUsers[i];
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

void InitialStockFunction(string product, string condition, string status, int maxSerial) {

    for (int i = (maxSerial-(initialStockCount-1)); i < (maxSerial + 1); i++)
    {

        Tree1->Insert(i, product, condition, status, "Sean C");

    }
}

int main()
{
    SystemUsers.emplace_back(Employee1);
    SystemUsers.emplace_back(Admin1);
    SystemUsers.emplace_back(Customer1);


    InitialStockFunction(ProductList[2], ConditionList[0], Status[0], 100);
    InitialStockFunction(ProductList[0], ConditionList[1], Status[0], 200);
    InitialStockFunction(ProductList[4], ConditionList[0], Status[0], 300);


    Login();

    //delete Tree1;

    //change into overrides with classes to meet commandment


    //Tree1->Delete(Tree1->root, 2);
    //Tree1->DisplayInOrder(Tree1->root);

    //Tree1->Find(55);
    //Tree1->Find(ProductList[4], Tree1->root);

    //Tree1->DisplayRoot();

    //Tree1->SortTree(Tree1->root);

}
