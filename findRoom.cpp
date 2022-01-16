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

	return 0;
}