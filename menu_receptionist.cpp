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
		cout << "Podaj date poczatkowa:\n";
		fromDate = inputInDateSystem();
		cout << "\nPodaj date koncowa:\n";
		toDate = inputInDateSystem();
		roomToReserve = account.checkAvailability(fromDate,toDate,rooms,50);
		menu_gui::reset();
		menu_gui::add_top_text("Wybrano ponizszy pokoj");
		menu_gui::add_top_text("ilosc osob | pietro | standard | powierzchnia || cena za dobe");
		menu_gui::add_top_text(roomToString(roomToReserve));
		menu_gui::add_top_text("Czy chcesz dokonac rezerwacji w terminie");
		menu_gui::add_top_text("od: " + dateToString(fromDate,1));
		menu_gui::add_top_text("do: " + dateToString(toDate,1));
		menu_gui::add_top_text("");
		menu_gui::add_option("Tak, kontynuuj");
		menu_gui::add_option("Nie, wroc do menu");

		switch (menu_gui::display())
		{
		case 0:
			cout << "takkkkkk\n";
			break;
		case 1:
			cout << "nieeeeeeee\n";
			break;
		}
		system("pause");
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	}

	cout << "(TYMCZASOWE!) Wybrano pokoj:" << endl;
	cout << "ilosc osob | pietro | standard | powierzchnia || cena za dobe" << endl;
	cout << roomToString(roomToReserve);
	system("pause");
}