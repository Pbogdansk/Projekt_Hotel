#include "pch.h"
#include "CppUnitTest.h"
#include "../include.h"
#include "../classes/Admin.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace customer
{
	TEST_CLASS(AddingNewObject)
	{
	public:

        TEST_METHOD(RandomTest0)
        {
            Customer newCustomer("Bazyli", "Kucharski", 13021954, "BazyliKucharski@dayrep.com");
            string theName = "Bazyli";
            Assert::AreEqual(theName, newCustomer.getName()[0]);
        }
        TEST_METHOD(RandomTest1) {
            Customer newCustomer("Bazyli", "Kucharski", 13021954, "BazyliKucharski@dayrep.com");
            string theName2 = "Kucharski";
            Assert::AreEqual(theName2, newCustomer.getSurname());
        }
        TEST_METHOD(RandomTest2) {
            Customer newCustomer("Bazyli", "Kucharski", 13021954, "BazyliKucharski@dayrep.com");
            string theName3 = "BazyliKucharski@dayrep.com";
            Assert::AreEqual(newCustomer.getEmail(), theName3);
        }
        TEST_METHOD(RandomTest3) {
            Customer newCustomer("Bazyli", "Kucharski", 13021954, "BazyliKucharski@dayrep.com");
            Assert::AreEqual(newCustomer.getDateOfBirth(), 13021954);
        }
	};
}