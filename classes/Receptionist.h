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
	public: Room* checkAvailability(string aInt_startingDate, string aInt_endingDate);

	public: Reservation reservation(string aRoom_p, string aInt_startingDate, string aInt_endingDate);
};

#endif
