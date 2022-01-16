#include "include.h"

int roomQualityMenu, numberOfPeopleMenu, floorMenu, surfaceAreaMenu;
bool sure;
void howManyPeople();
void menu_addRoom();
void whatSurfaceArea();
int whatFloor();
void areYouSure();

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
		floorMenu = whatFloor();
		whatSurfaceArea();
		areYouSure();
		break;
	case 1:
		roomQualityMenu = 2;
		howManyPeople();
		floorMenu = whatFloor();
		whatSurfaceArea();
		areYouSure();
		break;
	case 2:
		roomQualityMenu = 1;
		howManyPeople();
		floorMenu = whatFloor();
		whatSurfaceArea();
		areYouSure();
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

void areYouSure() {
	std::cout << "czy jesteœ pewien ¿e chcesz utworzyc pokoj z nastepujacymi parametrami?\n";
	std::cout << "standard: " << roomQualityMenu << "\n liczba miejsc: " << numberOfPeopleMenu << "\npowierzchnia: " << surfaceAreaMenu << "\nna pietrze: " << floorMenu << std::endl;
	std::cin >> sure;
	if (sure == true) {
	
	}
}
