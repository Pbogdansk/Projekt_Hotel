#include <exception>
#include <vector>
using namespace std;

#ifndef __Rezerwacja_h__
#define __Rezerwacja_h__

// #include "Klient.h"
// #include "zameldowanie.h"
#include "Recepcjonistka.h"
#include "Admin.h"
// #include "Pok�j.h"

class Klient;
class zameldowanie;
class Recepcjonistka;
class Admin;
class Pok�j;
class Rezerwacja;

class Rezerwacja
{
	private: int _data_od;
	private: int _data_do;
	private: bool _op�acone;
	public: Klient* _unnamed_Klient_;
	public: zameldowanie* _unnamed_zameldowanie_;
	public: std::vector<Recepcjonistka*> _unnamed_Recepcjonistka_;
	public: std::vector<Admin*> _unnamed_Admin_;
	public: Pok�j* _unnamed_Pok�j_;

	public: void zap�a�(string aBool_rodzaj_platnosci);

	public: void anuluj_rezerwarcj�();
};

#endif
