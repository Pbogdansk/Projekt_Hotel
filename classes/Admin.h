#include <exception>
using namespace std;

#ifndef __Admin_h__
#define __Admin_h__

// #include "Pok�j.h"
#include "osoba.h"

class Pok�j;
// class osoba;
class Admin;

class Admin: public osoba
{
	public: Pok�j* _unnamed_Pok�j_;

	public: void dodaj_pok�j(string aInt_ilosc_os�b, string aInt_pi�tro, string aInt_standard, string aInt_powierzchnia);

	public: void usu�_pok�j(string aPok�j);
};

#endif
