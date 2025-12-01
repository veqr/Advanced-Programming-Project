#pragma once
#include "User.h"
class Customer : public User
{
	Customer(string username, string userpassword, string usertype);
	void Screen();
	~Customer();
};