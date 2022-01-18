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

	void changeSomeonesPassword(Person someone, string newPassword);
	void changeSomeonesName(Person someone, string newName, string newName2);
	void changeSomeonesSurname(Person someone, string newSurname);
	void changeSomeonesDateOfBirth(Person someone, int newDateOfBirth);
	void changeSomeonesEmail(Person someone, string newEmail);
};

#endif
