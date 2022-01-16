#include <exception>
#include <string>
using namespace std;

#include "Person.h"

Person::Person(string newName, string newSurname, int newDateOfBirth, string newEmail, string newPassword) {
	name[0] = newName;
	surname = newSurname;
	dateOfBirth = newDateOfBirth;
	email = newEmail;
	password = newPassword;
}
Person::Person() {
}


string* Person::getName() {
	return this->name;
}
string Person::get2Name() {
	return name[1];
}
string Person::getSurename() {
	return surname;
}
int Person::getDateOfBirth() {
	return this->dateOfBirth;
}
string Person::getEmail() {
	return this->email;
}
int Person::getPermissions()
{
	return static_cast <int> (this->_permissions);
}


void Person::setName(string aName, string bName) {
	this->name[0] = aName;
	this->name[1] = bName;
}
void Person::setSurename(string aSurename) {
	throw "Not yet implemented";
}
void Person::setDateOfBirth(int aDateOfBirth) {
	this->dateOfBirth = aDateOfBirth;
}
void Person::setEmail(string aEmail) {
	this->email = aEmail;
}
bool Person::getIsLogged()
{
	return isLogged;
}

bool Person::changePassword(string newPassword, string NewerPassword) {
	throw "Not yet implemented";
}


bool Person::logIn(string newEmail, string newPassword) {
	
	if (newEmail == email && newPassword == password)
	{
		isLogged = true;
		return true;
	}
	return false;
}
void Person::logOut() {
	isLogged = false;
}
