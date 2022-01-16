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
	findEmailAdressInGivenArray(allAccounts, numberOfAllAccounts, receivedEmailAdress);
}

int findEmailAdressInGivenArray(Person* allAccounts, int numberOfAccounts, string wantedEmail)
{
	return 0;
}