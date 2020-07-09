//Ship class header file

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//creats the base class ShipClass
class ShipClass
{
	string shipName;
	int shipYear = 0;

public:
	//constructor
	ShipClass();
	ShipClass(string name, int year);

	//prototypes
	void displayShipInfo();

	//setters
	void setShipName(string name);
	void setShipYear(int year);

	//getters
	string getShipName() { return shipName; }
	int getShipYear() { return shipYear; }
	
	
};

