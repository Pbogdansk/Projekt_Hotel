#include "pch.h"
#include "CppUnitTest.h"
#include "../include.h"
#include "../classes/Receptionist.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace receptionist
{
	TEST_CLASS(AddingNewObject)
	{
	public:

		TEST_METHOD(RandomTest0)
		{
			Room newroom(1, 2, 30);
			Assert::AreEqual(newroom.getFloor(), 2);
		}
	};
}