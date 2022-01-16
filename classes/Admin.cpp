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
//	throw "Not yet implemented";
}

void Admin::removeRoom(Room p) {
	throw "Not yet implemented";
}