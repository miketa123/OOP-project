#include "Trie.h"


Trie::Trie() {
	root = getNode('/' - 'a');
}

Trie::~Trie() {
	removeAllElements(root);
}

void Trie::insert(Broj* broj) {
	Trienode* curr = root;
	int index;
	string word = broj->getName();
	for (int i = 0; word[i] != '\0'; i++) {
		index = word[i];
		if (curr->child[index] == nullptr)
			curr->child[index] = getNode(index);
		curr->child[index]->count++;
		curr = curr->child[index];
		
	}
	curr->broj = broj;
	
}

bool Trie::search(string& word) {
	Trienode* curr = root;
	int index;
	for (int i = 0; word[i] != '\0'; i++) {
		index = word[i];
		if (!curr->child[index])
			return false;
		curr = curr->child[index];
	}
	return curr->broj;
}

bool Trie::startsWith(string& prefix) {
	Trienode* curr = root;
	int index;
	for (int i = 0; prefix[i] != '\0'; i++) {
		index = prefix[i];
		if (!curr->child[index])
			return false;
		curr = curr->child[index];
	}
	return curr->count > 0;
}

void Trie::getNumbers(Trienode* curr) {
	
	if (curr->broj)
		cout << "---" << curr->broj->getName() << " " << curr->broj->getNumber() << endl;
	for (int i = 0; i < 128; i++) {
		if (curr->child[i])
			getNumbers(curr->child[i]);
	}
}


int Trie::countNumbers(Trienode* curr, int& n) {
	int index;
	if (curr->broj)
		n++;
	for (int i = 0; i < 128; i++) {
		if (curr->child[i])
			countNumbers(curr->child[i], n);
	}
	return n;
}

void Trie::searchPrefix(string& prefix) {
	Trienode* current = this->root;
	
	int index;
	for (int i = 0; i<prefix.length(); i++) {
		if (!current)
			return;
		index = prefix[i];
		current = current->child[index];
		
	}
	getNumbers(current);
}

void Trie::searchName(string& name) {
	Trienode* current = this->root;

	int index;
	for (int i = 0; i < name.length(); i++) {
		if (!current)
			return;
		index = name[i];
		current = current->child[index];

	}
	cout << current->broj->getName() << " " << current->broj->getNumber();
}

Broj* Trie::getContact(string& name) {
	Trienode* current = this->root;

	int index;
	for (int i = 0; i < name.length(); i++) {
		index = name[i];
		current = current->child[index];
	}
	return current->broj;
}


int Trie::countPrefix(string& prefix) {
	Trienode* current = this->root;
	int n = 0;
	int index;
	for (int i = 0; i < prefix.length(); i++) {
		if (!current)
			return -1;
		index = prefix[i];
		current = current->child[index];

	}
	return countNumbers(current, n);
}

bool Trie::removeNumber(string& ime) {
	if (!root)
		return false;

	Trienode* current = this->root;
	int index;
	for (int i = 0; ime[i] != '\0'; i++) {
		index = ime[i];
		current = current->child[index];
	}
	if (current->broj) {
		current->broj = nullptr;
		return true;
	}
	return false;
}

void Trie::removeAllElements(Trienode* current) {
	for (int i = 0; i < 128; i++) 
		if (current->child[i]) 
			removeAllElements(current->child[i]);
	if (current->broj)
		delete current->broj;
	delete current;
}

void Trie::removeAllElements() {
	removeAllElements(this->root);
}

void Trie::editName(string& trime, string& novoime) {
	Trienode* current = this->root;
	int index;
	for (int i = 0; i < trime.length(); i++) {
		if (!current)
			return;
		index = trime[i];
		current = current->child[index];
	}
	string telefon = current->broj->getNumber();
	delete current->broj;
	Broj* b = new Broj(novoime, telefon);
	insert(b);
}

void Trie::editNumber(string& name, string& newnumber) {
	Trienode* current = this->root;
	int index;
	for (int i = 0; i < name.length(); i++) {
		if (!current)
			return;
		index = name[i];
		current = current->child[index];
	}
	current->broj->setNumber(newnumber);
}

void Trie::edit(string& trime, string& novoime, string& novbroj) {
	Trienode* current = this->root;
	int index;
	for (int i = 0; i < trime.length(); i++) {
		if (!current)
			return;
		index = trime[i];
		current = current->child[index];
	}
	delete current->broj;
	Broj* b = new Broj(novoime, novbroj);
	insert(b);
}

