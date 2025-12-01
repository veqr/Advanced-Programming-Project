#pragma once
#include "User.h"
class Employee : public User
{
public:
	Employee(string username, string userpassword, string usertype);
	void Screen();
	~Employee();
};

