#include <exception>

using namespace std;

#include "Receptionist.h"
#include "Room.h"
#include "Reservation.h"
#include "Person.h"
#include <iostream>
extern int substractDates(int date1, int date2);
extern string roomToString(Room room);

Receptionist::Receptionist(){}
Receptionist::Receptionist(string newName, string newSurname, int newDateOfBirth, string newEmail, string newPassword) {
	name[0] = newName;
	surname = newSurname;
	dateOfBirth = newDateOfBirth;
	email = newEmail;
	password = newPassword;
	permissions = permReceptionist;
}

Room Receptionist::checkAvailability(int startingDate, int endingDate, Room* rooms, int numberOfRooms) {	//returns pokoj do rezerwacji
	
	int daysFromNewYear = substractDates(01012022, startingDate);
	int numberOfDays = substractDates(startingDate, endingDate);
	if (numberOfDays == -1)
		throw "zla data";
	//cout << "from " << startingDate << " to " << endingDate << " is " << numberOfDays << " days" << endl;

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
			roomToString(rooms[i]);
			cout << "pokoj nr." << i+1 << " jest wolny" << endl;
		}
	}
	return Room();
}

Reservation Receptionist::reservation(Room p, int startingDate, int endingDate) {
	throw "Not yet implemented";
}