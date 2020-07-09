//Ryan Routhier
//6/16/2019
// ArraysAndMemory.cpp 
// This program takes 7 rentals given to you from the user and displays them and the computer memory address location of these rentals. It uses only pointers to display this information.
//It can also take the rentals and sort them in order as well as give the user the sum of all the rents.


#include "pch.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
//Allows user to enter his 7 places he has for rent
void enterRents(int *rentals, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Enter rent amount " << i + 1 << ":";
		cin >> *(rentals + i);
	}
}
// displays the properities as entered
void displayRents(int *rentals, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Rental property " << i + 1 << " " << *(rentals + i) << endl;

	}
	cout << endl;
}
//displays the memory location of the rentals
void displayMemoryLocations(int *rentals, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Memory address of cell " << i << " = " << &*(rentals + i)  << endl;

	}
}
//sorts the rentals in order
void selectionSort(int *rentals, int n)
{
	int min, temp;

	for (int i = 0; i < n - 1; i++)
	{
		min = i;

		for (int j = i + 1; j < n; j++)
		{
			if (*(rentals + j) < *(rentals + min))
				min = j;
			//min will keep track of the index
		}

		//if min no longer equals i than, then swap
		if (min != i)
		{
			temp = *(rentals + i);
			*(rentals + i) = *(rentals + min);
			*(rentals + min) = temp;
		}
	}
}
// to calculate the sum of all the rents entered
int sumRents(int *rentals, int n)
{
	int total = 0;
	for (int i = 0; i < n; i++)
	{
		total += *(rentals + i);
	}
	cout << "total rents = $" << total << endl << endl;
	return total;
}

int main()
{
	int getMenuItem = 0, rentals[7] { 1200, 740, 660, 1000, 550, 920, 1350 };
	int propertyCount = 7;
	// main while loop for menu 
	while (getMenuItem != 6)
	{
		//main switch to operate the menu
		cout << "Sinclair Property Management\n\n"
			<< "Select from the following menu\n"
			<< "1 Enter rent amounts\n"
			<< "2 Display rents\n"
			<< "3 Sort rent amounts\n"
			<< "4 Total rents\n"
			<< "5 Display rent array memory locations\n"
			<< "6 Exit program\n\n"
			<< "Enter Selection: ";
		cin >> getMenuItem;
		cout << endl;
		//switch
		switch (getMenuItem)
		{
		case 1:
			enterRents(rentals, propertyCount);
			break;
		case 2:
			displayRents(rentals, propertyCount);
			break;
		case 3:
			selectionSort(rentals, propertyCount);
			break;
		case 4:
			sumRents(rentals, propertyCount);
			break;
		case 5:
			displayMemoryLocations(rentals, propertyCount);
			break;
		case 6:
			return 0;
			break;
		default:
			cout << "Please enter a valid option\n";
			break;
		}
	}
}