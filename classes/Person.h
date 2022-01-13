#include <exception>
#include <string>
using namespace std;

#ifndef __Person_h__
#define __Person_h__

class Person;

class Person
{
	private: string _name[2];
	private: string _surname;
	private: int _dateOfBirth;
	private: string _email;
	private: string _password;
	private: bool _isLogged;

	enum typeOfAccount { Customer = 0, Receptionist = 1, Admin = 2 };
	private: typeOfAccount _permissions;

	public: int getPermissions();

	public: bool logIn(string aString_email, string aString_password);

	public: bool changePassword(string aString_password, string aString_newPassword);

	public: void logOut();

	public: void person(string aString_name, string aString_surname, string aInt_dateOfBirth, string aString_email);

	public: string* getName();

	public: void setName(string aName, string bName );

	public: string getSurename();

	public: void setSurename(string aSurename);

	public: int getDateOfBirth();

	public: void setDateOfBirth(int aDateOfBirth);

	public: string getEmail();

	public: void setEmail(string aEmail);
};

#endif
