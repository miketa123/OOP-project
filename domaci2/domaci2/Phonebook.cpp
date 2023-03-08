#include "Phonebook.h"

PhoneBook::PhoneBook()
{
	this->stablo = new Trie();
	//this->input = "";
	
}

PhoneBook::~PhoneBook() {
	this->stablo->removeAllElements();
	while (!this->red.empty()) {
		red.pop();
	}
}

void PhoneBook::loadPhonebook(const string& input) {
	//this->input = &input;
	readFile(input);
	//openTerminal();
}

void PhoneBook::readFile(const string& path) {
	ifstream input(path.c_str());
	string red, ime, telefon = "";
	string a;
	Broj* b;
	int ind = 0;
	if (input.is_open()) {
		//istringstream is(input);

		//while (getline(is, red)) {
			//cout << red << endl;
		while (std::getline(input, red)) {
			ind++;
			ime = getName(red);
			telefon = getNumber(red);
			try {
				throwNumber(telefon);
				b = new Broj(ime, telefon);
				this->stablo->insert(b);
			}
			catch (PhonebookException& e) {
				std::cout << "Greska u " << ind << "-om redu: " << e.what() << endl;
			}
			//}
		}
	}
	else
		std::cout << "Fajl nije otvoren" << endl;
	
}

string PhoneBook::getName(string& red) {
	string ime = "";
	//telefon = "";
	int index = 0;
	for (int i = 0; i < red.length(); i++) {
		if (red[i] == ',') {
			index = i;
			break;
		}
	}
	for (int i = 0; i < index; i++)
		ime += red[i];
	return ime;
}

string PhoneBook::getNumber(string& red) {
	string telefon = "";
	int index = 0;
	for (int i = 0; i < red.length(); i++) {
		if (red[i] == ',') {
			index = i;
			break;
		}
	}
	for (int i = index + 1; i < red.length(); i++)
		telefon += red[i];
	return telefon;
}

void PhoneBook::throwNumber(string& broj) {

	if ((broj[0] != '+') and (broj[0] != '0'))
		throw PhonebookException("Broj nema odgovarajuci prefix");
	if (broj[0] == '+') {
		for (int i = 1; i < broj.length(); i++) {
			if (broj[i] == ' ')
				continue;
			if (!isdigit(broj[i]))
				throw PhonebookException("Broj sadrzi karakter koji nije cifra");
		}
		if ((broj.length() != 14) and (broj.length() != 15))
			throw PhonebookException("Broj nema dovoljno cifara");
		if ((broj[1] != '3') or (broj[2] != '8') or (broj[3] != '1'))
			throw PhonebookException("Broj nema odgovarajuci prefix");
		if (broj[4] != ' ')
			throw PhonebookException("Broj nema u sebi razmak");
		if (broj[5] != '6') {
			if (broj[5] != '1')
				throw PhonebookException("Broj nije ni fiksni ni mobilni");
			else
				if (broj[6] != '1')
					throw PhonebookException("Broj nije ni fiksni ni mobilni");
		}
		if (broj[7] != ' ')
			throw PhonebookException("Broj nema u sebi razmak");
		
	}
	if (broj[0] == '0') {
		for (int i = 1; i < broj.length(); i++) {
			if (broj[i] == ' ')
				continue;
			if (!isdigit(broj[i]))
				throw PhonebookException("Broj sadrzi karakter koji nije cifra");
		}
		if ((broj.length() != 11) and (broj.length() != 10))
			throw PhonebookException("Broj nema dovoljno cifara");
		if (broj[1] != '6') {
			if (broj[1] != '1')
				throw PhonebookException("Broj nije ni fiksni ni mobilni");
			else
				if (broj[2] != '1')
					throw PhonebookException("Broj nije ni fiksni ni mobilni");
		}
		if (broj[3] != ' ')
			throw PhonebookException("Broj nema u sebi razmak");
	}

}

void PhoneBook::search(string& prefix) {
	this->stablo->searchPrefix(prefix);
}

void PhoneBook::newContact(string& ime, string& broj) {
	Broj* b;
	try {
		throwNumber(broj);
		b = new Broj(ime, broj);
		this->stablo->insert(b);
	}
	catch (PhonebookException& e) {
		std::cout << "Uneti broj nije u dobrom formatu: " << e.what() << endl;
	}
}

void PhoneBook::editName(string& trime, string& novoime) {
	this->stablo->editName(trime, novoime);
}

void PhoneBook::editNumber(string& ime, string& broj) {
	try {
		throwNumber(broj);
		this->stablo->editNumber(ime, broj);
	}
	catch (PhonebookException& e) {
		std::cout << "Uneti broj nije u dobrom formatu: " << e.what() << endl;
	}
}

void PhoneBook::edit(string& trime, string& novoime, string& novbroj) {
	try {
		throwNumber(novbroj);
		this->stablo->edit(trime, novoime, novbroj);
	}
	catch (PhonebookException& e) {
		std::cout << "Uneti broj nije u dobrom formatu: " << e.what() << endl;
	}
}

void PhoneBook::openTerminal() {
	std::cout << "--------------------------" << endl;
	std::cout << "Welcome to your phonebook!" << endl;
	std::cout << "--------------------------" << endl;
	string komanda;
	string ime;
	string broj;
	string selektovan = "";
	int sel = 0;
	queue<Broj*> pomocna;
	while (1) {
		std::cout << "Enter the command: ";
		std::getline(cin, komanda);
		int index = 0;


		if (komanda == "EXIT") {
			break;
		}
		if (komanda == "NEW") {
			index = 1;
			std::cout << "- Enter name: ";
			std::getline(cin, ime);
			std::cout << "- Enter number: ";
			std::getline(cin, broj);
			newContact(ime, broj);
		}
		if (komanda == "SEARCH") {
			index = 1;
			std::cout << "- Enter the contact name or first few letters: ";
			std::getline(cin, ime);
			std::cout << "- " << this->stablo->countPrefix(ime) << " contacts have been found : " << endl;
			search(ime);
		}
		if (komanda == "SELECT") {
			index = 2;
			sel = 1;
			std::cout << "- Enter the contact name: ";
			std::getline(cin, selektovan);
			//cin >> selektovan;
			if (this->stablo->search(selektovan)) {
				std::cout << "- Contact ";
				this->stablo->searchName(selektovan);
				std::cout << " is now selected." << endl;
			}
			else {
				sel = 0;
				std::cout << "- No contact has been found." << endl;
			}
		}
		if (komanda == "DELETE") {
			index = 1;
			if (sel == 1) {
				std::cout << "- Contact ";
				this->stablo->searchName(selektovan);
				std::cout << " has been deleted." << endl;
				this->stablo->removeNumber(selektovan);
				sel = 0;
			}
		}
		if (komanda == "EDIT") {
			index = 1;
			if (sel == 1) {
				std::cout << "--Enter the new name: ";
				std::getline(cin, ime);
				std::cout << "--Enter the new number: ";
				std::getline(cin, broj);
				if (ime != "") {
					if (broj == "")
						editName(selektovan, ime);
					else
						edit(selektovan, ime, broj);
					this->stablo->removeNumber(selektovan);
				}
				else
					if (broj != "")
						editNumber(selektovan, broj);
				sel = 0;
			}
		}
		if (komanda == "CALL") {
			index = 1;
			if (sel == 1) {
				std::cout << "- Contact ";
				this->stablo->searchName(selektovan);
				std::cout << " has been called." << endl;
				Broj* b = this->stablo->getContact(selektovan);
				if (this->red.size() == 10)
					this->red.pop();
				this->red.push(b);
				sel = 0;
			};
		}
		if (komanda == "CALL_HISTORY") {
			index = 1;
			std::cout << "- Call history: " << endl;
			pomocna = this->red;
			while (!pomocna.empty()) {
				std::cout << pomocna.front()->getName() << " " << pomocna.front()->getNumber() << endl;
				pomocna.pop();
			}
		}


		if (index == 0)
			std::cout << "- Command doesnt exist. " << endl;

	}
}