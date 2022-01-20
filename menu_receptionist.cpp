#include "include.h"
#include "classes/Reservation.h"

//do dodania:
// - melodowanie / wymeldowanie
// - przypisywanie rezerwacji do konkretnej osoby



void menu_receptionist(Receptionist account, Room*& rooms, int* pointerCurrentNumberOfRooms, Reservation* reservations, int* pointerCurrentNumberOfReservations, int* pointerCurrentNumberOfBookedIn) {

	Customer newCustomer = Customer();
	Room* pointerRoomToReserve = new Room[1];
	Reservation newReservation;
	int fromDate = -1;
	int toDate = -1;
	while (1)
	{
		menu_gui::reset();
		menu_gui::add_top_text("Konto: " + account.getEmail());
		menu_gui::add_top_text("");
		menu_gui::add_top_text("Menu Recepcjonisty");
		menu_gui::add_option("Sprawdz dostepnosc pokoi");
		menu_gui::add_option("Dodaj rezerwacje");
		menu_gui::add_option("Usun rezerwacje");
		menu_gui::add_option("Dokonaj platnosci");
		menu_gui::add_option("Zamelduj klienta");
		menu_gui::add_option("Wymelduj klienta");
		menu_gui::add_option("Pasjans");
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
				pointerRoomToReserve = account.checkAvailability(fromDate, toDate, rooms, *pointerCurrentNumberOfRooms);
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
		case 1:	//dodaj rezerwacje
			if (pointerRoomToReserve->getNumberOfPeople() == 0)	//nie wybrano jeszcze pokoju
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
					//wybierz konto albo utworz nowe dla klienta  \/
					string newEmail;
					system("cls");
					cout << "Szczegoly dotyczace rezerwacji:" << endl;
					cout << "Podaj adres email, ktory bedzie identyfikowal rezerwacje" << endl;
					cin >> newEmail;
					newCustomer = Customer("RECEPTIONIST", "RESERVATION", 26061970, newEmail, "aaSDWTJevGfZ3Wp0");
					//wybierz konto albo utworz nowe dla klienta  /\

					newReservation = account.reservation(pointerRoomToReserve, fromDate, toDate, &newCustomer);
					newReservation.makeReservation();
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
		case 3:	//dokonaj platnosci
			makePayment(reservations, pointerCurrentNumberOfReservations);
			break;
		case 4:	//melodowanie / wymelodwanie
		{
			menu_gui::reset();
			menu_gui::add_top_text("Meldowanie klienta");
			menu_gui::add_top_text("Wybierz rezerwacje");
			menu_gui::add_top_text("");
			menu_gui::add_top_text("email klienta                    | data od    | do         | czy zaplacono | kwota do zaplacenia");
			for (int i = 0; i < *pointerCurrentNumberOfReservations; i++)
			{
				menu_gui::add_option(newReservation.reservationToString(reservations[i]) + "           | " + to_string(reservations[i].getAmountRemainingToPay()));
			}
			menu_gui::add_option("Anuluj");
			int indexOfChoosenReservation = menu_gui::display();

			if (indexOfChoosenReservation == *pointerCurrentNumberOfReservations)
				//Reservation reservationToCancel = reservations[indexOfChoosenReservation];
				return;

			menu_gui::reset();
			menu_gui::add_top_text("Meldowanie Klienta");
			menu_gui::add_top_text("Jestes pewnien, ze chcesz zameldowac klienta?");
			menu_gui::add_option("Tak");
			menu_gui::add_option("Anuluj");
			int PickedOption = menu_gui::display();
			if (PickedOption == 0) //tak
			{
				newReservation.setBookIn(newReservation.getStartingDate(), newReservation.getEndingDate());
				(*pointerCurrentNumberOfBookedIn)++;
				menu_gui::reset();
				menu_gui::add_top_text("Udalo sie zameldowac klienta");
				menu_gui::add_option("Ok");
				switch (menu_gui::display())
				{
				case 0:
					break;
				}
			}
			else if (PickedOption == 1) // anuluj
			{
				break;
			}
		}

		break;

		case 5:
		{
			{
				menu_gui::reset();
				menu_gui::add_top_text("Meldowanie klienta");
				menu_gui::add_top_text("Wybierz rezerwacje");
				menu_gui::add_top_text("");
				menu_gui::add_top_text("email klienta                    | data od    | do         | czy zaplacono | kwota do zaplacenia");
				for (int i = 0; i < *pointerCurrentNumberOfBookedIn; i++)
				{
					menu_gui::add_option(newReservation.reservationToString(reservations[i]) + "           | " + to_string(reservations[i].getAmountRemainingToPay()));
				}
				menu_gui::add_option("Anuluj");
				int indexOfChoosenReservation = menu_gui::display();

				menu_gui::reset();
				menu_gui::add_top_text("Wymeldowanie Klienta");
				menu_gui::add_top_text("Jestes pewnien, ze chcesz wymeldowac klienta?");
				menu_gui::add_option("Tak");
				menu_gui::add_option("Anuluj");
				int PickedOption = menu_gui::display();
				if (PickedOption == 0) //tak
				{
					newReservation.setBookIn(newReservation.getStartingDate(), newReservation.getEndingDate());
					menu_gui::reset();
					menu_gui::add_top_text("Udalo sie wymeldowac klienta");
					menu_gui::add_option("Ok");
					switch (menu_gui::display())
					{
					case 0:
						break;
					}
				}
				else if (PickedOption == 1) // anuluj
				{
					break;
				}

			}


			break;
		case 6:
			menu_gui::reset();
			menu_gui::add_top_text("Skup sie!");
			menu_gui::add_option("juz juz");
			menu_gui::display();
			break;
		case 7:	//wyjdz
			return;	//wyjscie z tego menu
		}
		}
	}
}