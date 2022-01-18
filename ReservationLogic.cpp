#include "include.h"


string reservationToString(Reservation reservation)
{
	string output = reservation.getCustomerEmail();
	while (output.length() < 20)
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


void cancelReservation(Reservation* reservations, int* pointerCurrentNumberOfReservations)
{
	menu_gui::reset();
	menu_gui::add_top_text("Usuwanie rezerwacji");
	menu_gui::add_top_text("Wybierz rezerwacje do usuniecia");
	menu_gui::add_top_text("");
	menu_gui::add_top_text("email klienta          | data od    | do         | czy zaplacono");
	for (int i = 0; i < *pointerCurrentNumberOfReservations; i++)
	{
		menu_gui::add_option(reservationToString(reservations[i]));
	}
	menu_gui::add_option("Anuluj");

	int tempChoice = menu_gui::display();
	if (tempChoice == *pointerCurrentNumberOfReservations)
		return;	//opcja Anuluj
	
	system("pause");

}