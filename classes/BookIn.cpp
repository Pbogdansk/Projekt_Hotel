#include <exception>
#include <string>
using namespace std;

#include "BookIn.h"
#include "Reservation.h"

void BookIn::bookIn(int startingDate, int endingDate) {
	throw "Not yet implemented";
}

void BookIn::bookOut() {
	throw "Not yet implemented";
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