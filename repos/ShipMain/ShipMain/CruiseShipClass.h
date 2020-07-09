//Cruise class header file

#include <iostream>
#include <string>
#include <iomanip>
//#include "ShipClass.h"

using namespace std;

//creats a cruise ship class which also gets the base class ShipClass functions
class CruiseShipClass : public ShipClass
{
	int shipPassengers;
	string shipName;
	int shipYear = 0;

public:
	//constructor
	CruiseShipClass(string name, int year, int passengers);

	//prototypes
	void displayShipInfo();

	//setter
	void setShipPassengers(int passengers);

	int getShipPassengers() { return shipPassengers; }
};
