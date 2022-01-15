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
	private: string _numberOfPeople_int;
	private: int _floor;
	private: int _roomQuality;
	private: int _price;
	private: int _surfaceArea;
	public: std::vector<Reservation*> _unnamed_Reservation_;
	public: Admin* _unnamed_Admin_;

	public: void calculatePrice();
	public: Room(int floor, int roomQuality, int surfaceArea);
	public: int getFloor();
};

#endif
