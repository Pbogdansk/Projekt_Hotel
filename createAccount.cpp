#include "include.h"

void createAccount(Customer customersAccounts[]) {
	string newName;
	string newSurname;
	int newDateOfBirth;
	string newEmail;
	string newPassword;
	system("cls");		// czyszczenie ekranu (wed³ug Rafa³a przynajmniej)
	cout << "Prosze podac panskie imie: ";
	cin >> newName;
	cout << endl << "Prosze podac panskie nazwisko: ";
	cin >> newSurname;
	cout << endl << "Prosze podac panska date urodzenia: ";
	cin >> newDateOfBirth;
	cout << endl << "Prosze podac panski adres e-mail: ";
	cin >> newEmail;
	cout << endl << "Prosze podac panskie haslo ";
	cin >> newPassword;

	customersAccounts[11] = Customer(newName, newSurname, newDateOfBirth, newEmail, newPassword);
}