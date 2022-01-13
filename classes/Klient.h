#include <exception>
#include <vector>
using namespace std;

#ifndef __Klient_h__
#define __Klient_h__

#include "Rezerwacja.h"
// #include "Pokój.h"
#include "osoba.h"

class Rezerwacja;
class Pokój;
// class osoba;
class Klient;

class Klient: public osoba
{
	public: std::vector<Rezerwacja*> _unnamed_Rezerwacja_;

	public: Pokój* sprawdŸ_dostêpnoœæ(string aInt_data_od, string aInt_data_do);

	public: Rezerwacja rezerwacja(string aPokój_p, string aInt_data_od, string aInt_data_do);
};

#endif
