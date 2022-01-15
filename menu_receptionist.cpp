#include "include.h"

void menu_receptionist(){
	menu_gui::reset();
	menu_gui::add_top_text("Witaj recepcjonistko jaki pasjans dzisiaj?");
	menu_gui::add_option("Dodaj rezerwacje");
	menu_gui::add_option("Usun rezerwacje");
	menu_gui::add_option("Wroc do menu");

	switch (menu_gui::display())
	{
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	}

}