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
	bool isOccupied;

public:
	Room(int newNumberOfPeople, int newFloor, int newRoomQuality, int newSurfaceArea, bool newIsOccupied);

	int calculatePrice(int roomArea);
	
	int getFloor();
};

#endif
