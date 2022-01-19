#include "include.h"

int roomQualityMenu, numberOfPeopleMenu, floorMenu, surfaceAreaMenu;
std::string sure;
void howManyPeople();
void menu_addRoom(Admin account, Room*& rooms, int* pointerCurrentNumberOfRooms);
void whatSurfaceArea();
int whatFloor();
void areYouSure(Admin account, Room*& rooms, int* pointerCurrentNumberOfRooms);
Room newRoom;
void menu_usun_pokoj();
void menu_admin(Admin account, Room*& rooms, int* pointerCurrentNumberOfRooms) {

	//test
	//account.addRoom(0,1,2,3);
	//test

	menu_gui::reset();
	menu_gui::add_top_text("Witaj admin kogo zbanujesz dzisiaj?");
	menu_gui::add_option("Dodaj pokoj");
	menu_gui::add_option("Usun istniejacy pokoj");
	menu_gui::add_option("Wroc do menu");
	
	switch (menu_gui::display())
	{
	case 0:
		menu_addRoom(account, rooms, pointerCurrentNumberOfRooms);
		break;
	case 1:
		menu_usun_pokoj();
		break;
	case 2:
		break;
	}

}void menu_addRoom(Admin account, Room*& rooms, int* pointerCurrentNumberOfRooms) {
	
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
		floorMenu = whatFloor();
		whatSurfaceArea();
		areYouSure(account, rooms, pointerCurrentNumberOfRooms);
		break;
	case 1:
		roomQualityMenu = 2;
		howManyPeople();
		floorMenu = whatFloor();
		whatSurfaceArea();
		areYouSure(account, rooms, pointerCurrentNumberOfRooms);
		break;
	case 2:
		roomQualityMenu = 1;
		howManyPeople();
		floorMenu = whatFloor();
		whatSurfaceArea();
		areYouSure(account, rooms, pointerCurrentNumberOfRooms);
		break;
	case 3:

		break;
	}
}
void howManyPeople() {
	std::cout << "ilu ludzi bêdzie w nowym pokoju?\n";
	std::cin >> numberOfPeopleMenu;
}
int whatFloor() {
	menu_gui::reset();
	menu_gui::add_top_text("Wybierz pietro pokoju do dodania:");
	
	menu_gui::add_option("1");	
	menu_gui::add_option("2");	
	menu_gui::add_option("3");	
	menu_gui::add_option("4");	
	menu_gui::add_option("5");	
	menu_gui::add_option("6");
	menu_gui::add_option("7");
	menu_gui::add_option("8");
	menu_gui::add_option("9");
	menu_gui::add_option("10");
	menu_gui::add_option("11");
	menu_gui::add_option("12");

	switch (menu_gui::display())
	{

	case 0:
		return 1;
		break;
	case 1:
		return 2;
		break;
	case 2:
		return 3;
		break;
	case 3:
		return 4;
		break;
	case 4:
		return 5;
		break;
	case 5:
		return 6;
		break;
	case 6:
		return 7;
		break;

	case 7:
		return 8;
		break;

	case 8:
		return 9;
		break;

	case 9:
		return 10;
		break;

	case 10:
		return 11;
		break;

	case 11:
		return 12;
		break;

	}
}
void whatSurfaceArea() {
	std::cout << "\nJaka bedzie powierzchnia nowego pokoju? [m^2]\n";
	std::cin >> surfaceAreaMenu;
}

void areYouSure(Admin account, Room*& rooms, int* pointerCurrentNumberOfRooms) {

	while (1)
	{
		menu_gui::reset();
		menu_gui::add_top_text("czy jestes pewien ze chcesz utworzyc pokoj z nastepujacymi parametrami ?");
		menu_gui::add_top_text("standard: " + to_string(roomQualityMenu) + "\nliczba miejsc: " + to_string(numberOfPeopleMenu) + "\npowierzchnia: " + to_string(surfaceAreaMenu) + "\nna pietrze: " + to_string(floorMenu));
		menu_gui::add_option("Tak");
		menu_gui::add_option("Nie");
		newRoom = Room(numberOfPeopleMenu, floorMenu, roomQualityMenu, surfaceAreaMenu);
		if (menu_gui::display() == 0) {
			Room* temp = new Room[(*pointerCurrentNumberOfRooms) + 1];
			std::copy(rooms, rooms + (*pointerCurrentNumberOfRooms), temp);
			delete[] rooms;
			rooms = temp;
			//dodanie nowego pokoju
			rooms[*pointerCurrentNumberOfRooms] = newRoom;
			*pointerCurrentNumberOfRooms += 1;
			return;
		}
		else{
			return;
		}
	}
}


void menu_usun_pokoj() {

}