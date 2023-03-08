#pragma once
#include <string>
#include <iostream>
using namespace std;

class Broj {
public:
	Broj(string&, string&);
	~Broj();
	string getName();
	string getNumber() ;
	void setName(string&);
	void setNumber(string&);
private:
	string ime;
	string broj;
};
