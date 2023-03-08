#include "Phonebook.h"
#include <sstream>
using namespace std;

int main() {
	string path = "tst.csv";
	//stringstream buff;
	//buff << input.rdbuf();
	PhoneBook* imenik = new PhoneBook();
	imenik->loadPhonebook(path);
	imenik->openTerminal();



}