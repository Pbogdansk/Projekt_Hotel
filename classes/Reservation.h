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

class BookIn;
class Receptionist;
class Admin;
class Room;
class Customer;
class Reservation;

class Reservation
{
private:
	Room* reservatedRoom;
	Customer* customer;
	BookIn* bookIn;
	int startingDate;
	int endingDate;
	bool paymentStatus;
	int amountRemainingToPay = 0;
	bool isBooked;

public:
	Reservation(int newStartingDate, int newEndingDate, bool newPaymentStatus, Room* newReservatedRoom = NULL, Customer* newCustomer = NULL, BookIn* newBookIn = NULL);
	Reservation();
	void pay(int paymentAmount);
	void annulReservation();
	void makeReservation();

	int getStartingDate();
	int getEndingDate();
	bool getPaymentStatus();
	string getCustomerEmail();
	int getRoomPrice();
	int getAmountRemainingToPay();
	string reservationToString(Reservation reservation);

	bool getIsAnyoneBookedIn();
	void setBookIn(int startingDate, int endingDate);
	void setBookOut();
};

#endif
