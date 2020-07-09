//Cargo class header file

#include <iostream>
#include <string>
#include <iomanip>


using namespace std;

//creats a cargo ship class which also gets the base class ShipClass functions
class CargoShipClass : public ShipClass
{
	int shipTonnage;
	string shipName;
	int shipYear = 0;

public:
	//constructor
	CargoShipClass(string name, int year, int t);

	//prototypes
	void displayShipInfo();

	//setter
	void setShipTonnage(int tonnage);

	//getter
	int getShipTonnage() { return shipTonnage; }
};
