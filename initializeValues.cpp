#include "include.h"

void initializeWithDefaultValues(Customer* customersAccounts, Receptionist* receptionistsAccounts, Admin* adminsAccounts, Room* rooms)
{   
	customersAccounts[0] = Customer("Bazyli ", "Kucharski", 13021954, "BazyliKucharski@dayrep.com");
	customersAccounts[1] = Customer("Dobrogost", "Wojciechowski", 3091971, "DobrogostWojciechowski@rhyta.com");
	customersAccounts[2] = Customer("Ludmita ", "Zajac", 4101988, "LudmitaZajac@dayrep.com");
	customersAccounts[3] = Customer("Dominik ", "Olszewski", 20071963, "DominikOlszewski@jourrapide.com");
	customersAccounts[4] = Customer("Klementyna", "Zawadzka", 16061960, "KlementynaZawadzka@dayrep.com");
	customersAccounts[5] = Customer("Marek", "Pawlak", 27111938, "MarekPawlak@rhyta.com");
	customersAccounts[6] = Customer("Aureliusz", "Rutkowski", 26071947, "AureliuszRutkowski@teleworm.us");
	customersAccounts[7] = Customer("Tekla", "Czarnecka", 30041949, "TeklaCzarnecka@teleworm.us");
	customersAccounts[8] = Customer("Lidia", "Czerwinska", 8111982, "LidiaCzerwinska@teleworm.us");
	customersAccounts[9] = Customer("Klara", "Walczak", 26061970, "KlaraWalczak@dayrep.com");

	receptionistsAccounts[0] = Receptionist("Tobiasz", "Tomaszewski", 24081965, "TobiaszTomaszewski@rhyta.com");
	receptionistsAccounts[1] = Receptionist("Gertruda", "Dudek", 3091951, "GertrudaDudek@jourrapide.com");

	adminsAccounts[0] = Admin("Klara", "Walczak", 26061970, "KlaraWalczak@dayrep.com");
	adminsAccounts[1] = Admin("Eligiusz", "Kaczmarek", 24091987, "EligiuszKaczmarek@teleworm.us");

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
		counterAllAccounts++;
	}
	for (int i = 0; i < numberOfReceptionistsAccounts; i++)
	{
		allAccounts[counterAllAccounts] = receptionistsAccounts[i];
		counterAllAccounts++;
	}
	for (int i = 0; i < numberOfAdminsAccounts; i++)
	{
		allAccounts[counterAllAccounts] = adminsAccounts[i];
		counterAllAccounts++;
	}
}