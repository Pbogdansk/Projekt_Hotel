#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include <exception>

#include "classes/Admin.h"
#include "classes/BookIn.h"
#include "classes/Customer.h"
#include "classes/Person.h"
#include "classes/Receptionist.h"
#include "classes/Room.h"
#include "classes/Reservation.h"

void menu_admin(Admin account, Room*& rooms, int* pointerCurrentNumberOfRooms);
void menu_receptionist(Receptionist account, Room*& rooms, int numberOfRooms, Reservation*& reservations, int* pointerCurrentNumberOfReservations);
void menu_customer(Customer account, Room*& rooms, int numberOfRooms, Reservation*& reservations, int* pointerCurrentNumberOfReservations);

bool logInAccount(Person* allAccounts, int numberOfAllAccounts);

enum typeOfAccount { permCustomer = 0, permReceptionist = 1, permAdmin = 2 };
extern Room* rooms;
extern Person currentlyLoggedIn;
extern void initializeWithDefaultValues(Customer*, Receptionist*, Admin*);
//extern void assignAllAccountsToOneVariable(Person* allAccounts, Customer* customersAccounts, Receptionist* receptionistsAccounts, Admin* adminsAccounts);
void assignAllAccountsToOneVariable(Person* allAccounts, Customer* customersAccounts, Receptionist* receptionistsAccounts, Admin* adminsAccounts, int numberOfAllAccounts, int numberOfCustomersAccounts, int numberOfReceptionistsAccounts, int numberOfAdminsAccounts);
extern void initializeRoomsWithDefaultValues(Room* rooms, int numberOfRooms);
extern int substractDates(int date1, int date2);
extern string roomToString(Room room);

void createAccount(int* pointerCurrentNumberOfAccounts, Person*& allAccounts, int* pointerCurrentNumberOfCustomers, Customer*& customersAccounts);

void makePayment(Reservation*& reservations, int* pointerCurrentNumberOfReservations);
void makePaymentCustomer(Reservation*& reservations, int* pointerCurrentNumberOfReservations, Reservation*& customersReservation);
//options:
//0 (default):  01.01.2022
//1			 :	01 stycznia 2022
string dateToString(int date, int option = 0);
int inputInDateSystem();
void cancelReservation(Reservation*& reservations, int* pointerCurrentNumberOfReservations);
void cancelReservationCustomer(Reservation*& reservations, int* pointerCurrentNumberOfReservations, Reservation*& customersReservation);

using namespace std;
namespace menu_gui
{
    //text above options selection     to add use 'add_top_text(string)'
    void add_top_text(string input);
    //text below options selection     to add use 'add_bottom_text(string)'
    void add_option(string input);
    //user's options to choose from    to add use 'add_option(string)'
    void add_bottom_text(string input);
    //reseting top_text, bottom_textand all options   'reset()'
    void reset();
    //show menu_gui, RETURNs index of choosen option(0, 1, 2..)
    //to navigate thru menu use arrows(up, down->choose option) (right, enter->accept)
    int display(int position_in = 0);
}