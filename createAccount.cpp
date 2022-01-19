#include "include.h"
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
#include <cstdlib>

void addingAccount(int* pointerCurrentNumberOfAccounts, Person* allAccounts[], int* pointerCurrentNumberOfCustomers, Customer* customersAccounts[],
	string newName, string newSurname, int newDateOfBirth, string newEmail, string newPassword) 
{
	Person newAccount = Person(newName, newSurname, newDateOfBirth, newEmail, newPassword);
	Person* temp = new Person[(*pointerCurrentNumberOfAccounts) + 1];
	std::copy(*allAccounts, *allAccounts + (*pointerCurrentNumberOfAccounts), temp);
	delete[] *allAccounts;
	*allAccounts = temp;
	//dodanie nowej rezerwacji
	*allAccounts[*pointerCurrentNumberOfAccounts] = newAccount;
	*pointerCurrentNumberOfAccounts += 1;


	Customer newCustomer = Customer(newName, newSurname, newDateOfBirth, newEmail, newPassword);
	Customer* temporaryCustomer = new Customer[(*pointerCurrentNumberOfCustomers) + 1];
	std::copy(*customersAccounts, *customersAccounts + (*pointerCurrentNumberOfCustomers), temp);
	delete[] * customersAccounts;
	*customersAccounts = temporaryCustomer;
	//dodanie nowej rezerwacji
	*customersAccounts[*pointerCurrentNumberOfCustomers] = newCustomer;
	*pointerCurrentNumberOfCustomers += 1;
}

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
	cout << endl << "Prosze podac panska date urodzenia" << endl;
	newDateOfBirth = inputInDateSystem();
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
		Sleep(4000);
	}
}