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

void changeSomeonesPassword(Person someone, string newPassword) {
	someone.setPassword(newPassword);
}
void changeSomeonesName(Person someone, string newName, string newName2) {
	someone.setName(newName, newName2);
}
void changeSomeonesSurname(Person someone, string newSurname) {
	someone.setSurname(newSurname);
}
void changeSomeonesDateOfBirth(Person someone, int newDateOfBirth) {
	someone.setDateOfBirth(newDateOfBirth);
}
void changeSomeonesEmail(Person someone, string newEmail) {
	someone.setEmail(newEmail);
}