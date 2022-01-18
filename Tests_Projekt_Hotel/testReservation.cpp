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
		TEST_METHOD(amountToPay0)
		{
			Customer c1 = Customer();
			Room r1 = Room(3, 2, 0, 35);
			double price = 1;
			price *= (1 + 2 * 0.8);
			price *= (3 * 35);
			price *= 1;
			int totalDays = substractDates(01012022, 31042022);

			Reservation newReservation(01012022, 31042022, 1, &r1, &c1);
			newReservation.makeReservation();

			Assert::AreEqual(totalDays * static_cast <int> (price), newReservation.getAmountRemainingToPay());
		}
		TEST_METHOD(amountToPay1)
		{		
			Customer c1 = Customer();
			Room r1 = Room(2, 2, 2, 24);
			double price = 1;
			price *= (1 + 1 * 0.8);
			price *= (3 * 24);
			price *= 2;
			int totalDays = substractDates(01012022, 31042022);

			Reservation newReservation(01012022, 31042022, 1, &r1, &c1);
			newReservation.makeReservation();

			Assert::AreEqual(totalDays * static_cast <int> (price), newReservation.getAmountRemainingToPay());
		}
		TEST_METHOD(amountToPayAfterAdvancePayment0)
		{
			Customer c1 = Customer();
			Room r1 = Room(3, 2, 0, 35);
			double price = 1;
			price *= (1 + 2 * 0.8);
			price *= (3 * 35);
			price *= 1;
			int totalDays = substractDates(01012022, 31042022);

			Reservation newReservation(01012022, 31042022, 1, &r1, &c1);
			newReservation.makeReservation();

			newReservation.pay(1000);

			Assert::AreEqual(totalDays * static_cast <int> (price) - 1000, newReservation.getAmountRemainingToPay());
		}
		TEST_METHOD(amountToPayAfterAdvancePayment1)
		{
			Customer c1 = Customer();
			Room r1 = Room(2, 2, 2, 24);
			double price = 1;
			price *= (1 + 1 * 0.8);
			price *= (3 * 24);
			price *= 2;
			int totalDays = substractDates(01012022, 31042022);

			Reservation newReservation(01012022, 31042022, 1, &r1, &c1);
			newReservation.makeReservation();

			newReservation.pay(1000);

			Assert::AreEqual(totalDays * static_cast <int> (price) - 1000, newReservation.getAmountRemainingToPay());
		}
	};
}