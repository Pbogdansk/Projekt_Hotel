#include "pch.h"
#include "CppUnitTest.h"
#include "../include.h"
#include "../classes/Reservation.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace reservation
{
	TEST_CLASS(AddingNewObject)
	{
	public:

		TEST_METHOD(startingDateTest)
		{
			Reservation newReservation(01012022, 31042022, 1);
			Assert::AreEqual(01012022, newReservation.getStartingDate());
		}
		TEST_METHOD(endingDateTest)
		{
			Reservation newReservation(01012022, 31042022, 1);
			Assert::AreEqual(31042022, newReservation.getEndingDate());
		}
		TEST_METHOD(paymentStatusTest)
		{
			Reservation newReservation(01012022, 31042022, 1);
			Assert::AreEqual(1, int(newReservation.getPaymentStatus()));
		}
	};
}