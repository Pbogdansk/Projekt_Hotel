#include <exception>
using namespace std;

#include "Admin.h"
#include "Room.h"
#include "Person.h"
#include "../include.h"

Admin::Admin(){}
Admin::Admin(string newName, string newSurname, int newDateOfBirth, string newEmail, string newPassword) {
	name[0] = newName;
	surname = newSurname;
	dateOfBirth = newDateOfBirth;
	email = newEmail;
	password = newPassword;
	permissions = permAdmin;
}

void Admin::addRoom() {
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
//void Admin::removeRoom(Room p) {
//	throw "Not yet implemented";
//}