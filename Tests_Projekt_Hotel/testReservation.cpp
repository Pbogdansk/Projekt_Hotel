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

		TEST_METHOD(RandomTest0)
		{
			Room newReservation(01012022, 31042022, 1);
			//Assert::AreEqual(newroom.getFloor(), 2);
		}
	};
}