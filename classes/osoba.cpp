#include <exception>
#include <string>
using namespace std;

#include "osoba.h"
bool osoba::logowanie(string aString_email, string aString_has這) {
	throw "Not yet implemented";
}

bool osoba::zmien_has這(string aString_has這, string aString_nowe_has這) {
	throw "Not yet implemented";
}

void osoba::wylogowanie() {
	throw "Not yet implemented";
}

osoba::osoba(string aString_Imie, string aString_Nazwisko, string aInt_Data_Urodzenia, string aString_email) {
}

string* osoba::getImie() {
	return this->_imie;
}

void osoba::setImie(string aImie, string bImie ) {
	this->_imie[0] = aImie;
	this->_imie[1] = bImie;
}

string osoba::getNazwisko() {
	return this->_nazwisko;
}

void osoba::setNazwisko(string aNazwisko) {
	this->_nazwisko = aNazwisko;
}

int osoba::getData_urodzenia() {
	return this->_data_urodzenia;
}

void osoba::setData_urodzenia(int aData_urodzenia) {
	this->_data_urodzenia = aData_urodzenia;
}

string osoba::getEmail() {
	return this->_email;
}

void osoba::setEmail(string aEmail) {
	this->_email = aEmail;
}

