//Ryan Routhier
// sortingNew.cpp : week 3 assignment
//06/05/2019
//CIS 1202
/* This program takes in address and tax data. It allows the user to pick options based off that data. Then it can search for a tax amount based off of the address typed in. It can 
then also sort the tax amounts in order. It finally display to the user who owes the most tax money.
*/

#include "pch.h"
#include <iostream>
#include<iomanip>
#include <string>
#include <fstream>
#include <cmath>

//prototypes
using namespace std;
void loadArrays(string[], double[], int);
void showArrays(string[], double[], int);
void lookUpTaxes(string[], double[], int);
void sortTaxes(string[], double[], int);
void biggestTaxes(string[], double[], int);


int main()
{
	int length = 0, i = 0, showMenu = 0;
	double amtDue[7];
	string address[7];
	//to load data into arrays
	loadArrays(address,amtDue,length);
	//main While loop to execute options for user
	while (showMenu != 5)
	{
		//Display Menu
		cout << "County Auditors Property Tax Sort and Search\n\n"
			 << "1: Display the property tax data\n"
			 << "2: Look up taxes for a particular address\n"			
			 << "3: Sort tax amounts into ascending order\n"
		   	 << "4: Display property with largest tax due\n"
			 << "5: Exit\n"
		     << "Please enter your selection: ";
		cin >> showMenu;
		//switch options given
		switch (showMenu)
		{
			//to show arrays to user
		case 1:
			showArrays(address, amtDue, length);
			break;
			//to look up specific address and tax
		case 2:
			lookUpTaxes(address, amtDue, length);
			break;
			//to sort taxes in order
		case 3:
			sortTaxes(address, amtDue, length);
			break;
			//to display who has the most taxes
		case 4:
			biggestTaxes(address, amtDue, length);
			break;
			//to exit program
		case 5:
			return 0;
			break;
			//for invalid input
		default:
			cout << "invlaid choice ? try again\n\n";
			break;
		}
	}
	
	return 0;
}

//to load data into array
void loadArrays(string address[], double amtDue[], int length)
{
	int i =0;
	ifstream inputFile("prog3");

	while (inputFile >> address[i] >> amtDue[i])
	{
		i++;
		length++;
	}

}
//to show array to user
void showArrays(string address[], double amtDue[], int length)
{
	int i = 0;
	length = 7;
	cout << "County Auditor Records\n\n";
	while (i < length)
	{
		cout << left <<setw(10)<< address[i] << " = " << amtDue[i] << endl;
		i++;
	}

}
//to look up taxes for specific address
void lookUpTaxes(string address[], double amtDue[], int length)
{
	string addressNum;
	int i =0;

	length = 0;
	cout << "Enter address to look up: ";
	cin >> addressNum;

	while (addressNum != address[i]) 
	{
		i++;
		length++;
	}
	cout << "The taxes for "<< address[i] << " - " << amtDue[i] << endl;
}
// to sort taxes in order
void sortTaxes(string address[], double amtDue[], int length)
{
	string temp;
	int startScan, maxIndex;
	double maxValue;
	length = 7;
	//loop to sort data in order
	for (startScan = 0; startScan < (length - 1); startScan++)
	{
		maxIndex = startScan;
		maxValue = amtDue[startScan];
		temp = address[startScan];
		for (int index = startScan + 1; index < length; index++)
		{
			if (amtDue[index] < maxValue)
			{
				maxValue = amtDue[index];
				temp = address[index];
				maxIndex = index;
			}
		}

		amtDue[maxIndex] = amtDue[startScan];
		address[maxIndex] = address[startScan];
		amtDue[startScan] = maxValue;
		address[startScan] = temp;
	}
}
//displays the most taxes
void biggestTaxes(string address[], double amtDue[], int length)
{
	double mostTax =0;
	string mostAddress;
	length = 7;
	for (int i = 0; i < length; i++)         //<-------------------------------------------------------------------------------------------------- This is Stuff that i added
	{                                        
		if (amtDue[i] > mostTax)
		{
			mostTax = amtDue[i];             
			mostAddress = address[i];
		}
	}
	cout << "The Largest tax amount - "<< mostTax<< " at " << mostAddress << endl; //<-------------------------------------------------------------end of stuff i added/changed
}
