#include "pch.h"
#include "CppUnitTest.h"
#include "../include.h"
#include "../classes/BookIn.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace classBookIn {
	TEST_CLASS(AddingNewObject) {
public:

	TEST_METHOD(startingDate0)
	{
		int newStartingDate = 22122022;
		int newEndingDate = 24122022;
		BookIn bookInObj = BookIn(newStartingDate, newEndingDate);

		Assert::AreEqual(newStartingDate, bookInObj.getStartingDate());
	}
	TEST_METHOD(endingDate0)
	{
		int newStartingDate = 22122022;
		int newEndingDate = 24122022;
		BookIn bookInObj = BookIn(newStartingDate, newEndingDate);

		Assert::AreEqual(newEndingDate, bookInObj.getEndingDate());
	}
	TEST_METHOD(testFromReservation0)
	{
		Customer c1 = Customer();
		Room r1 = Room(2, 2, 2, 24);
		Reservation newReservation(1012022, 31042022, 1, &r1, &c1);


		Assert::AreEqual(newReservation.getIsAnyoneBookedIn(), false);
	}
	TEST_METHOD(testFromReservation0)
	{
		Customer c1 = Customer();
		Room r1 = Room(2, 2, 2, 24);
		int newStartingDate = 22122022;
		int newEndingDate = 24122022;
		Reservation newReservation(1012022, 31042022, 1, &r1, &c1);
		newReservation.setBookIn(newStartingDate, newEndingDate);

		Assert::AreEqual(newReservation.getIsAnyoneBookedIn(), true);
	}
	};
}