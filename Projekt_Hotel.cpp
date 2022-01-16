#include "include.h"

Person currentlyLoggedIn;
int main()
{
   Person allAccounts[15];
   Customer customersAccounts[10];
   Receptionist receptionistsAccounts[2];
   Admin adminsAccounts[2];

   

   Room rooms[50];
   initializeWithDefaultValues(customersAccounts, receptionistsAccounts, adminsAccounts, rooms);
   assignAllAccountsToOneVariable(allAccounts, customersAccounts, receptionistsAccounts, adminsAccounts);

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
	   switch () {
	   }
	   system("pause");
	   break;
   case 1:
	   //create_a_account();
	   break;
   case 2:
	   return 0x0;
	   break;
   }

   switch (currentlyLoggedIn.getPermissions())
   {
   case permCustomer:	//customer
	   menu_customer(customersAccounts[currentlyLoggedIn.getIndex()]);
	   break;

   case permReceptionist:	//receptionist
	   menu_receptionist(receptionistsAccounts[currentlyLoggedIn.getIndex()]);
	   break;

   case permAdmin:	//admin
	   menu_admin(adminsAccounts[currentlyLoggedIn.getIndex()]);
	   break;
   }

   return 0x0;
}
