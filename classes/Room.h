#include <exception>
#include <vector>
using namespace std;

#ifndef __Room_h__
#define __Room_h__

#include "Reservation.h"
// #include "Admin.h"

class Reservation;
class Admin;
class Room;

class Room
{
private:
	int numberOfPeople;
	int floor;
	int roomQuality;
	int price;
	int surfaceArea;
	//bool isOccupied = false;
	bool isOccupied[365] = { false };

public:
	Room(int newNumberOfPeople=0, int newFloor=0, int newRoomQuality=0, int newSurfaceArea=0);

	void calculatePrice();
	
	int getNumberOfPeople();
	int getFloor();
	int getRoomQuality();
	int getPrice();
	int getSurfaceArea();
	bool getIsOccupied(int dateToCheck);

	friend class Reservation;
};

#endif
