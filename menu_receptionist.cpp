#include "include.h"

void menu_receptionist(Receptionist account, Room* rooms, int numberOfRooms, Reservation* reservations, int* pointerCurrentNumberOfReservations){
	
	Room roomToReserve = NULL;
	int fromDate = -1;
	int toDate = -1;
	while (1)
	{
		menu_gui::reset();
		menu_gui::add_top_text("Witaj recepcjonistko jaki pasjans dzisiaj?");
		menu_gui::add_option("Sprawdz dostepnosc pokoi");
		menu_gui::add_option("Dodaj rezerwacje");
		menu_gui::add_option("Usun rezerwacje");
		menu_gui::add_option("Wroc do menu");

		switch (menu_gui::display())
		{
		case 0:	//sprawdz dostepnosc
			system("cls");	//czyszczenie ekranu
			cout << "Podaj date poczatkowa:\n";
			fromDate = inputInDateSystem();
			cout << "\nPodaj date koncowa:\n";
			toDate = inputInDateSystem();
			while (1)
			{
				roomToReserve = account.checkAvailability(fromDate, toDate, rooms, 50);
				menu_gui::reset();
				menu_gui::add_top_text("Wybrano ponizszy pokoj");
				menu_gui::add_top_text("ilosc osob | pietro | standard | powierzchnia || cena za dobe");
				menu_gui::add_top_text(roomToString(roomToReserve));
				menu_gui::add_top_text("w terminie");
				menu_gui::add_top_text("od: " + dateToString(fromDate, 1));
				menu_gui::add_top_text("do: " + dateToString(toDate, 1));
				menu_gui::add_top_text("");
				menu_gui::add_top_text("Potwierdzasz wybor?");
				menu_gui::add_option("Tak, kontynuuj");
				menu_gui::add_option("Nie, wroc do wyboru pokoi");

				int tempChoice = menu_gui::display();
				if (tempChoice == 0)
					break;
				}
			break;
		case 1:	//dodaj rezerwacje
			if (roomToReserve.getNumberOfPeople() == 0)	//nie wybrano jeszcze pokoju
			{
				menu_gui::reset();
				menu_gui::add_top_text("Przed rozpoczeciem rezerwacji prosze wybrac pokoj (po wczesniejszym wyszukaniu w 'sprawdz dostepnosc pokoi')");
				menu_gui::add_option("Ok");
				menu_gui::display();
			}
			else
			{
				int numberOfDays = substractDates(fromDate, toDate);
				menu_gui::reset();
				menu_gui::add_top_text("ilosc osob | pietro | standard | powierzchnia || cena za dobe");
				menu_gui::add_top_text(roomToString(roomToReserve));
				menu_gui::add_top_text("Termin: od: " + dateToString(fromDate,1) + " do: " + dateToString(toDate,1));
				menu_gui::add_top_text("Liczba dni: " + to_string(numberOfDays));
				menu_gui::add_top_text("Calkowita kwota: " + to_string(numberOfDays * roomToReserve.getPrice()));
				menu_gui::add_top_text("");
				menu_gui::add_option("Dodaj rezerwacje");
				menu_gui::add_option("Anuluj");
				Customer newCustomer = Customer("Klara", "Walczak", 26061970, "KlaraWalczak@dayrep.com", "aaSDWTJevGfZ3Wp0");
				if (menu_gui::display() == 0)	//dodaj rezerwacjê
				{
					//dokonaj platnosci  \/
					bool paymentStatus = false;
					//dokonaj platnosci  /\
					//wybierz konto albo utworz nowe dla klienta  \/

					//wybierz konto albo utworz nowe dla klienta  /\

					Reservation newReservation = Reservation(fromDate, toDate, paymentStatus, &roomToReserve, &newCustomer);
					//powiêkszenie tablicy reservations o jeden
					Reservation* temp = new Reservation[(*pointerCurrentNumberOfReservations) + 1];
					std::copy(reservations, reservations + (*pointerCurrentNumberOfReservations), temp);
					delete[] reservations;
					reservations = temp;
					//dodanie nowej rezerwacji
					reservations[*pointerCurrentNumberOfReservations] = newReservation;
					*pointerCurrentNumberOfReservations += 1;
				}
			}
			break;
		case 2:	//usun rezerwacje
			cancelReservation(reservations, pointerCurrentNumberOfReservations);
			break;
		case 3:	//wyjdz
			return;	//wyjscie z tego menu
		}
	}
}