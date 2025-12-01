#include "Admin.h"

Admin::Admin(string username, string userpassword, string usertype)
{
	this->username = username;
	this->userpassword = userpassword;
	this->usertype = usertype;
}

void Admin::Screen(SerialTree* Tree1)
{
	cout << "Admin";
}

Admin::~Admin()
{
}
