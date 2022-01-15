#include "pch.h"
#include "CppUnitTest.h"
#include "../include.h"
#include "../classes/Admin.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace reservation
{
	TEST_CLASS(AddingNewObject)
	{
	public:

        TEST_METHOD(RandomTest0)
        {
            Customer newCustomer("Bazyli", "Kucharski", 13021954, "BazyliKucharski@dayrep.com");
            string theName = "Bazyli";
            Assert::AreSame(newCustomer.getName()[0], theName);
        }
        TEST_METHOD(RandomTest1) {
            Customer newCustomer("Bazyli", "Kucharski", 13021954, "BazyliKucharski@dayrep.com");
            string theName2 = "Kucharski";
            Assert::AreSame(newCustomer.getName()[1], theName2);
        }
        TEST_METHOD(RandomTest2) {
            Customer newCustomer("Bazyli", "Kucharski", 13021954, "BazyliKucharski@dayrep.com");
            string theName3 = "BazyliKucharski@dayrep.com";
            Assert::AreSame(newCustomer.getEmail(), theName3);
        }
        TEST_METHOD(RandomTest3) {
            Customer newCustomer("Bazyli", "Kucharski", 13021954, "BazyliKucharski@dayrep.com");
            Assert::AreEqual(newCustomer.getDateOfBirth(), 13021954);
        }
	};
}