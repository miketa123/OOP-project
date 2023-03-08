#pragma once
#include <string>
#include "Broj.h"
#include <iostream>


using namespace std;

class Trie {
public:
	Trie();
	~Trie();
	void insert(Broj* broj);
	bool search(string& name);
	bool startsWith(string& pref);
	void searchPrefix(string& prefix);
	int countPrefix(string& prefix);
	bool removeNumber(string& ime);
	void removeAllElements();
	void editName(string& trenutnoime, string& novoime);
	void editNumber(string& ime, string& novbroj);
	void edit(string& trenutnoime, string& novoime, string& novbroj);
	void searchName(string& name);
	Broj* getContact(string& name);

private:
	struct Trienode {
		char val;
		int count;
		int end;
		Broj* broj;
		Trienode* child[128];
	};
	Trienode* root;

	Trienode* getNode(int index) {
		Trienode* newnode = new Trienode();
		newnode->val = index;
		newnode->count = newnode->end = 0;
		newnode->broj = nullptr;
		
		for (int i = 0; i < 128; i++)
			newnode->child[i] = nullptr;
		return newnode;
	}
	void getNumbers(Trienode* root);
	int countNumbers(Trienode* root, int& n);
	void removeAllElements(Trienode* root);
	
};