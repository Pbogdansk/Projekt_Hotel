#include <exception>
#include <string>
using namespace std;

#include "Person.h"
bool Person::logIn(string aString_email, string aString_password) {
	throw "Not yet implemented";
}

bool Person::changePassword(string aString_password, string aString_newPassword) {
	throw "Not yet implemented";
}

void Person::logOut() {
	throw "Not yet implemented";
}

void Person::person(string aString_name, string aString_surname, string aInt_dateOfBirth, string aString_email) {
	throw "Not yet implemented";
}

string* Person::getName() {
	return this->_name;
}

void Person::setName(string aName, string bName ) {
	this->_name[0] = aName;
	this->_name[1] = bName;
}

string Person::getSurename() {
	throw "Not yet implemented";
}

void Person::setSurename(string aSurename) {
	throw "Not yet implemented";
}

int Person::getDateOfBirth() {
	return this->_dateOfBirth;
}

void Person::setDateOfBirth(int aDateOfBirth) {
	this->_dateOfBirth = aDateOfBirth;
}

string Person::getEmail() {
	return this->_email;
}

void Person::setEmail(string aEmail) {
	this->_email = aEmail;
}

int Person::getPermissions()
{
	return static_cast <int> (this->_permissions);
}

