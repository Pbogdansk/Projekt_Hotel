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

	bool changeSomeonesPassword(Person*& someone, string newPassword);
	bool changeSomeonesName(Person*& someone, string newName, string newName2);
	bool changeSomeonesSurname(Person*& someone, string newSurname);
	bool changeSomeonesDateOfBirth(Person*& someone, int newDateOfBirth);
	bool changeSomeonesEmail(Person*& someone, string newEmail);
};

#endif
