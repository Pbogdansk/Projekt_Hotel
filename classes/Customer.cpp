#include <exception>
#include <vector>
using namespace std;

#include "Customer.h"
#include "Reservation.h"
#include "Room.h"
#include "Person.h"

Customer::Customer() {}
Customer::Customer(string newName, string newSurname, int newDateOfBirth, string newEmail) {
	name[0] = newName;
}

Room* Customer::checkAvailability(int startingDate, int endingDate) {
	throw "Not yet implemented";
}

Reservation Customer::reservation(Room p, int startingDate, int endingDate) {
	throw "Not yet implemented";
}

