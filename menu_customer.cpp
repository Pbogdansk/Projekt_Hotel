#include "include.h"

void menu_customer(Customer account, Room*& rooms, int numberOfRooms, Reservation*& reservations, int* pointerCurrentNumberOfReservations) {
	Room* pointerRoomToReserve = new Room[1];
	Reservation newReservation;
	Reservation* customersReservation = new Reservation[1];
	Customer newCustomer = Customer();
	int fromDate = -1;
	int toDate = -1;
	while (1)
	{
		menu_gui::reset();
		menu_gui::add_top_text("Konto: " + account.getEmail());
		menu_gui::add_top_text("");
		menu_gui::add_top_text("Menu Klienta");
		menu_gui::add_option("Sprawdz dostepnosc pokoi");
		menu_gui::add_option("Dodaj rezerwacje");
		menu_gui::add_option("Usun rezerwacje");
		menu_gui::add_option("Dokonaj platnosci");
		menu_gui::add_option("Meldowanie/wymeldowanie");
		menu_gui::add_option("Zmiana danych klienta");
		menu_gui::add_option("Wroc do menu");

		switch (menu_gui::display())
		{
		case 0: //sprawdzenie dostepnosci
			system("cls");	//czyszczenie ekranu
			cout << "Podaj date poczatkowa:\n";
			fromDate = inputInDateSystem();
			cout << "\nPodaj date koncowa:\n";
			toDate = inputInDateSystem();
			while (1)
			{
				pointerRoomToReserve = account.checkAvailability(fromDate, toDate, rooms, numberOfRooms);
				if (pointerRoomToReserve != NULL)
				{
					menu_gui::reset();
					menu_gui::add_top_text("Wybrano ponizszy pokoj");
					menu_gui::add_top_text("ilosc osob | pietro | standard | powierzchnia || cena za dobe");
					menu_gui::add_top_text(roomToString(*pointerRoomToReserve));
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
				else
					break;
			}
			break;
		case 1: //dodaj rezerwacje
			if (account.getAlreadyHaveReservation() == true)
			{
				menu_gui::reset();
				menu_gui::add_top_text("Mozna miec tylko jedna rezerwacje na raz!");
				menu_gui::add_option("Ok");
				menu_gui::display();
			}
			else if (pointerRoomToReserve->getNumberOfPeople() == 0)	//nie wybrano jeszcze pokoju
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
				menu_gui::add_top_text(roomToString(*pointerRoomToReserve));
				menu_gui::add_top_text("Termin: od: " + dateToString(fromDate, 1) + " do: " + dateToString(toDate, 1));
				menu_gui::add_top_text("Liczba dni: " + to_string(numberOfDays));
				menu_gui::add_top_text("Calkowita kwota: " + to_string(numberOfDays * pointerRoomToReserve->getPrice()));
				menu_gui::add_top_text("");
				menu_gui::add_option("Dodaj rezerwacje");
				menu_gui::add_option("Anuluj");
				if (menu_gui::display() == 0)	//dodaj rezerwacjê
				{
					bool paymentStatus = false;

					account.reservation(pointerRoomToReserve, fromDate, toDate);
					Reservation* sth = account.getCustomersReservation();
					sth->makeReservation();
					//powiêkszenie tablicy reservations o jeden
					Reservation* temp = new Reservation[(*pointerCurrentNumberOfReservations) + 1];
					std::copy(reservations, reservations + (*pointerCurrentNumberOfReservations), temp);
					delete[] reservations;
					reservations = temp;
					//dodanie nowej rezerwacji
					reservations[*pointerCurrentNumberOfReservations] = *account.getCustomersReservation();
					*pointerCurrentNumberOfReservations += 1;
					account.setAlreadyHaveReservation(true);
				}
			}
			break;
		case 2: //usun rezerwacje		
			customersReservation = account.getCustomersReservation();
			if (account.getAlreadyHaveReservation() == false)
				customersReservation = NULL;
			cancelReservationCustomer(reservations, pointerCurrentNumberOfReservations, customersReservation);
			account.setAlreadyHaveReservation(false);
			break;
		case 3: //dokonaj platnosci
			customersReservation = account.getCustomersReservation();
			if (account.getAlreadyHaveReservation() == false)
				customersReservation = NULL;
			makePaymentCustomer(reservations, pointerCurrentNumberOfReservations, customersReservation);
			break;
		case 4: //melodowanie / wymeldowanie
			//
			// 
			//
			break;
		case 5: //zmiana danych klienta
			menu_gui::reset();
			menu_gui::add_top_text("Prosze wybraæ ktora informacje chce pan/pani zmienic");
			menu_gui::add_option("Imie");
			menu_gui::add_option("Nazwisko");
			menu_gui::add_option("Data urodzenia");
			menu_gui::add_option("E-mail");
			menu_gui::add_option("Haslo");
			menu_gui::add_option("Wroc do menu");
			menu_gui::display();
		 
			switch (menu_gui::display()) {
			case 0:		//zmiana imienia
				currentlyLoggedIn.changeName();
				break;
			case 1:		//zmiena nazwiska
				//currentlyLoggedIn.changeSurname();
				break;
			case 2:		//zmiana daty urodzenia
				//currentlyLoggedIn.changeDateOfBirth();
				break;
			case 3:		//zmiana e-mailu
				//currentlyLoggedIn.changeEmail();
				break;
			case 4:		//zmiana has³a
				//currentlyLoggedIn.changePassword();
				break;
			case 5:		//powrót do menu
				return;
			}

		
			break;
		case 6: //wroc do menu / wyloguj
			return;
		}
	}
}