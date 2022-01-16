#include <exception>
using namespace std;

#include "Receptionist.h"
#include "Room.h"
#include "Reservation.h"
#include "Person.h"

Receptionist::Receptionist(){}
Receptionist::Receptionist(string newName, string newSurname, int newDateOfBirth, string newEmail, string newPassword) {
	name[0] = newName;
	surname = newSurname;
	dateOfBirth = newDateOfBirth;
	email = newEmail;
	password = newPassword;
	permissions = permReceptionist;
}

Room* Receptionist::checkAvailability(int startingDate, int endingDate) {
	throw "Not yet implemented";
}

Reservation Receptionist::reservation(Room p, int startingDate, int endingDate) {
	throw "Not yet implemented";
}