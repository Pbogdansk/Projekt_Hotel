#include <exception>
using namespace std;

#ifndef __Admin_h__
#define __Admin_h__

// #include "Pokój.h"
#include "osoba.h"

class Pokój;
// class osoba;
class Admin;

class Admin: public osoba
{
	public: Pokój* _unnamed_Pokój_;

	public: void dodaj_pokój(string aInt_ilosc_osób, string aInt_piêtro, string aInt_standard, string aInt_powierzchnia);

	public: void usuñ_pokój(string aPokój);
};

#endif
