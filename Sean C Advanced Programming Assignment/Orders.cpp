#include "Orders.h"
#include <vector>

string conditions[3] = { "New","Used","Faulty" };

vector<string> OProductList
{
	"Pax A920",
	"Pax A920 Pro",
	"Lenovo Think Vision T24H_20",
	"Lenovo Think Vision T24m_10",
	"Lenovo Think Vision T2223pD",
	"IOT Sim 1",
};

vector<string> OStatus
{
	"Picked",
	"Available",
};


void Orders::ShowOrders()//Outputting order data
{
	for (int i = 0; i < ordersList.size(); i++) {
		cout << "Order Number: " << ordersList[i][0] << " :: Customer: " << ordersList[i][1] << " :: Status: " << ordersList[i][2] << " :: Product: " << OProductList[stoi(ordersList[i][3])] << " :: Quantity: " << ordersList[i][4] << " :: Condition: " << conditions[stoi(ordersList[i][5])] << " :: Address: " << ordersList[i][6] << endl;
	}
}

void Orders::DisplayOrder(int key)//Displaying a specific order and its data
{
	cout << "Order Number: " << ordersList[key][0] << " :: Customer: " << ordersList[key][1] << " :: Status: " << ordersList[key][2] << " :: Product: " << OProductList[stoi(ordersList[key][3])] << " :: Quantity: " << ordersList[key][4] << " :: Condition: " << conditions[stoi(ordersList[key][5])] << " :: Address: " << ordersList[key][6] << endl;
}

void Orders::AddOrder(vector<string> order)//Adding a new order to the vector
{
	ordersList.emplace_back(order);
}

void Orders::CompleteOrder(int key)//Completing the order by changing its Status data
{
	ordersList[key][2] = "Complete";
}

int Orders::NewOrderNumber()//Creates a new order number so its unique
{
	return (ordersList.size() + 1);
}



Orders::Orders()
{

}

Orders::~Orders()
{
}
