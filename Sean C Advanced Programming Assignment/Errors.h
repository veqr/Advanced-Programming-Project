#pragma once
#include <exception>
#include <iostream>
#include <string>

using namespace std;

class Errors : public exception
{
public:
	const char* what() {
		return "Invalid input";
	}
	const char* delwhat() {
		return "Cannot edit product that does not exist.";
	}
};

