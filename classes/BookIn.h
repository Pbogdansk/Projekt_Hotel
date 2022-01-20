#include <exception>
using namespace std;

#ifndef __BookIn_h__
#define __BookIn_h__

// #include "Reservation.h"
#include <string>

class Reservation;
class BookIn;

class BookIn {
private:
	int startingDate;
	int endingDate;
	bool isAnyoneBookedIn = false;
public:
	void bookIn(int startingDate, int endingDate);
	void bookOut();
	int getStartingDate();
	int getEndingDate();
	bool getIsAnyoneBookedIn();
	BookIn(int startingDate=-1, int endingDate=-1);
};

#endif
