#include "pch.h"
#include "CppUnitTest.h"
#include "../include.h"
#include "../LogInAccount.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LogInAccount {
	TEST_CLASS(functionfindEmailAdressInGivenArray) {
public:

	TEST_METHOD(BasicTest0)
	{
		Person accounts[2];
		accounts[0] = Person("Bazyli", "Kucharski", 13021954, "BazyliKucharski@dayrep.com");
		accounts[1] = Person("Tekla", "Czarnecka", 30041949, "TeklaCzarnecka@teleworm.us");
		string wantedEmail = "TeklaCzarnecka@teleworm.us";

		int indexInArrayOfGivenEmail = findEmailAdressInGivenArray(accounts, 2, wantedEmail);
		Assert::AreEqual(indexInArrayOfGivenEmail,1);
	}
	TEST_METHOD(BasicTest1)
	{
		Person accounts[4];
		accounts[0] = Person("Bazyli", "Kucharski", 13021954, "BazyliKucharski@dayrep.com");
		accounts[1] = Person("Tekla", "Czarnecka", 30041949, "TeklaCzarnecka@teleworm.us");
		accounts[2] = Person("Dominik ", "Olszewski", 20071963, "DominikOlszewski@jourrapide.com");
		accounts[3] = Person("Klementyna", "Zawadzka", 16061960, "KlementynaZawadzka@dayrep.com");
		string wantedEmail = "DominikOlszewski@jourrapide.com";

		int indexInArrayOfGivenEmail = findEmailAdressInGivenArray(accounts, 4, wantedEmail);
		Assert::AreEqual(indexInArrayOfGivenEmail, 2);
	}
	TEST_METHOD(CannotFindGivenAdress0)
	{
		Person accounts[2];
		accounts[0] = Person("Bazyli", "Kucharski", 13021954, "BazyliKucharski@dayrep.com");
		accounts[1] = Person("Tekla", "Czarnecka", 30041949, "TeklaCzarnecka@teleworm.us");
		string wantedEmail = "GertrudaDudek@jourrapide.com";

		int indexInArrayOfGivenEmail = findEmailAdressInGivenArray(accounts, 2, wantedEmail);
		Assert::AreEqual(indexInArrayOfGivenEmail, -1);
	}
	TEST_METHOD(CannotFindGivenAdress1)
	{
		Person accounts[4];
		accounts[0] = Person("Bazyli", "Kucharski", 13021954, "BazyliKucharski@dayrep.com");
		accounts[1] = Person("Tekla", "Czarnecka", 30041949, "TeklaCzarnecka@teleworm.us");
		accounts[2] = Person("Dominik ", "Olszewski", 20071963, "DominikOlszewski@jourrapide.com");
		accounts[3] = Person("Klementyna", "Zawadzka", 16061960, "KlementynaZawadzka@dayrep.com");
		string wantedEmail = "KlaraWalczak@dayrep.com";

		int indexInArrayOfGivenEmail = findEmailAdressInGivenArray(accounts, 4, wantedEmail);
		Assert::AreEqual(indexInArrayOfGivenEmail, -1);
	}
	};
	TEST_CLASS(methodLogInPerson) {
public:

	TEST_METHOD(BasicTest0)
	{
		Person account = Person("Bazyli", "Kucharski", 13021954, "BazyliKucharski@dayrep.com","ad7oFahR");
		string emailToLogIn = "BazyliKucharski@dayrep.com";
		string passwordToLogIn = "ad7oFahR";

		Assert::AreEqual(account.logIn(emailToLogIn,passwordToLogIn),true);
	}
	TEST_METHOD(BasicTest1)
	{
		Person account = Person("Dominik ", "Olszewski", 20071963, "DominikOlszewski@jourrapide.com","sathah9M");
		string emailToLogIn = "DominikOlszewski@jourrapide.com";
		string passwordToLogIn = "sathah9M";

		Assert::AreEqual(account.logIn(emailToLogIn, passwordToLogIn), true);
	}
	TEST_METHOD(WrongEmail0)
	{
		Person account = Person("Bazyli", "Kucharski", 13021954, "BazyliKucharski@dayrep.com", "ad7oFahR");
		string emailToLogIn = "KlementynaZawadzka@dayrep.com";
		string passwordToLogIn = "ad7oFahR";

		Assert::AreEqual(account.logIn(emailToLogIn, passwordToLogIn), false);
	}
	TEST_METHOD(WrongPassword0)
	{
		Person account = Person("Bazyli", "Kucharski", 13021954, "BazyliKucharski@dayrep.com", "ad7oFahR");
		string emailToLogIn = "KlementynaZawadzka@dayrep.com";
		string passwordToLogIn = "uZai9ecae7l";

		Assert::AreEqual(account.logIn(emailToLogIn, passwordToLogIn), false);
	}
	};
}