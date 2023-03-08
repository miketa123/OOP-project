#include "Broj.h"
using namespace std;



Broj::Broj(string& ime, string& broj) 
	: ime(ime), broj(broj) {}

Broj::~Broj() {}

string Broj::getName() {
	return this->ime;
}

string Broj::getNumber() {
	return this->broj;
}

void Broj::setName(string& name) {
	this->ime = name;
}

void Broj::setNumber(string& number) {
	this->broj = number;
}
















/*Fiksni::Fiksni(string& ime, string& broj, string& preprefix) {
	this->ime = ime;
	this->broj = broj;
	this->preprefix = preprefix;
}

string Fiksni::getName() {
	return this->ime;
}

string Fiksni::getNumber()  {
	return this->broj;
}

const string Fiksni::prefix = "11";

string Fiksni::getPrefixFik() {
	return prefix;
}

string Fiksni::getPreprefix() {
	return this->preprefix;
}

Mobilni::Mobilni(string& ime, string& broj, string& prefix, string& preprefix) {
	this->ime = ime;
	this->broj = broj;
	this->prefix = prefix;
	this->preprefix = preprefix;
}

string Mobilni::getName() {
	return this->ime;
}

string Mobilni::getNumber() {
	return this->ime;
}

string Mobilni::getPrefixMob() {
	return this->prefix;
}

string Mobilni::getPreprefix() {
	return this->preprefix;
}*/