#include "include.h"


string reservationToString(Reservation reservation)
{
	string output = reservation.getCustomerEmail();
	while (output.length() < 30)
		output += " ";
	output += " | ";
	output += dateToString(reservation.getStartingDate());
	output += " | ";
	output += dateToString(reservation.getEndingDate());
	output += " | ";
	if (reservation.getPaymentStatus() == true)
		output += "TAK";
	else
		output += "NIE";
	return output;
}


void cancelReservation(Reservation*& reservations, int* pointerCurrentNumberOfReservations) {
	menu_gui::reset();
	menu_gui::add_top_text("Usuwanie rezerwacji");
	menu_gui::add_top_text("Wybierz rezerwacje do usuniecia");
	menu_gui::add_top_text("");
	menu_gui::add_top_text("email klienta                    | data od    | do         | czy zaplacono");
	for (int i = 0; i < *pointerCurrentNumberOfReservations; i++)
	{
		menu_gui::add_option(reservationToString(reservations[i]));
	}
	menu_gui::add_option("Anuluj");

	int indexOfReseravtionToCancel = menu_gui::display();
	if (indexOfReseravtionToCancel == *pointerCurrentNumberOfReservations)
		return;	//opcja Anuluj
	
	Reservation reservationToCancel = reservations[indexOfReseravtionToCancel];

	menu_gui::reset();
	menu_gui::add_top_text("Usuwanie rezerwacji");
	menu_gui::add_top_text("Jestes pewnien, ze chcesz usunac nastepujaca rezerwacje?");
	menu_gui::add_top_text("");
	menu_gui::add_top_text("email klienta                    | data od    | do         | czy zaplacono");
	menu_gui::add_top_text(reservationToString(reservationToCancel));
	menu_gui::add_option("Tak");
	menu_gui::add_option("Anuluj");

	if (menu_gui::display() == 1)
		return;	//opcja Anuluj

	//zwrot kasy
	int moneyToReturn = reservationToCancel.getAmountRemainingToPay();
		moneyToReturn = reservationToCancel.getRoomPrice() * substractDates(reservationToCancel.getStartingDate(), reservationToCancel.getEndingDate()) - moneyToReturn;
	//zwrot kasy

	Reservation* temp = new Reservation[(*pointerCurrentNumberOfReservations) - 1];
	for (int i = 0, j = 0; i < (*pointerCurrentNumberOfReservations); i++) //copy bez tego usuwanego
	{
		if (i != indexOfReseravtionToCancel)
		{
			temp[j] = reservations[i];
			j++;
		}
	}
	delete[] reservations;
	reservations = temp;
	*pointerCurrentNumberOfReservations -= 1;

	reservationToCancel.annulReservation();


	menu_gui::reset();
	menu_gui::add_top_text("Pomyslnie anulowano rezerwacje");
	menu_gui::add_top_text("email klienta                  | data od    | do         | czy zaplacono");
	menu_gui::add_top_text(reservationToString(reservationToCancel));
	menu_gui::add_top_text("");
	if (moneyToReturn > 0)
	{
		menu_gui::add_top_text("Kwota do zwrotu klienowi: " + to_string(moneyToReturn));
		menu_gui::add_option("Potwierdz dokonanie zwrotu pieniedzy");
	}
	else
	{
		menu_gui::add_option("Ok");
	}
	menu_gui::display();
}

void cancelReservationCustomer(Reservation*& reservations, int* pointerCurrentNumberOfReservations, Reservation*& customersReservation) {
	menu_gui::reset();
	menu_gui::add_top_text("Usuwanie rezerwacji");
	menu_gui::add_top_text("Wybierz rezerwacje do usuniecia");
	menu_gui::add_top_text("");
	menu_gui::add_top_text("email klienta                    | data od    | do         | czy zaplacono");
	if (customersReservation != NULL)
		menu_gui::add_option(reservationToString(*customersReservation));
	menu_gui::add_option("Anuluj");

	int indexOfReseravtionToCancel = menu_gui::display();
	if (indexOfReseravtionToCancel == 1)
		return;	//opcja Anuluj
	if (customersReservation == NULL)
		return;

	menu_gui::reset();
	menu_gui::add_top_text("Usuwanie rezerwacji");
	menu_gui::add_top_text("Jestes pewnien, ze chcesz usunac nastepujaca rezerwacje?");
	menu_gui::add_top_text("");
	menu_gui::add_top_text("email klienta                    | data od    | do         | czy zaplacono");
	menu_gui::add_top_text(reservationToString(*customersReservation));
	menu_gui::add_option("Tak");
	menu_gui::add_option("Anuluj");

	if (menu_gui::display() == 1)
		return;	//opcja Anuluj

	//zwrot kasy
	int moneyToReturn = customersReservation->getAmountRemainingToPay();
	moneyToReturn = customersReservation->getRoomPrice() * substractDates(customersReservation->getStartingDate(), customersReservation->getEndingDate()) - moneyToReturn;

	//zwrot kasy

	Reservation* temp = new Reservation[(*pointerCurrentNumberOfReservations) - 1];
	for (int i = 0, j = 0; i < (*pointerCurrentNumberOfReservations); i++) //copy bez tego usuwanego
	{
		if (reservations[i].getCustomerEmail() != customersReservation->getCustomerEmail())
		{
			temp[j] = reservations[i];
			j++;
		}
	}
	delete[] reservations;
	reservations = temp;
	*pointerCurrentNumberOfReservations -= 1;

	customersReservation->annulReservation();


	menu_gui::reset();
	menu_gui::add_top_text("Pomyslnie anulowano rezerwacje");
	menu_gui::add_top_text("email klienta                  | data od    | do         | czy zaplacono");
	menu_gui::add_top_text(reservationToString(*customersReservation));
	menu_gui::add_top_text("");
	if (moneyToReturn > 0)
	{
		menu_gui::add_top_text("Kwota, ktora zostanie zwrocona: " + to_string(moneyToReturn));
		menu_gui::add_option("Ok");
	}
	else
	{
		menu_gui::add_option("Ok");
	}
	menu_gui::display();
}

void makePayment(Reservation*& reservations, int* pointerCurrentNumberOfReservations) {
	menu_gui::reset();
	menu_gui::add_top_text("Dokonywanie platnosci naleznych za rezerwacje");
	menu_gui::add_top_text("Wybierz rezerwacje");
	menu_gui::add_top_text("");
	menu_gui::add_top_text("email klienta                    | data od    | do         | czy zaplacono | kwota do zaplacenia");
	for (int i = 0; i < *pointerCurrentNumberOfReservations; i++)
	{
		menu_gui::add_option(reservationToString(reservations[i]) + "           | " + to_string(reservations[i].getAmountRemainingToPay()));
	}
	menu_gui::add_option("Anuluj");
	int indexOfChoosenReservation = menu_gui::display();
	
	if (indexOfChoosenReservation == *pointerCurrentNumberOfReservations)
		return;

	int amountOfMoneyToPay = 0;
	while (1) //pêtla platnosci (powtarzanie gdy ktos wpisze kwote mniejsza od zera lub wieksza od maksymalnej)
	{
		menu_gui::reset();
		menu_gui::add_top_text("email klienta                  | data od    | do         | czy zaplacono | kwota do zaplacenia");
		menu_gui::add_top_text(reservationToString(reservations[indexOfChoosenReservation]) + "           | " + to_string(reservations[indexOfChoosenReservation].getAmountRemainingToPay()));
		menu_gui::add_top_text("");
		menu_gui::add_option("Zaplac calosc");
		menu_gui::add_option("Zaplac zaliczke (20%)");
		menu_gui::add_option("Niestandardowa kwota");
		
		int typeOfPayment = menu_gui::display();
		if (typeOfPayment == 2)
		{
			cin >> amountOfMoneyToPay;
			if (amountOfMoneyToPay < 0 || amountOfMoneyToPay > reservations[indexOfChoosenReservation].getAmountRemainingToPay())
			{
				menu_gui::reset();
				menu_gui::add_top_text("Prosze podac prawidlowa kwote");
				menu_gui::add_option("Ok");
				menu_gui::display();
			}
			else
				break;
		}
		else if (typeOfPayment == 1)
		{
			amountOfMoneyToPay = 0.2 * reservations[indexOfChoosenReservation].getAmountRemainingToPay();
			break;
		}
		else
		{
			amountOfMoneyToPay = reservations[indexOfChoosenReservation].getAmountRemainingToPay();
			break;
		}
	}

	menu_gui::reset();
	menu_gui::add_top_text("email klienta                  | data od    | do         | czy zaplacono | kwota do zaplacenia");
	menu_gui::add_top_text(reservationToString(reservations[indexOfChoosenReservation]) + "           | " + to_string(reservations[indexOfChoosenReservation].getAmountRemainingToPay()));
	menu_gui::add_top_text("");
	menu_gui::add_top_text("Wybierz metode platnosci");
	menu_gui::add_option("Gotowka");
	menu_gui::add_option("Karta platnicza");
	menu_gui::add_option("Anuluj");

	
	int CashOrCard = menu_gui::display();
	if (CashOrCard == 2)
		return;

	reservations[indexOfChoosenReservation].pay(amountOfMoneyToPay); //placenie

	menu_gui::reset();
	menu_gui::add_top_text("Pomyslinie dokonano platnosci");
	if (reservations[indexOfChoosenReservation].getAmountRemainingToPay() > 0)
		menu_gui::add_top_text("Pozostala kwota do uregulowania: " + to_string(reservations[indexOfChoosenReservation].getAmountRemainingToPay()));
	menu_gui::add_option("Ok");
	menu_gui::display();
	return;
}

void makePaymentCustomer(Reservation*& reservations, int* pointerCurrentNumberOfReservations, Reservation*& customersReservation) {
	menu_gui::reset();
	menu_gui::add_top_text("Dokonywanie platnosci naleznych za rezerwacje");
	menu_gui::add_top_text("Wybierz rezerwacje");
	menu_gui::add_top_text("");
	menu_gui::add_top_text("email klienta                    | data od    | do         | czy zaplacono | kwota do zaplacenia");
	if (customersReservation != NULL)
	menu_gui::add_option(reservationToString(*customersReservation) + "           | " + to_string(customersReservation->getAmountRemainingToPay()));
	menu_gui::add_option("Anuluj");
	int indexOfChoosenReservation = menu_gui::display();

	if (indexOfChoosenReservation == *pointerCurrentNumberOfReservations)
		return;
	if (customersReservation == NULL)
		return;

	int amountOfMoneyToPay = 0;
	while (1) //pêtla platnosci (powtarzanie gdy ktos wpisze kwote mniejsza od zera lub wieksza od maksymalnej)
	{
		menu_gui::reset();
		menu_gui::add_top_text("email klienta                  | data od    | do         | czy zaplacono | kwota do zaplacenia");
		menu_gui::add_top_text(reservationToString(reservations[indexOfChoosenReservation]) + "           | " + to_string(customersReservation->getAmountRemainingToPay()));
		menu_gui::add_top_text("");
		menu_gui::add_option("Zaplac calosc");
		menu_gui::add_option("Zaplac zaliczke (20%)");
		menu_gui::add_option("Niestandardowa kwota");

		int typeOfPayment = menu_gui::display();
		if (typeOfPayment == 2)
		{
			cin >> amountOfMoneyToPay;
			if (amountOfMoneyToPay < 0 || amountOfMoneyToPay > customersReservation->getAmountRemainingToPay())
			{
				menu_gui::reset();
				menu_gui::add_top_text("Prosze podac prawidlowa kwote");
				menu_gui::add_option("Ok");
				menu_gui::display();
			}
			else
				break;
		}
		else if (typeOfPayment == 1)
		{
			amountOfMoneyToPay = 0.2 * customersReservation->getAmountRemainingToPay();
			break;
		}
		else
		{
			amountOfMoneyToPay = customersReservation->getAmountRemainingToPay();
			break;
		}
	}

	menu_gui::reset();
	menu_gui::add_top_text("email klienta                  | data od    | do         | czy zaplacono | kwota do zaplacenia");
	menu_gui::add_top_text(reservationToString(*customersReservation) + "           | " + to_string(customersReservation->getAmountRemainingToPay()));
	menu_gui::add_top_text("");
	menu_gui::add_top_text("Wybierz metode platnosci");
	menu_gui::add_option("Gotowka");
	menu_gui::add_option("Karta platnicza");
	menu_gui::add_option("Anuluj");


	int CashOrCard = menu_gui::display();
	if (CashOrCard == 2)
		return;

	customersReservation->pay(amountOfMoneyToPay); //placenie

	menu_gui::reset();
	menu_gui::add_top_text("Pomyslinie dokonano platnosci");
	if (customersReservation->getAmountRemainingToPay() > 0)
		menu_gui::add_top_text("Pozostala kwota do uregulowania: " + to_string(customersReservation->getAmountRemainingToPay()));
	menu_gui::add_option("Ok");
	menu_gui::display();
	return;
}