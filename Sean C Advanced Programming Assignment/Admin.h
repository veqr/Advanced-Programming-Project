#pragma once
#include "User.h"
class Admin : public User
{
public:
	Admin(string username, string userpassword, string usertype);
	void Screen(SerialTree* Tree1);
	~Admin();
};

