#include <exception>
#include <vector>
using namespace std;

#ifndef __Rezerwacja_h__
#define __Rezerwacja_h__

// #include "Klient.h"
// #include "zameldowanie.h"
#include "Recepcjonistka.h"
#include "Admin.h"
// #include "Pokój.h"

class Klient;
class zameldowanie;
class Recepcjonistka;
class Admin;
class Pokój;
class Rezerwacja;

class Rezerwacja
{
	private: int _data_od;
	private: int _data_do;
	private: bool _op³acone;
	public: Klient* _unnamed_Klient_;
	public: zameldowanie* _unnamed_zameldowanie_;
	public: std::vector<Recepcjonistka*> _unnamed_Recepcjonistka_;
	public: std::vector<Admin*> _unnamed_Admin_;
	public: Pokój* _unnamed_Pokój_;

	public: void zap³aæ(string aBool_rodzaj_platnosci);

	public: void anuluj_rezerwarcjê();
};

#endif
