#include "include.h"

int roomQualityMenu, numberOfPeopleMenu, floorMenu, surfaceAreaMenu;
std::string sure;
Room newRoom;
void howManyPeople();
void menu_addRoom(Admin account, Room*& rooms, int* pointerCurrentNumberOfRooms);
void whatSurfaceArea();
int whatFloor();
void areYouSure(Admin account, Room*& rooms, int* pointerCurrentNumberOfRooms);
Room newRoom;
void changeClientsData(Customer*& customersAccounts, int currentNumberOfCustomers);
void menu_usun_pokoj(Room*& rooms, int* pointerCurrentNumberOfRooms, Room availaibleRooms[]);

void menu_admin(Admin account, Room*& rooms, int* pointerCurrentNumberOfRooms,
	Customer*& customersAccounts, int currentNumberOfCustomers) {
  Room* availaibleRooms = new Room[*pointerCurrentNumberOfRooms];
  int availaibleRoomscounter = 0;
	while (1) {
		menu_gui::reset();
		menu_gui::add_top_text("Witaj admin kogo zbanujesz dzisiaj?");
		menu_gui::add_option("Dodaj pokoj");
		menu_gui::add_option("Usun istniejacy pokoj");
		menu_gui::add_option("Zmien dane klienta");
		menu_gui::add_option("Wroc do menu");

		switch (menu_gui::display())
		{
		case 0:
			menu_addRoom(account, rooms, pointerCurrentNumberOfRooms);
			break;
		case 1:
			menu_usun_pokoj(rooms, pointerCurrentNumberOfRooms, availaibleRooms);
			break;
		case 2:
			changeClientsData(customersAccounts, currentNumberOfCustomers);
			break;
		default:
			return;
		}
	}
}

void menu_addRoom(Admin account, Room*& rooms, int* pointerCurrentNumberOfRooms) {

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
			menu_gui::reset();
			menu_gui::add_top_text("Utworzyles pokoj o parametrach: ");
			menu_gui::add_top_text("standard: " + to_string(roomQualityMenu) + "\nliczba miejsc: " + to_string(numberOfPeopleMenu) + "\npowierzchnia: " + to_string(surfaceAreaMenu) + "\nna pietrze: " + to_string(floorMenu));
			menu_gui::add_option("OK");
			switch (menu_gui::display())
			{
			case 0:
				return;
			}
		}
		else {
			return;
		}
	}
}

void changeClientsData(Customer*& customersAccounts, int currentNumberOfCustomers) {
	menu_gui::reset();
	menu_gui::add_top_text("Proszê wybrac uzytkownika ktoremu zostana zmienione dane");
  
	for (int i = 0; i < currentNumberOfCustomers; i++)
	{
		menu_gui::add_option(customersAccounts[i].getName() + " " + customersAccounts[i].getSurname());
	}
	menu_gui::add_option("Powrot");

	int chosenIndex = menu_gui::display();

	menu_gui::reset();
	menu_gui::add_top_text("Prosze wybrac ktora informacja zostanie zmieniona użytkownikowi " +
		customersAccounts[chosenIndex].getName() + " " + customersAccounts[chosenIndex].getSurname());
	menu_gui::add_option("Imie");
	menu_gui::add_option("Nazwisko");
	menu_gui::add_option("Data urodzenia");
	menu_gui::add_option("E-mail");
	menu_gui::add_option("Haslo");
	menu_gui::add_option("Powrot");

	switch (menu_gui::display())
	{
	case 0:			//zmiana imienia
		customersAccounts[chosenIndex].changeName();
		break;
	case 1:			//zmiena nazwiska
		customersAccounts[chosenIndex].changeSurname();
		break;
	case 2:			//zmiana daty urodzenia
		customersAccounts[chosenIndex].changeDateOfBirth();
		break;
	case 3:			//zmiana e-mailu
		customersAccounts[chosenIndex].changeEmail();
		break;
	case 4:			//zmiana hasła
		customersAccounts[chosenIndex].forceChangePassword();
		break;

	default:
		break;
	}
}
void menu_usun_pokoj(Room*& rooms, int* pointerCurrentNumberOfRooms, Room availaibleRooms[]) {
	int availaibleRoomscounter = 0;
	menu_gui::reset();
	menu_gui::add_top_text("Usuwanie pokoju");
	menu_gui::add_top_text("Wybierz pokoj do usuniecia");
	for (int i = 0; i < *pointerCurrentNumberOfRooms; i++)
	{
		bool isThisRoomFree = true;
		for (int j = 0; j < 365; j++)
		{
			if (rooms[i].getIsOccupied(21 + j) == true)
				isThisRoomFree = false;
		}
		if (isThisRoomFree == true)
		{
			menu_gui::add_option(roomToString(rooms[i]));
			availaibleRooms[availaibleRoomscounter] = rooms[i];
			availaibleRoomscounter++;
		}
	}

	//Room* temp = new Room[(*pointerCurrentNumberOfRooms) - 1];
	//for (int i = 0, j = 0; i < (*pointerCurrentNumberOfRooms); i++) //copy bez tego usuwanego
	//{
	//	 (i != indexOfRoomToDelete)
	//	{
	//		temp[j] = rooms[i];
	//		j++;
	//	}
	//}
	//delete[] rooms;
	//rooms = temp;
	//*pointerCurrentNumberOfRooms -= 1;

	}
