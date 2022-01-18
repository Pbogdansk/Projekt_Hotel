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
	Reservation customersReservation;
	Reservation* pointerCustomersReservation = NULL;
	bool alreadyHaveReservation = false;
public:
	Customer();
	Customer(string newName, string newSurname, int newDateOfBirth, string newEmail, string newPassword = "");

	Room* checkAvailability(int startingDate, int endingDate, Room* rooms, int numberOfRooms);
	void reservation(Room* pointerRoomToReserve, int startingDate, int endingDate);

	Reservation* getCustomersReservation();

	bool getAlreadyHaveReservation();
	void setAlreadyHaveReservation(bool state);
};

#endif
