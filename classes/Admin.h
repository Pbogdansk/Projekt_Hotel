#include <exception>
using namespace std;

#ifndef __Admin_h__
#define __Admin_h__

// #include "Room.h"
#include "Person.h"

class Room;
// class Person;
class Admin;

class Admin: public Person
{
public:
	Admin();
	Admin(string newName, string newSurname, int newDateOfBirth, string newEmail, string newPassword = "");

	void addRoom(int numberOfPeople, int floor, int roomQuality, int surfaceArea);
	void removeRoom(Room p);
};

#endif
