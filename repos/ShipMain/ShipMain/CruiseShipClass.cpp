//Ryan
// CruiseShipMain

#include <iostream>
#include <string>
#include "ShipClass.h"
#include "CargoShipClass.h"
#include "CruiseShipClass.h"
using namespace std;

//to set passengers
void CruiseShipClass::setShipPassengers(int passengers)
{
	shipPassengers = passengers;
}

//constructor to set name ,year and passengers to a CruiseShipClass class
CruiseShipClass::CruiseShipClass(string name, int year, int passengers)
{
	setShipName(name);
	setShipYear(year);
	setShipPassengers(passengers);
}

//to display the cruise ship information
void CruiseShipClass::displayShipInfo()
{
	cout << "\nCruise Ship Information\n";
	ShipClass::ShipClass::displayShipInfo();
	cout << "Maximum Passengers: " << getShipPassengers() << endl << endl;
}