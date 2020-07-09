//Ryan Routhier
//CustomerContactApp.cpp
// 6/30/2019
//This program allows a user to enter a customer into the system as well as both their home and business address. You can then view all the customers inputed into the system.
// Finally you can search through the records based on a first and last name to see if the customer is in the system.

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;
 
//makes a structure to save address
struct Address 
{
	string street, city, state, zip;
};
//makes structue to save customer data with an address
struct Customer
{
	string firstName, lastName;
	Address homeAddress, businessAddress;
};

//call to show address
void showAddress(Address a)
{
	cout << "\t" << a.street << " " << a.city << ", " << a.state << " " << a.zip << endl;
}
//call to show customer
void showCustomer(Customer x)
{
	cout << "customer name: " << x.firstName << " " << x.lastName << endl;
	cout << "Business Address: \n";
	showAddress(x.businessAddress);
	cout << "Home Address: \n";
	showAddress(x.homeAddress);
	
}
//function to get name and address data for the customer. It returns a customer data type. 
Customer getCustomer()
{
	Customer temp;

	//enter customer data in to record information
	cout << "Enter customer first name: ";
	cin >> temp.firstName;
	cout << "Enter customer last name: ";
	cin >> temp.lastName;
	cin.ignore();
	cout << "Enter Business Address\n"
		 <<"Enter street address: ";
	getline(cin, temp.businessAddress.street);
	cout << "Enter city: ";
	cin >> temp.businessAddress.city;
	cout << "Enter state: ";
	cin >> temp.businessAddress.state;
	cout << "Enter zip code: ";
	cin >> temp.businessAddress.zip;
	cin.ignore();
	cout << "Enter Home Address\n"
		<< "Enter street address: ";
	getline(cin, temp.homeAddress.street);
	cout << "Enter city: ";
	cin >> temp.homeAddress.city;
	cout << "Enter state: ";
	cin >> temp.homeAddress.state;
	cout << "Enter zip code: ";
	cin >> temp.homeAddress.zip;
	
	return temp;
}
// call to find a customer based on first and last name
void findCust(Customer x[], int size)
{
	string targetFirstName, targetLastName;
	bool findName=false;

	//allow user to input who they want to find in data 
	cout << "numCust = " << size << endl;
	cout << "Enter customer first name: ";
	cin >> targetFirstName;
	cout << "Enter customer last name: ";
	cin >> targetLastName;
	//resets findname to false
	findName = false;

	//searches for data based on first and last name
	for (int i = 0; i < size; i++)
	{
		//if the first and last name are found out the information
		if (targetFirstName == x[i].firstName && targetLastName == x[i].lastName)
		{
			cout << "Found him\n";
			showCustomer(x[i]);
			findName = true;
		}

	}
	// if not found outputs not found
	if (findName != true)
	{
		cout << "Customer not found" << endl;
	}
}
int main()
{
	const int SIZE = 20;
	Customer customerData[SIZE];
	int size = 0;
	int menuChoice = 0;
	bool loopBreak = false;
	
	//main loop to run program
	while (loopBreak != true)
	{
	// menu to show options to user
	cout << "Customer Contacts Menu\n\n"
		 << "Select from the list Below\n\n"
		 << "1: Enter new customer\n"
		 << "2: Display all Customers \n"
		 << "3: Display a particular customer \n"
		 << "4: Exit program \n" << endl;
	 
	//allows user to enter choice
		cin >> menuChoice;
		//uses user choice to select an option
		switch (menuChoice)
		{
			//calls function to enter in new customer
		case 1: customerData[size] = getCustomer();
			size++;
			break;
		case 2:  
			//calls function to show all data from customers in the program
			for (int i = 0; i < size; i++)
			{
				showCustomer(customerData[i]);
			}
			break;
			//calls function to find a customer
		case 3: findCust(customerData, size);
			break;
		case 4: 
			// ends program
			loopBreak = true;
			break;
		default:
			//validates that a user has made a valid selection
			cout << "Invalid choice, please re-enter" << endl;
		}
	}
	
	return 0;

}