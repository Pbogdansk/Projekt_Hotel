#include <exception>

using namespace std;

#include "Receptionist.h"
#include "Room.h"
#include "Reservation.h"
#include "Person.h"
#include <iostream>
#include "../include.h"

Receptionist::Receptionist(){}
Receptionist::Receptionist(string newName, string newSurname, int newDateOfBirth, string newEmail, string newPassword) {
	name[0] = newName;
	surname = newSurname;
	dateOfBirth = newDateOfBirth;
	email = newEmail;
	password = newPassword;
	permissions = permReceptionist;
}

Room* Receptionist::checkAvailability(int startingDate, int endingDate, Room* rooms, int numberOfRooms) {	//returns pokoj do rezerwacji
	
	int daysFromNewYear = substractDates(1012022, startingDate);
	int numberOfDays = substractDates(startingDate, endingDate);
	if (numberOfDays == -1)	//zla data
	{
		menu_gui::reset();
		menu_gui::add_top_text("Podany zakres dat jest nieprawidlowy");
		menu_gui::add_option("Wroc");
		menu_gui::display();
		return NULL;
	}
	//cout << "from " << startingDate << " to " << endingDate << " is " << numberOfDays << " days" << endl;

	Room** availaibleRooms = new Room*[numberOfRooms];
	int availaibleRoomscounter = 0;

	menu_gui::reset();
	menu_gui::add_top_text("Oto wolne pokoje Wasci Panie");
	menu_gui::add_top_text("Wybierz ktory mam zarezerwowac");
	menu_gui::add_top_text("");
	menu_gui::add_top_text("ilosc osob | pietro | standard | powierzchnia || cena za dobe");
	for (int i = 0; i < numberOfRooms; i++)
	{
		bool isThisRoomFree = true;
		for (int j = 0; j < numberOfDays; j++)
		{
			if (rooms[i].getIsOccupied(daysFromNewYear + j) == true)
				isThisRoomFree = false;
		}
		if (isThisRoomFree == true)
		{
			menu_gui::add_option(roomToString(rooms[i]));
			availaibleRooms[availaibleRoomscounter] = &rooms[i];
			availaibleRoomscounter++;
		}
	}
	menu_gui::add_option("Paaaaanie nie stac mnie");


	if (availaibleRoomscounter < 1) // save_check: czy nie ma ¿adnych wolnych pokoi
	{
		menu_gui::reset();
		menu_gui::add_top_text("Niestety nie ma wolnych pokoi w podanym terminie");
		menu_gui::add_option("Wroc");
		menu_gui::display();
		return NULL;
	}

	int choosenRoom = menu_gui::display();
	if (choosenRoom == availaibleRoomscounter)	//wybrano opcjê wróæ
	{
		return NULL;
	}
	else
	{
		return availaibleRooms[choosenRoom];
	}
}

Reservation Receptionist::reservation(Room p, int startingDate, int endingDate) {
	throw "Not yet implemented";
}