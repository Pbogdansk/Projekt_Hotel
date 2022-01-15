#include "pch.h"
#include "CppUnitTest.h"
#include "../include.h"
#include "../classes/Admin.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace classRoom {
	TEST_CLASS(AddingNewObject) {
	public:

		TEST_METHOD(RandomTest0)
		{
			Room newroom(1, 2, 30);
			Assert::AreEqual(newroom.getFloor(), 2);
		}
	};
}