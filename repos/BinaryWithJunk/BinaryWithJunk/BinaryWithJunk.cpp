// BinaryFile.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int DESC_SIZE = 40;

struct Product
{
	long prodNum;
	char prodName[DESC_SIZE];
	double price;
	int qty;
};

int showMenu(int menu)
{
	cout << "1 - Display product inventory\n"
		<< "2 - Display a particular product\n"
		<< "3 - Modify a product\n"
		<< "4 - Exit program\n\n"
		<< "Enter menu choice";
	cin >> menu;
	return menu;
}

void makeFile(fstream &inventory)
{
	long prodNum[11] = { 1101, 1102, 1103, 1104, 1105, 1106, 1107, 1108, 1109, 1110 };
	char prodName[11][DESC_SIZE] = { "nuts", "bolts", "nails", "hammer", "screw-driver", "s-hook", "glue", "pliers", "saw", "L-bracket" };
	double price[11] = { 0.10, 0.20, 0.05, 10.00, 5.00, 0.50, 1.98, 7.95, 25.00, 1.95 };
	int menuChoice = 0, qty[11] = { 600, 600, 1000, 65, 72, 20, 25, 6, 7, 25 };

	Product record[11];

	inventory.open("inventory.dat", ios::out | ios::binary);
	inventory.close();

	//input record[11]
	for (int i = 0; i < 10; i++)
	{
		record[i].prodNum = prodNum[i];

		for (int x = 0; x < DESC_SIZE; x++)
		{
			record[i].prodName[x] = prodName[i][x];
		}
		record[i].price = price[i];
		record[i].qty = qty[i];

		//output record[11]

	//cout << record[i].prodNum;
		for (int x = 0; x < 12; x++)
		{
			record[i].prodName[x] = prodName[i][x];
			//	cout << record[i].prodName[x];
		}
		//cout << record[i].price << record[i].qty;

		inventory.open("inventory.dat", ios::app | ios::binary);

		inventory << record[i].prodNum << "$";
		for (int x = 0; x < DESC_SIZE; x++)
		{
			inventory << record[i].prodName[x];
		}
		inventory << "$";
		//for (int x = 0; x < 1; x++)

		inventory << setw(4) << record[i].price;

		inventory << "$";
		//for (int x = 0; x < 1; x++)
		//{
		inventory << setw(4) << record[i].qty;
		//}
		inventory << "*";
		inventory.close();
	}
}
void printFile(fstream &inventory)
{
	string input;// , number, name, cost, quantity;
	int count = 0;

	inventory.open("inventory.dat", ios::in | ios::binary);

	while (inventory)
	{
		getline(inventory, input, '$');

		if (inventory)
		{
			cout << "Record #" << count << " ";
			cout << input << endl;
			//cout << sizeof(number);
			getline(inventory, input, '$');
			cout << input << endl;
			//cout << sizeof(name);
			getline(inventory, input, '$');
			cout << input << endl;
			//cout << sizeof(cost);
			getline(inventory, input, '*');
			cout << input << endl;
			//cout << sizeof(quantity);
			count++;
		}


	}
	//count--;
	inventory.close();

	//cout << count;
}
void displayRecord(fstream &inventory)
{

	string input;
	int x = 31, recNumber;// , temp;// , row[11] = { 0,29,29,31,27,26,28,29,28,26 };

	cout << "Enter record number to be displayed: ";
	cin >> recNumber;

	inventory.open("inventory.dat", ios::in | ios::binary);
	/*for (int i = 0; i <= recNumber; i++)
	{
		x = x + row[i];
	}*/
	x = x * recNumber;
	cout << "Record Number: " << recNumber << endl;
	inventory.seekg(x, ios::beg);
	if (inventory)
	{
		getline(inventory, input, '$');
		cout << input << endl;
		getline(inventory, input, '$');
		cout << input << endl;
		getline(inventory, input, '$');
		cout << input << endl;
		getline(inventory, input, '*');
		cout << input << endl;

	}
	inventory.close();
}
void modifyRecord(fstream &inventory)
{
	Product newRecord;
	char prodName[DESC_SIZE];
	string name;
	int x = 31, modNumber;// , temp, loopBreak = 0;
	//char *p = strstr(prodName, target);

	cout << "Enter record number to be modified: ";
	cin >> modNumber;


	x = x * modNumber;
	cout << "Record Number: " << modNumber << endl;

	cout << "Product Number: ";
	//cin.ignore();
	cin >> newRecord.prodNum;
	cout << "Product Name: ";
	cin.ignore();
	cin.getline(prodName, DESC_SIZE);
	//cin >> newRecord.prodName;
	/*cin.getline(newRecord.prodName, DESC_SIZE);
	cin.ignore();*/
	//getline(newRecord.prodName, test);
	cout << "Price: ";
	cin >> newRecord.price;
	cout << "Quantity: ";
	cin >> newRecord.qty;

	//name = prodName;
	inventory.open("inventory.dat", ios::in | ios::out | ios::binary);
	inventory.seekp(x, ios::beg);

	inventory << newRecord.prodNum << "$";
	inventory << setw(DESC_SIZE) << left << prodName; //= cin.getline(newRecord.prodName, DESC_SIZE);
	//for (int x = 0; x < DESC_SIZE; x++)
	//{
	//	inventory << newRecord.prodName[x];
	//	if (newRecord.prodName[x] = ' ')
	//	{
	//		inventory << " ";
	//	}
	//}
	inventory << "$";
	//for (int x = 0; x < 1; x++)

	inventory << setw(4) << newRecord.price;

	inventory << "$";
	//for (int x = 0; x < 1; x++)
	//{
	inventory << setw(4) << newRecord.qty;
	//}
	inventory << "*";
	inventory.close();
}
//inventory.open("inventory.dat", ios::in | ios::binary);
	/*if (inventory)
	{
		getline(inventory, input, ' ');
		cout << input << endl;
		getline(inventory, input, ' ');
		cout << input << endl;
		getline(inventory, input, ' ');
		cout << input << endl;
		getline(inventory, input, '*');
		cout << input << endl;

	}
	inventory.close();*/

int main()
{

	int menuChoice = 0;
	bool loopBreak = false;
	fstream inventory;
	//Product record[12];

	makeFile(inventory);

	while (loopBreak != true)
	{
		menuChoice = showMenu(menuChoice);

		switch (menuChoice)
		{

		case 1: printFile(inventory);
			break;
		case 2: displayRecord(inventory);
			break;
		case 3: modifyRecord(inventory);
			break;
		case 4: loopBreak = true;
			break;
		default: cout << "Please enter a valid option" << endl;
			break;
		}

	}
	return 0;
}

