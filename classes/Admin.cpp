#include <exception>
using namespace std;

#include "Admin.h"
#include "Room.h"
#include "Person.h"

Admin::Admin(){}
Admin::Admin(string newName, string newSurname, int newDateOfBirth, string newEmail, string newPassword) {
	name[0] = newName;
	surname = newSurname;
	dateOfBirth = newDateOfBirth;
	email = newEmail;
	password = newPassword;
	permissions = permAdmin;
}

void Admin::addRoom(int numberOfPeople, int floor, int roomQuality, int surfaceArea) {
	Room(numberOfPeople, floor, roomQuality, surfaceArea);
}

void Admin::removeRoom(Room p) {
	throw "Not yet implemented";
}

bool Admin::changeSomeonesPassword(Person*& someone, string newPassword) {
	someone->setPassword(newPassword);
	return 0;
}
bool Admin::changeSomeonesName(Person*& someone, string newName, string newName2) {
	someone->setName(newName, newName2);
	return 0;
}
bool Admin::changeSomeonesSurname(Person*& someone, string newSurname) {
	someone->setSurname(newSurname);
	return 0;
}
bool Admin::changeSomeonesDateOfBirth(Person*& someone, int newDateOfBirth) {
	someone->setDateOfBirth(newDateOfBirth);
	return 0;
}
bool Admin::changeSomeonesEmail(Person*& someone, string newEmail) {
	someone->setEmail(newEmail);
	return 0;
}