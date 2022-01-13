#include <exception>
#include <vector>
using namespace std;

#ifndef __Customer_h__
#define __Customer_h__

#include "Reservation.h"
// #include "Room.h"
#include "Person.h"

class Reservation;
class Room;
// class Person;
class Customer;

class Customer: public Person
{
	public: std::vector<Reservation*> _unnamed_Reservation_;

	public: Room* checkAvailability(string aInt_startingDate, string aInt_endingDate);

	public: Reservation reservation(string aRoom_p, string aInt_startingDate, string aInt_endingDate);
};

#endif
