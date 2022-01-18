#include <exception>
#include <vector>
using namespace std;

#include "Room.h"
#include "Reservation.h"
#include "Customer.h"
#include "BookIn.h"
#include "Receptionist.h"
#include "Admin.h"
#include "../include.h"


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

void Reservation::pay(int paymentAmount) {
	throw "Not yet implemented";
}
int Reservation::getAmountRemainingToPay() {
	return amountRemainingToPay;
}

void Reservation::annulReservation() {
	int daysFromNewYear = substractDates(1012022, startingDate);
	int numberOfDays = substractDates(startingDate, endingDate);
	for (int j = 0; j < numberOfDays; j++)
	{
		reservatedRoom->setIsOccupied(daysFromNewYear + j, false);
	}
}

void Reservation::makeReservation() {
	int daysFromNewYear = substractDates(1012022, startingDate);
	int numberOfDays = substractDates(startingDate, endingDate);
	for (int j = 0; j < numberOfDays; j++)
	{
		reservatedRoom->setIsOccupied(daysFromNewYear + j, true);
	}
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

