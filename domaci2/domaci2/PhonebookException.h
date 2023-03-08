#pragma once
#include <exception>
#include <string>
using namespace std;

class PhonebookException : public exception {
public:
	PhonebookException(const char* msg)
		:exception(msg) {}
};