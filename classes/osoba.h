#include <string>

#ifndef __osoba_h__
#define __osoba_h__

class osoba;

class osoba
{
	private: string _imie[2];
	private: string _nazwisko;
	private: int _data_urodzenia;
	private: string _email;
	private: string _has這;
	private: bool _czy_zalogowany;

	public: bool logowanie(string aString_email, string aString_has這);

	public: bool zmien_has這(string aString_has這, string aString_nowe_has這);

	public: void wylogowanie();

	public: osoba(string aString_Imie, string aString_Nazwisko, string aInt_Data_Urodzenia, string aString_email);

	public: string* getImie();

	public: void setImie(string aImie, string bImie);

	public: string getNazwisko();

	public: void setNazwisko(string aNazwisko);

	public: int getData_urodzenia();

	public: void setData_urodzenia(int aData_urodzenia);

	public: string getEmail();

	public: void setEmail(string aEmail);
};

#endif
