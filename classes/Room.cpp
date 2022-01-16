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

	calculatePrice();
}

void Room::calculatePrice() {
	double outputPrice = 1;
	//numberOfPeople	(n-1)times +80%
	outputPrice *= (1 + (numberOfPeople - 1) * 0.8);
	//quality			1 -> 100%, 2 -> 130%, 3 -> 200%, >3 -> 300%
	switch (roomQuality)
	{
	case 0: 
		break;
	case 1:
		outputPrice *= 1.3;
		break;
	case 2:
		outputPrice *= 2;
		break;
	default:
		outputPrice *= 3;
		break;
	}
	//surfaceArea		1 -> 3*
	outputPrice *= (3 * surfaceArea);

	price = outputPrice;
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
double Room::getPrice() {
	return price;
}
int Room::getSurfaceArea() {
	return surfaceArea;
}
bool Room::getIsOccupied() {
	return isOccupied;
}