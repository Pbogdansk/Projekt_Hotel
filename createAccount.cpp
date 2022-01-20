#include "include.h"
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
#include <cstdlib>

void addingAccount(int* pointerCurrentNumberOfAccounts, Person*& allAccounts, int* pointerCurrentNumberOfCustomers, Customer*& customersAccounts,
	string newName, string newSurname, int newDateOfBirth, string newEmail, string newPassword) 
{
	Person* temporaryAllAccounts = new Person[(*pointerCurrentNumberOfAccounts) + 1];
	std::copy(allAccounts, allAccounts + (*pointerCurrentNumberOfAccounts), temporaryAllAccounts);
	delete[] allAccounts;
	allAccounts = temporaryAllAccounts;

	Customer newCustomer = Customer(newName, newSurname, newDateOfBirth, newEmail, newPassword);
	Customer* temporaryCustomer = new Customer[(*pointerCurrentNumberOfCustomers) + 1];
	std::copy(customersAccounts, customersAccounts + (*pointerCurrentNumberOfCustomers), temporaryCustomer);
	delete[] customersAccounts;
	customersAccounts = temporaryCustomer;
	//dodanie nowego konta klienta
	customersAccounts[*pointerCurrentNumberOfCustomers] = newCustomer;
	*pointerCurrentNumberOfCustomers += 1;
	*pointerCurrentNumberOfAccounts += 1;
}

void createAccount(int* pointerCurrentNumberOfAccounts, Person*& allAccounts,
	int* pointerCurrentNumberOfCustomers, Customer*& customersAccounts)
{
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
		addingAccount(pointerCurrentNumberOfAccounts, allAccounts, pointerCurrentNumberOfCustomers, customersAccounts,
			newName, newSurname, newDateOfBirth, newEmail, newPassword);
		menu_gui::reset();
		menu_gui::add_top_text("Dziekujemy za stworzenie konta w naszym hotelu");
		menu_gui::add_option("Przejdz do menu");
		menu_gui::display();
	}
	else {
		menu_gui::reset();
		menu_gui::add_top_text("Podane hasla nie pokrywaja sie, prosze powtorzyc probe tworzenia konta");
		menu_gui::add_option("Przejdz do menu");
		menu_gui::display();
	}
}