#include <exception>
#include <vector>
using namespace std;

#ifndef __Reservation_h__
#define __Reservation_h__

// #include "Customer.h"
// #include "BookIn.h"
#include "Receptionist.h"
#include "Admin.h"
#include "Room.h"

class Customer;
class BookIn;
class Receptionist;
class Admin;
class Room;
class Reservation;

class Reservation
{
private:
	Room* reservatedRoom;
	Customer* customer;
	int startingDate;
	int endingDate;
	bool paymentStatus;

public:
	Reservation(int newStartingDate, int newEndingDate, bool newPaymentStatus, Room* newReservatedRoom = NULL, Customer* newCustomer = NULL);
	Reservation();

	void pay(bool paymentMethod);
	void annulReservation();

	int getStartingDate();
	int getEndingDate();
	bool getPaymentStatus();

};

#endif
