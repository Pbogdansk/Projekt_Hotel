#include "include.h"

void initializeWithDefaultValues(Customer* customersAccounts, Receptionist* receptionistsAccounts, Admin* adminsAccounts)
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
	customersAccounts[9] = Customer("Klara", "Walczak", 26061970, "klient@gmail.com" , "jestekliente");

	receptionistsAccounts[0] = Receptionist("Tobiasz", "Tomaszewski", 24081965, "recepcja@pl.pl" , "lol123");
	receptionistsAccounts[1] = Receptionist("Gertruda", "Dudek", 3091951, "GertrudaDudek@jourrapide.com" , "ZrlcrtNwf49rM9NZ");

	adminsAccounts[0] = Admin("Wojciech", "Sum", 26061970, "test@test.pl" , "123");
	adminsAccounts[1] = Admin("Adam", "Szczupak", 24091987, "EligiuszKaczmarek@teleworm.us" , "t5JbHo7JrMgia1wY");
}
void assignAllAccountsToOneVariable(Person* allAccounts, Customer* customersAccounts, Receptionist* receptionistsAccounts, Admin* adminsAccounts, int numberOfAllAccounts, int numberOfCustomersAccounts, int numberOfReceptionistsAccounts, int numberOfAdminsAccounts)
{
	int counterAllAccounts = 0;
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
	for (int i = 0; i < numberOfCustomersAccounts; i++)
	{
		allAccounts[counterAllAccounts] = customersAccounts[i];
		allAccounts[counterAllAccounts].setIndex(i);
		counterAllAccounts++;
	}	
}

void initializeRoomsWithDefaultValues(Room* rooms, int numberOfRooms)
{
	//Room(int newNumberOfPeople = 0, int newFloor = 0, int newRoomQuality = 0, int newSurfaceArea = 0);
	//jedynki	20%
	int i = 0;
	for (; i < 0.2*numberOfRooms; i++)
	{
		int numberOfPeople = 1;
		int floor = rand() % 18 + 1;
		int roomQuality = rand() % 3;
		int surfaceArea = 10 + rand() % 30;
		rooms[i] = Room(numberOfPeople, floor, roomQuality, surfaceArea);
	}
	//dwojki	30%
	for (; i < 0.5*numberOfRooms; i++)
	{
		int numberOfPeople = 2;
		int floor = rand() % 18 + 1;
		int roomQuality = rand() % 3;
		int surfaceArea = 14 + rand() % 30;
		rooms[i] = Room(numberOfPeople, floor, roomQuality, surfaceArea);
	}
	//trojki	20%
	for (; i < 0.7*numberOfRooms; i++)
	{
		int numberOfPeople = 3;
		int floor = rand() % 18 + 1;
		int roomQuality = rand() % 3;
		int surfaceArea = 17 + rand() % 30;
		rooms[i] = Room(numberOfPeople, floor, roomQuality, surfaceArea);
	}
	//czworki	10%
	for (; i < 0.8*numberOfRooms; i++)
	{
		int numberOfPeople = 4;
		int floor = rand() % 18 + 1;
		int roomQuality = rand() % 3;
		int surfaceArea = 20 + rand() % 30;
		rooms[i] = Room(numberOfPeople, floor, roomQuality, surfaceArea);
	}
	//reszta 5->10	reszta(20%)
	for (; i < numberOfRooms; i++)
	{
		int numberOfPeople = rand()%6 + 5;
		int floor = rand() % 18 + 1;
		int roomQuality = rand() % 3;
		int surfaceArea = 20 + 2*numberOfPeople + rand() % 30;
		rooms[i] = Room(numberOfPeople, floor, roomQuality, surfaceArea);
	}
}