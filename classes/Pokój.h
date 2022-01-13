#include <exception>
#include <vector>
using namespace std;

#ifndef __Pokój_h__
#define __Pokój_h__

#include "Rezerwacja.h"
// #include "Admin.h"

class Rezerwacja;
class Admin;
class Pokój;

class Pokój
{
	private: string _iloœæ_osób_int;
	private: int _piêtro;
	private: int _standard;
	private: int _cena;
	private: int _powierzchnia;
	public: std::vector<Rezerwacja*> _unnamed_Rezerwacja_;
	public: Admin* _unnamed_Admin_;

	public: void oblicz_cene();
};

#endif
