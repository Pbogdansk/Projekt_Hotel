#include "pch.h"
#include "CppUnitTest.h"
#include "../include.h"
#include "../classes/Customer.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace customer {
	TEST_CLASS(AddingNewObject)
	{
	public:

		TEST_METHOD(RandomTest0)
		{
			Customer newCustomer(Reservation newReservation);
			//Assert::AreEqual(newCustomer.getFloor(), 2);
		}
	};
}