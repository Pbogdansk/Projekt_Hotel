#include <exception>
#include <vector>
using namespace std;

#ifndef __Customer_h__
#define __Customer_h__

#include "Reservation.h"
// #include "Room.h"
#include "Person.h"

class Customer: public Person
{
public:
	Customer();
	Customer(string newName, string newSurname, int newDateOfBirth, string newEmail);

	Room* checkAvailability(int startingDate, int endingDate);
	Reservation reservation(Room p, int startingDate, int endingDate);
};

#endif
