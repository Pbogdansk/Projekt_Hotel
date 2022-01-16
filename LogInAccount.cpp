#include "include.h"
int findEmailAdressInGivenArray(Person* allAccounts, int numberOfAccounts, string wantedEmail);

void logInAccount(Person* allAccounts, int numberOfAllAccounts)
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
			//udalo sie zalogowac
		}
		else
		{
			//nie udalo sie
		}
	}
	else	//nie znaleziono
	{

	}

}

int findEmailAdressInGivenArray(Person* allAccounts, int numberOfAccounts, string wantedEmail)
{
	for (int i = 0; i < numberOfAccounts; i++)
	{
		if (allAccounts[i].getEmail() == wantedEmail)
			return i;
	}
	return -1;	//nie znaleziono �adnego pasuj�cego adresu email
}