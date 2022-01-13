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
	public: Room* _unnamed_Room_;

	public: void addRoom(string aInt_numberOfPeople, string aInt_floor, string aInt_roomQuality, string aInt_surfaceArea);

	public: void removeRoom(string aRoomj);
};

#endif
