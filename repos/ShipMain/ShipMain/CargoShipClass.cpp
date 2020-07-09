//Ryan
// CargoShipMain

#include <iostream>
#include <string>
#include "ShipClass.h"
#include "CargoShipClass.h"
#include "CruiseShipClass.h"
using namespace std;

//to set tonnage
void CargoShipClass::setShipTonnage(int tonnage)
{
	shipTonnage = tonnage;
}

//constructor to set name ,year and tonnage to a CargoShipClass class
CargoShipClass::CargoShipClass(string name, int year, int tonnage)
{
	setShipName(name);
	setShipYear(year);
	setShipTonnage(tonnage);

}

//to display the cargo ship information
void CargoShipClass::displayShipInfo()
{
	cout << "\nCargo Ship Information\n";
	ShipClass::ShipClass::displayShipInfo();
	cout << "Cargo Capacity: " << getShipTonnage() << endl << endl;
}

