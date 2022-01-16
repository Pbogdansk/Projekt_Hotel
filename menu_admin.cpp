#include "include.h"

int roomQualityMenu, numberOfPeopleMenu, floorMenu, surfaceAreaMenu;
void howManyPeople();
void menu_addRoom();
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
		 menu_addRoom();
		break;
	case 1:
		//menu_usun_pokoj();
		break;
	case 2:
		break;
	}

}void menu_addRoom() {
	
	menu_gui::reset();
	menu_gui::add_top_text("Wybierz standard pokoju do dodania:");
	menu_gui::add_option("belweder");
	menu_gui::add_option("premium");
	menu_gui::add_option("ekonomiczny ");
	menu_gui::add_option("Wroc do menu");

	
	switch (menu_gui::display())
	{
	case 0:
		roomQualityMenu = 3;
		howManyPeople();
		break;
	case 1:
		roomQualityMenu = 2;
		howManyPeople();
		break;
	case 2:
		roomQualityMenu = 1;
		howManyPeople();
		break;
	case 3:

		break;
	}
}
void howManyPeople() {
	std::cout << "ilu ludzi bêdzie w nowym pokoju?\n";
	std::cin >> numberOfPeopleMenu;
}