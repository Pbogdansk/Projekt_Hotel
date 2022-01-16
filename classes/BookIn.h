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
	bool isBooked;

public:
	void bookIn(int startingDate, int EndingDate);
	void bookOutj();
};

#endif
