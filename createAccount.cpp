#include "include.h"

void createAccount(Customer customersAccounts[]) {
	string newName;
	string newSurname;
	int newDateOfBirth;
	string newEmail;
	string newPassword, newPassword2;
	system("cls");		// czyszczenie ekranu (wed³ug Rafa³a przynajmniej)
	cout << "Prosze podac panskie imie: ";
	cin >> newName;
	cout << endl << "Prosze podac panskie nazwisko: ";
	cin >> newSurname;
	cout << endl << "Prosze podac panska date urodzenia w formacie (ddnnrrrr): ";
	cin >> newDateOfBirth;								//Crush, gdy przyjmie s³owo
	cout << endl << "Prosze podac panski adres e-mail: ";
	cin >> newEmail;
	cout << endl << "Prosze podac panskie haslo ";
	cin >> newPassword;
	cout << "Porsze powtorzyc haslo: ";
	cin >> newPassword2;
	
	if (newPassword == newPassword2) {
		customersAccounts[9] = Customer(newName, newSurname, newDateOfBirth, newEmail, newPassword);
		cout << "Dziekujemy za stworzenie konta w naszym hotelu" << endl;
	}
	else {
		cout << "Podane hasla nie pokrywaja sie, prosze powtorzyc probe tworzenia konta" << endl;
	}
}