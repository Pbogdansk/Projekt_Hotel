#include <exception>
#include <string>
using namespace std;

#ifndef __zameldowanie_h__
#define __zameldowanie_h__

// #include "Rezerwacja.h"

class Rezerwacja;
class zameldowanie;

class zameldowanie
{
	private: int _data_od;
	private: int _data_do;
	private: bool _czy_zameldowany;
	public: Rezerwacja* _unnamed_Rezerwacja_;

	public: void zamelduj(string aInt_data_od, string aData_do);

	public: void wymelduj();
};

#endif
