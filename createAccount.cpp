#include "include.h"
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
#include <cstdlib>

void createAccount(Customer customersAccounts[]) {
	string newName;
	string newSurname;
	int newDateOfBirth;
	string newEmail;
	string newPassword, newPassword2;
	system("cls");		// czyszczenie ekranu (wed�ug Rafa�a przynajmniej)
	cout << "Prosze podac panskie imie: ";
	cin >> newName;
	cout << endl << "Prosze podac panskie nazwisko: ";
	cin >> newSurname;
	cout << endl << "Prosze podac panska date urodzenia w formacie (ddnnrrrr): ";
	cin >> newDateOfBirth;								//Crush, gdy przyjmie s�owo
	cout << endl << "Prosze podac panski adres e-mail: ";
	cin >> newEmail;
	cout << endl << "Prosze podac panskie haslo ";
	cin >> newPassword;
	cout << endl << "Porsze powtorzyc haslo: ";
	cin >> newPassword2;
	
	if (newPassword == newPassword2) {
		customersAccounts[9] = Customer(newName, newSurname, newDateOfBirth, newEmail, newPassword);
		cout << endl << "Dziekujemy za stworzenie konta w naszym hotelu" << endl;
		Sleep(2000);
	}
	else {
		cout << endl << "Podane hasla nie pokrywaja sie, prosze powtorzyc probe tworzenia konta" << endl;
		Sleep(2000);
	}
}