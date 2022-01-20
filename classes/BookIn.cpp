#include <exception>
#include <string>
using namespace std;

#include "BookIn.h"
#include "Reservation.h"

void BookIn::bookIn(int newStartingDate, int newEndingDate) {
	startingDate = newStartingDate;
	endingDate = newEndingDate;
	isAnyoneBookedIn = true;
}

void BookIn::bookOut() {
	isAnyoneBookedIn = false;
}

int BookIn::getStartingDate() {
	return startingDate;
}

int BookIn::getEndingDate() {
	return endingDate;
}

bool BookIn::getIsAnyoneBookedIn() {
	return isAnyoneBookedIn;
}

BookIn::BookIn(int newStartingDate, int newEndingDate) {
	startingDate = newStartingDate;
	endingDate = newEndingDate;
	if (newStartingDate == -1 && newEndingDate == -1)
		isAnyoneBookedIn = false;
	else
		isAnyoneBookedIn = true;
}