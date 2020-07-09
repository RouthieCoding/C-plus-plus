//Ryan
// ShipMain program
//7/30/2019
/* This program creats a base class named ShipClass and then makes more classes(CargoShipClass and CruiseShipClass) with the inheritance of ShipClass.
The classes have getter and setter functions to record and output the information for each class properly. All classes have names and years built while only
CruiseShipClass can have a maximum passengers entered as well as only CargoShipClass can have it's tonnage capacity entered.
*/

#include <iostream>
#include <string>
#include "ShipClass.h"
#include "CargoShipClass.h"
#include "CruiseShipClass.h"
using namespace std;

int main()
{
	string shipName;
	int shipYear =0, passengers, tonnage;

	// To enter in ship information
	cout << "Ship\n\n";
	cout << "Please Enter Ship Name: ";
	getline(cin, shipName);
	cout << "Enter Enter Year Built: ";
	cin >> shipYear;

	//to create the ship class object
	ShipClass boat(shipName, shipYear);

	//to display the ship class
	cout << "\nShip Information\n";
	boat.displayShipInfo();

	// To enter in cruise ship information
	cin.ignore();
	cout << "\nCruise Ship\n\n";
	cout << "Please Enter Cruise Ship Name: ";
	getline(cin, shipName);
	cout << "Please Enter Year Built: ";
	cin >> shipYear;
	cout << "Please Enter maximum passenger capacity: ";
	cin >> passengers;

	//to create the cruise ship class object
	CruiseShipClass cruise(shipName, shipYear, passengers);

	//to display the cruise ship class
	cruise.displayShipInfo();

	// To enter in cargo ship information
	cin.ignore();
	cout << "Cargo Ship\n\n";
	cout << "Please Enter Cargo Ship Name: ";
	getline(cin, shipName);
	cout << "Please Enter Year Built: ";
	cin >> shipYear;
	cout << "Enter Enter cargo capacity in tonnage: ";
	cin >> tonnage;

	// to create the cargo ship class
	CargoShipClass cargo(shipName, shipYear, tonnage);

	//to display the cargo ship class
	cargo.displayShipInfo();

	//To show all boats
	cout << "\nShip Information\n";
	boat.displayShipInfo();
	cargo.displayShipInfo();
	cruise.displayShipInfo();
}

