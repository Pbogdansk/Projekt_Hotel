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

void Admin::changeSomeonesPassword(Person someone, string newPassword) {
	someone.setPassword(newPassword);
}
void Admin::changeSomeonesName(Person someone, string newName, string newName2) {
	someone.setName(newName, newName2);
}
void Admin::changeSomeonesSurname(Person someone, string newSurname) {
	someone.setSurname(newSurname);
}
void Admin::changeSomeonesDateOfBirth(Person someone, int newDateOfBirth) {
	someone.setDateOfBirth(newDateOfBirth);
}
void Admin::changeSomeonesEmail(Person someone, string newEmail) {
	someone.setEmail(newEmail);
}