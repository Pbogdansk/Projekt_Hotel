#include <exception>
#include <vector>
using namespace std;

#ifndef __Reservation_h__
#define __Reservation_h__

// #include "Customer.h"
// #include "BookIn.h"
#include "Receptionist.h"
#include "Admin.h"
// #include "Room.h"

class Customer;
class BookIn;
class Receptionist;
class Admin;
class Room;
class Reservation;

class Reservation
{
	private: int _startingDate;
	private: int _endingDate;
	private: bool _paymentStatus;

	public: void pay(string aBool_paymentMethod);

	public: void annulReservation();
};

#endif
