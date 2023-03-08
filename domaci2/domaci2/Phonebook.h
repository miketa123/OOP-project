#pragma once
#include "Broj.h"
#include "Trie.h"
#include <fstream>
#include <iostream>
#include <queue>
#include "PhonebookException.h"
#include <sstream>

using namespace std;

class PhoneBook {
public:
	PhoneBook();
	~PhoneBook();
	void loadPhonebook(const string& input);
	void openTerminal();
private:
	queue<Broj*> red;
	//string input;
	Trie* stablo;
	
	void readFile(const string& input);
	string getName(string& red);
	string getNumber(string& red);
	void throwNumber(string& broj);
	void search(string&);
	void newContact(string&, string&);
	void editName(string&, string&);
	void editNumber(string&, string&);
	void edit(string&, string& , string&);
};