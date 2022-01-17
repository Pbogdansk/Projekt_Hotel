#include <exception>
#include <string>
using namespace std;

#ifndef __Person_h__
#define __Person_h__

class Person
{
protected:
	string name[2];
	string surname;
	int dateOfBirth;
	string email;
	string password;
	bool isLogged;
	int index;

	enum typeOfAccount { permCustomer = 0, permReceptionist = 1, permAdmin = 2 };
	typeOfAccount permissions;

public:
	Person(string newName, string newSurname, int newDateOfBirth, string newEmail, string newPassword = "");
	Person();

	string* getName();
	string get2Name();
	string getSurname();
	int getDateOfBirth();
	string getEmail();
	int getPermissions();
	bool getIsLogged();
	int getIndex();

	void setName(string aName, string bName );
	void setSurname(string newSurname);
	void setDateOfBirth(int newDateOfBirth);
	void setEmail(string newEmail);
	void setIndex(int aIndex);

	bool changePassword(string currentPassword, string newPassword);

	bool logIn(string aString_email, string aString_password);
	void logOut();
};

#endif
