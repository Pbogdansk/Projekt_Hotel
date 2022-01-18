#include "include.h"

Person currentlyLoggedIn;
int main()
{
   srand(time(NULL));
   Person allAccounts[15];
   Customer customersAccounts[10];
   Receptionist receptionistsAccounts[2];
   Admin adminsAccounts[2];
   Reservation* reservations = new Reservation[0];
   int currentNumberOfReservations = 0;
   int* pointerCurrentNumberOfReservations = &currentNumberOfReservations;


   Room rooms[50];
   initializeWithDefaultValues(customersAccounts, receptionistsAccounts, adminsAccounts);
   assignAllAccountsToOneVariable(allAccounts, customersAccounts, receptionistsAccounts, adminsAccounts);
   initializeRoomsWithDefaultValues(rooms, 50);

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
	   if (logInAccount(allAccounts, 14) == true)
			cout << "(TYMCZASOWE!)\nudalo sie zalogowac, poziom konta: " << currentlyLoggedIn.getPermissions() << endl;
	   switch (currentlyLoggedIn.getPermissions()) {
	   case 0:
		   menu_customer(customersAccounts[currentlyLoggedIn.getIndex()]);
		   break;
	   case 1:
		   menu_receptionist(receptionistsAccounts[currentlyLoggedIn.getIndex()], rooms, 50, reservations, pointerCurrentNumberOfReservations);
		   break;
	   case 2:
		   menu_admin(adminsAccounts[currentlyLoggedIn.getIndex()]);
		   break;
	   }
//	   system("pause");
//	   break;
//   case 1:
//	   //create_a_account();
//	   break;
 //  case 2:
//	   return 0x0;
//	   break;
   }

   switch (currentlyLoggedIn.getPermissions())
   {
   case permCustomer:	//customer
	   menu_customer(customersAccounts[currentlyLoggedIn.getIndex()]);
	   break;

   case permReceptionist:	//receptionist
	   //menu_receptionist(receptionistsAccounts[currentlyLoggedIn.getIndex()],rooms,50);
	   break;

   case permAdmin:	//admin
	   menu_admin(adminsAccounts[currentlyLoggedIn.getIndex()]);
	   break;
   }

   return 0x0;
}
