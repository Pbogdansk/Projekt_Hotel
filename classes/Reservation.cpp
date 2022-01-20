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


Reservation::Reservation(int newStartingDate, int newEndingDate, bool newPaymentStatus, Room* newReservatedRoom, Customer* newCustomer, BookIn* newBookIn)
{
	startingDate = newStartingDate;
	endingDate = newEndingDate;
	paymentStatus = newPaymentStatus;
	reservatedRoom = newReservatedRoom;
	customer = newCustomer;
	bookIn = newBookIn;
}
Reservation::Reservation() {
}

void Reservation::pay(int paymentAmount) {
	amountRemainingToPay -= paymentAmount;
	if (amountRemainingToPay <= 0)
		paymentStatus = true;
}
int Reservation::getAmountRemainingToPay() {
	return amountRemainingToPay;
}

string Reservation::reservationToString(Reservation reservation)
{
	string output = reservation.getCustomerEmail();
	while (output.length() < 30)
		output += " ";
	output += " | ";
	output += dateToString(reservation.getStartingDate());
	output += " | ";
	output += dateToString(reservation.getEndingDate());
	output += " | ";
	if (reservation.getPaymentStatus() == true)
		output += "TAK";
	else
		output += "NIE";
	return output;
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
	amountRemainingToPay += numberOfDays * reservatedRoom->getPrice();
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

bool Reservation::getisBooked() {
	return isBooked;
};

void Reservation::setisBooked(bool a) {
	isBooked = a;
};

bool Reservation::getIsAnyoneBookedIn() {
	return bookIn->getIsAnyoneBookedIn();
}

void Reservation::setBookIn(int dateFrom, int dateTo){

	bookIn->bookIn(dateFrom, dateTo);
}

void Reservation::setBookOut() {
	if (bookIn->getIsAnyoneBookedIn() == true)
		bookIn->bookOut();
}