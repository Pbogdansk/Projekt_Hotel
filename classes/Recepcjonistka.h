#include <exception>
using namespace std;

#ifndef __Recepcjonistka_h__
#define __Recepcjonistka_h__

// #include "Pok�j.h"
#include "Rezerwacja.h"
#include "osoba.h"

class Pok�j;
class Rezerwacja;
// class osoba;
class Recepcjonistka;

class Recepcjonistka: public osoba
{

	public: Pok�j* sprawd�_dost�pno��(string aInt_data_od, string aInt_data_do);

	public: Rezerwacja rezerwacja(string aPok�j_p, string aInt_data_od, string aInt_data_do);
};

#endif
