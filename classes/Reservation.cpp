#include <exception>
#include <vector>
using namespace std;

#include "Reservation.h"
#include "Customer.h"
#include "BookIn.h"
#include "Receptionist.h"
#include "Admin.h"
#include "Room.h"

Reservation::Reservation(int newStartingDate, int newEndingDate, bool newPaymentStatus)
{
	
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

