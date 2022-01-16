#include "include.h"

void initializeWithDefaultValues(Customer* customersAccounts, Receptionist* receptionistsAccounts, Admin* adminsAccounts, Room* rooms)
{   
	customersAccounts[0] = Customer("Bazyli ", "Kucharski", 13021954, "BazyliKucharski@dayrep.com","73YfIC7oJem0Li7c");
	customersAccounts[1] = Customer("Dobrogost", "Wojciechowski", 3091971, "DobrogostWojciechowski@rhyta.com" , "Iz6nMaLSOwOyZ8Xg");
	customersAccounts[2] = Customer("Ludmita ", "Zajac", 4101988, "LudmitaZajac@dayrep.com" , "s6ryifyHyWbgN7TH");
	customersAccounts[3] = Customer("Dominik ", "Olszewski", 20071963, "DominikOlszewski@jourrapide.com" , "PYZeJx9atNA7gTmy");
	customersAccounts[4] = Customer("Klementyna", "Zawadzka", 16061960, "KlementynaZawadzka@dayrep.com" , "hlU3urkWnzGc9F9y");
	customersAccounts[5] = Customer("Marek", "Pawlak", 27111938, "MarekPawlak@rhyta.com","GKQs8w5xpSg9DF4v");
	customersAccounts[6] = Customer("Aureliusz", "Rutkowski", 26071947, "AureliuszRutkowski@teleworm.us","KMEm1xTW2aPRvY0I");
	customersAccounts[7] = Customer("Tekla", "Czarnecka", 30041949, "TeklaCzarnecka@teleworm.us" , "KCkrShkgg70Pn4VS");
	customersAccounts[8] = Customer("Lidia", "Czerwinska", 8111982, "LidiaCzerwinska@teleworm.us" , "Szra563zEd3cNyFM");
	customersAccounts[9] = Customer("Klara", "Walczak", 26061970, "KlaraWalczak@dayrep.com" , "aaSDWTJevGfZ3Wp0");

	receptionistsAccounts[0] = Receptionist("Tobiasz", "Tomaszewski", 24081965, "TobiaszTomaszewski@rhyta.com" , "ut1xvbqCtRrz72E9");
	receptionistsAccounts[1] = Receptionist("Gertruda", "Dudek", 3091951, "GertrudaDudek@jourrapide.com" , "ZrlcrtNwf49rM9NZ");

	adminsAccounts[0] = Admin("Klara", "Walczak", 26061970, "testtest@test.pl" , "p4ssw0rd123");
	adminsAccounts[1] = Admin("Eligiusz", "Kaczmarek", 24091987, "EligiuszKaczmarek@teleworm.us" , "t5JbHo7JrMgia1wY");

	rooms[0] = Room(2, 2, 5, 50);
	rooms[1] = Room(1, 3, 4, 20);
}

void assignAllAccountsToOneVariable(Person* allAccounts, Customer* customersAccounts, Receptionist* receptionistsAccounts, Admin* adminsAccounts)
{
	int numberOfAllAccounts = 14;
	int numberOfCustomersAccounts = 10;
	int numberOfReceptionistsAccounts = 2;
	int numberOfAdminsAccounts = 2;

	int counterAllAccounts = 0;
	for (int i = 0; i < numberOfCustomersAccounts; i++)
	{
		allAccounts[counterAllAccounts] = customersAccounts[i];
		allAccounts[counterAllAccounts].setIndex(i);
		counterAllAccounts++;
	}
	for (int i = 0; i < numberOfReceptionistsAccounts; i++)
	{
		allAccounts[counterAllAccounts] = receptionistsAccounts[i];
		allAccounts[counterAllAccounts].setIndex(i);
		counterAllAccounts++;
	}
	for (int i = 0; i < numberOfAdminsAccounts; i++)
	{
		allAccounts[counterAllAccounts] = adminsAccounts[i];
		allAccounts[counterAllAccounts].setIndex(i);
		counterAllAccounts++;
	}
}