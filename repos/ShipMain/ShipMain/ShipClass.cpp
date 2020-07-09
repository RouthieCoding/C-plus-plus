//Ryan
// ShipMain

#include <iostream>
#include <string>
#include "ShipClass.h"
#include "CargoShipClass.h"
#include "CruiseShipClass.h"
using namespace std;

//to set string name
void ShipClass::setShipName(string name)
{
	shipName = name;
}
//to set ship year
void ShipClass::setShipYear(int year)
{
	shipYear = year;
}
//constructor to set name and year to a shipclass class 
ShipClass::ShipClass(string name, int year)
{

	setShipName(name);
	setShipYear(year);

}

//program wanted me to have a base constructor so i made one and made it do nothing
ShipClass::ShipClass()
{
}
//to display the ship information
void ShipClass::displayShipInfo()
{
	cout << "\nShip Name: " << getShipName() << endl << "Year Built: " << getShipYear() << endl;
}

