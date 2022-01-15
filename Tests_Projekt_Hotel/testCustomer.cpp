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
			string theName = "Bazyli";
			string theName2 = "Kucharski";
			string theName3 = "BazyliKucharski@dayrep.com";
			Customer newCustomer("Bazyli", "Kucharski", 13021954, "BazyliKucharski@dayrep.com");
			Assert::AreSame(newCustomer.getName()[0], theName);
			Assert::AreSame(newCustomer.getName()[1], theName2);
			Assert::AreSame(newCustomer.getEmail(), theName3);
			Assert::AreEqual(newCustomer.getDateOfBirth(), 13021954);
		}
	};
}