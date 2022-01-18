#include <exception>
#include <vector>
using namespace std;

#include "Room.h"
#include "Reservation.h"
#include "Customer.h"
#include "BookIn.h"
#include "Receptionist.h"
#include "Admin.h"


Reservation::Reservation(int newStartingDate, int newEndingDate, bool newPaymentStatus, Room* newReservatedRoom, Customer* newCustomer)
{
	startingDate = newStartingDate;
	endingDate = newEndingDate;
	paymentStatus = newPaymentStatus;
	reservatedRoom = newReservatedRoom;
	customer = newCustomer;
}
Reservation::Reservation() {
}

void Reservation::pay(bool paymentMethod) {
	throw "Not yet implemented";
}

void Reservation::annulReservation() {
	throw "Not yet implemented";
}

int Reservation::getStartingDate() {
	return startingDate;
}
int Reservation::getEndingDate() {
	return endingDate;
}
bool Reservation::getPaymentStatus() {
	return paymentStatus;
}

string Reservation::getCustomerEmail() {
	return customer->getEmail();
}

int Reservation::getRoomPrice() {
	return reservatedRoom->getPrice();
}

