#include "include.h"

void initializeWithDefaultValues(Customer* customersAccounts, Receptionist* receptionistsAccounts, Admin* adminsAccounts, Room* rooms)
{   
	Person kot("Bazyli", "Kucharski", 13021954, "BazyliKucharski@dayrep.com");
	Customer kor("Bazyli", "Kucharski", 13021954, "BazyliKucharski@dayrep.com");

	customersAccounts[0] = Customer("Bazyli ", "Kucharski", 13021954, "BazyliKucharski@dayrep.com");
	customersAccounts[1] = Customer("Dobrogost", "Wojciechowski", 3091971, "DobrogostWojciechowski@rhyta.com");
	customersAccounts[2] = Customer("Ludmita ", "Zaj¹c", 4101988, "LudmitaZajac@dayrep.com");
	customersAccounts[3] = Customer("Dominik ", "Olszewski", 20071963, "DominikOlszewski@jourrapide.com");
	customersAccounts[4] = Customer("Klementyna", "Zawadzka", 16061960, "KlementynaZawadzka@dayrep.com");
	customersAccounts[5] = Customer("Marek", "Pawlak", 27111938, "MarekPawlak@rhyta.com");
	customersAccounts[6] = Customer("Aureliusz", "Rutkowski", 26071947, "AureliuszRutkowski@teleworm.us");
	customersAccounts[7] = Customer("Tekla", "Czarnecka", 30041949, "TeklaCzarnecka@teleworm.us");
	customersAccounts[8] = Customer("Lidia", "Czerwinska", 8111982, "LidiaCzerwinska@teleworm.us");
	customersAccounts[9] = Customer("Klara", "Walczak", 26061970, "KlaraWalczak@dayrep.com");

	//customersAccounts[0] = Admin("Klara", "Walczak", 26061970, "KlaraWalczak@dayrep.com");

}









