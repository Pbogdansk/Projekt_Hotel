#include <exception>
#include <vector>
using namespace std;

#include "Room.h"
#include "Reservation.h"
#include "Admin.h"

int Room::calculatePrice(int roomArea) {
	throw "Not yet implemented";
}

Room::Room(int newNumberOfPeople, int newFloor, int newRoomQuality, int newSurfaceArea, bool newIsOccupied)
{
	numberOfPeople = newNumberOfPeople;
	floor = newFloor;
	roomQuality = newRoomQuality;
	surfaceArea = newSurfaceArea;
	isOccupied = newIsOccupied;

	price = calculatePrice(surfaceArea);
}

int Room::getFloor() {
	return floor;
}