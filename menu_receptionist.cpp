#include "include.h"

void menu_receptionist(Receptionist account, Room* rooms, int numberOfRooms){
	menu_gui::reset();
	menu_gui::add_top_text("Witaj recepcjonistko jaki pasjans dzisiaj?");
	menu_gui::add_option("(TYMCZAS!) sprawdx dostepnosc pokoi");
	menu_gui::add_option("Dodaj rezerwacje");
	menu_gui::add_option("Usun rezerwacje");
	menu_gui::add_option("Wroc do menu");

	Room roomToReserve;
	int fromDate = -1;
	int toDate = -1;
	switch (menu_gui::display())
	{
	case 0:
		system("cls");	//czyszczenie ekranu
		cout << "Podaj date poczatkowa: ";
		cin >> fromDate;
		cout << "Podaj date koncowa:    ";
		cin >> toDate;
		roomToReserve = account.checkAvailability(fromDate,toDate,rooms,50);
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	}

}