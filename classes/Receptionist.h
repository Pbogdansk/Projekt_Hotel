#include <exception>
using namespace std;

#ifndef __Receptionist_h__
#define __Receptionist_h__

// #include "Room.h"
#include "Reservation.h"
#include "Person.h"

class Room;
class Reservation;
// class Person;
class Receptionist;

class Receptionist: public Person
{
public:
	Receptionist();
	Receptionist(string newName, string newSurname, int newDateOfBirth, string newEmail, string newPassword = "");

	Room checkAvailability(int startingDate, int endingDate, Room* rooms, int numberOfRooms);
	Reservation reservation(Room p, int startingDate, int endingDate);
};

#endif
