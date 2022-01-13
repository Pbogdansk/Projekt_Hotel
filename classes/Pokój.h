#include <exception>
#include <vector>
using namespace std;

#ifndef __Pok�j_h__
#define __Pok�j_h__

#include "Rezerwacja.h"
// #include "Admin.h"

class Rezerwacja;
class Admin;
class Pok�j;

class Pok�j
{
	private: string _ilo��_os�b_int;
	private: int _pi�tro;
	private: int _standard;
	private: int _cena;
	private: int _powierzchnia;
	public: std::vector<Rezerwacja*> _unnamed_Rezerwacja_;
	public: Admin* _unnamed_Admin_;

	public: void oblicz_cene();
};

#endif
