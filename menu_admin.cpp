#include "include.h"
#include "classes/Admin.cpp"


void menu_admin(Admin account) {

	//test
	account.addRoom(0,1,2,3);
	//test

	menu_gui::reset();
	menu_gui::add_top_text("Witaj admin kogo zbanujesz dzisiaj?");
	menu_gui::add_option("Dodaj pokoj");
	menu_gui::add_option("Usun istniejacy pokoj");
	menu_gui::add_option("Wroc do menu");
	
	switch (menu_gui::display())
	{
	case 0:
		currentlyLoggedIn.addRoom();
		break;
	case 1:
		//menu_usun_pokoj();
		break;
	case 2:
		break;
	}

}