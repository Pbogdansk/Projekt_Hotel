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

	if (totalDays2 - totalDays1 < 1)
		return -1;
	return totalDays2 - totalDays1;
}