#include "Employee.h"

Employee::Employee(string username, string userpassword, string usertype)
{
	this->username = username;
	this->userpassword = userpassword;
	this->usertype = usertype;
}

void Employee::Screen()
{
	cout << "Logged in as Employee" << endl << "Below are the menu options: " << endl;

}

Employee::~Employee(){}
