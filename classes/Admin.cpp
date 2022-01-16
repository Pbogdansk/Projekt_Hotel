#include <exception>
#include "../include.h"

using namespace std;

#include "Admin.h"
#include "Room.h"
#include "Person.h"

void Admin::addRoom(string aInt_numberOfPeople, string aInt_floor, string aInt_roomQuality, string aInt_surfaceArea) {
	void menu_addRoom();
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

void Admin::removeRoom(Room p) {
	throw "Not yet implemented";
}