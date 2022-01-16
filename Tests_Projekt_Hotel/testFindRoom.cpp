#include "pch.h"
#include "CppUnitTest.h"
#include "../include.h"
#include "../findRoom.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace testFindRoom {
	TEST_CLASS(functionsubstractDates) {
public:
	TEST_METHOD(date1_bigger_than_date2)
	{
		int date1 = 15012022;
		int date2 = 10012022;
		Assert::AreEqual(-1, substractDates(date1, date2));
	}
	TEST_METHOD(BasicTest0)
	{
		int date1 = 10012022;
		int date2 = 15012022;
		Assert::AreEqual(5, substractDates(date1, date2));
	}
	TEST_METHOD(BasicTest1)
	{
		int date1 = 10012022;
		int date2 = 15022022;
		Assert::AreEqual(21+15, substractDates(date1, date2));
	}
	TEST_METHOD(BasicTest2)
	{
		int date1 = 10012022;
		int date2 = 10012023;
		Assert::AreEqual(365, substractDates(date1, date2));
	}
	};
}