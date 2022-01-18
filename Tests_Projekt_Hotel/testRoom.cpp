#include "pch.h"
#include "CppUnitTest.h"
#include "../include.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace room
{
	TEST_CLASS(AddingNewObject)
	{
	public:
		//Room(int newNumberOfPeople=0, int newFloor=0, int newRoomQuality=0, int newSurfaceArea=0);
		TEST_METHOD(NumberOfPeople0)
		{
			Room r1 = Room(1);
			Assert::AreEqual(1, r1.getNumberOfPeople());
		}
		TEST_METHOD(NumberOfPeople1)
		{
			Room r1 = Room(43574);
			Assert::AreEqual(43574, r1.getNumberOfPeople());
		}
		TEST_METHOD(Floor0)
		{
			Room r1 = Room(0,1);
			Assert::AreEqual(1, r1.getFloor());
		}
		TEST_METHOD(Floor1)
		{
			Room r1 = Room(0,43574);
			Assert::AreEqual(43574, r1.getFloor());
		}
		TEST_METHOD(RoomQuality0)
		{
			Room r1 = Room(0,0,1);
			Assert::AreEqual(1, r1.getRoomQuality());
		}
		TEST_METHOD(RoomQuality1)
		{
			Room r1 = Room(0,0,43574);
			Assert::AreEqual(43574, r1.getRoomQuality());
		}
		TEST_METHOD(SurfaceArea0)
		{
			Room r1 = Room(0, 0, 0,1);
			Assert::AreEqual(1, r1.getSurfaceArea());
		}
		TEST_METHOD(SurfaceArea1)
		{
			Room r1 = Room(0, 0, 0,43574);
			Assert::AreEqual(43574, r1.getSurfaceArea());
		}
		TEST_METHOD(CombinedTest0)
		{
			Room r1 = Room(21, 2, 27, 11);
			Assert::AreEqual(21, r1.getNumberOfPeople());
			Assert::AreEqual(2, r1.getFloor());
			Assert::AreEqual(27, r1.getRoomQuality());
			Assert::AreEqual(11, r1.getSurfaceArea());
		}
		TEST_METHOD(CombinedTest1)
		{
			Room r1 = Room(17, 27, 31, 37);
			Assert::AreEqual(17, r1.getNumberOfPeople());
			Assert::AreEqual(27, r1.getFloor());
			Assert::AreEqual(31, r1.getRoomQuality());
			Assert::AreEqual(37, r1.getSurfaceArea());
		}
		TEST_METHOD(Price0)
		{
			Room r1 = Room(17, 27, 2, 37);
			double price = 1;
			price *= (1 + 16 * 0.8);
			price *= (3 * 37);
			price *= 2;
			Assert::AreEqual(static_cast <int> (price), r1.getPrice());
			/*
			price:
			numberofpeople	n = 1 => 1 (n-1)times +0,8
				1 -> 100%
				2 -> 180%
				3 -> 260%
				4 -> 340%
;			floor:
				no impact
			quality
				 1 -> *=1
				 2 -> *=1.3
				 3 -> *=2
			surface
				10* surface
			*/
		}
		TEST_METHOD(Price1)
		{
			Room r1 = Room(2, 2, 2, 24);
			double price = 1;
			price *= (1 + 1 * 0.8);
			price *= (3 * 24);
			price *= 2;
			Assert::AreEqual(static_cast <int> (price), r1.getPrice());
		}
		TEST_METHOD(Price2)
		{
			Room r1 = Room(3, 2, 0, 35);
			double price = 1;
			price *= (1 + 2 * 0.8);
			price *= (3 * 35);
			price *= 1;
			Assert::AreEqual(static_cast <int> (price), r1.getPrice());
		}
	};
}