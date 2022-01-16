#include "include.h"

int main()
{
   Person allAccounts[15];
   Customer customersAccounts[10];
   Receptionist receptionistsAccounts[2];
   Admin adminsAccounts[2];
   Person currentlyLoggedIn;

   Room rooms[50];
   initializeWithDefaultValues(customersAccounts, receptionistsAccounts, adminsAccounts, rooms);
   assignAllAccountsToOneVariable(allAccounts, customersAccounts, receptionistsAccounts, adminsAccounts);

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
	   logInAccount(allAccounts,14);
	   break;
   case 1:
	   //create_a_account();
	   break;
   case 2:
	   return 0x0;
	   break;
   }


   // po zalogowaniu siê na odpowiednie konto
   menu_gui::reset();
   menu_gui::add_top_text("zaloguj sie na wybrane konto (tymczasowe rozwiazanie pomijajace logowanie)");
   menu_gui::add_top_text("");
   menu_gui::add_option("customersAccounts[0]");
   menu_gui::add_option("receptionistsAccounts[0]");
   menu_gui::add_option("adminsAccounts[0]");

   //switch (currentlyLoggedIn.getPermissions())
   switch (menu_gui::display())
   {
   case 0:	//customer
	   currentlyLoggedIn = customersAccounts[0];
	   menu_customer();
	   break;

   case 1:	//receptionist
	   currentlyLoggedIn = receptionistsAccounts[0];
	   menu_receptionist();
	   break;

   case 2:	//admin
	   currentlyLoggedIn = adminsAccounts[0];
	   menu_admin();
	   break;
   }

   return 0x0;
}
