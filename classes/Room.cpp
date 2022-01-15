#include <exception>
#include <vector>
using namespace std;

#include "Room.h"
#include "Reservation.h"
#include "Admin.h"

void Room::calculatePrice() {
	throw "Not yet implemented";
}

Room::Room(int floor = 0, int roomQuality=0, int surfaceArea=0)
{
	_floor = floor;
}

int Room::getFloor() {
	return _floor;
}