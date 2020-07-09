// BinaryFile1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

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

int main()
{
	long prodNum[11] = { 1101, 1102, 1103, 1104, 1105, 1106, 1107, 1108, 1109, 1110 };
	char prodName[11][DESC_SIZE] = { "nuts", "bolts", "nails", "hammer", "screw-driver", "s-hook", "glue", "pliers", "saw", "L-bracket" };
	double price[11] = { 0.10, 0.20, 0.05, 10.00, 5.00, 0.50, 1.98, 7.95, 25.00, 1.95 };
	int menuChoice = 0, count = 0, qty[11] = { 600, 600, 1000, 65, 72, 20, 25, 6, 7, 25 };
	string input;
	bool loopBreak = false;
	Product record[11];
	fstream inventory;

	inventory.open("inventory.dat", ios::out | ios::binary);
	inventory.close();

	//input record[11]
	for (int i = 0; i < 10; i++)
	{
		record[i].prodNum = prodNum[i];

		for (int x = 0; x < 15; x++)
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
		for (int x = 0; x < 15; x++)
		{
			inventory << record[i].prodName[x];
		}
		inventory << "$" << record[i].price << "$" << record[i].qty << "$" << endl;
		count++;
		inventory.close();
	}
	inventory.open("inventory.dat", ios::in | ios::binary);
	if (inventory)
	{
		getline(inventory, input, '$');
		
		while (inventory)
		{
			cout << input;

			getline(inventory, input, '$');
			
		}
		
		inventory.close();
	}

	inventory.open("inventory.dat", ios::in | ios::binary);
	cout << "Here is record 1:\n";
	inventory.seekg(prodNum[1], ios::beg);
	inventory.read(reinterpret_cast<char *>(&record), sizeof(record));
	cout << record->prodNum << " " << record->price<< endl;

	cout << count;
}






//
//
//
//
//int printFile(fstream &inventory)
//{
//	Product record;
//	int count = 0;
//
//	inventory.clear();
//	inventory.seekg(0L, ios::beg);
//
//	inventory.read(reinterpret_cast<char *>(&record), sizeof(record));
//	while (!inventory.eof())
//	{
//
//		cout << "Record #" << count << "Product Number: " << record.prodNum << endl;
//		cout << "Product Name: " << record.prodName[DESC_SIZE] << endl;
//		cout << "Price: $" << record.price << endl;
//		cout << "Quantity: " << record.qty << endl;
//		inventory.read(reinterpret_cast<char *>(&record), sizeof(record));
//		count++;
//	}
//	return count;
//}
//int main()
//{
//	//long prodNum[11] = { 1101, 1102, 1103, 1104, 1105, 1106, 1107, 1108, 1109, 1110 };
//	//char prodName[11][DESC_SIZE] = { "nuts", "bolts", "nails", "hammer", "screw-driver", "s-hook", "glue", "pliers", "saw", "L-bracket" };
//	//double price[11] = { 0.10, 0.20, 0.05, 10.00, 5.00, 0.50, 1.98, 7.95, 25.00, 1.95 };
//	int menuChoice = 0;// , qty[11] = { 600, 600, 1000, 65, 72, 20, 25, 6, 7, 25 };
//	bool loopBreak = false;
//	fstream inventory;
//	Product record[12];
//
//	//dummyData(inventory);
//
//	//for (int i = 0; i < 10; i++)
//	//{
//	//	record[i].prodNum = prodNum[i];
//
//	//	for (int x = 0; x < 15; x++)
//	//	{
//	//		record[i].prodName[x] = prodName[i][x];
//	//		//	cout << record[i].prodName[x];
//	//	}
//
//	//	record[i].price = price[i];
//	//	record[i].qty = qty[i];
//
//	//	cout << record[i].prodNum;
//	//	for (int x = 0; x < 12; x++)
//	//	{
//	//		record[i].prodName[x] = prodName[i][x];
//	//		cout << record[i].prodName[x];
//	//	}
//	//	cout << record[i].price << record[i].qty;
//
//		//inventory.open("inventory.dat", ios::app | ios::binary);
//
//		//inventory << record[i].prodNum << " ";
//		//for (int x = 0; x < DESC_SIZE; x++)
//		//{
//		//	inventory << record[i].prodName[x];
//		//}
//		//inventory << " " << record[i].price << " " << record[i].qty << endl;
//		//inventory.close();
//	//}
//	while (loopBreak != true)
//	{
//		menuChoice = showMenu(menuChoice);
//
//		switch (menuChoice)
//		{
//
//		case 1: printFile(inventory);
//			break;
//		case 2:
//			break;
//		case 3:
//			break;
//		case 4: loopBreak = true;
//			break;
//		default: cout << "Please enter a valid option" << endl;
//			break;
//		}
//
//	}
//	return 0;
//}
