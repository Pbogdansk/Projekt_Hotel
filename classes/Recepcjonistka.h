#include <exception>
using namespace std;

#ifndef __Recepcjonistka_h__
#define __Recepcjonistka_h__

// #include "Pokój.h"
#include "Rezerwacja.h"
#include "osoba.h"

class Pokój;
class Rezerwacja;
// class osoba;
class Recepcjonistka;

class Recepcjonistka: public osoba
{

	public: Pokój* sprawdŸ_dostêpnoœæ(string aInt_data_od, string aInt_data_do);

	public: Rezerwacja rezerwacja(string aPokój_p, string aInt_data_od, string aInt_data_do);
};

#endif
