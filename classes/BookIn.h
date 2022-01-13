#include <exception>
using namespace std;

#ifndef __BookIn_h__
#define __BookIn_h__

// #include "Reservation.h"
#include <string>

class Reservation;
class BookIn;

class BookIn
{
	private: int _startingDate;
	private: int _endingDate;
	private: bool _isBooked;
	public: Reservation* _unnamed_Reservation_;

	public: void bookIn(string aInt_startingDate, string aEndingDate);

	public: void bookOutj();
};

#endif
