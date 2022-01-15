#include <exception>
#include <vector>
using namespace std;

#include "Room.h"
#include "Reservation.h"
#include "Admin.h"

Room::Room(int newNumberOfPeople, int newFloor, int newRoomQuality, int newSurfaceArea)
{
	numberOfPeople = newNumberOfPeople;
	floor = newFloor;
	roomQuality = newRoomQuality;
	surfaceArea = newSurfaceArea;

	price = calculatePrice(surfaceArea);
}

int Room::calculatePrice(int roomArea) {
	throw "Not yet implemented";
}

int Room::getNumberOfPeople() {
	return numberOfPeople;
}
int Room::getFloor() {
	return floor;
}
int Room::getRoomQuality() {
	return roomQuality;
}
int Room::getPrice() {
	return price;
}
int Room::getSurfaceArea() {
	return surfaceArea;
}
bool Room::getIsOccupied() {
	return isOccupied;
}