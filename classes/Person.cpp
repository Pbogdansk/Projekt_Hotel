#include <exception>
#include <string>
#include "../include.h"

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


string Person::getName() {
	return name[0];
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

bool Person::logIn(string givenEmail, string givenPassword) {
	
	if (givenEmail == email && givenPassword == password)
	{
		isLogged = true;
		return true;
	}
	menu_gui::reset();
	menu_gui::add_top_text("Niestety podane haslo jest niepoprawne");
	menu_gui::add_option("Wroc do menu");
	menu_gui::display();
	return false;
}
void Person::logOut() {
	isLogged = false;
}

void Person::forceChangePassword() {
	menu_gui::reset();
	string newPassword;
	cout << endl << "Prosze podac nowe haslo ";
	cin >> newPassword;

	password = (newPassword);

	menu_gui::reset();
	menu_gui::add_top_text("Pomyslnie zmieniono haslo");
	menu_gui::add_option("Wroc do menu");
	menu_gui::display();
}

void Person::changeName() {
	menu_gui::reset();
	string newName;
	cout << endl << "Prosze podac nowe imie: ";
	cin >> newName;

	setName(newName, getName());

	menu_gui::reset();
	menu_gui::add_top_text("Pomyslnie zmieniono imie");
	menu_gui::add_option("Wroc do menu");
	menu_gui::display();
}
void Person::changeSurname() {
	menu_gui::reset();
	string newSurmame;
	cout << endl << "Prosze podac nowe nazwisko: ";
	cin >> newSurmame;

	setSurname(newSurmame);

	menu_gui::reset();
	menu_gui::add_top_text("Pomyslnie zmieniono nazwisko");
	menu_gui::add_option("Wroc do menu");
	menu_gui::display();
}
void Person::changeDateOfBirth() {
	menu_gui::reset();
	int dateOfBirth;
	cout << endl << "Prosze podac nowa date urodzenia: ";
	cin >> dateOfBirth;

	setDateOfBirth(dateOfBirth);

	menu_gui::reset();
	menu_gui::add_top_text("Pomyslnie zmieniono date urodzenia");
	menu_gui::add_option("Wroc do menu");
	menu_gui::display();
}
void Person::changeEmail() {
	menu_gui::reset();
	string newEmail;
	cout << endl << "Prosze podac nowy adres E-mail: ";
	cin >> newEmail;

	setEmail(newEmail);

	menu_gui::reset();
	menu_gui::add_top_text("Pomyslnie zmieniono adres E-mail");
	menu_gui::add_option("Wroc do menu");
	menu_gui::display();
}
bool Person::changePassword() {
	menu_gui::reset();
	string currentPassword, newPassword;
	cout << endl << "Prosze podac obecne haslo: ";
	cin >> currentPassword;
	cout << endl << "Prosze podac nowe haslo: ";
	cin >> newPassword;

	if (password == currentPassword) {
		password = newPassword;
		menu_gui::reset();
		menu_gui::add_top_text("Pomyslnie zmieniono haslo");
		menu_gui::add_option("Wroc do menu");
		menu_gui::display();

		return 1;
	}
	else {
		menu_gui::reset();
		menu_gui::add_top_text("Podane haslo jest niepoprawne");
		menu_gui::add_option("Wroc do menu");
		menu_gui::display();
		return 1;
	}
}