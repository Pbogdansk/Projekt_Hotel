#include "include.h"

void menu_admin() {
	menu_gui::reset();
	menu_gui::add_top_text("Witaj admin kogo zbanujesz dzisiaj?");
	menu_gui::add_option("Dodaj pokoj");
	menu_gui::add_option("Usun istniejacy pokoj");
	menu_gui::add_option("Wroc do menu");
	
	switch (menu_gui::display())
	{
	case 0:
		void menu_addRoom();
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
		
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:

		break;
	}
}