#include <exception>
#include <vector>
using namespace std;

#ifndef __Klient_h__
#define __Klient_h__

#include "Rezerwacja.h"
// #include "Pok�j.h"
#include "osoba.h"

class Rezerwacja;
class Pok�j;
// class osoba;
class Klient;

class Klient: public osoba
{
	public: std::vector<Rezerwacja*> _unnamed_Rezerwacja_;

	public: Pok�j* sprawd�_dost�pno��(string aInt_data_od, string aInt_data_do);

	public: Rezerwacja rezerwacja(string aPok�j_p, string aInt_data_od, string aInt_data_do);
};

#endif
