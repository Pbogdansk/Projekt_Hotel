#include "include.h"

int substractDates(int date1, int date2)
{
	cout << date1 << endl;
	int year1 = date1 % 10000;
	date1 /= 10000;
	int month1 = date1 % 100;
	date1 /= 100;
	int day1 = date1;

	int year2 = date2 % 10000;
	date2 /= 10000;
	int month2 = date2 % 100;
	date2 /= 100;
	int day2 = date2;

	int totalDays1 = day1;
	switch (month1)
	{
	case 12:
		totalDays1 += 30;	//caly listopad
	case 11:
		totalDays1 += 31;	//caly pazdziernik
	case 10:
		totalDays1 += 30;	//caly wrzesien
	case 9:
		totalDays1 += 31;	//caly sierpien
	case 8:
		totalDays1 += 31;	//caly lipiec
	case 7:
		totalDays1 += 30;	//caly czerwiec
	case 6:
		totalDays1 += 31;	//caly maj
	case 5:
		totalDays1 += 30;	//caly kwiecien
	case 4:
		totalDays1 += 31;	//caly marzec
	case 3:
		totalDays1 += 28;	//caly luty
	case 2:
		totalDays1 += 31;	//caly styczen
	}
	for (int i = 0; i < year1-2022;i++)
		totalDays1 += 365;

	int totalDays2 = day2;
	switch (month2)
	{
	case 12:
		totalDays2 += 30;	//caly listopad
	case 11:
		totalDays2 += 31;	//caly pazdziernik
	case 10:
		totalDays2 += 30;	//caly wrzesien
	case 9:
		totalDays2 += 31;	//caly sierpien
	case 8:
		totalDays2 += 31;	//caly lipiec
	case 7:
		totalDays2 += 30;	//caly czerwiec
	case 6:
		totalDays2 += 31;	//caly maj
	case 5:
		totalDays2 += 30;	//caly kwiecien
	case 4:
		totalDays2 += 31;	//caly marzec
	case 3:
		totalDays2 += 28;	//caly luty
	case 2:
		totalDays2 += 31;	//caly styczen
	}
	for (int i = 0; i < year2 - 2022;i++)
		totalDays2 += 365;

	if (totalDays2 - totalDays1 < 0)
		return -1;
	return totalDays2 - totalDays1;
}

string roomToString(Room room)
{
	/*
	int numberOfPeople;
	int floor;
	int roomQuality;
	double price;
	int surfaceArea;
	//bool isOccupied = false;
	bool isOccupied[365] = { false };
	*/
	//cout << "ilosc osob | pietro | standard | powierzchnia || cena za dobe" << endl;

	string result = "        ";
	if (room.getNumberOfPeople() < 10)	//taktyczna spacja jeœli mniejsze ni¿ 10
		result += " ";
	result += to_string(room.getNumberOfPeople());
	result += " |     ";
	if (room.getFloor() < 10)	//taktyczna spacja jeœli mniejsze ni¿ 10
		result += " ";
	result += to_string(room.getFloor());
	result += " |        ";
	result += to_string(room.getRoomQuality());
	result += " |          ";
	if (room.getSurfaceArea() < 100)	//taktyczna spacja jeœli mniejsze ni¿ 100
		result += " ";
	if (room.getSurfaceArea() < 10)	//taktyczna spacja jeœli mniejsze ni¿ 10
		result += " ";
	result += to_string(room.getSurfaceArea());
	result += " ||        ";
	if (room.getPrice() < 1000)	//taktyczna spacja jeœli mniejsze ni¿ 1000
		result += " ";
	if (room.getPrice() < 100)	//taktyczna spacja jeœli mniejsze ni¿ 100
		result += " ";
	if (room.getPrice() < 10)	//taktyczna spacja jeœli mniejsze ni¿ 10
		result += " ";
	result += to_string(static_cast <int> (room.getPrice()));

	return result;
}

//options:
//0 (default):  01.01.2022
//1			 :	01 stycznia 2022
string dateToString(int date, int option)
{
	int year = date % 10000;
	date /= 10000;
	int month = date % 100;
	date /= 100;
	int day = date;

	string output = "";
	switch (option)
	{
	case 1:
		if (day < 10)
			output += "0";
		output += to_string(day) + " ";
		switch (month)
		{
		case 1:
			output += "stycznia";
			break;
		case 2:
			output += "lutego";
			break;
		case 3:
			output += "marca";
			break;
		case 4:
			output += "kwietnia";
			break;
		case 5:
			output += "maja";
			break;
		case 6:
			output += "czerwca";
			break;
		case 7:
			output += "lipca";
			break;
		case 8:
			output += "sierpnia";
			break;
		case 9:
			output += "wrzesnia";
			break;
		case 10:
			output += "pazdziernika";
			break;
		case 11:
			output += "listopada";
			break;
		case 12:
			output += "grudnia";
			break;
		}
		output += " " + to_string(year);
		break;

	default:
		if (day < 10)
			output += "0";
		output += to_string(day) + ".";
		if (month < 10)
			output += "0";
		output += to_string(month) + ".";
		output += to_string(year);
		break;
	}
	return output;
}

int inputInDateSystem()
{
	int day, month, year, output;
	cout << "dzien:   ";
	cin >> day;
	cout << "miesiac: ";
	cin >> month;
	cout << "rok:     ";
	cin >> year;
	output = year;
	output += month * 10000;
	output += day * 1000000;
	
	return output;
}