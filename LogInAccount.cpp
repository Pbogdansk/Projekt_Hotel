#include "include.h"
#include <Windows.h>
int findEmailAdressInGivenArray(Person* allAccounts, int numberOfAccounts, string wantedEmail);

bool logInAccount(Person* allAccounts, int numberOfAllAccounts)
{
	string receivedEmailAdress, receivedPassword;
	system("cls");// czyszczenie ekranu ;p
	cout << "Logowanie w aplikacji hotelu" << endl << endl;
	cout << "adres email: ";
	cin >> receivedEmailAdress;
	cout << "haslo:       ";
	cin >> receivedPassword;
	int indexOfGivenEmail = findEmailAdressInGivenArray(allAccounts, numberOfAllAccounts, receivedEmailAdress);
	if (indexOfGivenEmail != -1)	//znaleziono
	{
		if (allAccounts[indexOfGivenEmail].logIn(receivedEmailAdress, receivedPassword) == true)
		{
			currentlyLoggedIn = allAccounts[indexOfGivenEmail];
			return true;
		}
		else
		{
			//nie udalo sie
		}
	}
	else	//nie znaleziono
	{
		return false;
	}
}

int findEmailAdressInGivenArray(Person* allAccounts, int numberOfAccounts, string wantedEmail)
{
	for (int i = 0; i < numberOfAccounts; i++)
	{
		if (allAccounts[i].getEmail() == wantedEmail)
			return i;
	}
	menu_gui::reset();
	menu_gui::add_top_text("Niestety nie ma w naszej bazie konta o podanym adresie e-mail");
	menu_gui::add_option("Przejdz do menu");
	menu_gui::display();
	return -1;	//nie znaleziono �adnego pasuj�cego adresu email
}