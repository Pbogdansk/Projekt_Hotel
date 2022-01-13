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
	public: Customer* _unnamed_Customer_;
	public: BookIn* _unnamed_BookIn_;
	public: std::vector<Receptionist*> _unnamed_Receptionist_;
	public: std::vector<Admin*> _unnamed_Admin_;
	public: Room* _unnamed_Room_;

	public: void pay(string aBool_paymentMethod);

	public: void annulReservation();
};

#endif
