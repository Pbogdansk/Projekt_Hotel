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
	double price;
	int surfaceArea;
	bool isOccupied = 0;

public:
	Room(int newNumberOfPeople=0, int newFloor=0, int newRoomQuality=0, int newSurfaceArea=0);

	void calculatePrice();
	
	int getNumberOfPeople();
	int getFloor();
	int getRoomQuality();
	double getPrice();
	int getSurfaceArea();
	bool getIsOccupied();
};

#endif
