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
	int moneyToReturn = 0;
	if (reservationToCancel.getPaymentStatus())
		moneyToReturn = reservationToCancel.getRoomPrice() * substractDates(reservationToCancel.getStartingDate(), reservationToCancel.getEndingDate());
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
	menu_gui::add_top_text("email klienta                    | data od    | do         | czy zaplacono");
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
	menu_gui::display();
}