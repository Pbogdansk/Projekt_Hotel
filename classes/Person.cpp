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
string Person::getSurname() {
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
	return static_cast <int> (this->permissions);
}
int Person::getIndex()
{
	return index;
}
bool Person::getIsLogged()
{
	return isLogged;
}


void Person::setName(string aName, string bName) {
	this->name[0] = aName;
	this->name[1] = bName;
}
void Person::setSurname(string newSurname) {
	surname = newSurname;
}
void Person::setDateOfBirth(int newDateOfBirth) {
	this->dateOfBirth = newDateOfBirth;
}
void Person::setEmail(string newEmail) {
	this->email = newEmail;
}
void Person::setPassword(string newPassword) {
	password = newPassword;
}
void Person::setIndex(int aIndex) {
	index = aIndex;
}

bool Person::changePassword(string currentPassword, string newPassword) {
	if (password == currentPassword) {
		password = newPassword;

		return 1;
	}
	else {
		return 1;
	}
}

bool Person::logIn(string givenEmail, string givenPassword) {
	
	if (givenEmail == email && givenPassword == password)
	{
		isLogged = true;
		return true;
	}
	return false;
}
void Person::logOut() {
	isLogged = false;
}
