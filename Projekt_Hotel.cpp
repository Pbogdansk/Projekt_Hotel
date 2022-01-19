#include "include.h"

Person currentlyLoggedIn;
int main()
{
	srand(time(NULL));
	Person* allAccounts = new Person[14];					//Person allAccounts[15];
	Customer* customersAccounts = new Customer[10];			//Customer customersAccounts[10];
	Receptionist receptionistsAccounts[2];
	Admin adminsAccounts[2];
	Reservation* reservations = new Reservation[0];
	int currentNumberOfReservations = 0;
	int* pointerCurrentNumberOfReservations = &currentNumberOfReservations;

	int currentNumberOfAccounts = 14;
	int* pointerCurrentNumberOfAccounts = &currentNumberOfAccounts;

	int currentNumberOfCustomers = 10;
	int* pointerCurrentNumberOfCustomers = &currentNumberOfCustomers;

	Room* rooms = new Room[50];
   int currentNumberOfRooms = 50;
   int* pointerCurrentNumberOfRooms = &currentNumberOfRooms;

	initializeWithDefaultValues(customersAccounts, receptionistsAccounts, adminsAccounts);
	assignAllAccountsToOneVariable(allAccounts, customersAccounts, receptionistsAccounts, adminsAccounts, currentNumberOfAccounts, currentNumberOfCustomers,2,2);
	initializeRoomsWithDefaultValues(rooms, *pointerCurrentNumberOfRooms);

	while (1)
	{
		currentlyLoggedIn = allAccounts[0];

		//main menu
		menu_gui::reset();
		menu_gui::add_top_text("Witamy w aplikacji hotelu, bla bla bla");
		menu_gui::add_top_text("Co chcesz zrobic wasci panie?");
		menu_gui::add_top_text("");
		menu_gui::add_option("zaloguj sie na istniejace konto");
		menu_gui::add_option("zaloz konto");
		menu_gui::add_option("wyjdz z programu");

		switch (menu_gui::display())
		{
		case 0:
			if (logInAccount(allAccounts, currentNumberOfAccounts))
				switch (currentlyLoggedIn.getPermissions()) {
				case 0:
					menu_customer(customersAccounts[currentlyLoggedIn.getIndex()], rooms, *pointerCurrentNumberOfRooms, reservations, pointerCurrentNumberOfReservations);
					break;
				case 1:
					menu_receptionist(receptionistsAccounts[currentlyLoggedIn.getIndex()], rooms, *pointerCurrentNumberOfRooms, reservations, pointerCurrentNumberOfReservations);
					break;
				case 2:
					menu_admin(adminsAccounts[currentlyLoggedIn.getIndex()], rooms, pointerCurrentNumberOfRooms);
					break;
				}
			break;
		case 1: //zakladanie konta		
			createAccount(pointerCurrentNumberOfAccounts, allAccounts, pointerCurrentNumberOfCustomers, customersAccounts);
			assignAllAccountsToOneVariable(allAccounts, customersAccounts, receptionistsAccounts, adminsAccounts, currentNumberOfAccounts, currentNumberOfCustomers, 2, 2);
			break;
		case 2://wyjdz z programu
			return 0x0;
		}
	}
	return 0x0;
}
