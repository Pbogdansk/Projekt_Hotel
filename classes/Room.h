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
	bool isOccupied = 0;

public:
	Room(int newNumberOfPeople, int newFloor, int newRoomQuality, int newSurfaceArea);

	int calculatePrice(int roomArea);
	
	int getNumberOfPeople();
	int getFloor();
	int getRoomQuality();
	int getPrice();
	int getSurfaceArea();
	bool getIsOccupied();
};

#endif
